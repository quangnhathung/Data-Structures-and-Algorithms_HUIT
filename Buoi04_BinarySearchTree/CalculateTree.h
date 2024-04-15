#pragma once
#include "Binarysearchtreewithint.h"
#include "BSTWithFraction.h"
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
//**************FRACTION*****************
//dem phan so >1
int CountFractionGreaterthan1(TreeNodeFrct* root);
//toi gian 
void SimplifyTree(TreeNodeFrct*& root);
//li?t kê ph?n t? ? m?c k
int Max(int a, int b);
int HeightTreeFrct(TreeNodeFrct* root);
void ListedLevelFrct(TreeNodeFrct* root, int k);
int CountnodeLevelFrct(TreeNodeFrct* root, int k);
float SumLevelFrct(TreeNodeFrct* root, int k);
//tu va mau cung la so nguyen to
bool CheckPrimeNum(int n);
bool CheckPrimeFraction(Fraction x);
void ListedPrimeFrct(TreeNodeFrct* root);
//Ps lon nhat trong cay
void MaxTreeFrct(TreeNodeFrct* root, TreeNodeFrct* max); 
//ps nho nhat trong cay
void MinTreeFrct(TreeNodeFrct* root, TreeNodeFrct* min); 
//liet ke phan so lon hon 1
void ListedGreaterThanFrct(TreeNodeFrct* root);
//liet ke phan so be hon 1
void ListedlowerThanFrct(TreeNodeFrct* root);
//tongcay
float SumTreeFrct(TreeNodeFrct* root);
