#pragma once
#include"BinarySearchTreeWithFraction.h";
#include<iostream>
#include"Fraction.h"
#include"CalculateTree.h"

struct AvlNodeFrct {
	Fraction data;
	int Height;
	AvlNodeFrct* Left;
	AvlNodeFrct* Right;
};
struct AvlTreeFrct {
	AvlNodeFrct* Root;
};
//khoi tao
void InitAVLTreeFrct(AvlTreeFrct& tr);
AvlNodeFrct* CreateAVLNodeFrct(Fraction x);
//cac phep xoay cay

int Height(AvlNodeFrct* root);
//xoay phai khi lech trai
void RotateRightFrct(AvlNodeFrct*& root);
//xoay trai khi lech phai
void RotateLeftFrct(AvlNodeFrct*& root);
//them phan tu vao cay
void Add_AvlTreeFrct(AvlNodeFrct*& root, AvlNodeFrct* p);
//xoa
AvlNodeFrct* FindAvlNodeFrctReplace(AvlNodeFrct* root);
int valbalence(AvlNodeFrct* root);
void Dlt_AvlNodeFrct(AvlNodeFrct*& root, Fraction x);
//duuyet cay
void TraverseLNRFrctAVL(AvlNodeFrct* root);
void TraverseRNLFrctAVL(AvlNodeFrct* root);
void TraverseLRNFrctAVL(AvlNodeFrct* root);
void TraverseRLNFrctAVL(AvlNodeFrct* root);
void TraverseNLRFrctAVL(AvlNodeFrct* root);
void TraverseNRLFrctAVL(AvlNodeFrct* root);
//format laij cay
void FormatAVLTree(AvlNodeFrct*& root);
//dem so luong phan so lon hon 1 
int CountFractionAvlTree(AvlNodeFrct* root);
//xoa toan bo cay
void Dlt_avlTree(AvlNodeFrct*& root);
void Listed(AvlNodeFrct* root, int x);