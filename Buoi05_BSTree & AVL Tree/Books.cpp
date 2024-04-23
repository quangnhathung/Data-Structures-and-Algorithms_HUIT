//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include"Books.h"
using namespace std;
//Do thoi gian hoc ly thuyet ngan,nen thay chi day thuaatj toan
// vi vay em khong hieu code trong sach(phan BalFactor) nen em danh hoc tu been ngoai
// em xin loi vi dieu nay a!

//khoi tao
void InitBooks_AVL(BookAvlTree& tr) {
	tr.root = NULL;
}
AVLBOOK* CreateNodeBook(Book x) {
	AVLBOOK* p = new AVLBOOK;
	p->Data = x;
	p->Height = 0;
	p->Left = p->Right = NULL;
	return p;
}
int Height(AVLBOOK* root) {
	if (root == NULL) return 0;
	return 1 + Max(Height(root->Left), Height(root->Right));
}
//xoay cay
//xoay trai khi lech phai
void RotateLeftBook(AVLBOOK*& root) {
	AVLBOOK* t = root->Right;
	root->Right = t->Left;
	t->Left = root;
	//setup lai chieu cao
	root->Height = 1 + Max(Height(root->Left), Height(root->Right));
	t->Height = 1 + Max(Height(t->Left), Height(t->Right));
	root = t;
}
//xoay phai khi lech trai
void RotateRightBook(AVLBOOK*& root) {
	AVLBOOK* t = root->Left;
	root->Left = t->Right;
	t->Right = root;
	root->Height = 1 + Max(Height(root->Left), Height(root->Right));
	t->Height = 1 + Max(Height(t->Left), Height(t->Right));
	root = t;
}
//them
void Add_AVLbookTree(AVLBOOK*& root, AVLBOOK* p) {
	if (root == NULL) {
		p->Height = 1;
		root = p;
		return;
	}
	if (p->Data.Tensach < root->Data.Tensach) {
		Add_AVLbookTree(root->Left, p);
	}
	else if (p->Data.Tensach > root->Data.Tensach) {
		Add_AVLbookTree(root->Right, p);
	}
	else return;
	//setup
	root->Height = 1 + Max(Height(root->Left), Height(root->Right));
	//gia tri can bang
	int valbalance = Height(root->Left) - Height(root->Right);
	//cac truong hop mat can bang
	//lech trai
	if (valbalance > 1 && p->Data.Tensach < root->Left->Data.Tensach) {//ll
		RotateRightBook(root);
		return;
	}
	if (valbalance > 1 && p->Data.Tensach > root->Left->Data.Tensach) {//lr
		RotateLeftBook(root->Left);
		RotateRightBook(root);
		return;
	}
	//lechpahi
	if (valbalance < -1 && p->Data.Tensach > root->Right->Data.Tensach) {//rr
		RotateLeftBook(root);
		return;
	}
	if (valbalance < -1 && p->Data.Tensach < root->Right->Data.Tensach) {//rl
		RotateRightBook(root->Right);
		RotateLeftBook(root);
		return;
	}
	return;
}
//xoa theo ma sach 
AVLBOOK* FindNodeAvlBookReplace(AVLBOOK* root) {
	AVLBOOK* p = root->Left;
	while (p->Right != NULL) {
		p = p->Right;
	}
	return p;
}
int Valbanlance(AVLBOOK* root) {
	return Height(root->Left) - Height(root->Right);
}
void Dlt_AVLbook(AVLBOOK*& root, string s) {
	if (root == NULL) return;
	if (root->Data.Masach < s) {
		Dlt_AVLbook(root->Left, s);
	}
	else if (root->Data.Masach > s) {
		Dlt_AVLbook(root->Right, s);
	}
	else {//tim thay
		//thuowng hop la nut la 
		if (root->Left != NULL && root->Right != NULL) {
			AVLBOOK* t = root;
			root = NULL;
			delete t;
		}
		//truong hop la nut co 1 con
		else if (root->Left == NULL) {
			AVLBOOK* t = root;
			root == root->Right;
			delete t;
		}
		else if (root->Right == NULL) {
			AVLBOOK* t = root;
			root == root->Left;
			delete t;
		}
		//trohn hop co hai con
		else if (root->Left != NULL && root->Right == NULL) {
			AVLBOOK* t = FindNodeAvlBookReplace(root);
			root->Data = t->Data;
			Dlt_AVLbook(root->Left, t->Data.Masach);
		}
		return;
	}
	//setup
	root->Height = 1 + Max(Height(root->Left), Height(root->Right));
	//gia tri can bang
	int valbalance = Height(root->Left) - Height(root->Right);
	//cac truong hop mat can bang
	//lech trai
	if (valbalance > 1 && Valbanlance(root->Left) >= 0) {
		//ll
		RotateRightBook(root);
		return;
	}
	if (valbalance > 1 && Valbanlance(root->Left) < 0) {
		//lr
		RotateLeftBook(root->Left);
		RotateRightBook(root);
		return;
	}
	if (valbalance < -1 && Valbanlance(root->Right) >= 0) {
		//rr
		RotateLeftBook(root);
		return;
	}
	if (valbalance < -1 && Valbanlance(root->Right) < 0) {
		//rl
		RotateRightBook(root->Right);
		RotateLeftBook(root);
		return;
	}
	return;
}
//xoa toan bo cay
void Dlt_Books(AVLBOOK*& root) {
	if (root == NULL) return;
	Dlt_Books(root->Left);
	Dlt_Books(root->Right);
	AVLBOOK* t = root;
	root = NULL;
	delete t;
	return;
}
//input
void InputTree(AVLBOOK*& root) {
	ifstream file("Input02.txt");
	string s;
	while (getline(file, s)) {
		Book x;
		stringstream ss(s);
		getline(ss, x.Masach, ',');
		getline(ss, x.Tensach, ',');
		ss >> x.Xuatban;
		ss.ignore();
		Add_AVLbookTree(root, CreateNodeBook(x));
	}
	file.close();
	cout << "Done!" << endl;
	return;
}
//6 phep duyet cay
void TraverseLNRBooks(AVLBOOK* root) {
	if (root == NULL) return;
	TraverseLNRBooks(root->Left);
	cout << root->Data.Tensach << " " << endl;
	TraverseLNRBooks(root->Right);
}
void TraverseRNLBooks(AVLBOOK* root) {
	if (root == NULL) return;
	TraverseRNLBooks(root->Right);
	cout << root->Data.Tensach << " " << endl;
	TraverseRNLBooks(root->Left);
}
void TraverseLRNBooks(AVLBOOK* root) {
	if (root == NULL) return;
	TraverseLRNBooks(root->Left);
	TraverseLRNBooks(root->Right);
	cout << root->Data.Tensach << " " << endl;
}
void TraverseRLNBooks(AVLBOOK* root) {
	if (root == NULL) return;
	TraverseRLNBooks(root->Right);
	TraverseRLNBooks(root->Left);
	cout << root->Data.Tensach << " " << endl;
}
void TraverseNLRBooks(AVLBOOK* root) {
	if (root == NULL) return;
	cout << root->Data.Tensach << " " << endl;
	TraverseNLRBooks(root->Left);
	TraverseNLRBooks(root->Right);
}
void TraverseNRLBooks(AVLBOOK* root) {
	if (root == NULL) return;
	cout << root->Data.Tensach << " " << endl;
	TraverseNRLBooks(root->Right);
	TraverseNRLBooks(root->Left);
}
int cnt(AVLBOOK* root, int n) {
	if (root == NULL) {
		return 0;
	}
	if (root->Data.Xuatban == n) {
		return 1 + cnt(root->Left, n) + cnt(root->Right, n);
	}
	else return 0 + cnt(root->Left, n) + cnt(root->Right, n);
}