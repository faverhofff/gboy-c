#include "base.h"
#include "cpu.h"
#include "mmu.h"
#include "gb.h"

void GB::PowerUp(const string& _bootableRom, const string& _cartbridge) {
	try {
		mMmu.LoadRoms(_bootableRom, _cartbridge);
		mCpu.SetMmu(&mMmu);

		while (true) {
			mCpu.Step();
		}
	}
	catch (std::runtime_error &e) {
		cout << e.what() << "\n";
	}
}