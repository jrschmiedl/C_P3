/**
  @file text.c file
  @author jrschmie Jacob Schmiedl
  Text file that handles the input and output for the program.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "text.h"
#include "operations.h"

/** The max number of rows in a file */
#define MAX_ROWS 10000
/** The max amount of characters in a line */
#define MAX_CHARATERS 100
/** Global char array used to edit the text */
extern char array[ MAX_ROWS ][ 101 ];
/** Global integer of the amount of lines in the text */
extern int numberOfLines;

/**
  Readfile function. It reads in a file and stores it in the array.
  @param fp pointer to the file
 */  
void readFile( FILE *fp )
{
    char ch;
    int count = 0;
    numberOfLines = 0;

    while ( fscanf( fp, "%c", &ch ) != EOF)
    {
       count++;
       if ( ch == '\n' )
       {
           array[ numberOfLines ][ count - 1] = '\0';
           numberOfLines++;
           count = 0;
       } else
       {
           array[ numberOfLines ][ count - 1 ] = ch;
       }
       if ( count >= MAX_CHARATERS ) 
       {
           fprintf( stderr, "Line too long\n" );
           exit( 1 );
       }
       if ( numberOfLines >= MAX_ROWS ) 
       {
           fprintf( stderr, "Too many lines\n" );
           exit( 1 );
       }
    }
}

/**
  Writefile function. It writes the array back into a textfile.
  @param fp pointer to the file
 */  
void writeFile( FILE *fp )
{
    int lines = numberOfLines;
    int col;
    for ( int row = 0; row < lines; row++ )
    {
        int len = strlen( array[ row ] );
        for ( col = 0; col < len ; col++ )
        {
            fprintf( fp, "%c", array[ row ][ col ] );
        }
        fprintf( fp, "\n" );
    }

}