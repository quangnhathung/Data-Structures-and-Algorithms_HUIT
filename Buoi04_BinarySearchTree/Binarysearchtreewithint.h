#pragma once
#include<iostream>
#include<ctime>
struct TreeNode {
	int data;
	TreeNode* Left;
	TreeNode* Right;
};
struct BinarySearchTree {
	TreeNode* Root;
};
TreeNode* CreateTreeNode(int x);
void Init_BinarySearchTree(BinarySearchTree& tr);
bool IsEmpty(BinarySearchTree tr);
void Add_Tree(TreeNode*& root, TreeNode* p);
int Dlt_TreeNode(TreeNode*& root, int x);
void TraverseLNR(TreeNode* root);
void TraverseRNL(TreeNode* root);
void TraverseLRN(TreeNode* root);
void TraverseRLN(TreeNode* root);
void TraverseNLR(TreeNode* root);
void TraverseNRL(TreeNode* root);
TreeNode* FindTreeNode(TreeNode* root, int x);
int HeightTree(TreeNode* root);