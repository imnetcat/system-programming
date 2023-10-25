#include"bitmap.h"
#include"memmgr.h"
#include "performance.h"

void PerformanceTestDriver(alloc_proto alloc, free_proto free, realloc_proto realloc = nullptr)
{
	double p[8] = { .15, .20, .35, .20, .02, .04, .02, .02 };
	unsigned long x[8] = { 16,32,64,128,256,512,1024,4096 };
	test_data td; 
	td.dptr = p; 
	td.lptr = x; 
	td.samplesize = 1024; 
	td.length = 8;
	performance pt = performance(&td);
	pt.test(alloc, free, realloc);
	return;
}

/*
void debugTest()
{
	void* ptr[10]; int i;
	initMemMgr(270);
	ptr[0] = newMalloc(8); 
	ptr[1] = newMalloc(12); 
	ptr[2] = newMalloc(33); 
	ptr[3] = newMalloc(1);
	ptr[4] = newMalloc(122);
	ptr[5] = newMalloc(50);

	for (i = 0; i < 6; i++) { newFree(ptr[i]); }
	closeMemMgr(); 
	return;
}
*/

MemoryManager manager(1024 * 1024);

static void* test_alloc_wrapper(unsigned int size)
{
	void* ptr = manager.alloc(size);
#ifdef DEBUG_MALL0CV1
	(*mmptr).printState();
#endif
	return ptr;
}

static void test_free_wrapper(void* ptr)
{
	manager.free(ptr);

#ifdef DEBUG_MALL0CV1
	(*mmptr).printState();
#endif
}

void main()
{
	printf("-------------------------------------------------------------------\n");
	printf("Standart malloc\\free\n");
	PerformanceTestDriver(malloc, free);

	printf("-------------------------------------------------------------------\n");
	printf("Custom malloc\\free\n");
	manager.printState();
	PerformanceTestDriver(test_alloc_wrapper, test_free_wrapper);
	manager.printState();
	return;
}