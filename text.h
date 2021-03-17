/**
  @file text.h
  @author jrschmie Jacob Schmiedl
  The header file for text.c
 */

/**
  Readfile function. It reads in a file and stores it in the array.
  @param fp pointer to the file
 */  
void readFile( FILE *fp );

/**
  Writefile function. It writes the array back into a textfile.
  @param fp pointer to the file
 */  
void writeFile( FILE *fp );

/** The max number of rows in a file */
#define MAX_ROWS 10000

/** The max amount of characters in a line */
#define MAX_CHARATERS 100

/** Global char array used to edit the text */
char array[ MAX_ROWS ][ 101 ];

/** Global integer of the amount of lines in the text */
int numberOfLines;