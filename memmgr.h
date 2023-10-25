#pragma once
#include "stdafx.h"
#include "bitmap.h"
#include "bst.h"

class MemoryManager
{
private:
	BinarySearchTree bst;
	BitMap* bmap;
	HANDLE handle;
	unsigned char* mem;
	unsigned long memLength;

public:
	MemoryManager(unsigned long totalbytes);
	~MemoryManager();
	void* alloc(unsigned long nbytes);
	void free(void* ptr);
	void printState();
};