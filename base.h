#pragma once
#ifndef __BASE_H
#define __BASE_H

#include <string>
#include <iostream>
using namespace std;

typedef unsigned char u8;
typedef char i8;
typedef unsigned short u16;
typedef short i16;

#define S8Kb (1024 * 8)

inline void Panic(const string& _message) {
	cout << _message;
	exit(1);
}

#endif