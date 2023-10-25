#include "memmgr.h"

#define BYTES_PER_BITMAP_BYTE 1

MemoryManager::MemoryManager(unsigned long totalbytes)
{
	//init 3 dynamic objects: bmap, bst, mem[]
	bmap = new BitMap((totalbytes / BYTES_PER_BITMAP_BYTE) + 1);
	bst.root_ptr = NULL;
	memLength = (*bmap).getByteSize() * BYTES_PER_BITMAP_BYTE;
	handle = GetProcessHeap(); if (handle == NULL)
	{
		printf("MemoryManager::MemoryManager() : invalid handle\n");
		return;
	}
	mem = (unsigned char*)HeapAlloc(handle, HEAP_ZERO_MEMORY, memLength);

	//for portability, you could use:
	//mem = (unsigned char*)malloc(memLength);
	if (mem == NULL)
	{
		printf("MemoryManager::MemoryManager() :"); printf("could not alloc memory\n"); exit(1);
	}
	
	//printf("MemoryManager::MemoryManager () :"); printf("mallloc() mem[%lu]\n", memLength);

	return;
}/*end constructor-*/

MemoryManager::~MemoryManager()
{
	//release resources for objects: bmap, bst, mem[] delete(bmap);
	bst.deleteAll(&(bst.root_ptr));
	if (HeapFree(handle, HEAP_NO_SERIALIZE, mem) == 0)
	{
		printf("MemoryManager::-MemoryManager(): HeapFree() failed\n");
		return;
	}
	
	//for portability, you could use:
	//free(mem);
	//printf("MemoryManager::-MemoryManager ():"); printf("free() mem[%lu]\n", memLength);
	delete bmap;
	return;

}/*end destructor-*/

void* MemoryManager::alloc(unsigned long nbytes)
{
	unsigned long run_bits = 0;
	long index = 0;
	BiNode node;
	
	//printf("MemoryManager::allocate(): request %lu bytes\n", nbytes);

	//translate nbytes into # of bits in BitMap
	run_bits = (nbytes / BYTES_PER_BITMAP_BIT) + 1;
	//printf("MemoryManager : :allocate() : runJoits=%lu\n", run_bits);
	index = ((*bmap).getBitRun(run_bits));
	if (index == -1) return nullptr;

	//printf("MemoryManager::allocate(): found run of %lu bits ", run_bits);
	//printf("at %lu\n", index);
	//reserved bits in BitMap
	(*bmap).setBits(0, run_bits, index);
	node.value = (unsigned long)(&mem[index * 16]);
	node.index = index;
	node.nreserved = run_bits;
	bst.insertNode(&(bst.root_ptr), &node);
	//return memory represented by BitMap bits
	//printf("MemoryManager::allocate(): address=%lu\n", &mem[index * 16]);

	return((void*)&mem[index * 16]);

}/*end allocate-*/

void MemoryManager::free(void* addr)
{
	struct BiNode* ptr;
	ptr = bst.findNode(bst.root_ptr, (unsigned long)addr); if (ptr != NULL)
	{
		//printf("MemoryManager::release(): addr=%lu\n", (unsigned long)addr);
		(*bmap).setBits(1, (*ptr).nreserved, (*ptr).index); bst.deleteNode(&(bst.root_ptr), (unsigned long)addr);
	}
	return;
}/*end release-*/

void MemoryManager::printState()
{
	//printf("-------------------------------------------------------------------\n");
	//(*bmap).printMap();
	//printf("-------------------------------------------------------------------\n");
	bst.printTree(bst.root_ptr, 0);
	//printf("-------------------------------------------------------------------\n");
	return;
}
