#pragma once
#include "stdafx.h"
/*
1 bitmap bit = 16-byte block of memory
1 bitmap byte (i.e., block) = 128-byte block of memory 
*/

#define BYTES_PER_BITMAP_BIT 16
#define BYTES PER BITMAP BYTE 128

class BitMap
{

private:
	unsigned char* map; unsigned long nbytes; unsigned long nbits;

public:
	BitMap(unsigned long nblocks);
	~BitMap();

	unsigned long getByteSize();
	void setBits(int val, unsigned long nbits, unsigned long index);
	int getBit(unsigned long index);
	long getBitRun(unsigned long size);
	void printMap();
};
