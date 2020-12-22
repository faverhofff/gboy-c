#pragma once
#ifndef __MMU_H
#define __MMU_H

class MMU
{
public:
	MMU();
	bool LoadRoms(const string& _bootableRom, const string& _filename);

	inline void WriteU8(u16 _virtAdd, u8 _value) {
		(*VirtAddrToPhysAddr(_virtAdd)) = _value;
	}
	inline u8 ReadU8(u16 _virtAdd)  {
		return *VirtAddrToPhysAddr(_virtAdd);
	}

	inline void WriteU16(u16 _virtAdd, u16 _value) {
		*(u16*)VirtAddrToPhysAddr(_virtAdd) = _value;
	}

	inline u16 ReadU16(u16 _virtAdd) {
		return *(u16*)VirtAddrToPhysAddr(_virtAdd);
	}

private:
	u8* VirtAddrToPhysAddr(u16 _virtAddr);

	u8 mRam[S8Kb];
	u8 mVRam[S8Kb];
	u8 *mRom{ nullptr };
	u8 mBootableRom[256];
	bool mBootableRomEnabled = true;
};

#endif
