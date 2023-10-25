#pragma once
#include "stdafx.h"

using alloc_proto = void* (*)(size_t);
using free_proto = void(*)(void*);
using realloc_proto = void* (*)(void*, size_t);

struct test_data
{
	double* dptr; 
	unsigned long* lptr; 
	unsigned long samplesize;
	unsigned long length;
};

class performance
{
public:
	performance(struct test_data* tdptr); 
	void test(alloc_proto alloc, free_proto free, realloc_proto realloc = nullptr);

private:
	unsigned long nAllocations; 
	unsigned long arraySize;
	double* p; 
	unsigned long* x;

	double getU(); 
	unsigned long getRandomVariate();
	void getAllocArray(unsigned long* lptr);
};

performance::performance(struct test_data* tdptr)
{
	p = (*tdptr).dptr; 
	x = (*tdptr).lptr;
	nAllocations = (*tdptr).samplesize; 
	arraySize = (*tdptr).length; 
	return;
}

double performance::getU()
{
	return(((double)rand()) / ((double)RAND_MAX));
}

unsigned long performance::getRandomVariate()
{
	double U;
	unsigned long i; 
	double total;

	U = getU();

	for (i = 0, total = p[0]; i <= arraySize - 2; i++)
	{
		if (U < total) { return(x[i]); } total = total + p[i + 1];
	}
	return(x[arraySize - 1]);

	/*
	the above is a cleaner/slower way of doing something like:

	if(U < p[0]){return(x[0]); }
	else if(U <(p[0]+p[1])){return(x[1]);}
	else if (U < (p [0] +p [1 ] +p [2] ) ) {return (x [2 ] ) ; }
	else if (U < (p [0] +p [1 ] +p [2] +p [3] ) ) {return (x [3] ) ; }
	else if (U < (p [0] +p [1 ] +p [2] +p [3] +p [4 ] ) ) {return (x [4] ) ; }
	else if (U < (p [0] +p [1 ] +p [2] +p [3] +p [4 ] +p [5] ) ) {return (x [5] ) ; }
	else if (U < (p [0] +p [1 ] +p [2] +p [3] +p [4 ] +p [5] +p [ 6] ) )
	{return(x[6]);> else{ return (x[7]); }
	*/
}

void performance::getAllocArray(unsigned long* lptr)
{
	unsigned long i;
	for (i = 0; i < nAllocations; i++)
	{
		lptr[i] = getRandomVariate();
	}
	return;
}

void performance::test(alloc_proto alloc, free_proto free, realloc_proto realloc)
{
	unsigned long* allocs;
	unsigned long i;
	unsigned long ticksl, ticks2;

	char** addr; /*pointer to an array of pointers*/
				 /*create array of address holders to stockpile malioc() returns*/
	addr = (char**)malloc(sizeof(char*) * nAllocations); if (addr == NULL)
	{
		printf("could not allocate address repository\n"); exit(1);
	}

	/*create stream of allocation values*/
	allocs = (unsigned long*)malloc(sizeof(long) * nAllocations); if (allocs == NULL)
	{
		printf("could not allocate mallocO request stream\n"); exit(1);
	}

	getAllocArray(allocs);

	ticksl = GetTickCount();

	for (i = 0; i < nAllocations; i++)
	{
		addr[i] = (char*)alloc(allocs[i]);
		if (addr[i] == NULL)
		{
			printf("malloc()=addr[%lu]=%lu failed\n", i, addr[i]); 
			exit(1);
		}
	}

	for (i = 0; i < nAllocations; i++)
	{
		free(addr[i]);
	}

	ticks2 = GetTickCount();

	free(addr); free(allocs);

	unsigned long res = ticks2 - ticksl;
	if (res > 0) 
	{
		printf("performance test: %lu ms\n", res);
	}
	else
	{
		printf("performance test: <1 ms\n");
	}
}