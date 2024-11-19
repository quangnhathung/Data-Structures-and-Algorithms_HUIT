#pragma once
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<string>
#define size 26
using namespace std;
struct Vocabulary {
	string Word;
	string Meaning;
};
struct DictNode {
	Vocabulary key;
	DictNode* Next;
};

DictNode* Bucket[];
int Hashfunc(string s);
DictNode* CreataDictNode(Vocabulary data);
//them phan tu
void AddHead(DictNode* bucket, DictNode* p);
void AddTail(DictNode* bucket, DictNode* p);
DictNode* GetNodePrev(DictNode* bucket, DictNode* p);
void AddBefore(DictNode* bucket[], DictNode* q, DictNode* p);
void Insert(DictNode* bucket[], DictNode* p);
DictNode* GetNodeValue(DictNode* bucket[], string s);
DictNode* SearchMeaning(DictNode* bucket[], string s);
void Input(DictNode* bucket[], string s);
void Show(DictNode* bucket[], string s);