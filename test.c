/*
 * Name: Bram Nutt
 * Numerous test cases for detecting if hasUniqueChars works. Tests all printable characters, 
 * multiple spaces, edge cases, duplicates, and ineligeble characters.
 */

#include <stdio.h>    // printf
#include <stdbool.h>  // to define a boolean type and true, false
#include <string.h>   // strcpy  to copy a string
#include <assert.h>

// declaration of function from hasUniqueChars.c
bool hasUniqueChars(char * inputStr);


int main() {
  char string3[128];   // can copy in up to 127 characters
                       // chose 128 because it is a multiple of 8 bytes

  // -------------------------------------------------------------
  // Thorough and exhaustive tests of hasUniqueChars()  
  bool ok;    // holds the result of hasUniqueChars(); used in asserts
  
  // Test 1: duplicated string with spaces
  strcpy(string3, "This should fail (l and s and i and h)");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  printf("Test 1 passed: duplicates, should fail\n");
  
  // Test 2: This should be true and not fail
  strcpy(string3, "abcdefghij");
  ok = hasUniqueChars(string3);
  assert(ok);
  printf("Test 2 passed: no duplicates, should pass\n");

  // Test 3: This should pass and test all possible characters
  strcpy(string3, "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
  ok = hasUniqueChars(string3);
  assert(ok);
  printf("Test 3 passed: All printable characters, no duplicates, should pass\n");

  // Test 4: Tests Capital letter duplicate and should return false
  strcpy(string3, "ABCDEFGHIJKLMNOPQRSTUVWXYZA");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  printf("Test 4 passed: Caught duplicate, should fail\n");

  // Test 5: empty string and should pass
  strcpy(string3, "");
  ok = hasUniqueChars(string3);
  assert((ok));
  printf("Test 5 passed: Empty string, should pass\n");

  // Test 6: Edge case test and should pass
  strcpy(string3, "!@A~");
  ok = hasUniqueChars(string3);
  assert((ok));
  printf("Test 6 passed: Edge cases, should pass\n");

  // Test 7: Edge case duplicate test and should fail
  strcpy(string3, "!!");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  printf("Test 7 passed: Edge case duplicate found, should fail\n");

  // Test 8: Edge case duplicate test and should fail
  strcpy(string3, "@@");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  printf("Test 8 passed: Edge case duplicate found, should fail\n");

  // Test 9: Edge case duplicate test and should fail
  strcpy(string3, "AA");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  printf("Test 9 passed: Edge case duplicate found, should fail\n");

  // Test 10: Edge case duplicate test and should fail
  strcpy(string3, "~~");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  printf("Test 10 passed: Edge case duplicate found, should fail\n");

  // Test 11: Multiple spaces and should pass
  strcpy(string3, "         ");
  ok = hasUniqueChars(string3);
  assert((ok));
  printf("Test 11 passed: Many spaces but doesn't count it as a duplicate, should pass\n");

  // Test 12: Sentence with spaces and should pass
  strcpy(string3, "the quick fox");
  ok = hasUniqueChars(string3);
  assert((ok));
  printf("Test 12 passed: Sentence with spaces but doesn't count it as a duplicate, should pass\n");

  // Test 13: Sentence with newline character and should fail.
  strcpy(string3, "a b cc\n");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  printf("Test 13 passed: String with newline character, should fail\n");
  return 0;
}