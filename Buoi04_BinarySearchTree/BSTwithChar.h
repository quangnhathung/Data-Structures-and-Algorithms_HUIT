#pragma once
#include<stack>
#include<string>
#include<cctype>
#include<iostream>
using namespace std;
struct TreeNodeChar {
	char Data;
	TreeNodeChar* Left;
	TreeNodeChar* Right;
};
struct BinarySearchTreeChar {
	TreeNodeChar* Root;
};

int CheckStringValid(string s);
int Uutien(char c);
bool IsOperator(char c);
string InfixtoPostfix(string s);
void Init_BinarySearchTreeChar(BinarySearchTreeChar& tr);
TreeNodeChar* CreateTreeNodeChar(char x);
bool IsEmptyChar(BinarySearchTreeChar tr);
void Add_TreeChar(TreeNodeChar*& root, string s);
TreeNodeChar* FindNodeReplaceChar(TreeNodeChar* root);
int Dlt_TreeNodeChar(TreeNodeChar*& root, int x);
//6 phep duyet cay
void TraverseLNRChar(TreeNodeChar* root);
void TraverseRNLChar(TreeNodeChar* root);
void TraverseLRNChar(TreeNodeChar* root);
void TraverseRLNChar(TreeNodeChar* root);
void TraverseNLRChar(TreeNodeChar* root);
void TraverseNRLChar(TreeNodeChar* root);
TreeNodeChar* FindTreeNodeChar(TreeNodeChar* root, int x);