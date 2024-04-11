#include "Binarysearchtreewithint.h"
using namespace std;
//Chieu cao cua cay
int Max(int a, int b) {
	int max = a >= b ? a : b;
	return max;
}
int HeightTree(TreeNode* root) {
	if (root == NULL) return 0;
	return 1 + Max(HeightTree(root->Left), HeightTree(root->Right));
}
//dem cac nut co gia tri > x tren cay
int CountNodeGreater(TreeNode* root, int x) {
	if (root == NULL) {
		return 0;
	}
	if (root->data > x) {
		return 1 + CountNodeGreater(root->Left, x) + CountNodeGreater(root->Right, x);
	}
	else {
		return  CountNodeGreater(root->Left, x) + CountNodeGreater(root->Right, x);
	}
}
void ListedGreaterThanx(TreeNode* root,int x) {
	if (root == NULL) return;
	ListedGreaterThanx(root->Left,x);
	if (root->data > x) {
		cout << root->data << " ";
	}
	ListedGreaterThanx(root->Right, x);
}
//Dem so nut tren cay
int CountPat(TreeNode* root) {
	if (root == NULL) return 0;
	return 1 + CountPat(root->Left) + CountPat(root->Right);
}
//Dem nut la
int CountLeaf(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->Left == NULL && root->Right == NULL) {
		return 1 + CountLeaf(root->Left) + CountLeaf(root->Right);
	}
	else {
		return 0 + CountLeaf(root->Left) + CountLeaf(root->Right);
	}
}
//dem nut co 1 con
int CountNodeHasOneChild(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->Left == NULL && root->Right != NULL) {
		return 1 + CountNodeHasOneChild(root->Left) + CountNodeHasOneChild(root->Right);
	}
	else if (root->Right == NULL && root->Left != NULL){
		return 1 + CountNodeHasOneChild(root->Left) + CountNodeHasOneChild(root->Right);
	}
	else {
		return 0 + CountNodeHasOneChild(root->Left) + CountNodeHasOneChild(root->Right);
	}
}
//dem nut co 2 con
int CountNodeHasTwoChild(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->Left != NULL && root->Right != NULL) {
		return 1 + CountNodeHasTwoChild(root->Left) + CountNodeHasTwoChild(root->Right);
	}
	else {
		return 0 + CountNodeHasTwoChild(root->Left) + CountNodeHasTwoChild(root->Right);
	}
}
//tng nut
int SumTree(TreeNode* root){
	if (root == NULL) {
		return 0;
	}
	return root->data + SumTree(root->Left) + SumTree(root->Right);
}
//tong cac nut la
int SumLeaf(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->Left == NULL && root->Right == NULL) {
		return root->data + SumLeaf(root->Left) + SumLeaf(root->Right);
	}
	else {
		return 0 + SumLeaf(root->Left) + SumLeaf(root->Right);
	}
}
//tong nut co 1 con
int SumNodeHasOneChild(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->Left == NULL && root->Right != NULL) {
		return root->data + SumNodeHasOneChild(root->Left) + SumNodeHasOneChild(root->Right);
	}
	else if (root->Right == NULL && root->Left != NULL) {
		return root->data + SumNodeHasOneChild(root->Left) + SumNodeHasOneChild(root->Right);
	}
	else {
		return 0 + SumNodeHasOneChild(root->Left) + SumNodeHasOneChild(root->Right);
	}
}
//tong nut co hai con
int SumNodeHasTwoChild(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->Left != NULL && root->Right != NULL) {
		return root->data + SumNodeHasTwoChild(root->Left) + SumNodeHasTwoChild(root->Right);
	}
	else {
		return 0 + SumNodeHasTwoChild(root->Left) + SumNodeHasTwoChild(root->Right);
	}
}
