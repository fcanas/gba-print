/* printf - Format and print strings to GBA the screen.
   Copyright (C) 2007  Fabian Canas

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#include "gba.h"
#include "gba_dma.h"
#include "Alpha.h"
#include "printf.h"
#include <stdlib.h>

//u16 bg;

typedef struct{
   u16 charFinger;
   u16 rowFinger;
   u16* ScreenBB;
   u16 scrollOffset;
   u16 scrollingFlag;
   u16 BGNum;
} printf_screen_t;

printf_screen_t* printf_gScreen;

/*
u16 charFinger;
u16 rowFinger;
u16* ScreenBB;

u16 scrollOffset;
u16 scrollingFlag;
u16 BGNum;
*/

static void DMACopy(void* source,void* dest,unsigned int count,unsigned int mode) { 
   if (mode == DMA_16NOW || mode == DMA_32NOW) { 
      REG_DMA3SAD = (unsigned int)source;
      REG_DMA3DAD = (unsigned int)dest;
      REG_DMA3CNT = count | mode;
   } 
} 

static void setOffset(){
   switch (printf_gScreen->BGNum){
         case 0:
            REG_BG0VOFS = printf_gScreen->scrollOffset;
            break;
         case 1:
            REG_BG1VOFS = printf_gScreen->scrollOffset;
            break;
         case 2:
            REG_BG2VOFS = printf_gScreen->scrollOffset;
            break;
         case 3:
            REG_BG3VOFS = printf_gScreen->scrollOffset;
            break;
      }
}

static void nextRow(){
   if (printf_gScreen->rowFinger > 17) printf_gScreen->scrollingFlag = 1;
   if (printf_gScreen->rowFinger > 64) printf_gScreen->rowFinger -= 32;
   if (printf_gScreen->scrollingFlag){
      printf_gScreen->scrollOffset += 8;
      setOffset();
      int i;
      for (i=0;i<29;i++){
        printf_gScreen->ScreenBB[i + (((printf_gScreen->rowFinger-19)&0x1F)<<5)] = 1;
      }
   }
   printf_gScreen->rowFinger++;
}

static void printchar(char c){
   if (c>31) c = c - 31;
   else if(c==10) {
      nextRow();
      printf_gScreen->charFinger=0;
      return;
   } else if(c==9) {
      printf_gScreen->charFinger += 3;
      if (printf_gScreen->charFinger > 29) {
         nextRow();
         printf_gScreen->charFinger = 0;
      }
      return;
   }
   else if(c==8) {
      if (printf_gScreen->charFinger==0) {
         printf_gScreen->charFinger = 29;
         printf_gScreen->rowFinger --;
      } else printf_gScreen->charFinger -= 1;
      printf_gScreen->ScreenBB[printf_gScreen->charFinger + 
         ((printf_gScreen->rowFinger & 0x1F)<<5)] = 1;
      return;
   }
   
   printf_gScreen->ScreenBB[printf_gScreen->charFinger + 
      ((printf_gScreen->rowFinger & 0x1F)<<5)] = c;
   printf_gScreen->charFinger++;
   
   if (printf_gScreen->charFinger > 29) {
      nextRow();
      printf_gScreen->charFinger = 0;
   }
}

static void reverseString(char* c, int size) {
   char r[size];
   int i;
   int j = size - 1;
   for(i = 0; i <= j; i++) {
      j--;
      r[i] = c[j];
      r[j] = c[i];
   }
   for(i=0; i<size-1; i++){
      c[i]=r[i];
   }
}

static void intToCharP(unsigned int i, char* c, int base){
   int j=0;
   while(i != 0){
      c[j] = (i % base) + 48;
      if (((c[j]-48) > 9) && base>10) c[j] += 7;
      i = i/base;
      j++;
   }
   c[j]='\0';
   reverseString(c, j+1);
}

//Warning, does funny stuff when printing an octal # with bit 30 `on'
static void printBase(int i, int base){
   char num[11]; //Max 32b width in octal
   if (i==0) {
   num[0]='0';
   num[1]='\0';
   }
   else intToCharP(i, num, base);
   print_f(num);
}

void print_f(char *fmt, ...){
   char *p; //Critical for this to be the first line (bad hack)
   int i;
   char *s;
   char fmtbuf[256];
   int argNum = 9; //More of that bad hack: 9th memory location after first var
                   //is the second argument. 

   for(p = fmt; *p != '\0'; p++){
      if (*p == 37){
         p++;
         switch(*p){
            case 'c':
               i = ((int*) &p)[argNum];
               argNum++;
               printchar(i);
               break;
               
            case 'd':
               i = ((int*) &p)[argNum];
               argNum++;
               printBase(i,10);
               break;
               
            case 'i':
               i = ((int*) &p)[argNum];
               argNum++;
               printBase(i,10);
               break;
                  
            case 's':
               s = (char*)((int*) &p)[argNum];
               argNum++;
               print_f(s);
               break;
               
            case 'x':
               i = ((int*) &p)[argNum];
               argNum++;
               printBase(i,16);
               break;
               
            case 'X':
               i = ((int*) &p)[argNum];
               argNum++;
               printBase(i,16);
               break;
               
            case 'o':
               i = ((int*) &p)[argNum];
               argNum++;
               printBase(i,8);
               break;
               
            case '%':
               printchar('%');
               break;
            default: printchar('Z');
         }
      } else {
         printchar(*p);
      }
   }
}

// ScreenBB, Background Number (0-3), charbb
void initTextBG(u16 screenBB, u16 bgNum, u16 charBlock){
   
   printf_gScreen = (printf_screen_t*) malloc(sizeof(printf_screen_t));
   
   printf_gScreen->charFinger=0;
   printf_gScreen->rowFinger=0;
   printf_gScreen->ScreenBB = (u16*) 0;
   printf_gScreen->scrollOffset=0;
   printf_gScreen->scrollingFlag=0;
   printf_gScreen->BGNum=0;
   
   u16 shape = TEXTBG_SIZE_256x256;
   printf_gScreen->ScreenBB = (u16*)ScreenBaseBlock(screenBB);
   u16* CharBB = (u16*) CharBaseBlock(charBlock);

   switch (bgNum) {
      case 0:
         SetMode( MODE_0 | OBJ_ENABLE | OBJ_MAP_1D | BG0_ENABLE );
         REG_BG0CNT = (BG_COLOR_16 | shape | screenBB<<SCREEN_SHIFT | charBlock<<CHAR_SHIFT);
         break;
      case 1:
         SetMode( MODE_0 | OBJ_ENABLE | OBJ_MAP_1D | BG1_ENABLE );
         REG_BG1CNT = (BG_COLOR_16 | shape | screenBB<<SCREEN_SHIFT | charBlock<<CHAR_SHIFT);
         break;
      case 2:
         SetMode( MODE_0 | OBJ_ENABLE | OBJ_MAP_1D | BG2_ENABLE );
         REG_BG2CNT = (BG_COLOR_16 | shape | screenBB<<SCREEN_SHIFT | charBlock<<CHAR_SHIFT);
         break;
      case 3:
         SetMode( MODE_0 | OBJ_ENABLE | OBJ_MAP_1D | BG3_ENABLE );
         REG_BG3CNT = (BG_COLOR_16 | shape | screenBB<<SCREEN_SHIFT | charBlock<<CHAR_SHIFT);
         break;
   }
      
   DMACopy((void*) alphabet_Pallete, (void*) BG_PaletteMem, 3, DMA_16NOW);
   
   DMACopy((void*) numbers, (void*) (CharBB+16), 1584, DMA_16NOW);
   printf_gScreen->charFinger = 0;
   printf_gScreen->rowFinger = 0;
   printf_gScreen->scrollingFlag = 0;
   printf_gScreen->scrollOffset = 0;
   printf_gScreen->BGNum=bgNum;
   
   setOffset();
   
   int x, y;
   //clear screen
   for(y=0; y<31; y++){
      for(x=0; x<31; x++){
         printf_gScreen->ScreenBB[x + (y<<5)] = 1;
      }
   }
}
