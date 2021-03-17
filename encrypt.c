/**
  @file encrypt.c file
  @author jrschmie Jacob Schmiedl
  This file handles all of the decryption done.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "text.h"
#include "operations.h"

/**
  Main Method 
  @param argc integer of arguments given by the command line.
  @param argv[] array pointer that holds the arguments
  @return output success. 
 */ 
int main( int argc, char *argv[] ) 
{
   int swap1;
   int swap2;
   int letterShift;

   FILE *fp = NULL;
   if ( strcmp( argv[ argc - 2 ], "-" ) == 0) {
       fp = stdin;
   } else {
       fp = fopen( argv[ argc - 2 ], "r" );
   }
   if ( !fp )
   {
        fprintf( stderr, "Can't open file: %s\n", argv[ argc -2 ] );
        exit ( 1 );
   }
   readFile( fp );
   
   for ( int i = 1; i < argc - 2; i++ )
   {
       if ( strcmp( argv[ i ], "left" ) == 0)
       {
           rotateLinesLeft();
       } else if ( strcmp( argv[ i ], "right" ) == 0)
       {
           rotateLinesRight();
       } else if ( strcmp( argv[ i ], "swap" ) == 0)
       {
           swap1 = atoi( argv[ i + 1 ] );
           swap2 = atoi( argv[ i + 2 ] );
           if ( swap1 > numberOfLines || swap2 > numberOfLines )
           {
               fprintf( stderr, "invalid arguments\nusage: encrypt operation* (infile|-) (outfile|-)\n");
               exit( 1 );
           }
           swapLines( swap1, swap2 );
       } else if ( strcmp( argv[ i ], "reverse" ) == 0)
       {
           reverseLines();
       } else if ( strcmp( argv[ i ], "shift" ) == 0)
       {
           letterShift = atoi( argv[ i + 1 ] );
           shiftLetters( letterShift );
       } else if ( strspn( argv[ i ], "[0123456789]") == 0)
       {
           fprintf( stderr, "invalid arguments\nusage: encrypt operation* (infile|-) (outfile|-)\n" );
           exit( 1 );
       }
   }

   fclose( fp );

   fp = NULL;
   if ( strcmp( argv[ argc - 1 ], "-" ) == 0 )
   {
       fp = stdout;
   } else {
       fp = fopen( argv[ argc - 1 ], "w");
   }

   if ( !fp )
   {
       fprintf( stderr, "Can't open file: %s\n", argv[ argc - 1 ] );
       exit ( 1 );
   }

   writeFile( fp );


   fclose( fp );

   return EXIT_SUCCESS;
}
