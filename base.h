#pragma once
#ifndef __BASE_H
#define __BASE_H

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

typedef unsigned char u8;
typedef char i8;
typedef unsigned short u16;
typedef short i16;

string Int2Hex(int _value);

#define S8Kb (1024 * 8)

#endif