#pragma once
#ifndef __GB_H
#define __GB_H

class GB {
public:
	void PowerUp(const string& _bootableRom, const string& _cartbridge);
	void Run();
	
private:
	CPU mCPU;
	MMU mMmu;
};

#endif
