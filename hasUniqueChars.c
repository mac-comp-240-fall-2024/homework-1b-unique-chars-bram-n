/*
 * hasUniqueChars.c
 *
 * Given a string of characters, which are encoded in ascii,
 * determine if the string contains all unique characters.
 *
 * Author: Bram Nutt
 */

#include <stdio.h>   // fprintf, printf
#include <stdlib.h>  // exit() defined here
#include <string.h>  // useful string operations
#include <ctype.h>   //useful character operations
#include <stdbool.h> // to define a boolean type and true, false
                     // see https://en.wikibooks.org/wiki/C_Programming/stdbool.h

#include "binary_convert.h"

/*
 * This function is for debugging by printing out the value
 * of an input insigned long as a binary string.
 */
void seeBits(unsigned long value, char *debug_text)
{

  // string to represent binary value of variable value
  char *bin_str;

  bin_str = ulong_to_bin_str(value);
  printf("%s%s\n", debug_text, bin_str);
  free(bin_str);
}

/*
 * Given an input string of chars, check for any non-printing
 * characters and print an error and exit if the string has any.
 */
void checkInvalid(char *inputStr)
{
  char nextChar;
  int i;

  for (i = 0; i < strlen(inputStr); i++)
  {
    nextChar = inputStr[i];

    // if nextChar is invalid (31 or less or 127 as an ascii char code), then bail out
    if ((nextChar <= 31) || (nextChar == 127))
    {
      fprintf(stderr, "invalid character in string\n");
      exit(EXIT_FAILURE);
    }
  }
}

/*
 * This function takes a string as input, checks if it is invalid
 * and determines whether the characters in the string are unique, ignoring spaces.
 * It uses two unsigned long variables as bit vectors to efficiently keep track
 * of seen characters.
 */
bool hasUniqueChars(char *inputStr)
{
  // bail out quickly if any invalid characters
  checkInvalid(inputStr);

  int i; // loop counter

  // unsigned long can handle 64 different chars in a string
  // if a bit at a position is 1, then we have seen that character
  unsigned long checkBitsA_z = 0;      // for checking A through z and {|}~
  unsigned long checkBitsexcl_amp = 0; // for checking ! though @

  char nextChar; // next character in string to check
  unsigned long currentChar = 1;

  for (i = 0; i < strlen(inputStr); i++)
  {
    nextChar = inputStr[i];

    if (nextChar == ' ')
    {
      continue;
    }

    if (nextChar > 64)
    {
      currentChar = currentChar << (nextChar - 65);
      if ((checkBitsA_z & currentChar) != 0)
      {
        return false;
      }
      else
      {
        checkBitsA_z = checkBitsA_z | currentChar;
        currentChar = 1;
      }
    }
    else
    {
      currentChar = currentChar << (nextChar - 33);
      if ((checkBitsexcl_amp & currentChar) != 0)
      {
        return false;
      }
      else
      {
        checkBitsexcl_amp = checkBitsexcl_amp | currentChar;
        currentChar = 1;
      }
    }
  }
  // if through all the characters, then no duplicates found
  return true;
}
