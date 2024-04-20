#pragma once
#include<iostream>
#include "BinarySearchTree.h"
#include<cmath>
#include<stack>
#include "BinarySearchTreeWithFraction.h"
using namespace std;
//khoang cach phan tu gan nhat trong cay
int Distance(int a, int b);
void MinDistance(TreeNode* root, int& a, int x, int& b);
int Max(int a, int b);
//tong gia tri cua cay
int SumTreeWithoutRecursion(TreeNode* root);
//chieu cao
int HeightTree(TreeNode* root);
//dem so nut co gia tri lon hon x cho truoc
int CountNodeGreater(TreeNode* root, int x);
void ListedGreaterThanx(TreeNode* root, int x);
//Dem so nut tren cay
int CountPat(TreeNode* root);
//Dem nut la
int CountLeaf(TreeNode* root);
//dem nut la o muc k
int CountleafofLevel(TreeNode* root, int k);
//lon nhat trong cay
void MaxTree(TreeNode* root, TreeNode* max);
//nho nhat trong cay
void MinTree(TreeNode* root, TreeNode* min);
//dem nut co 1 con
int CountNodeHasOneChild(TreeNode* root);
//dem nut co 2 con
int CountNodeHasTwoChild(TreeNode* root);
//dem so nut o muc k
int CountNodeLevel(TreeNode* root, int k);
//dem cac nut trong khoang
int CountNodeInRange(TreeNode* root, int x, int y);
//dem cac node nho hon x
int CountNodeLower(TreeNode* root, int x);
//tng nut
int SumTree(TreeNode* root);
//tong cac nut la
int SumLeaf(TreeNode* root);
//tong nut co 1 con
int SumNodeHasOneChild(TreeNode* root);
//tong nut co hai con
int SumNodeHasTwoChild(TreeNode* root);
//liet ke phan tu o muc k
void ListedLevel(TreeNode* root, int k);
//tong so hoan thien
bool CheckPerfectNum(int n);
int SumPerfectNumber(TreeNode* root);
//tong so nguyen to
int SumPrimeNum(TreeNode* root);
//tong so chinh phuong
bool CheckPerfectSquare(int n);
int SumPerfectSquare(TreeNode* root);
//liet ke so hoan thien
void ListedPerfectNum(TreeNode* root);
//liet ke so chan
void ListedEvennum(TreeNode* root);
//dem nut la chan
int CountLeafeven(TreeNode* root);
//dem nut co 1 con va la so nguyen to
int CountNodeHasOneChildPrime(TreeNode* root);
//dem nut co 2 con la so hoan thien
int CountNodeHasTwoChildPerfectSquare(TreeNode* root);
//tong so le
int SumOddNum(TreeNode* root);
//tong nut gia tri le khong phair la la
int SumOddNumNotLeaf(TreeNode* root);
//tong nut co 1 con va la so nguyen to
int SumNodeHasOneChildPrime(TreeNode* root);
//tong nut co 2 con la so chinh phuonh
int SumNodeHasTwoChildPerfectSquare(TreeNode* root);
//kiem tra co phai cay nhi phan tim kiem hay khong
bool CheckBinarySearchTree(TreeNode* root);
//kiem tra cay co can bang hay khong
bool CheckBalance(TreeNode* root);
//kiem tra cay co can bang hoan toan hay khong
bool CheckPerfectBalance(TreeNode* root);


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