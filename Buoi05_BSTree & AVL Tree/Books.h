#pragma once
#include<iostream>
#include<string>
#include"CalculateTree.h"
#include<fstream>
#include<sstream>
using namespace std;

struct Book {
	string Masach;
	string Tensach;
	int Xuatban;
};
struct AVLBOOK {
	int Height;
	Book Data;
	AVLBOOK* Left;
	AVLBOOK* Right;
};
struct BookAvlTree {
	AVLBOOK* root;
};

//khoi tao
void InitBooks_AVL(BookAvlTree& tr);
AVLBOOK* CreateNodeBook(Book x);
int Height(AVLBOOK* root);
//xoay cay
//xoay trai khi lech phai
void RotateLeftBook(AVLBOOK*& root);
//xoay phai khi lech trai
void RotateRightBook(AVLBOOK*& root);
//them
void Add_AVLbookTree(AVLBOOK*& root, AVLBOOK* p);
//xoa theo ma sach 
AVLBOOK* FindNodeAvlBookReplace(AVLBOOK* root);
void Dlt_AVLbook(AVLBOOK*& root, string s);
//xoa toan bo cay
void Dlt_Books(AVLBOOK*& root);
//input
void InputTree(AVLBOOK*& root);
//6 phep duyet cay
void TraverseLNRBooks(AVLBOOK* root);
void TraverseRNLBooks(AVLBOOK* root);
void TraverseLRNBooks(AVLBOOK* root);
void TraverseRLNBooks(AVLBOOK* root);
void TraverseNLRBooks(AVLBOOK* root);
void TraverseNRLBooks(AVLBOOK* root);
int cnt(AVLBOOK* root, int n);