#include"Dictionary.h"
using namespace std;

DictNode* Bucket[size] = { NULL,NULL };
int Hashfunc(string s) {
	if (s[0] >= 65 && s[0] <= 90) return s[0] - 'A';
	return s[0] - 'a';
}
DictNode* CreataDictNode(Vocabulary data) {
	DictNode* p = new DictNode;
	p->key = data;
	p->Next = NULL;
	return p;
}
//them phan tu
void AddHead(DictNode* bucket, DictNode* p) {
	if (p == NULL) {
		cerr << "Cap phat that bai!" << endl;
		return;
	}
	int b = Hashfunc(p->key.Word);
	if (bucket == NULL) {
		bucket = p;
		return;
	}
	p->Next = bucket;
	bucket = p;
	return;
}
void AddTail(DictNode* bucket, DictNode* p) {
	if (p == NULL) {
		cerr << "Cap phat that bai!" << endl;
		return;
	}
	int b = Hashfunc(p->key.Word);
	if (bucket == NULL) {
		bucket = p;
		return;
	}
	DictNode* q = bucket;
	while (q->Next != NULL) {
		if (q->Next == NULL) {
			q->Next = p;
			return;
		}
		q = q->Next;
	}
	return;
}
DictNode* GetNodePrev(DictNode* bucket, DictNode* p) {
	DictNode* q = bucket;
	while (q->Next != p) {
		q = q->Next;
	}
	return q;
}
void AddBefore(DictNode* bucket[], DictNode* q, DictNode* p) {
	//them p truoc q
	if (p == NULL) {
		cerr << "Cap phat that bai!" << endl;
		return;
	}
	int b = Hashfunc(p->key.Word);
	if (bucket[b] == NULL) {
		bucket[b] = p;
		return;
	}
	DictNode* r = GetNodePrev(bucket[b], p);
	r->Next = p;
	p->Next = q;
	return;
}
void Insert(DictNode* bucket[], DictNode* p) {
	if (p == NULL) return;
	int b = Hashfunc(p->key.Word);
	if (bucket[b] == NULL) {
		bucket[b] = p;
		return;
	}
	DictNode* q = bucket[b];
	while (q!=NULL && (q->key.Word <= p->key.Word)) {
		q = q->Next;
	}
	if (q == NULL) {
		AddTail(bucket[b], p);
		return;
	}
	p->Next = q->Next;
	q->Next = p;
	return;
}
DictNode* GetNodeValue(DictNode* bucket[], string s) {
	int b = Hashfunc(s);
	if (bucket[b] == NULL)
		return NULL;
	DictNode* p = bucket[b];
	while (p != NULL) {
		if (p->key.Word == s) {
			return p;
		}
		p = p->Next;
	}
	return NULL;
}
DictNode* SearchMeaning(DictNode* bucket[], string s) {
	return GetNodeValue(bucket,s);
}
void Show(DictNode* bucket[],string s) {
	int b = Hashfunc(s);
	cout << s << ": endl";
	DictNode* p = bucket[b];
	while (p != NULL) {
		cout << "\t" << p->key.Word << " : " << p->key.Meaning << "\t" << endl;
		p = p->Next;
	}
}
