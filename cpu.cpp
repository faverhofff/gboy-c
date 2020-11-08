#include "base.h"
#include "mmu.h"
#include "cpu.h"

void CPU::Step() 
{
	u8 opcode = mMmu->ReadU8(mRegPC++);

	switch(opcode) {
		case 0x31:	// LD SP, nn
			mRegSP = mMmu->ReadU16(mRegPC);
			mRegPC += 2;
			break;

		default:
			throw std::runtime_error("unknow upcode." + opcode);
	}
};