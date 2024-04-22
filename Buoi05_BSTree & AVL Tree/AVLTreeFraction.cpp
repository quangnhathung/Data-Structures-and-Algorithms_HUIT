#include"AVLtreeFrct.h"
using namespace std;

//khoi tao
void InitAVLTreeFrct(AvlTreeFrct& tr) {
	tr.Root = NULL;
}
AvlNodeFrct* CreateAVLNodeFrct(Fraction x) {
	AvlNodeFrct* p = new AvlNodeFrct;
	p->data = x;
	p->Height = 0;
	p->Left = p->Right = NULL;
	return p;
}
//cac phep xoay cay

int Height(AvlNodeFrct* root) {
	if (root == NULL) return 0;
	return 1 + Max(Height(root->Left), Height(root->Right));
}
//xoay phai khi lech trai
void RotateRightFrct(AvlNodeFrct*& root) {
	AvlNodeFrct* t = root->Left;
	root->Left = t->Right;
	t->Right = root;
	root->Height = 1 + Max(Height(root->Left), Height(root->Right));
	t->Height = 1 + Max(Height(t->Left), Height(t->Right));
	root = t;
}
//xoay trai khi lech phai
void RotateLeftFrct(AvlNodeFrct*& root) {
	AvlNodeFrct* t = root->Right;
	root->Right = t->Left;
	t->Left = root;
	root->Height = 1 + Max(Height(root->Left), Height(root->Right));
	t->Height = 1 + Max(Height(t->Left), Height(t->Right));
	root = t;
}
//them phan tu vao cay
void Add_AvlTreeFrct(AvlNodeFrct*& root, AvlNodeFrct* p) {
	if (p == NULL) {
		return;
	}
	if (root == NULL) {
		p->Height = 1;
		root = p;
		return;
	}
	else if (FractionValue(p->data) < FractionValue(root->data)) {
		Add_AvlTreeFrct(root->Left, p);
	}
	else if (FractionValue(p->data) > FractionValue(root->data)) {
		Add_AvlTreeFrct(root->Right, p);
	}
	else return;
	//setup
	root->Height = 1 + Max(Height(root->Left), Height(root->Right));
	int valbalane = Height(root->Left) - Height(root->Right);
	//cac truong hop mmat can bang
	//case LL
	if (valbalane > 1 && FractionValue(p->data) < FractionValue(root->Left->data)) {
		RotateRightFrct(root);
		return;
	}
	//case rr
	if (valbalane < -1 && FractionValue(p->data) > FractionValue(root->Right->data)) {
		RotateLeftFrct(root);
		return;
	}
	//case Lr
	if (valbalane > 1 && FractionValue(p->data) > FractionValue(root->Left->data)) {
		RotateLeftFrct(root->Left);
		RotateRightFrct(root);
		return;
	}
	//case rl
	if (valbalane < -1 && FractionValue(p->data) < FractionValue(root->Right->data)) {
		RotateRightFrct(root->Right);
		RotateLeftFrct(root);
		return;
	}
	return;
}
//xoa
AvlNodeFrct* FindAvlNodeFrctReplace(AvlNodeFrct* root) {
	AvlNodeFrct* p = root->Left;
	while (p->Right != NULL) {
		p = p->Right;
	}
	return p;
}
int valbalence(AvlNodeFrct* root) {
	return Height(root->Left) - Height(root->Right);
}
void Dlt_AvlNodeFrct(AvlNodeFrct*& root, Fraction x) {
	if (root == NULL) return;
	if (FractionValue(x) < FractionValue(root->data)) {
		Dlt_AvlNodeFrct(root->Left,x);
	}
	else if (FractionValue(x) > FractionValue(root->data)) {
		Dlt_AvlNodeFrct(root->Right, x);
	}
	else{//timthay
		//case 1: la nut la
		if (root->Left == NULL && root->Right == NULL) {
			AvlNodeFrct* t = root;
			root = NULL;
			delete t;
		}
		//case 2: la nut co 1 con
		else if (root->Right == NULL) {
			AvlNodeFrct* t = root;
			root = root->Left;
			delete t;
		}
		else if (root->Left == NULL) {
			AvlNodeFrct* t = root;
			root = root->Right;
			delete t;
		}
		//truong hop co 2 con
		else if (root->Left != NULL && root->Right != NULL) {
			AvlNodeFrct* t = FindAvlNodeFrctReplace(root);
			root->data = t->data;
			Dlt_AvlNodeFrct(root->Left, t->data);
		}
		return;
	}
	//setup
	root->Height = 1 + Max(Height(root->Left), Height(root->Right));
	int valbalane = Height(root->Left) - Height(root->Right);
	//cac truong hop mat can bang
	//cay lech trai
	if (valbalane>1&& valbalence(root->Left)>=0){//ll
		RotateRightFrct(root);
		return;
	}
	if (valbalane > 1 && valbalence(root->Left) < 0){//lr
		RotateLeftFrct(root->Left);
		RotateRightFrct(root);
		return;
	}//lech pahi
	if (valbalane < -1 && valbalence(root->Right) >= 0) {//rr
		RotateLeftFrct(root);
		return;
	}
	if (valbalane < -1 && valbalence(root->Right) < 0) {//rl
		RotateRightFrct(root->Right);
		RotateLeftFrct(root);
		return;
	}
	return;
}
//duuyet cay
void TraverseLNRFrctAVL(AvlNodeFrct* root) {
	if (root == NULL) return;
	TraverseLNRFrctAVL(root->Left);
	if (root->data.Mau == 1) {
		cout << root->data.Tu << " ";
	}
	else {
		cout << root->data.Tu << "/" << root->data.Mau << " ";
	}
	TraverseLNRFrctAVL(root->Right);
}
void TraverseRNLFrctAVL(AvlNodeFrct* root) {
	if (root == NULL) return;
	TraverseRNLFrctAVL(root->Right);
	if (root->data.Mau == 1) {
		cout << root->data.Tu << " ";
	}
	else {
		cout << root->data.Tu << "/" << root->data.Mau << " ";
	}
	TraverseRNLFrctAVL(root->Left);
}
void TraverseLRNFrctAVL(AvlNodeFrct* root) {
	if (root == NULL) return;
	TraverseLRNFrctAVL(root->Left);
	TraverseLRNFrctAVL(root->Right);
	if (root->data.Mau == 1) {
		cout << root->data.Tu << " ";
	}
	else {
		cout << root->data.Tu << "/" << root->data.Mau << " ";
	}
}
void TraverseRLNFrctAVL(AvlNodeFrct* root) {
	if (root == NULL) return;
	TraverseRLNFrctAVL(root->Right);
	TraverseRLNFrctAVL(root->Left);
	if (root->data.Mau == 1) {
		cout << root->data.Tu << " ";
	}
	else {
		cout << root->data.Tu << "/" << root->data.Mau << " ";
	}
}
void TraverseNLRFrctAVL(AvlNodeFrct* root) {
	if (root == NULL) return;
	if (root->data.Mau == 1) {
		cout << root->data.Tu << " ";
	}
	else {
		cout << root->data.Tu << "/" << root->data.Mau << " ";
	}
	TraverseNLRFrctAVL(root->Left);
	TraverseNLRFrctAVL(root->Right);
}
void TraverseNRLFrctAVL(AvlNodeFrct* root) {
	if (root == NULL) return;
	if (root->data.Mau == 1) {
		cout << root->data.Tu << " ";
	}
	else {
		cout << root->data.Tu << "/" << root->data.Mau << " ";
	}
	TraverseNRLFrctAVL(root->Right);
	TraverseNRLFrctAVL(root->Left);
}
//format laij cay
void FormatAVLTree(AvlNodeFrct* &root) {
	if (root == NULL) return;
	format(root->data.Tu, root->data.Mau);
	FormatAVLTree(root->Right);
	FormatAVLTree(root->Left);
	return;
}
//dem so luong phan so lon hon 1 
int CountFractionAvlTree(AvlNodeFrct* root) {
	if (root == NULL) return 0;
	if (FractionValue(root->data) > 1) {
		return 1 + CountFractionAvlTree(root->Left) + CountFractionAvlTree(root->Right);
	}
	else return 0 +CountFractionAvlTree(root->Left) + CountFractionAvlTree(root->Right);
}
//xoa toan bo cay
void Dlt_avlTree(AvlNodeFrct* &root) {
	if (root == NULL) return;
	Dlt_avlTree(root->Left);
	Dlt_avlTree(root->Right);
	AvlNodeFrct* t = root;
	root = NULL;
	delete t;
}
//liet ke nut co mau bang mau phan so x
void Listed(AvlNodeFrct* root, int x) {
	if (root == NULL) return;
	if (root->data.Mau == x) {
		if (root->data.Mau == 1) {
			cout << root->data.Tu << " ";
		}
		else {
			cout << root->data.Tu << "/" << root->data.Mau << " ";
		}
	}
	else {

	}
	Listed(root->Right,x);
	Listed(root->Left,x);
}