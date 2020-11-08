#pragma once
#ifndef __MMU_H
#define __MMU_H

class MMU
{
public:
	MMU();
	bool LoadRoms(const string& _bootableRom, const string& _filename);

	inline void WriteU8(u16 _virtAdd, u8 _value) {
		u8 *memory;
		u16 physAddr;

		VirtAddrToPhysAddr(_virtAdd, memory, physAddr);

		memory[physAddr] = _value;
	}
	inline u8 ReadU8(u16 _virtAdd)  {
		u8* memory;
		u16 physAddr;

		VirtAddrToPhysAddr(_virtAdd, memory, physAddr);

		return memory[physAddr];
	}

	inline void WriteU16(u16 _virtAdd, u16 _value) {
		u8* memory;
		u16 physAddr;

		VirtAddrToPhysAddr(_virtAdd, memory, physAddr);

		memory[physAddr] = _value & 0x00FF;
		memory[physAddr + 1] = (_value >> 8) & 0x00FF;
	}

	inline u16 ReadU16(u16 _virtAdd) {
		u8* memory;
		u16 physAddr;

		VirtAddrToPhysAddr(_virtAdd, memory, physAddr);

		return (memory[physAddr + 1] << 8) | memory[physAddr];
	}

private:
	void VirtAddrToPhysAddr(u16 _virtAddr, u8*& _memory, u16& _physAddr) ;

	u8 mRam[S8Kb];
	u8 mVRam[S8Kb];
	u8 *mRom;
	u8 mBootableRom[256];
	bool mBootableRomEnabled = true;
};

#endif
