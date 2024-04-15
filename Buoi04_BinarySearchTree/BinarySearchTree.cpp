//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include "Binarysearchtreewithint.h"
using namespace std;
void Init_BinarySearchTree(BinarySearchTree& tr) {
	tr.Root = NULL;
}
TreeNode* CreateTreeNode(int x) {
	TreeNode* p = new TreeNode;
	p->data = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}
bool IsEmpty(BinarySearchTree tr) {
	if (tr.Root == NULL) return true;
	return false;
}
void Add_Tree(TreeNode*& root, TreeNode* p) {
	if (p == NULL) return;
	if (root == NULL) {
		root = p;
		return;
	}
	if (p->data > root->data) {
		Add_Tree(root->Right, p);
	}
	if (p->data < root->data) {
		Add_Tree(root->Left, p);
	}
}
//xoa 1 phan tu x
TreeNode* FindNodeReplace(TreeNode* root) {
	TreeNode* p = root->Left;
	//chon phan tu phai nhat cua caa ben trai
	while (1) {
		p = p->Right;
		if (p->Right == NULL) return p;
	}
}
int Dlt_TreeNode(TreeNode*& root, int x) {
	if (root == NULL) {
		return 0;
	}
	if (x < root->data) {
		Dlt_TreeNode(root->Left, x);
	}
	else if (x > root->data) {
		Dlt_TreeNode(root->Right, x);
	}
	else if (x == root->data) {//tim thay x
		//case 1: x la nut la:
		if (root->Left == NULL && root->Right == NULL) {
			TreeNode* temp = root;
			root = NULL;
			delete temp;
		}
		//case 2: nut cha co 1 con
		else if (root->Left == NULL) {
			TreeNode* temp = root;
			root = root->Right;
			delete temp;
		}
		else if (root->Right == NULL) {
			TreeNode* temp = root;
			root = root->Left;
			delete temp;
		}//case 3: co 2 con
		else if (root->Right != NULL && root->Left) {
			TreeNode* t = FindNodeReplace(root);
			root->data = t->data;
			Dlt_TreeNode(root->Left, t->data);
		}
		return 1;//thuc hien thanh cong
	}
	return 0; //Khong tim thay phan tu x
}
//6 phep duyet cay
void TraverseLNR(TreeNode* root) {
	if (root == NULL) return;
	TraverseLNR(root->Left);
	cout << root->data << " ";
	TraverseLNR(root->Right);
}
void TraverseRNL(TreeNode* root) {
	if (root == NULL) return;
	TraverseRNL(root->Right);
	cout << root->data << " ";
	TraverseRNL(root->Left);
}
void TraverseLRN(TreeNode* root) {
	if (root == NULL) return;
	TraverseLRN(root->Left);
	TraverseLRN(root->Right);
	cout << root->data << " ";
}
void TraverseRLN(TreeNode* root) {
	if (root == NULL) return;
	TraverseRLN(root->Right);
	TraverseRLN(root->Left);
	cout << root->data << " ";
}
void TraverseNLR(TreeNode* root) {
	if (root == NULL) return;
	cout << root->data << " ";
	TraverseNLR(root->Left);
	TraverseNLR(root->Right);
}
void TraverseNRL(TreeNode* root) {
	if (root == NULL) return;
	cout << root->data << " ";
	TraverseNRL(root->Right);
	TraverseNRL(root->Left);
}
//tim kiem 1 phan tu
TreeNode* FindTreeNode(TreeNode* root, int x) {
	if (root == NULL) return NULL;
	if (root->data == x) return root;
	if (x < root->data) {
		FindTreeNode(root->Left, x);
	}
	else if (x > root->data) {
		FindTreeNode(root->Right, x);
	}
}