#include <iostream>
#include <stdio.h>
#include "base.h"
#include "cpu.h"
#include "mmu.h"
#include "gb.h"

void main(int argn, char *argc[])
{
    GB gb;

    gb.PowerUp(argc[1], argc[2]);

    //return 0;
}