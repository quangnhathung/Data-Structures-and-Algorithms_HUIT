//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include "BinarySearchTreeWithFraction.h"
using namespace std;
void Init_BinarySearchTreeFrct(BinarySearchTreeFrct& tr) {
	tr.Root = NULL;
}
TreeNodeFrct* CreateTreeNodeFrct(Fraction x) {
	TreeNodeFrct* p = new TreeNodeFrct;
	p->data = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}
bool IsEmptyFrct(BinarySearchTreeFrct tr) {
	if (tr.Root == NULL) return true;
	return false;
}
float FractionValue(Fraction x) {
	return 1.00 * x.Tu / x.Mau;
}
void Add_TreeFrct(TreeNodeFrct*& root, TreeNodeFrct* p) {
	if (p == NULL) return;
	if (root == NULL) {
		root = p;
		return;
	}
	if (FractionValue(p->data) > FractionValue(root->data)) {
		Add_TreeFrct(root->Right, p);
	}
	if (FractionValue(p->data) < FractionValue(root->data)) {
		Add_TreeFrct(root->Left, p);
	}
}


//xoa 1 phan tu x
TreeNodeFrct* FindNodeReplaceFrct(TreeNodeFrct* root) {
	TreeNodeFrct* p = root->Left;
	//chon phan tu phai nhat cua caa ben trai
	while (1) {
		p = p->Right;
		if (p->Right == NULL) return p;
	}
}
int Dlt_TreeNodeFrct(TreeNodeFrct*& root, Fraction x) {
	if (root == NULL) {
		return 0;
	}
	if (FractionValue(x) > FractionValue(root->data)) {
		Dlt_TreeNodeFrct(root->Left, x);
	}
	else if (FractionValue(x) < FractionValue(root->data)) {
		Dlt_TreeNodeFrct(root->Right, x);
	}
	else if (FractionValue(x) == FractionValue(root->data)) {//tim thay x
		//case 1: x la nut la:
		if (root->Left == NULL && root->Right == NULL) {
			TreeNodeFrct* temp = root;
			root = NULL;
			delete temp;
		}
		//case 2: nut cha co 1 con
		else if (root->Left == NULL) {
			TreeNodeFrct* temp = root;
			root = root->Right;
			delete temp;
		}
		else if (root->Right == NULL) {
			TreeNodeFrct* temp = root;
			root = root->Left;
			delete temp;
		}//case 3: co 2 con
		else if (root->Right != NULL && root->Left) {
			TreeNodeFrct* t = FindNodeReplaceFrct(root);
			root->data = t->data;
			Dlt_TreeNodeFrct(root->Left, t->data);
		}
		return 1;//thuc hien thanh cong
	}
	return 0; //Khong tim thay phan tu x
}


//6 phep duyet cay
void TraverseLNRFrct(TreeNodeFrct* root) {
	if (root == NULL) return;
	TraverseLNRFrct(root->Left);
	if (root->data.Mau == 1) {
		cout << root->data.Tu << " ";
	}
	else {
		cout << root->data.Tu << "/" << root->data.Mau << " ";
	}
	TraverseLNRFrct(root->Right);
}
void TraverseRNLFrct(TreeNodeFrct* root) {
	if (root == NULL) return;
	TraverseRNLFrct(root->Right);
	if (root->data.Mau == 1) {
		cout << root->data.Tu << " ";
	}
	else {
		cout << root->data.Tu << "/" << root->data.Mau << " ";
	}
	TraverseRNLFrct(root->Left);
}
void TraverseLRNFrct(TreeNodeFrct* root) {
	if (root == NULL) return;
	TraverseLRNFrct(root->Left);
	TraverseLRNFrct(root->Right);
	if (root->data.Mau == 1) {
		cout << root->data.Tu << " ";
	}
	else {
		cout << root->data.Tu << "/" << root->data.Mau << " ";
	}
}
void TraverseRLNFrct(TreeNodeFrct* root) {
	if (root == NULL) return;
	TraverseRLNFrct(root->Right);
	TraverseRLNFrct(root->Left);
	if (root->data.Mau == 1) {
		cout << root->data.Tu << " ";
	}
	else {
		cout << root->data.Tu << "/" << root->data.Mau << " ";
	}
}
void TraverseNLRFrct(TreeNodeFrct* root) {
	if (root == NULL) return;
	if (root->data.Mau == 1) {
		cout << root->data.Tu << " ";
	}
	else {
		cout << root->data.Tu << "/" << root->data.Mau << " ";
	}
	TraverseNLRFrct(root->Left);
	TraverseNLRFrct(root->Right);
}
void TraverseNRLFrct(TreeNodeFrct* root) {
	if (root == NULL) return;
	if (root->data.Mau == 1) {
		cout << root->data.Tu << " ";
	}
	else {
		cout << root->data.Tu << "/" << root->data.Mau << " ";
	}
	TraverseNRLFrct(root->Right);
	TraverseNRLFrct(root->Left);
}
//tim kiem 1 phan tu
TreeNodeFrct* FindTreeNodeFrct(TreeNodeFrct* root, Fraction x) {
	if (root == NULL) return NULL;
	if (FractionValue(x) == FractionValue(root->data)) return root;
	if (FractionValue(x) < FractionValue(root->data)) {
		FindTreeNodeFrct(root->Left, x);
	}
	else if (FractionValue(x) > FractionValue(root->data)) {
		FindTreeNodeFrct(root->Right, x);
	}
}