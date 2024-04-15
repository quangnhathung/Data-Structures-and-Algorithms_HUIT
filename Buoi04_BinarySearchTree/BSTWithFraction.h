#pragma once
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
struct Fraction {
	int Tu;
	int Mau;
};
struct TreeNodeFrct {
	Fraction data;
	TreeNodeFrct* Left;
	TreeNodeFrct* Right;
};
struct BinarySearchTreeFrct {
	TreeNodeFrct* Root;
};
TreeNodeFrct* CreateTreeNodeFrct(Fraction x);
void Init_BinarySearchTreeFrct(BinarySearchTreeFrct& tr);
bool IsEmptyFrct(BinarySearchTreeFrct tr);
float FractionValue(Fraction x);
void Add_TreeFrct(TreeNodeFrct*& root, TreeNodeFrct* p);
int Dlt_TreeNodeFrct(TreeNodeFrct*& root, Fraction x);
void TraverseLNRFrct(TreeNodeFrct* root);
void TraverseRNLFrct(TreeNodeFrct* root);
void TraverseLRNFrct(TreeNodeFrct* root);
void TraverseRLNFrct(TreeNodeFrct* root);
void TraverseNLRFrct(TreeNodeFrct* root);
void TraverseNRLFrct(TreeNodeFrct* root);
TreeNodeFrct* FindTreeNodeFrct(TreeNodeFrct* root, Fraction x);