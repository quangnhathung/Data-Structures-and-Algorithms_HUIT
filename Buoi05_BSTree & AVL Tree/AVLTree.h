#pragma once
#include "iostream"
#include <cmath>
#include"CalculateTree.h"
using namespace std;
 
struct AVLNode {
	int Height;
	int Data;
	AVLNode* Left;
	AVLNode* Right;
};
struct AVLTree {
	AVLNode* Root;
};

AVLNode* CreateAVLNode(int x);
void Init_AVLTree(AVLTree& tr);
//theem phan tu vao danh sach 
//Ham tinh chieu cao
int Max(int a, int b);
int Height(AVLNode* root);

//ham xoay
//xoay trai khi bi lech phai
void RotateLeft(AVLNode*& root);
//xoay phai khi lech trai
void RotateRight(AVLNode*& root);
//ham them nut vao caay avl
void Add_AvlTree(AVLNode*& root, AVLNode* p);
//xoa
//xoa
int ValBalance(AVLNode* root);
AVLNode* FindAvlNodeReplace(AVLNode* root);
void Dlt_AvlNode(AVLNode*& root, int x);
//xoa cay thi khoi can bang
void Dlt_AvlTree(AVLNode*& root);
//duyet cay NLR
void TraverseAVLtree_NLR(AVLNode* root);
//tim kiem cay
AVLNode* FindAvlNode(AVLNode* root, int x);