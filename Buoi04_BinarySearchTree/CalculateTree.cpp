//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include "Binarysearchtreewithint.h"
#include "Fraction.h"

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
//++++++++++++++PHAN SO++++++++++++++++++++++
//dem phan so >1
int CountFractionGreaterthan1(TreeNodeFrct* root) {
	if (root == 0) return 0;
	if (FractionValue(root->data) > 1) {
		return 1 + CountFractionGreaterthan1(root->Left) + CountFractionGreaterthan1(root->Right);
	}
	else {
		return 0 + CountFractionGreaterthan1(root->Left) + CountFractionGreaterthan1(root->Right);
	}
}
//toi gian 
void SimplifyTree(TreeNodeFrct*& root) {
	if (root == NULL) return;
	format(root->data.Tu, root->data.Mau);
	SimplifyTree(root->Right);
	SimplifyTree(root->Left);
}
//tong phan so
float SumTreeFrct(TreeNodeFrct* root) {
	if (root == NULL) {
		return 0;
	}
	return FractionValue(root->data) + SumTreeFrct(root->Left) + SumTreeFrct(root->Right);
}
//liet ke phan so lon hon 1
void ListedGreaterThanFrct(TreeNodeFrct* root) {
	if (root == NULL) return;
	ListedGreaterThanFrct(root->Left);
	if (FractionValue( root->data) > 1) {
		if (root->data.Mau == 1) {
			cout << root->data.Tu << " ";
		}
		else {
			cout << root->data.Tu << "/" << root->data.Mau << " ";
		}
	}
	ListedGreaterThanFrct(root->Right);
}
//liet ke phan so be hon 1
void ListedlowerThanFrct(TreeNodeFrct* root) {
	if (root == NULL) return;
	ListedlowerThanFrct(root->Left);
	if (FractionValue(root->data) < 1) {
		if (root->data.Mau == 1) {
			cout << root->data.Tu << " ";
		}
		else {
			cout << root->data.Tu << "/" << root->data.Mau << " ";
		}
	}
	ListedlowerThanFrct(root->Right);
}
//Ps lon nhat trong cay
void MaxTreeFrct(TreeNodeFrct* root,TreeNodeFrct* max) {
	/*if (root == NULL) return;
	if (FractionValue(root->data) >= FractionValue(max->data)) {
		max->data = root->data;
	}*/
	if (root->Right == NULL) {
		max->data = root->data;
		return;
	}
	MaxTreeFrct(root->Right, max);
}
//ps nho nhat trong cay
void MinTreeFrct(TreeNodeFrct* root, TreeNodeFrct* min) {
	if (root == NULL) return;
	if (FractionValue(root->data) <= FractionValue(min->data)) {
		min->data = root->data;
	}
	MinTreeFrct(root->Left, min);
	MinTreeFrct(root->Right, min);
}
//tu va mau cung la so nguyen to
bool CheckPrimeNum(int n) {
	if (n == 1) return false;
	for (int i = 2; i < sqrtf((float)n); i++) {
		if (n % 2 == 0) return false;
	}
	return true;
}
bool CheckPrimeFraction(Fraction x) {
	if (CheckPrimeNum(x.Tu) && CheckPrimeNum(x.Mau)) return true;
	return false;
}
void ListedPrimeFrct(TreeNodeFrct* root) {
	if (root == NULL) return;
	ListedPrimeFrct(root->Left);
	if (CheckPrimeFraction(root->data)) {
		if (root->data.Mau == 1) {
			cout << root->data.Tu << " ";
		}
		else {
			cout << root->data.Tu << "/" << root->data.Mau << " ";
		}
	}
	ListedPrimeFrct(root->Right);
}
//liệt kê phần tử ở mức k
int MaxFrct(int a, int b) {
	int max = a >= b ? a : b;
	return max;
}
int HeightTreeFrct(TreeNodeFrct* root) {
	if (root == NULL) return 0;
	return 1 + MaxFrct(HeightTreeFrct(root->Left), HeightTreeFrct(root->Right));
}
void ListedLevelFrct(TreeNodeFrct* root,int k) {
	if (root == NULL) return;
	if (k == 0) {
		if (root->data.Mau == 1) {
			cout << root->data.Tu << " ";
		}
		else {
			cout << root->data.Tu << "/" << root->data.Mau << " ";
		}
	}
	ListedLevelFrct(root->Left, k-1);
	ListedLevelFrct(root->Right, k-1);
}
int CountnodeLevelFrct(TreeNodeFrct* root, int k) {
	if (root == NULL) return 0;
	if (k == 0) {
		return 1 + CountnodeLevelFrct(root->Left, k - 1) + CountnodeLevelFrct(root->Right, k - 1);
	}
	else {
		return 0 + CountnodeLevelFrct(root->Left, k - 1) + CountnodeLevelFrct(root->Right, k - 1);
	}
}
//tong muc k
float SumLevelFrct(TreeNodeFrct* root, int k) {
	if (root == NULL) return 0;
	if (k == 0) {
		return FractionValue(root->data) + SumLevelFrct(root->Left, k - 1) + SumLevelFrct(root->Right, k - 1);
	}
	else {
		return 0 + SumLevelFrct(root->Left, k - 1) + SumLevelFrct(root->Right, k - 1);
	}
}
