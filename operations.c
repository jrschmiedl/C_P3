/**
  @file operations.c file
  @author jrschmie Jacob Schmiedl
  Does all of the operations for encrypt and decrypt
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operations.h"
#include "text.h"

/** The max amount you are allowed to shift a letter */
#define MAX_SHIFT 25
/** The min amount you are allowed to shift a letter */
#define MIN_SHIFT 1

/**
  ReverseLines method
  Reverses all of the lines in the text file  
 */ 
void reverseLines()
{
    char word;

    int row = 0;

    while ( row < numberOfLines )
    {
        int len = strlen( array[ row ] );
        char line[ len ];
        for (int col = 0; col < len; col++ )
        {
            line[ col ] = array[ row ][ col ];
        }
        int count = 0;

        while ( count < len )
        {
           word = line[ len - 1];
           line[ len - 1 ] = line[ count ];
           line[ count ] = word;
           count++;
           len--;
        }

        len = strlen( array[ row ] );
        for (int col = 0; col < len; col++ )
        {
            array[ row ][ col ] = line[ col ];
        }
        row++;
    }
}

/**
  SwapLines method. Swaps places of the two lines 
  @param m row number of the line trying to be swapped.
  @param n row number of the line trying to be swapped.
 */ 
void swapLines( int m, int n )
{
    m--;
    n--;
    int lenM = sizeof( array[ m ] ) / sizeof( array[ m ][ 0 ] );
    int lenN = sizeof( array[ n ] ) / sizeof( array[ n ][ 0 ] );
    char temp[ m ][ lenM ];

    for (int i = 0; i < lenM; i++ )
    {
        temp[ m - 1 ][ i ] = array[ m ][ i ];
    }
    for (int i = 0; i < lenN; i++ )
    {
        array[ m ][ i ] = array[ n ][ i ];
    }
    for (int i = 0; i < lenM; i++ )
    {
        array[ n ][ i ] = temp[ m - 1 ][ i ];
    }
}

/**
  Rotates the character 1 to the left. 
 */ 
void rotateLinesLeft()
{
    for ( int row = 0; row < numberOfLines; row++ )
    {
        char beginning = array[ row ][ 0 ];
        int len = strlen( array[ row ] );
        for ( int col = 1; col < len; col++ ) 
        {
            array[ row ][ col - 1 ] = array[ row ][ col ];
        }
        array[ row ][ len - 1 ] = beginning;
    }
}

/**
  Rotates the character 1 to the right. 
 */ 
void rotateLinesRight()
{
    char temp[ numberOfLines ][ 100 ];
    for ( int row = 0; row < numberOfLines; row++ )
    {
        int len = strlen( array[ row ] );
        temp[ row ][ 0 ] = array[ row ][ len - 1 ];
        for ( int col = len - 1; col > 0; col-- ) 
        {
            array[ row ][ col ] = array[ row ][ col - 1 ];
        }
        array[ row ][ 0 ] = temp[ row ][ 0 ];
    }
}

/**
  Shifts the Letter by the number given (ASCII)
  @param n integer that represents how far the letters should be shifted.
 */  
void shiftLetters( int n )
{

    int row = 0;
    int distance = 0;
    while ( row < numberOfLines )
    {
        int len = strlen( array[ row ] );
        char line[ len ];
        for (int col = 0; col < len; col++ )
        {
            line[ col ] = array[ row ][ col ];
        }

        if ( n >= MIN_SHIFT && n <= MAX_SHIFT )
        {
            for ( int i = 0; i <= len - 1; i++ )
            {
                if ( ( line[ i ] == ' ' ) || ( line[ i ] == '.' ) )
                {
                    //skip
                } else if ( ( line[ i ] + n) > 90 && line[ i ] >= 65 && line[ i ] <= 90 )
                {
                    distance = line[ i ] + n - 90;
                    line[ i ] = ( 65 - 1 ) + distance;
                 } else if ( ( line[ i ] + n) > 122 && line[ i ] >= 97 && line[ i ] <= 122 ) 
                 {
                    distance = line[ i ] + n - 122;
                    line[ i ] = ( 97 - 1 ) + distance;
                 } else if ( ( line[ i ] >= 65 && line[ i ] <= 90 ) || ( line[ i ] >= 97 && line[ i ] <= 122 ) ) 
                 {
                    line[ i ] = line[ i ] + n;
                 } 
            }
        } else if ( n < MIN_SHIFT && n >= -MAX_SHIFT )
        {
            for ( int i = 0; i <= len - 1; i++ )
            {
                if ( ( line[ i ] == ' ' ) || ( line[ i ] == '.' ) )
                {
                    //skip
                } else if ( ( line[ i ] + n) < 65 && line[ i ] >= 65 && line[ i ] <= 90 )
                {
                    distance = 65 - ( line[ i ] + n );
                    line[ i ] = ( 90 + 1 ) - distance;
                 } else if ( ( line[ i ] + n) < 97 && line[ i ] >= 97 && line[ i ] <= 122 ) 
                 {
                    distance = 97 - (line[ i ] + n );
                    line[ i ] = ( 122 + 1 ) - distance;
                 } else if ( ( line[ i ] >= 65 && line[ i ] <= 90 ) || ( line[ i ] >= 97 && line[ i ] <= 122 ) ) \
                 {
                    line[ i ] = line[ i ] + n;
                 } 
            }
        }

        for (int j = 0; j < len; j++ )
        {
            array[ row ][ j ] = line[ j ];
        }
        row++;
    }
}
