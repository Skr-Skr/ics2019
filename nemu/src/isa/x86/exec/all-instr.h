#include "cpu/exec.h"

make_EHelper(mov);

make_EHelper(operand_size);

make_EHelper(inv);
make_EHelper(nemu_trap);


// control.c
make_EHelper(call);
make_EHelper(ret);
make_EHelper(jcc);

// data-mov.c
make_EHelper(push);
make_EHelper(lea);
make_EHelper(movzx);
make_EHelper(movsx);
make_EHelper(leave);
make_EHelper(pop);
make_EHelper(pusha);
make_EHelper(popa);
make_EHelper(mov_cr2r);
make_EHelper(mov_r2cr);
make_EHelper(cltd);


// arith.c
make_EHelper(sub);
make_EHelper(adc);
make_EHelper(sbb);
make_EHelper(add);
make_EHelper(cmp);
make_EHelper(inc);
make_EHelper(dec);
make_EHelper(imul);
make_EHelper(imul1);
make_EHelper(imul2);

// system.c
make_EHelper(in);

// logic.c
make_EHelper(xor);
make_EHelper(and);
make_EHelper(or);
make_EHelper(test);
make_EHelper(setcc);
make_EHelper(sar);
make_EHelper(shl);
make_EHelper(shr);
make_EHelper(not);

// special.c
make_EHelper(nop);