//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include "BinarySearchTreeWithFraction.h"
#include <iostream>
#include "BinarySearchTree.h"
#include "Fraction.h"
#include "CalculateTree.h"
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
		return  0 + CountNodeGreater(root->Left, x) + CountNodeGreater(root->Right, x);
	}
}
//dem cac nut trong khoang
int CountNodeInRange(TreeNode* root, int x, int y) {
	if (root == NULL) return 0;
	if (root->data >= x && root->data <= y) {
		return 1 + CountNodeInRange(root->Left, x, y) + CountNodeInRange(root->Right, x, y);
	}
	else {
		return 0 + CountNodeInRange(root->Left, x, y) + CountNodeInRange(root->Right, x, y);
	}
}
//dem cac node nho hon x
int CountNodeLower(TreeNode* root, int x) {
	if (root == NULL) {
		return 0;
	}
	if (root->data < x) {
		return 1 + CountNodeLower(root->Left, x) + CountNodeLower(root->Right, x);
	}
	else {
		return  0 + CountNodeLower(root->Left, x) + CountNodeLower(root->Right, x);
	}
}
//dem so nut o muc k
int CountNodeLevel(TreeNode* root, int k) {
	if (root == NULL) return 0;
	if (k == 0) {
		return 1 + CountNodeLevel(root->Left, k - 1) + CountNodeLevel(root->Right, k - 1);
	}
	else return 0 + CountNodeLevel(root->Left, k - 1) + CountNodeLevel(root->Right, k - 1);
	CountNodeLevel(root->Left, k - 1);
	CountNodeLevel(root->Right, k - 1);
}
//liet ke phan tu o muc k
void ListedLevel(TreeNode* root, int k) {
	if (root == NULL) return;
	if (k == 0) {
		cout << root->data << " ";
	}
	ListedLevel(root->Left, k - 1);
	ListedLevel(root->Right, k - 1);
}
//liet ke so lon hon x
void ListedGreaterThanx(TreeNode* root, int x) {
	if (root == NULL) return;
	ListedGreaterThanx(root->Left, x);
	if (root->data > x) {
		cout << root->data << " ";
	}
	ListedGreaterThanx(root->Right, x);
}
//lon nhat trong cay
void MaxTree(TreeNode* root, TreeNode* max) {
	if (root->Right == NULL) {
		max->data = root->data;
		return;
	}
	MaxTree(root->Right, max);
}
//nho nhat trong cay
void MinTree(TreeNode* root, TreeNode* min) {
	if (root->Left == NULL) {
		min->data = root->data;
		return;
	}
	MinTree(root->Left, min);
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
//dem nut la o muc k
int CountleafofLevel(TreeNode* root, int k) {
	if (root == NULL) return 0;
	if (k == 0 && root->Left == NULL && root->Right == NULL)
		return 1 + CountleafofLevel(root->Left, k - 1) + CountleafofLevel(root->Right, k - 1);
	else return 0 + CountleafofLevel(root->Left, k - 1) + CountleafofLevel(root->Right, k - 1);
}
//dem nut co 1 con
int CountNodeHasOneChild(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->Left == NULL && root->Right != NULL) {
		return 1 + CountNodeHasOneChild(root->Left) + CountNodeHasOneChild(root->Right);
	}
	else if (root->Right == NULL && root->Left != NULL) {
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
int SumTree(TreeNode* root) {
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
//khoang cach phan tu gan nhat trong cay
int Distance(int a, int b) {
	return abs(a - b);
}
void MinDistance(TreeNode* root, int& a, int x, int& b) {
	//a luu gia tri khoang cach nho nhat hien tai
	//b luu gia tri cua root thoa dk
	if (root == NULL) return;
	if (Distance(root->data, x) < a) {
		a = Distance(root->data, x);
		b = root->data;
	}
	MinDistance(root->Left, a, x, b);
	MinDistance(root->Right, a, x, b);
}
//khoang cach phan tu xa nhat trong cay
void MaxDistance(TreeNode* root, int& a, int x, int& b) {
	//a luu gia tri khoang cach nho nhat hien tai
	//b luu gia tri cua root thoa dk
	if (root == NULL) return;
	if (Distance(root->data, x) > a) {
		a = Distance(root->data, x);
		b = root->data;
	}
	MaxDistance(root->Left, a, x, b);
	MaxDistance(root->Right, a, x, b);
}
//tong gia tri cua cay
int SumTreeWithoutRecursion(TreeNode* root) {
	stack<TreeNode*> st;
	TreeNode* p = root;
	int sum = 0;
	while (1) {
		while (p != NULL) {
			st.push(p);
			p = p->Left;
		}
		if (!st.empty()) {
			TreeNode* t = st.top();
			if (t->Right == NULL) {
				sum += t->data;
				st.pop();
			}
			else {
				p = t->Right;
				sum += st.top()->data;
				st.pop();
			}
		}
		else break;
	}
	return sum;
}
//tong so hoan thien
bool CheckPerfectNum(int n) {
	if (n < 0) return false;
	int x = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) x += i;
	}
	if (x == n) return true;
	return false;
}
int SumPerfectNumber(TreeNode* root) {
	if (root == NULL) return 0;
	if (CheckPerfectNum(root->data)) {
		return root->data + SumPerfectNumber(root->Left) + SumPerfectNumber(root->Right);
	}
	else return 0 + SumPerfectNumber(root->Left) + SumPerfectNumber(root->Right);
}
//tong so nguyen to
int SumPrimeNum(TreeNode* root) {
	if (root == NULL) return 0;
	if (CheckPrimeNum(root->data)) {
		return root->data + SumPrimeNum(root->Left) + SumPrimeNum(root->Right);
	}
	else return 0 + SumPrimeNum(root->Left) + SumPrimeNum(root->Right);
}
//tong so chinh phuong
bool CheckPerfectSquare(int n) {
	if (n < 0) return false;
	int x = sqrt((double)n);
	if (x * x == n) return true;
	return false;
}
int SumPerfectSquare(TreeNode* root) {
	if (root == NULL) return 0;
	if (CheckPerfectSquare(root->data)) {
		return root->data + SumPerfectSquare(root->Left) + SumPerfectSquare(root->Right);
	}
	else return 0 + SumPerfectSquare(root->Left) + SumPerfectSquare(root->Right);
}


//liet ke so hoan thien
void ListedPerfectNum(TreeNode* root) {
	if (root == NULL) return;
	ListedPerfectNum(root->Left);
	if (CheckPerfectNum(root->data)) {
		cout << root->data << " ";
	}
	ListedPerfectNum(root->Right);
}
//liet ke so chan
void ListedEvennum(TreeNode* root) {
	if (root == NULL) return;
	ListedEvennum(root->Left);
	if (root->data % 2 == 0) {
		cout << root->data << " ";
	}
	ListedEvennum(root->Right);
}
//dem nut la chan
int CountLeafeven(TreeNode* root) {
	if (root == NULL) return 0;
	if (root->data % 2 == 0 && root->Left == NULL && root->Right == NULL) {
		return 1 + CountLeafeven(root->Left) + CountLeafeven(root->Right);
	}
	else return 0 + CountLeafeven(root->Left) + CountLeafeven(root->Right);
}
//dem nut co 1 con va la so nguyen to
int CountNodeHasOneChildPrime(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->Left == NULL && root->Right != NULL && CheckPrimeNum(root->Right->data)) {
		return 1 + CountNodeHasOneChildPrime(root->Left) + CountNodeHasOneChildPrime(root->Right);
	}
	else if (root->Right == NULL && root->Left != NULL && CheckPrimeNum(root->Left->data)) {
		return 1 + CountNodeHasOneChildPrime(root->Left) + CountNodeHasOneChildPrime(root->Right);
	}
	else {
		return 0 + CountNodeHasOneChildPrime(root->Left) + CountNodeHasOneChildPrime(root->Right);
	}
}
//dem nut co 2 con la so chinh phuonh
int CountNodeHasTwoChildPerfectSquare(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->Left != NULL && root->Right != NULL && CheckPerfectSquare(root->Left->data) && CheckPerfectSquare(root->Right->data)) {
		return 1 + CountNodeHasTwoChildPerfectSquare(root->Left) + CountNodeHasTwoChildPerfectSquare(root->Right);
	}
	else {
		return 0 + CountNodeHasTwoChildPerfectSquare(root->Left) + CountNodeHasTwoChildPerfectSquare(root->Right);
	}
}

//tong so le
int SumOddNum(TreeNode* root) {
	if (root == NULL) return 0;
	if (root->data % 2 != 0) {
		return root->data + SumOddNum(root->Left) + SumOddNum(root->Right);
	}
	else return 0 + SumOddNum(root->Left) + SumOddNum(root->Right);
}
//tong nut gia tri le khong phair la la
int SumOddNumNotLeaf(TreeNode* root) {
	if (root == NULL) return 0;
	if (root->data % 2 != 0 && (root->Left != NULL || root->Right != NULL)) {
		return root->data + SumOddNumNotLeaf(root->Left) + SumOddNumNotLeaf(root->Right);
	}
	else return 0 + SumOddNumNotLeaf(root->Left) + SumOddNumNotLeaf(root->Right);
}
//tong nut co 1 con va la so nguyen to
int SumNodeHasOneChildPrime(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->Left == NULL && root->Right != NULL && CheckPrimeNum(root->Right->data)) {
		return root->data + SumNodeHasOneChildPrime(root->Left) + SumNodeHasOneChildPrime(root->Right);
	}
	else if (root->Right == NULL && root->Left != NULL && CheckPrimeNum(root->Left->data)) {
		return root->data + SumNodeHasOneChildPrime(root->Left) + SumNodeHasOneChildPrime(root->Right);
	}
	else {
		return 0 + SumNodeHasOneChildPrime(root->Left) + SumNodeHasOneChildPrime(root->Right);
	}
}
//tong nut co 2 con la so chinh phuonh
int SumNodeHasTwoChildPerfectSquare(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->Left != NULL && root->Right != NULL && CheckPerfectSquare(root->Left->data) && CheckPerfectSquare(root->Right->data)) {
		return root->data + SumNodeHasTwoChildPerfectSquare(root->Left) + SumNodeHasTwoChildPerfectSquare(root->Right);
	}
	else {
		return 0 + SumNodeHasTwoChildPerfectSquare(root->Left) + SumNodeHasTwoChildPerfectSquare(root->Right);
	}
}
//kiem tra co phai cay nhi phan tim kiem hay khong
bool CheckBinarySearchTree(TreeNode* root) {
	if (root == NULL) return false;
	if (root->data<root->Right->data && root->data>root->Left->data) return true;
	else return false;
	CheckBinarySearchTree(root->Left);
	CheckBinarySearchTree(root->Right);
}
//kiem tra cay co can bang hay khong
bool CheckBalance(TreeNode* root) {
	if (root == NULL) return true;
	if (abs(HeightTree(root->Left) - HeightTree(root->Right)) == 1 || abs(HeightTree(root->Left) - HeightTree(root->Right)) == 0 && CheckBalance(root->Left) && CheckBalance(root->Right)) {
		return true;
	}
	else return false;
	CheckBalance(root->Left);
	CheckBalance(root->Right);
}
//kiem tra cay co can bang hoan toan hay khong
bool CheckPerfectBalance(TreeNode* root) {
	if (root == NULL) return true;
	if (abs(HeightTree(root->Left) - HeightTree(root->Right)) == 0 && CheckPerfectBalance(root->Left) && CheckPerfectBalance(root->Right)) {
		return true;
	}
	else return false;
	CheckBalance(root->Left);
	CheckBalance(root->Right);
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
	if (FractionValue(root->data) > 1) {
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
void MaxTreeFrct(TreeNodeFrct* root, TreeNodeFrct* max) {
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
	if (n < 2) return false;
	for (int i = 2; i < sqrtf((float)n); i++) {
		if (n % i == 0) return false;
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
//li?t kê ph?n t? ? m?c k
int MaxFrct(int a, int b) {
	int max = a >= b ? a : b;
	return max;
}
int HeightTreeFrct(TreeNodeFrct* root) {
	if (root == NULL) return 0;
	return 1 + MaxFrct(HeightTreeFrct(root->Left), HeightTreeFrct(root->Right));
}
void ListedLevelFrct(TreeNodeFrct* root, int k) {
	if (root == NULL) return;
	if (k == 0) {
		if (root->data.Mau == 1) {
			cout << root->data.Tu << " ";
		}
		else {
			cout << root->data.Tu << "/" << root->data.Mau << " ";
		}
	}
	ListedLevelFrct(root->Left, k - 1);
	ListedLevelFrct(root->Right, k - 1);
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
