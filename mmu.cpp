#include <memory.h>
#include "base.h"
#include "mmu.h"

MMU::MMU() 
{
	mROM = nullptr;
	memset(mRAM, 0, S8Kb);
	memset(mVRAM, 0, S8Kb);
	memset(mBootableROM, 0, 256);
}

void MMU::LoadCartbridge(const string& _filename) {

}