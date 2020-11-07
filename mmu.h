#pragma once
#ifndef __MMU_H
#define __MMU_H

class MMU
{
public:
	MMU();

	void LoadCartbridge(const string _filename);

private:
	u8 mRAM[S8Kb];
	u8 mVRAM[S8Kb];
	u8 *mROM;
	u8 mBootableROM[256];
};

#endif
