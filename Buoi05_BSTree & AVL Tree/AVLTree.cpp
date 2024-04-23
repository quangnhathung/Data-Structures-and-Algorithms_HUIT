//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include "AVLTree.h"
using namespace std;
//Do thoi gian hoc ly thuyet ngan,nen thay chi day thuaatj toan
// vi vay em khong hieu code trong sach(phan BalFactor) nen em danh hoc tu been ngoai
// em xin loi vi dieu nay a!

//khoi tao 
AVLNode* CreateAVLNode(int x) {
	AVLNode* p = new AVLNode;
	if (p == NULL) return NULL;
	p->Data = x;
	p->Height = 0;
	p->Left = p->Right = NULL;
	return p;
}
void Init_AVLTree(AVLTree& tr) {
	tr.Root = NULL;
}
//theem phan tu vao danh sach 
//Ham tinh chieu cao
int Height(AVLNode* root) {
	if (root == NULL) return 0;
	return 1 + Max(Height(root->Left), Height(root->Right));
}
//ham xoay
//xoay trai khi bi lech phai
void RotateLeft(AVLNode*& root) {
	AVLNode* t = root->Right;
	root->Right = t->Left;
	t->Left = root;
	root->Height = 1 + Max(Height(root->Left), Height(root->Right));
	t->Height = 1 + Max(Height(t->Left), Height(t->Right));
	root = t;

}

//xoay phai khi lech trai
void RotateRight(AVLNode*& root) {
	AVLNode* t = root->Left;
	root->Left = t->Right;
	t->Right = root;
	//set lai chieu cao
	root->Height = 1 + Max(Height(root->Left), Height(root->Right));
	t->Height = 1 + Max(Height(t->Left), Height(t->Right));
	root = t;//gan dia chi cua t cho root, lam thay doi root
}
//ham them nut vao caay avl
void Add_AvlTree(AVLNode*& root, AVLNode* p) {
	if (p == NULL) return;
	//phan them doan dau cung giong nhuw them cay nhi phan
	if (root == NULL) {
		p->Height = 1;//dat chieu cao cho nut them vao bnag 1
		root = p;
		return;
	}
	if (p->Data < root->Data) {
		Add_AvlTree(root->Left, p);
	}
	else if (p->Data > root->Data) {
		Add_AvlTree(root->Right, p);
	}
	else return;//bang thi dung lai, vi gia tri trong cay nhi phan tiem kiem khong ddc trung nhau
	//sau khi theem, ham de quy se chay nguoc len deer setup lai cac gia tri
	//chieu cao
	root->Height = 1 + Max(Height(root->Left), Height(root->Right));
	//kiem tra can bang 
	int valbalance = Height(root->Left) - Height(root->Right);
	//>1 leech tra, <-1, lech phai
	//kiem tra cac truong hop mat can ban
	//TH1:LL: lech trai->xoay phai
	if (valbalance > 1 && p->Data < root->Left->Data) {
		RotateRight(root);
		return;
	}
	//TH2:RR lech phai xoay trai
	if (valbalance < -1 && p->Data > root->Right->Data) {
		RotateLeft(root);
		return;
	}
	//TH3:LR: xoay trai => xoay phai

	if (valbalance > 1 && p->Data > root->Left->Data) {
		RotateLeft(root->Left);
		RotateRight(root);
		return;
	}
	if (valbalance < -1 && p->Data < root->Right->Data) {
		RotateRight(root->Right);
		RotateLeft(root);
		return;
	}
	return;
}
//xoa
int ValBalance(AVLNode* root) {
	return Height(root->Left) - Height(root->Right);
}
AVLNode* FindAvlNodeReplace(AVLNode* root) {
	AVLNode* p = root->Left;
	while (p->Right != NULL) {
		p = p->Right;
	}
	return p;
}
void Dlt_AvlNode(AVLNode*& root, int x) {
	if (root == NULL) return;
	if (x < root->Data) {
		Dlt_AvlNode(root->Left, x);
	}
	else if (x > root->Data) {
		Dlt_AvlNode(root->Right, x);
	}
	else {
		//th la nut la
		if (root->Left == NULL && root->Right == NULL) {
			AVLNode* t = root;
			root = NULL;
			delete t;
		}
		//truowng hop la nut co 1 con
		else if (root->Left == NULL) {
			AVLNode* t = root;
			root = root->Right;
			delete t;
		}
		else if (root->Right == NULL) {
			AVLNode* t = root;
			root = root->Left;
			delete t;
		}
		//truowng hop la nut co 2 con
		else if (root->Left != NULL && root->Right != NULL) {
			AVLNode* t = FindAvlNodeReplace(root);
			root->Data = t->Data;
			Dlt_AvlNode(root->Left, t->Data);
		}
		return;
	}
	//setup thong tin
	root->Height = 1 + Max(Height(root->Left), Height(root->Right));
	int valbalance = Height(root->Left) - Height(root->Right);
	//cac truong hop mat can bang cay
	//th lech trai
	if (valbalance > 1 && ValBalance(root->Left) >= 0) {//ll
		RotateRight(root);
		return;
	}
	if (valbalance > 1 && ValBalance(root->Left) < 0) {//lr
		RotateLeft(root->Left);
		RotateRight(root);
		return;
	}
	//th lech phai
	if (valbalance < -1 && ValBalance(root->Right) <= 0) {//rr
		RotateLeft(root);
		return;
	}
	if (valbalance < -1 && ValBalance(root->Right) > 0) {//rl
		RotateRight(root->Right);
		RotateLeft(root);
		return;
	}
}
//xoa cay thi khoi can bang
void Dlt_AvlTree(AVLNode*& root) {
	if (root == NULL) return;
	Dlt_AvlTree(root->Left);
	Dlt_AvlTree(root->Right);
	if (root->Left == NULL && root->Right == NULL) {//gap toi nut la
		AVLNode* t = root;
		root = NULL;
		delete t;
		return;
	}
	return;
}
//duyet cay NLR
void TraverseAVLtree_NLR(AVLNode* root) {
	if (root == NULL) return;
	cout << root->Data << " ";
	TraverseAVLtree_NLR(root->Left);
	TraverseAVLtree_NLR(root->Right);
}
//tim kiem cay
AVLNode* FindAvlNode(AVLNode* root, int x) {
	if (root == NULL) return NULL;
	if (x < root->Data) {
		FindAvlNode(root->Left,x);
	}
	if (x > root->Data) {
		FindAvlNode(root->Right, x);
	}
	if (x == root->Data) return root;
}