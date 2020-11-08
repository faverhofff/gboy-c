#include "base.h"
#include "cpu.h"
#include "mmu.h"
#include "gb.h"

void GB::PowerUp(const string& _bootableRom, const string& _cartbridge) {
	mMmu.LoadRoms(_bootableRom, _cartbridge);

	while (true) {
		mCPU.Step();
	}
}