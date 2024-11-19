#pragma once
#include<iostream>
using namespace std;
#define size 100
struct HashNodeint {
	int key;
	HashNodeint* Next;
 };
HashNodeint* bucket[];
HashNodeint* CreateHashNodeint(int x);
int HashFunc(int key);
//them cuoi
HashNodeint* GetNodepre(HashNodeint* buckets, HashNodeint* q);
void AddTail(HashNodeint* buckets, HashNodeint* p);
void Insert(HashNodeint* bucket[], int key);
void Show(HashNodeint* bucket[]);
//kiem tra xem 1 bucket co rong khong
bool IsEmptyBucket(HashNodeint* bucket);
//xoa 1 phan tu ra khoi bang bam
//xoa dau 
void DltHead(HashNodeint* bucket);
//xoa cuoi
void DltTail(HashNodeint* bucket);
//xoa theo gia tri
//lay node theo gia tri
HashNodeint* GetNodeValue(HashNodeint* bucket, int key);
void Dltkey(HashNodeint* bucket, int key);
HashNodeint* Searchkey(HashNodeint* bucket[], int key);