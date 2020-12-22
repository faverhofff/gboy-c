#include <fstream>
#include <memory.h>
#include "base.h"
#include "mmu.h"
#include <iostream>

MMU::MMU() 
{
}

bool MMU::LoadRoms(const string& _bootableRom, const string& _filename) {
	std::ifstream bootable(_bootableRom, std::ios::binary);

	bootable.read((char*)mBootableRom, 256);

	bootable.close();

	return true;
}

u8* MMU::VirtAddrToPhysAddr(u16 _virtAddr)  {
	if (mBootableRomEnabled && (_virtAddr >= 0x000) && (_virtAddr <= 0x00FF)) {
		return &mBootableRom[_virtAddr];
	}

	if ((_virtAddr >= 0x000) && (_virtAddr <= 0x3FFF)) {
		return &mRom[_virtAddr];
	}

	if ((_virtAddr >= 0x8000) && (_virtAddr <= 0x9FFF)) {
		return &mVRam[_virtAddr - 0x8000];
	}

	if ((_virtAddr >= 0xC000) && (_virtAddr <= 0xDFFF)) {
		return &mRam[_virtAddr - 0xC000];
	}

	throw std::runtime_error("direccion de memoria invalida." + Int2Hex(_virtAddr) );
}