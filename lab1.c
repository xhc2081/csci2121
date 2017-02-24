/*
 * CSCI 2121 Lab 1: Bit Slinging
 *
 * lab1.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#include "testFramework.h"
#include <limits.h>

#if 0

You will provide your solution to the Lab by
editing the collection of functions in this source file.

CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  And yes, the comment for each funtion is a good idea,
  as we will check it to give marks to not working functions.

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting. This means you are not allowed to use
     unsigned since you will need to do implicit casting at some point.

  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTE:
  Use the test harness to check your functions for correctness.
#endif

/*
 * Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Make sure to use the labCheck program (Done automatical when using make)
 *      to check for following the rules.
 *   2. Use the testFramework to check that your solutions produce
 *      the correct answers. Watch out for corner cases around min and max.
 *   3. Write comments at the begining of each function.  If someting goes wrong,
 *      but you explain what the function should be doing, it will be considered
 *      when grading.
 *   4. All files other then lab1.c will be as they were when they were given to you.
 *      Any changes will not work when grading.
 *   5. Don't cheat by finding a bug in our testing.  You will probably get caught, and
 *      it won't be fun.
 *   6. If you find any bugs, please let us know.
 */
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 */
int bitAnd(int x, int y) {
  return ~(~x|~y);
}


/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 */
int minusOne(void) {
  return ~0;
}


/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 */
int tmax(void) {
  return ~(1<<31);
}


/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 */
int copyLSB(int x) {
  return x<<31>>31;
}


/*
 * evenBits - return the input word where all even-numbered bits of that are set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 */
int evenBits(int x) {
  int a = 0x55;
  int b = (a<<24) | (a<<16) | (a<<8) | a;
  return (x&b);
}


/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 */
int isEqual(int x, int y) {
  return !(x^y);
}


/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 */
int negate(int x) {
  return ~x+1;
}


/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 */
int bitMask(int highbit, int lowbit) {
  int a = ~0<<highbit;
  int b = 1<<highbit;
  int c = ~(a^b);
  return c>>lowbit<<lowbit;
}


/*
 * conditional - same as x ? y : z
 *   Equivalent notation: if (x != 0) { return y;} else {return z;}
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 */
int conditional(int x, int y, int z) {
  int conditional = (((~(!x)+1) & ~0) &z) | (((~(!(!x))+1) & ~0) &y);
  return conditional;
}


/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 */
int isPositive(int x) {
  return !((x &(1<<31)) | !x);
}


/*
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 */
int reverseBytes(int x) {
  int a = 0xFF;
  int first = x<<24;
  int second = (x<<8)&(a<<16);
  int third = (x>>8)&(a<<8);
  int forth = (x>>24)&a;
  return first | second | third | forth;
}


/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 */
int isPower2(int x) {
  int x1, x2, x3;
  x1 = ~0;
  x2 = x >> 31;
  x3 = (x1^x2);
  return !((x & (x + x3)) + !x);
}
