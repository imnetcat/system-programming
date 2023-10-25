#pragma once
#include "stdafx.h"
struct BiNode
{
   unsigned long value;
   unsigned long index; 
   unsigned long nreserved;

   struct BiNode* left; 
   struct BiNode* right;
};

class BinarySearchTree
{
public:
	struct BiNode* root_ptr;

	void insertNode(struct BiNode** link, unsigned long val); 
	void insertNode(struct BiNode** link, struct BiNode* ptr);
	struct BiNode* findNode(struct BiNode* link, unsigned long val);
	struct BiNode* deleteSmallestNode(struct BiNode** link); 
	void deleteNode(struct BiNode** link, unsigned long val); 
	void deleteAll(struct BiNode** link);
	void printTree(struct BiNode* link, int level); 
	unsigned long getHeight(struct BiNode* link);
};
