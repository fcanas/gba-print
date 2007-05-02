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

const u16 alphabet_Pallete[3] = {
    0x0000,0x7FFF,0x7FFF,
};

const u16 numbers [1584] =
	{
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   //!
   0x0000, 0x0000,
   0x0000, 0x0001,
   0x0000, 0x0001,
   0x0000, 0x0001,
   0x0000, 0x0001,
   0x0000, 0x0001,
   0x0000, 0x0000,
   0x0000, 0x0001,
   //"
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0100, 0x0001,
   0x0100, 0x0001,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   //#
   0x0000, 0x0000,
   0x0200, 0x0002,
   0x2220, 0x0022,
   0x0200, 0x0002,
   0x2220, 0x0022,
   0x0200, 0x0002,
   0x0000, 0x0000,
   0x0000, 0x0000,
   //$
   0x0000, 0x0000,
   0x2200, 0x0002,
   0x2020, 0x0020,
   0x2020, 0x0000,
   0x2200, 0x0002,
   0x2000, 0x0020, 
   0x2020, 0x0020, 
   0x2200, 0x0002,
   //%
   0x0000, 0x0000,
   0x0200, 0x0020,
   0x2020, 0x0020,
   0x0200, 0x0002,
   0x2000, 0x0000,
   0x0200, 0x0002,
   0x2020, 0x0020,
   0x0020, 0x0002,
   //&
   0x0000, 0x0000,
   0x2000, 0x0002,
   0x0200, 0x0020,
   0x0200, 0x0002,
   0x2000, 0x0000,
   0x0200, 0x0202,
   0x0200, 0x0020,
   0x2000, 0x0202,
   //'
   0x0000, 0x0000,
   0x2000, 0x0000,
   0x2000, 0x0000,
   0x2000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   //(
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   //)
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   //*  */
   0x0000, 0x0000,
   0x2000, 0x0000,
   0x2020, 0x0020,
   0x2200, 0x0002,
   0x2020, 0x0020,
   0x2000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   //+
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x2000, 0x0000,
   0x2000, 0x0000,
   0x2220, 0x0022,
   0x2000, 0x0000,
   0x2000, 0x0000,
   0x0000, 0x0000,
   //,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x2000, 0x0000,
   0x0200, 0x0000,
   //-
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x2220, 0x0022,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   //.
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x0000, 0x0000,
   0x2000, 0x0000,
   0x0000, 0x0000,
   // /
   0x0000, 0x0000,
   0x0000, 0x0002,
   0x2000, 0x0000,
   0x2000, 0x0000,
   0x0200, 0x0000,
   0x0200, 0x0000,
   0x0020, 0x0000,
   0x0020, 0x0000,
   
   //0
		0x0000, 0x0000,
      0x1100, 0x0001,
		0x0010, 0x0010,
		0x0010, 0x0011,
		0x1010, 0x0010,
		0x0110, 0x0010,
		0x0010, 0x0010,
		0x1100, 0x0001,
   //1
      0x0000, 0x0000,
		0x1000, 0x0000,
		0x1100, 0x0000,
		0x1000, 0x0000,
		0x1000, 0x0000,
		0x1000, 0x0000,
		0x1000, 0x0000,
		0x1000, 0x0000,
   //2
      0x0000, 0x0000,
		0x1100, 0x0001,
		0x0010, 0x0010,
		0x0000, 0x0010,
		0x0000, 0x0001,
		0x1000, 0x0000,
		0x0100, 0x0000,
		0x1110, 0x0011,
   //3
      0x0000, 0x0000,
		0x1100, 0x0001,
		0x0010, 0x0010,
		0x0000, 0x0010,
		0x1000, 0x0001,
		0x0000, 0x0010,
		0x0010, 0x0010,
		0x1100, 0x0001,
   //4
      0x0000, 0x0000,
		0x0000, 0x0001,
		0x1000, 0x0001,
		0x0100, 0x0001,
		0x0010, 0x0001,
		0x1110, 0x0011,
		0x0000, 0x0001,
		0x0000, 0x0001,
   //5
      0x0000, 0x0000,
		0x1110, 0x0011,
		0x0010, 0x0000,
		0x1110, 0x0001,
		0x0000, 0x0010,
		0x0000, 0x0010,
		0x0010, 0x0010,
		0x1100, 0x0001,
   //6
      0x0000, 0x0000,
		0x1100, 0x0001,
		0x0010, 0x0000,
		0x1110, 0x0001,
		0x0010, 0x0010,
		0x0010, 0x0010,
		0x0010, 0x0010,
		0x1100, 0x0001,
   //7
      0x0000, 0x0000,
		0x1110, 0x0011,
		0x0010, 0x0010,
		0x0000, 0x0010,
		0x0000, 0x0001,
		0x1000, 0x0000,
		0x1000, 0x0000,
		0x1000, 0x0000,
   //8
      0x0000, 0x0000,
		0x1100, 0x0001,
		0x0010, 0x0010,
		0x0010, 0x0010,
		0x1100, 0x0001,
		0x0010, 0x0010,
		0x0010, 0x0010,
		0x1100, 0x0001,
   //9
      0x0000, 0x0000,
		0x1100, 0x0001,
		0x0010, 0x0010,
		0x0010, 0x0010,
		0x0010, 0x0010,
		0x1100, 0x0011,
		0x0000, 0x0010,
		0x1100, 0x0001,
      //////////////////
   //:
    0x0000,0x0000,
    0x0000,0x0000,
    0x2000,0x0000,
    0x0000,0x0000,
    0x0000,0x0000,
    0x2000,0x0000,
    0x0000,0x0000,
    0x0000,0x0000,
    //;
    0x0000,0x0000,
    0x0000,0x0000,
    0x2000,0x0000,
    0x0000,0x0000,
    0x0000,0x0000,
    0x2000,0x0000,
    0x2000,0x0000,
    0x0200,0x0000,
    //<
    0x0000,0x0000,
    0x0000,0x0002,
    0x2000,0x0000,
    0x0200,0x0000,
    0x0020,0x0000,
    0x0200,0x0000,
    0x2000,0x0000,
    0x0000,0x0002,
    //=
    0x0000,0x0000,
    0x0000,0x0000,
    0x0000,0x0000,
    0x2220,0x0022,
    0x0000,0x0000,
    0x2220,0x0022,
    0x0000,0x0000,
    0x0000,0x0000,
    //>
    0x0000,0x0000,
    0x2000,0x0000,
    0x0000,0x0002,
    0x0000,0x0020,
    0x0000,0x0200,
    0x0000,0x0020,
    0x0000,0x0002,
    0x2000,0x0000,
    
    //?
    0x0000,0x0000,
    0x2200,0x0002,
    0x0020,0x0020,
    0x0000,0x0020,
    0x0000,0x0002,
    0x2000,0x0000,
    0x0000,0x0000,
    0x2000,0x0000,
    //@
    0x0000,0x0000,
    0x0000,0x0022,
    0x2000,0x0200,
    0x0200,0x0220,
    0x0200,0x0202,
    0x0200,0x0220,
    0x2000,0x0000,
    0x0000,0x0222,

//A
    0x0000,0x0000,
    0x2200,0x0002,
    0x0020,0x0020,
    0x0020,0x0020,
    0x2220,0x0022,
    0x0020,0x0020,
    0x0020,0x0020,
    0x0020,0x0020,
    
// B
    0x0000,0x0000,
    0x2220,0x0002,
    0x0020,0x0020,
    0x0020,0x0020,
    0x2220,0x0002,
    0x0020,0x0020,
    0x0020,0x0020,
    0x2220,0x0002,

// C
    0x0000,0x0000,
    0x2200,0x0002,
    0x0020,0x0020,
    0x0020,0x0000,
    0x0020,0x0000,
    0x0020,0x0000,
    0x0020,0x0020,
    0x2200,0x0002,

// D
    0x0000,0x0000,
    0x2220,0x0002,
    0x0020,0x0020,
    0x0020,0x0020,
    0x0020,0x0020,
    0x0020,0x0020,
    0x0020,0x0020,
    0x2220,0x0002,
    
// E
    0x0000, 0x0000,
    0x2220, 0x0022,
    0x0020, 0x0000,
    0x0020, 0x0000,
    0x2220, 0x0002,
    0x0020, 0x0000,
    0x0020, 0x0000,
    0x2220, 0x0022,

// F
    0x0000, 0x0000,
    0x2220, 0x0022,
    0x0020, 0x0000,
    0x0020, 0x0000,
    0x2220, 0x0002,
    0x0020, 0x0000,
    0x0020, 0x0000,
    0x0020, 0x0000,

// G
    0x0000, 0x0000,
    0x2200, 0x0002,
    0x0020, 0x0020,
    0x0020, 0x0000,
    0x0020, 0x0022,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x2200, 0x0002,

// H
    0x0000, 0x0000,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x2220, 0x0022,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0020, 0x0020,
    

// I
    0x0000,0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,

// J

    0x0000, 0x0000,
    0x0000, 0x0020,
    0x0000, 0x0020,
    0x0000, 0x0020,
    0x0000, 0x0020,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x2200, 0x0002,

// K
    0x0000, 0x0000,
    0x0020, 0x0020,
    0x0020, 0x0002,
    0x2020, 0x0000,
    0x0220, 0x0000,
    0x2020, 0x0000,
    0x0020, 0x0002,
    0x0020, 0x0020,
    

// L  
    0x0000,0x0000,
    0x0020, 0x0000,
    0x0020, 0x0000,
    0x0020, 0x0000,
    0x0020, 0x0000,
    0x0020, 0x0000,
    0x0020, 0x0000,
    0x2220, 0x0022,

// M
    0x0000, 0x0000,
    0x0020, 0x0020,
    0x0220, 0x0022,
    0x2020, 0x0020,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0020, 0x0020,

// N
    0x0000, 0x0000,
    0x0020, 0x0020,
    0x0220, 0x0020,
    0x2020, 0x0020,
    0x0020, 0x0022,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0020, 0x0020,

// O
    
    0x0000,0x0000,
    0x2200, 0x0002,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x2200, 0x0002,

// P
    0x0000,0x0000,
    0x2220, 0x0002,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x2220, 0x0002,
    0x0020, 0x0000,
    0x0020, 0x0000,
    0x0020, 0x0000,

// Q

    0x0000, 0x0000,
    0x2200, 0x0002,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x2020, 0x0020,
    0x2200, 0x0002,
    0x0000, 0x0020,

// R
    0x0000, 0x0000,
    0x2220, 0x0002,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x2220, 0x0002,
    0x2020, 0x0000,
    0x0020, 0x0002,
    0x0020, 0x0020,

// S

    0x0000, 0x0000,
    0x2200, 0x0002,
    0x0020, 0x0020,
    0x0020, 0x0000,
    0x2200, 0x0002,
    0x0000, 0x0020, 
    0x0020, 0x0020, 
    0x2200, 0x0002,

// T

    0x0000, 0x0000,
    0x2220, 0x0022,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,

// U
   
   0x0000, 0x0000,
   0x0020, 0x0020,
   0x0020, 0x0020,
   0x0020, 0x0020,
   0x0020, 0x0020,
   0x0020, 0x0020,
   0x0020, 0x0020,
   0x2200, 0x0002,

// V
  
    0x0000, 0x0000,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0200, 0x0002,
    0x0200, 0x0002,
    0x2000, 0x0000,
    0x2000, 0x0000,

// W
    
    0x0000, 0x0000,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x2020, 0x0020,
    0x0220, 0x0022,
    0x0020, 0x0020,

    

// X
    0x0000, 0x0000,
    0x0020, 0x0020,
    0x0200, 0x0002,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x0200, 0x0002,
    0x0020, 0x0020,

// Y
    0x0000, 0x0000,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0200, 0x0002,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    

// Z

    0x0000, 0x0000,
    0x2220, 0x0022,
    0x0000, 0x0020,
    0x0000, 0x0002,
    0x2000, 000000,
    0x0200, 0x0000,
    0x0020, 0x0000,
    0x2220, 0x0022,
        
    //////////////////
    //[
      0x0000, 0x0000,
      0x2000,0x0022,
		0x2000,0x0000,
      0x2000,0x0000,
      0x2000,0x0000,
      0x2000,0x0000,
      0x2000,0x0000,
      0x2000,0x0022,
      //Backslash
      0x0200,0x0000,
      0x0200,0x0000,
      0x2000,0x0000,
      0x2000,0x0000,
      0x0000,0x0002,
      0x0000,0x0002,
      0x0000,0x0020,
      0x0000,0x0020,
      //]
      
      0x0000,0x0000,
      0x2000,0x0022,
		0x0000,0x0020,
      0x0000,0x0020,
      0x0000,0x0020,
      0x0000,0x0020,
      0x0000,0x0020,
      0x2000,0x0022,
      //^
      0x0000,0x0000,
      0x0000,0x0002,
      0x2000,0x0020,
      0x0200,0x0200,
      0x0000,0x0000,
      0x0000,0x0000,
      0x0000,0x0000,
      0x0000,0x0000,
      //_
      0x0000,0x0000,
      0x0000,0x0000,
      0x0000,0x0000,
      0x0000,0x0000,
      0x0000,0x0000,
      0x0000,0x0000,
      0x0000,0x0000,
      0x2220,0x0222,
      //`
      0x0000,0x0000,
      0x2000,0x0000,
      0x0000,0x0002,
      0x0000,0x0020,
      0x0000,0x0000,
      0x0000,0x0000,
      0x0000,0x0000,
      0x0000,0x0000,
      
      /////////////
// a
    0x0000,0x0000,
    0x0000,0x0000,
    0x0000,0x0000,
    0x2000,0x0222,
    0x0200,0x0200,
    0x0200,0x0200,
    0x0200,0x0220,
    0x2000,0x0202,

// b
    0x0000,0x0000,
    0x0200,0x0000,
    0x0200,0x0000,
    0x0200,0x0022,
    0x2200,0x0200,
    0x0200,0x0200,
    0x0200,0x0200,
    0x2200,0x0022,

// c
    0x0000,0x0000,
    0x0000,0x0000,
    0x0000,0x0000,
    0x2000,0x0022,
    0x0200,0x0200,
    0x0200,0x0000,
    0x0200,0x0000,
    0x2000,0x0222,

// d
    0x0000,0x0000,
    0x0000,0x0200,
    0x0000,0x0200,
    0x2000,0x0222,
    0x0200,0x0200,
    0x0200,0x0200,
    0x0200,0x0200,
    0x2000,0x0222,
    
// e

    0x0000,0x0000,
    0x0000,0x0000,
    0x0000,0x0000,
    0x2000,0x0022,
    0x0200,0x0200,
    0x2200,0x0222,
    0x0200,0x0000,
    0x2000,0x0222,

// f

    0x0000, 0x0000,
    0x2000, 0x0002,
    0x0200, 0x0000,
    0x2220, 0x0002,
    0x0200, 0x0000,
    0x0200, 0x0000,
    0x0200, 0x0000,
    0x0200, 0x0000,
    
// g
    
    0x0000,0x0000,
    0x2000,0x0222,
    0x0200,0x0200,
    0x0200,0x0200,
    0x0200,0x0200,
    0x2000,0x0222,
    0x0000,0x0200,
    0x2000,0x0022,

/*
    0x2000,0x0222,
    0x0200,0x0200,
    0x0200,0x0200,
    0x0200,0x0200,
    0x0200,0x0220,
    0x2000,0x0202,
    0x0000,0x0200,
    0x2000,0x0022,

*/

// h
    0x0000 ,0x0000,
    0x0200, 0x0000,
    0x0200, 0x0000,
    0x2200, 0x0022,
    0x0200, 0x0200,
    0x0200, 0x0200,
    0x0200, 0x0200,
    0x0200, 0x0200,
    

// i
    0x0000, 0x0000,
    0x2000, 0x0000,
    0x0000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,

// j

    0x0000, 0x0000,
    0x0000, 0x0002,
    0x0000, 0x0000,
    0x0000, 0x0002,
    0x0000, 0x0002,
    0x0000, 0x0002,
    0x0000, 0x0002,
    0x2200, 0x0000,
    
// k
    0x0000, 0x0000,    
    0x0200, 0x0000,
    0x0200, 0x0000,
    0x0200, 0x0020,
    0x0200, 0x0002,
    0x2200, 0x0002,
    0x0200, 0x0020,
    0x0200, 0x0200,
    

// l
    0x0000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0000,
    0x2000, 0x0002,

// m
    0x0000,0x0000,
    0x0000,0x0000,
    0x0000,0x0000,
    0x2200,0x0020,
    0x0200,0x0202,
    0x0200,0x0202,
    0x0200,0x0202,
    0x0200,0x0202,

// n
    
    0x0000,0x0000,
    0x0000,0x0000,
    0x0000,0x0000,
    0x0200,0x0022,
    0x2200,0x0200,
    0x0200,0x0200,
    0x0200,0x0200,
    0x0200,0x0200,

// o
    
    0x0000,0x0000,
    0x0000,0x0000,
    0x0000, 0x0000,
    0x2000,0x0022,
    0x0200,0x0200,
    0x0200,0x0200,
    0x0200,0x0200,
    0x2000,0x0022,

// p
    0x0000,0x0000,
    0x0000,0x0000,
    0x2200,0x0022,
    0x0200,0x0200,
    0x0200,0x0200,
    0x2200,0x0022,
    0x0200,0x0000,
    0x0200,0x0000,


// q

    0x0000,0x0000,
    0x0000,0x0000,
    0x2000,0x0222,
    0x0200,0x0200,
    0x0200,0x0200,
    0x2000,0x0222,
    0x0000,0x0200,
    0x0000,0x0200,
    
// r
    
    0x0000,0x0000,
    0x0000,0x0000,
    0x0000,0x0000,
    0x0200,0x0022,
    0x2200,0x0200,
    0x0200,0x0000,
    0x0200,0x0000,
    0x0200,0x0000,

// s

    0x0000,0x0000,
    0x0000,0x0000,
    0x0000,0x0000,
    0x2200,0x0022,
    0x0020,0x0000,
    0x2200,0x0002,
    0x0000,0x0020,
    0x2220,0x0002,

// t

    0x0000,0x0000,
    0x0200, 0x0000,
    0x0200, 0x0000,
    0x2220, 0x0002,
    0x0200, 0x0000,
    0x0200, 0x0000,
    0x0200, 0x0000,
    0x2000, 0x0002,

// u
   
    0x0000,0x0000,
    0x0000,0x0000,
    0x0000,0x0000,
    0x0200,0x0200,
    0x0200,0x0200,
    0x0200,0x0200,
    0x0200,0x0220,
    0x2000,0x0202,

// v
  
    0x0000, 0x0000,
    0x0000, 0x0000,
    0x0000, 0x0000,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0200, 0x0002,
    0x0200, 0x0002,
    0x2000, 0x0000,
    
// w
    

    0x0000,0x0000,
    0x0000,0x0000,
    0x0000,0x0000,
    0x0200,0x0202,
    0x0200,0x0202,
    0x0200,0x0202,
    0x0200,0x0202,
    0x2000,0x0020,
    

// x

    0x0000, 0x0000,
    0x0000, 0x0000,
    0x0000, 0x0000,
    0x0020, 0x0020,
    0x0200, 0x0002,
    0x2000, 0x0000,
    0x0200, 0x0002,
    0x0020, 0x0020,

// y

    0x0000, 0x0000,
    0x0000, 0x0000,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x0020, 0x0020,
    0x2200, 0x0022,
    0x0000, 0x0020,
    0x2200, 0x0002,
    

// z

    0x0000, 0x0000,
    0x0000, 0x0000,
    0x0000, 0x0000,
    0x2220, 0x0022,
    0x0000, 0x0002,
    0x2000, 0x0000,
    0x0200, 0x0000,
    0x2220, 0x0022,   
    
    /////////////////
    
    //{
      0x0000,0x0000,
      0x0000,0x0022,
      0x2000,0x0000,
      0x2000,0x0000,
      0x0220,0x0000,
      0x2000,0x0000,
      0x2000,0x0000,
      0x0000,0x0022,
      
      //|
      0x0000,0x0000,
      0x2000,0x0000,
      0x2000,0x0000,
      0x2000,0x0000,
      0x2000,0x0000,
      0x2000,0x0000,
      0x2000,0x0000,
      0x2000,0x0000,
      //}
      0x0000,0x0000,
      0x2200,0x0000,
      0x0000,0x0002,
      0x0000,0x0002,
      0x0000,0x0220,
      0x0000,0x0002,
      0x0000,0x0002,
      0x2200,0x0000,
      //~
      0x0000,0x0000,
      0x0000,0x0000,
      0x0000,0x0000,
      0x2200,0x0200,
      0x0020,0x0022,
      0x0000,0x0000,
      0x0000,0x0000,
      0x0000,0x0000,
};
