#include "bitmap.h"
#include <stdio.h>
#include <stdlib.h>

BitMap::BitMap(unsigned long nblocks)
{
	unsigned long i = 0;
	map = (unsigned char*)calloc(nblocks, 1); 
	if (map == NULL)
	{
		printf("BitMap::BitMap():");
		printf("could not allocate bitmap\n");
		exit(1);
	}
	nbytes = nblocks; nbits = nbytes * 8;
	for (i = 0; i<nbytes; i++) { map[i] = 0xFF; }
	//printf("BitMap::BitMap(): nbytes=%lu", nbytes); 
	//printf(", nbits=%lu\n", nbits);
	return;

}/*end constructor-*/

BitMap::~BitMap()
{
	//printf("BitMap::-BitMap(): freeing map[%ld]\n", nbytes);
	free(map);
	return;
}/*end destructor-*/

unsigned long BitMap::getByteSize()
{
	return(nbytes);
}/*end getByteSize ()-*/

/*set nbits to val(i.e., 0,1) starting at bit specified by index */
void BitMap::setBits
(
	int val,
	unsigned long nbits,
	unsigned long index
)
{
	unsigned long bit;
	unsigned long i, j;
	unsigned char mask;
	bit = 0;

	for (i = 0; i < nbytes; i++)
	{
		mask = 1;
		for (j = 0; j < 8; j++)
		{
			if (bit >= index)
			{
				if (bit == index + nbits) { return; } if (val) { map[i] = map[i] | mask; }
				else { map[i] = map[i] & (~mask); }
			}
			bit++;
			mask = mask * 2;
		}
	}
	return;
}

/*returns that value of the specified bit (0-nbits-l) or -1 if index is out of bounds */

int BitMap::getBit(unsigned long index)
{
	unsigned long bit; unsigned long i, j; unsigned char mask;
	bit = 0;
	for (i = 0; i<nbytes; i++)
	{
		mask = 1;
		for (j = 0; j < 8; j++)
		{
			if (bit == index)
			{
				if (map[i]&mask) { return(1); }
				else { return(0); }
			}
			bit++;
			mask = mask * 2;
		}
	}
	return(-1);
} /*getBit-*/

/*returns the index that marks the start of 'size' bits set to 1 or returns -1 if such a run was not found */
long BitMap::getBitRun(unsigned long size)
{
	unsigned long current_size;
	unsigned long bit;
	unsigned long i, j;
	unsigned char mask;

	current_size = 0; bit = 0;
	for (i = 0; i<nbytes; i++)
	{
		mask = 1;
		for (j = 0; j < 8; j++)
		{
			if (map[i] & mask)
			{
				current_size++;
				if (current_size == size) { return(bit - size + 1); }
			}
			else
			{
				current_size = 0;
			}
			bit++;
			mask = mask * 2;
		}
	}
	return (-1);
} /*getBitRun-*/

void BitMap::printMap()
{
	unsigned long bit; unsigned long i, j; unsigned char mask;
	bit = 0;
	for (i = 0; i<nbytes; i++)
	{
		mask = 1;
		printf("byte[%u]=%x\n", i, map[i]);
		for (j = 0; j < 8; j++)
		{
			if (map[i] & mask) { printf("1"); }
			else { printf("0"); }
			bit++;
			mask = mask * 2;
		}
		printf("\n\n");
	}
	return;
}