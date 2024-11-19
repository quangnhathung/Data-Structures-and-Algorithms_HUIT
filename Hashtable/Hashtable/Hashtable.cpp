#include"HashTble(interger).h"
using namespace std;
HashNodeint* bucket[size] = { NULL,NULL };
HashNodeint* CreateHashNodeint(int x) {
	HashNodeint* p = new HashNodeint;
	p->key = x;
	p->Next = NULL;
	return p;
}

int HashFunc(int key) {
	return key % size;
}
//them cuoi
HashNodeint* GetNodepre(HashNodeint* buckets, HashNodeint* q) {
	HashNodeint* p = buckets;
	while (p->Next != q) {
		p = p->Next;
	}
	return p;
}
void AddTail(HashNodeint* buckets, HashNodeint* p) {
	if (p == NULL) {
		cerr << "Loi khong cap phat duoc bo nho" << endl;
		return;
	}
	HashNodeint* q = buckets;
	while (q->Next != NULL) {
		q = q->Next;
	}
	q->Next = p;
	return;
}
void Insert(HashNodeint* bucket[], int key) {
	int b = HashFunc(key);
	if (bucket[b] == NULL) {
		bucket[b] = CreateHashNodeint(key);
	}
	else {
		AddTail(bucket[b], CreateHashNodeint(key));
	}
	return;
}
void Show(HashNodeint* bucket[]) {
	for (int i = 0; i < size; i++) {
		if (bucket[i] != NULL) {
			cout << "Index:" << i << " Key: ";
			while (bucket[i] != NULL) {
				cout << bucket[i]->key<<" ";
				bucket[i] = bucket[i]->Next;
			}
		}
	}
}
//kiem tra xem 1 bucket co rong khong
bool IsEmptyBucket(HashNodeint* bucket) {
	if (bucket == NULL) return true;
	return false;
}
//xoa 1 phan tu ra khoi bang bam
//xoa dau 
void DltHead(HashNodeint* bucket) {
	HashNodeint* p = bucket;
	if (bucket->Next == NULL) {
		bucket = NULL;
		delete p;
		return;
	}
	bucket = bucket->Next;
	delete p;
	return;
}
//xoa cuoi
void DltTail(HashNodeint* bucket) {
	HashNodeint* p = bucket;
	while (p->Next != NULL) {
		p = p->Next;
	}
	delete p;
	return;
}
//xoa theo gia tri
//lay node theo gia tri
HashNodeint* GetNodeValue(HashNodeint* bucket, int key) {
	HashNodeint* p = bucket;
	while (p!=NULL && p->key != key) {
		p = p->Next;
	}
	return p;
}
void Dltkey(HashNodeint* bucket, int key) {
	HashNodeint* p,* q;
	p = GetNodeValue(bucket, key);
	if (p == bucket) {
		DltHead(bucket);
		return;
	}
	q = GetNodepre(bucket, p);
	q->Next = p->Next;
	delete p;
	return;
}
HashNodeint* Searchkey(HashNodeint* bucket[], int key) {
	return GetNodeValue(bucket[HashFunc(key)], key);
}