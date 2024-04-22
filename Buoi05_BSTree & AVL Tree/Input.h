#pragma once
#include "BinarySearchTreeWithFraction.h"
#include "BinarySearchTree.h"
#include "AVLtreeFrct.h"
void InputfromKeyboard(TreeNode*& root);
void InputFromArray(TreeNode*& root);
void InputRandom(TreeNode*& root);
void InputFromFile(TreeNode*& root);
//**********fraction*************************8
void InputfromKeyboardFrct(TreeNodeFrct*& root);
void InputFromArrayFrct(TreeNodeFrct*& root);
void InputRandomFrct(TreeNodeFrct*& root);
void InputFromFileFrct(TreeNodeFrct*& root);
//********************AVL fraction*********************8
//Nhap tu ban phim
void InputfromKeyboardAVLFrct(AvlNodeFrct*& root);
//Nhap tu mang
void InputFromArrayAVLFrct(AvlNodeFrct*& root);
//Nhau nhien
void InputRandomAVLFrct(AvlNodeFrct*& root);
//Nhap tu file 
void InputFromFileAVLFrct(AvlNodeFrct*& root);