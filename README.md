# system-programming 
## lab1-2

**output:**
```
-------------------------------------------------------------------
Standart malloc\free
performance test: <1 ms
-------------------------------------------------------------------
Custom malloc\free
BitMap::BitMap(): nbytes=3, nbits=24
MemoryManager::MemoryManager():mallloc() mem[384]
MemoryManager::allocate(): request 8 bytes
MemoryManager::allocate(): run_bits=l
MemoryManager::allocate(): found run of 1 bits at 0

insertNode(): inserting 5373964
MemoryManager::allocate(): address=5373964
-------------------------------------------------------------------
byte[0]=fe
01111111
byte[1]=ff
11111111
byte[2]=ff
11111111
-------------------------------------------------------------------
(5373964)
-------------------------------------------------------------------
MemoryManager::allocate(): request 12 bytes
MemoryManager::allocate(): run_bits=l
MemoryManager::allocate(): found run of 1 bits at 1
insertNode(): moving right
insertNode(): inserting 5373980
MemoryManager::allocate(): address=5373980
-------------------------------------------------------------------
byte[0]=fc
00111111
byte[1]=ff
11111111
byte[2]=ff
11111111
-------------------------------------------------------------------
-(5373980)
(5373964)
-------------------------------------------------------------------
MemoryManager::allocate(): request 33 bytes
MemoryManager::allocate(): run_bits=3
MemoryManager::allocate(): found run of 3 bits at 2
insertNode(): moving right
insertNode(): moving right
insertNode(): inserting 5373996
MemoryManager::allocate(): address=5373996
-------------------------------------------------------------------
byte[0]=e0
00000111
byte[1]=ff
11111111
byte[2]=ff
11111111
-------------------------------------------------------------------
—(5373996)
-(5373980)
(5373964)
-------------------------------------------------------------------
MemoryManager::allocate(): request 1 bytes
MemoryManager::allocate(): run_bits=l
MemoryManager::allocate(): found run of 1 bits at 5
insertNode(): moving right
insertNode(): moving right
insertNode(): moving right
insertNode(): inserting 5374044
MemoryManager::allocate(): address=5374044
-------------------------------------------------------------------
byte[0]=c0
00000011
byte[1]=ff
11111111
byte[2]=ff
11111111
-------------------------------------------------------------------
----(5374060)
---(5374044)
--(5373996)
-(5373980)
(5373964
-------------------------------------------------------------------
MemoryManager::allocate(): request 122 bytes
MemoryManager::allocate(): run_bits=8
MemoryManager::allocate(): found run of 8 bits at 6
insertNode(): moving right
insertNode(): moving right
insertNode(): moving right
insertNode(): moving right
insertNode(): inserting 5374060
MemoryManager::allocate(): address=5374060
-------------------------------------------------------------------
byte[0]=0 00000000
byte[1]=c0 00000011
byte[2]=ff 11111111
-------------------------------------------------------------------
----(5374060)
---(5374044)
--(5373996)
-(5373980)
(5373964
-------------------------------------------------------------------
MemoryManager::allocate(): request 50 bytes
MemoryManager::allocate(): run_bits=4
MemoryManager::allocate(): found run of 4 bits at 14
insertNode(): moving right
insertNode(): moving right
insertNode(): moving right
insertNode(): moving right
insertNode(): moving right
insertNode(): inserting 5374188
MemoryManager::allocate(): address=5374188
-------------------------------------------------------------------
byte[0]=0 00000000
byte[1]=0 00000000
byte[2]=fc 00111111
-------------------------------------------------------------------
-----(5374188)
----(5374060)
---(5374044)
--(5373996)
-(5373980)
(5373964)
-------------------------------------------------------------------
MemoryManager::release(): address=537396
deleteNode(): freeing 5373964
-------------------------------------------------------------------
byte[0]=1 10000000
byte[1]=0 00000000
byte[2]=fc 00111111
-------------------------------------------------------------------
----(5374188)
---(5374060)
--(5374044)
-(5373996)
(5373980)
-------------------------------------------------------------------
MemoryManager::release(): address=5373980
deleteNode(): freeing 5373980
-------------------------------------------------------------------
byte[0]=3 11000000
byte[1]=0 00000000
byte[2]=fc 00111111
-------------------------------------------------------------------
---(5374188)
--(5374060)
-(5374044)
(5373996)
-------------------------------------------------------------------
MemoryManager::release(): address=5373996
deleteNode(): freeing 5373996
-------------------------------------------------------------------
byte[0]=lf 11111000
byte[1]=0 00000000
byte[2]=fc 00111111
-------------------------------------------------------------------
—(5374188)
-(5374060)
(5374044)
-------------------------------------------------------------------
MemoryManager::release(): address=5374044
deleteNode(): freeing 5374044
-------------------------------------------------------------------
byte[0]=3f 11111100
byte[1]=0 00000000
byte[2]=fc 00111111
-------------------------------------------------------------------
- (5374188)
(5374060)
-------------------------------------------------------------------
MemoryManager::release() : address=5374060
deleteNode(): freeing 5374060
-------------------------------------------------------------------
byte[0]=ff 11111111
byte[1]=3f 11111100
byte[2]=fc 00111111
-------------------------------------------------------------------
(5374188)
-------------------------------------------------------------------
MemoryManager::release(): address=5374188
deleteNode(): freeing 5374188
-------------------------------------------------------------------
byte[0]=ff 11111111
byte[1]=ff 11111111
byte[2]=ff 11111111
-------------------------------------------------------------------
-------------------------------------------------------------------
BitMap::~BitMap(): freeing map[3]
MemoryManager::~MemoryManager():free() mem[384]
performance test: 35 ms
```
