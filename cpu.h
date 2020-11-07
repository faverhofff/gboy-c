#pragma once
#ifndef __CPU_H
#define __CPU_H

class CPU {
public:
	CPU();

private:
	MMU* mMmu;
	u8 mRegA;
	u8 mRegB;
	u8 mRegC;
	u8 mRegD;
	u8 mRegE;
	u8 mRegH;
	u8 mRegL;
	u16 mRegSP;
	u16 mRegPC;

	bool mFlagZ;
	bool mFlagN;
	bool mFlagH;
	bool mFlagC;
};

#endif