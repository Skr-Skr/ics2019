#include "FLOAT.h"
#include <stdint.h>
#include <assert.h>

FLOAT F_mul_F(FLOAT a, FLOAT b) {
  // assert(0);
  float result = a * b;
  for(int i = 0; i < 16; i++)
    result /= 2;
  return (int)result;
}

FLOAT F_div_F(FLOAT a, FLOAT b) {
  // assert(0);
  float result = a / b;
  for(int i = 0; i < 16; i++)
    result *= 2;
  return (int)result;
}

FLOAT f2F(float a) {
  /* You should figure out how to convert `a' into FLOAT without
   * introducing x87 floating point instructions. Else you can
   * not run this code in NEMU before implementing x87 floating
   * point instructions, which is contrary to our expectation.
   *
   * Hint: The bit representation of `a' is already on the
   * stack. How do you retrieve it to another variable without
   * performing arithmetic operations on it directly?
   */

  // assert(0);
  int flag = (a >= 0 ? 0 : 1);
  for(int i = 0; i < 16; i++)
    a *= 2;
  if(flag) {
    a = 0x100000000 - a;
  }
  return (FLOAT)a;
}

FLOAT Fabs(FLOAT a) {
  // assert(0);
  if((0x80000000 & a) == 1)
    return 0x100000000 - a;
  else 
    return a;
}

/* Functions below are already implemented */

FLOAT Fsqrt(FLOAT x) {
  FLOAT dt, t = int2F(2);

  do {
    dt = F_div_int((F_div_F(x, t) - t), 2);
    t += dt;
  } while(Fabs(dt) > f2F(1e-4));

  return t;
}

FLOAT Fpow(FLOAT x, FLOAT y) {
  /* we only compute x^0.333 */
  FLOAT t2, dt, t = int2F(2);

  do {
    t2 = F_mul_F(t, t);
    dt = (F_div_F(x, t2) - t) / 3;
    t += dt;
  } while(Fabs(dt) > f2F(1e-4));

  return t;
}
