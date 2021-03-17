/**
  @file operations.h
  @author jrschmie Jacob Schmiedl
  The header file for operations.c
 */

/** The max amount you are allowed to shift a letter */
#define MAX_SHIFT 25

/** The min amount you are allowed to shift a letter */
#define MIN_SHIFT 1

/**
  ReverseLines method
  Reverses all of the lines in the text file  
 */ 
void reverseLines();

/**
  SwapLines method. Swaps places of the two lines 
  @param m row number of the line trying to be swapped.
  @param n row number of the line trying to be swapped.
 */ 
void swapLines( int m, int n );

/**
  Rotates the character 1 to the left. 
 */ 
void rotateLinesLeft();

/**
  Rotates the character 1 to the right. 
 */ 
void rotateLinesRight();

/**
  Shifts the Letter by the number given (ASCII)
  @param n integer that represents how far the letters should be shifted.
 */
void shiftLetters( int n );