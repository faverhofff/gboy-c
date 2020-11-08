#include <fstream>
#include <memory.h>
#include "base.h"
#include "mmu.h"
#include <iostream>

MMU::MMU() 
{
	mROM = nullptr;
	memset(mRAM, 0, S8Kb);
	memset(mVRAM, 0, S8Kb);
	memset(mBootableROM, 0, 256);
}

bool MMU::LoadRoms(const string& _bootableRom, const string& _filename) {
	std::ifstream bootable(_bootableRom, std::ios::binary);

	bootable.read((char*)mBootableROM, 256);

	bootable.close();

	return true;
}

void MMU::VirtAddrToPhysAddr(u16 _virtAddr, u8*& _memory, u16& _physAddr) {
	if ((_virtAddr >= 0x000) && (_virtAddr <= 0x3FFF)) {
		_memory = mROM;
		_physAddr = _virtAddr;
		return;
	}

	if ((_virtAddr >= 0x8000) && (_virtAddr <= 0x9FFF)) {
		_memory = mVRAM;
		_physAddr = _virtAddr - 0x8000;
		return;
	}

	if ((_virtAddr >= 0xC000) && (_virtAddr <= 0xDFFF)) {
		_memory = mVRAM;
		_physAddr = _virtAddr - 0xC000;
		return;
	}

	throw std::runtime_error("direccion de memoria invalida." + _virtAddr );
}