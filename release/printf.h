#include "gba_types.h"
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

   DOCUMENTATION

   Some documentation phrasing and format adapted from BSD manual page printf(1)
   The presumed liscence applicable to parts of the documentation are at the end
   of this file.
   
   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!WARNING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   !!!BEFORE USING printf, initTextBG MUST BE CALLED AND RETURN SUCCESSFULLY!!!
   !!!!!!!!THOUGH printf IS WIDELY KNOWN, READ initTextBG BEFORE USING!!!!!!!!!
   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   
   The first argument is a format specification, which affects how the remaining
   arguments are printed.

   Three types of input can be passed within the format string:
      - Plain characters are printed directly onto the screen.
      - Escape sequences are interpreted and are printed to the screen.
      - Format specifications cause the printing of the next argument in a 
        specific way.

   Accepted Escape sequences are as follows:

           \b      Write a <backspace> character.

           \n      Write a <new-line> character.

           \t      Write a <tab> character.

           \'      Write a <single quote> character.

           \\      Write a backslash character.
           
   Each format specification is introduced by the percent character (``%'').
   The remainder of the format specification includes:
   
   dioXx      The argument is printed as a unsigned decimal (d or i),
               unsigned octal (o), unsigned hexadecimal (X
               or x), respectively.
               
   c           The first character of argument is printed.

   s           Characters from the string argument are printed until the end
                 is reached or until the number of characters indicated by the
                 precision specification is reached; however if the precision
                 is 0 or missing, all characters in the string are printed.

   %           Print a `%'; no argument is used.
   
*/
void print_f(char *fmt, ...);

/* Initializes backgrounds and tiles for the GBA to print to the screen.
   
   screenBB    [0-31]Determines which screen base block will be used to write 
                 text to. The printing screen takes up 1Kb, or exactly half of
                 the space allocated for a screen base block.
   
   bgNum       [0-3] Sets the background control register for a given background 
                 number (bgNum) for use as a tiled text background with the
                 appropriate screen and character base blocks as a sources.

   charBlock   [0-3] Determines which character block the character pallette 
                 will be loaded into. This requires 3168 bytes of space. Since  
                 one Character block is 16Kb, very little overall space is used.
                 The biggest restriction now is that these tiles must be at the 
                 beginning of a character base block.
               
   Important Details on Use:
   
   These functions can only be used in modes 0 and 1. In mode 0, backgrounds 0-3
   are available. In mode 1, only backgrounds 0 and 1 are available. This is due
   to the fact that text is printed on a tiled background without without
   rotation and scaling.
   
   In order to make the smallest program capable of printing to the screen as
   simple as possible, initTextBG sets the GBA's graphics mode, and may conflict
   with more complex code if backgrounds are not appropriately managed.
   
   Within the semi-standard macros used to develop this utility, the following
   settings are put in place upon initialization:
   
   SetMode( MODE_0 | OBJ_ENABLE | OBJ_MAP_1D | BG0_ENABLE );
                                                 ^
                                                 This character is variable
                                                 based on the desired screen.
   
   Once initialized, if no other GBA graphics code needs to run, you should have
   a fully functional screen printer. ``OBJ_ENABLE | OBJ_MAP_1D'' is included
   to simplify the inclusion of sprites in a hypothetical simple program without
   tampering with screen modes.
   
   IF MORE THAN ONE BACKGROUND IS DESIRED, the programmer will have to MANUALLY
   ACTIVATE the appropriate backgrounds, INCLUDING THE TEXT BACKGROUND, AFTER 
   CALLING THE INITTEXTBG FUNCTION!!!
   
   Example:
      If you want to use mode 0 with backgrounds 0 and 1 in addition to the text
      background, you should set the text background to 2 (or 3) and some of 
      your code would appear as follows:
      
      initTextBG(textSBB, 2, textCBB);
      SetMode( MODE_0 | BG0_ENABLE | BG1_ENABLE | BG2_ENABLE );
      
      where textSBB and textCBB were previously defined, and this program will
      not use sprites.
   
*/ 
void initTextBG(u16 screenBB, u16 bgNum, u16 charBlock);

/*-Portions of this document may be:

 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)stdio.h	8.5 (Berkeley) 4/29/95
 */
