#pragma once
#include "Binarysearchtreewithint.h"
int Max(int a, int b);
//chieu cao
int HeightTree(TreeNode* root);
//dem so nut co gia tri lon hon x cho truoc
int CountNodeGreater(TreeNode* root, int x);
void ListedGreaterThanx(TreeNode* root, int x);
//Dem so nut tren cay
int CountPat(TreeNode* root);
//Dem nut la
int CountLeaf(TreeNode* root);
//dem nut co 1 con
int CountNodeHasOneChild(TreeNode* root);
//dem nut co 2 con
int CountNodeHasTwoChild(TreeNode* root);
//tng nut
int SumTree(TreeNode* root);
//tong cac nut la
int SumLeaf(TreeNode* root);
//tong nut co 1 con
int SumNodeHasOneChild(TreeNode* root);
//tong nut co hai con
int SumNodeHasTwoChild(TreeNode* root);
