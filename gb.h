#pragma once
#ifndef __GB_H
#define __GB_H

class GB {
public:
	GB();
	~GB();

private:
	CPU mCPU;
	MMU mMmu;
};

#endif
