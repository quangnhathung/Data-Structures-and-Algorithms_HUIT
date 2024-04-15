#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include <Windows.h>
using namespace std;

#include "Binarysearchtreewithint.h"
#include "BSTWithFraction.h"
#include "BSTwithChar.h"
//===============================================================================
struct asciinode
{
    asciinode *left;
    asciinode *right;   
    
    int edge_length;//length of the edge from this node to its children
    int height;
    int lablen;

    int parent_dir; //-1=I am left, 0=I am root, 1=right   
    char label[11];//max supported unit32 in dec, 10 digits max   
};
//===============================================================================
/* Khai báo thuộc tính color */
enum EColor { RED, BLACK };
void set_Color(int colorBackground, int colorText);
//===============================================================================
int MIN(int X, int Y);
int MAX(int X, int Y);
//===============================================================================
asciinode* build_ascii_tree_recursive(TreeNode* t);
asciinode* build_ascii_tree_recursiveFrct(TreeNodeFrct* t);
asciinode* build_ascii_tree_recursiveChar(TreeNodeChar* t);
//Copy the tree into the ascii node structre
asciinode* build_ascii_tree(TreeNode* t);
asciinode* build_ascii_treeFrct(TreeNodeFrct* t);
asciinode* build_ascii_treeChar(TreeNodeChar* t);
//Free all the nodes of the given tree
void deleteAscii(asciinode* root);

//The following function fills in the lprofile array for the given tree.
//It assumes that the center of the label of the root of this tree
//is located at a position (x,y).  It assumes that the edge_length
//fields have been computed for this tree.
void compute_lprofile(asciinode* node, int x, int y);

void compute_rprofile(asciinode* node, int x, int y);

//This function fills in the edge_length and 
//height fields of the specified tree
void compute_edge_lengths(asciinode* node);

//This function prints the given level of the given tree, assuming
//that the node has the given x cordinate.
void print_level(asciinode* node, int x, int level);

//prints ascii tree for given Tree structure
void print_ascii_tree(TreeNode* t);
void print_ascii_treeFrct(TreeNodeFrct* t);
void print_ascii_treeChar(TreeNodeChar* t);

