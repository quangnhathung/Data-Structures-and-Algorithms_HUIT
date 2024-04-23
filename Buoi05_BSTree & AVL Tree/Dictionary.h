#pragma once
#include<iostream>
#include"CalculateTree.h"
#include<sstream>
#include<stack>
#include<fstream>
#include<string>

using namespace std;
struct Dictionary {
	string Vocabulary;
	string Meaning;
};
struct AVLDictNode {
	int Height;
	Dictionary Data;
	AVLDictNode* Left;
	AVLDictNode* Right;
};
struct AVLTreeDictionary {
	AVLDictNode* Root;
};

//khoi tao
AVLDictNode* CreateDictnode(Dictionary x);
void Init_Dictionary(AVLTreeDictionary& tr);
int Height(AVLDictNode* root);
//them phan tu
//xoay cay
//xoay trai khi lech phai
void RotateLeft(AVLDictNode*& root);
//xoay phai khi lech trai
void RotateRight(AVLDictNode*& root);
//them
void Add_Dictionary(AVLDictNode*& root, AVLDictNode* p);
//input
void InputDictionary(AVLDictNode*& root);
//Nhap de in cay
void InputDictionaryDemo(AVLDictNode*& root);
//LNR
void TraverseDct(AVLDictNode* root);
int cntvcl(AVLDictNode* root);
bool CheckBalance(AVLDictNode* root);
//them phan tu vao cay
void UpdateData(AVLDictNode * &root, string s);
void Dlt_Vocabulary(AVLDictNode*& root, string s);
void Dlt_Dct(AVLDictNode*& root);
//so sanh 2 xau
string upperstr(string s);
int CompareStr(string s1, string s2);
AVLDictNode* Translate(AVLDictNode* root, string s);