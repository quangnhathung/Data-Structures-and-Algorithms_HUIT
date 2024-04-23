//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include"Dictionary.h"
//Do thoi gian hoc ly thuyet ngan,nen thay chi day thuaatj toan
// vi vay em khong hieu code trong sach(phan BalFactor) nen em danh hoc tu been ngoai
// em xin loi vi dieu nay a!

//khoi tao
AVLDictNode* CreateDictnode(Dictionary x) {
	AVLDictNode* t = new AVLDictNode;
	t->Height = 0;
	t->Left = t->Right = NULL;
	t->Data = x;
	return t;
}
AVLDictNode* CreateDictNode(Dictionary x) {
	AVLDictNode* p = new AVLDictNode;
	p->Data = x;
	p->Height = 0;
	p->Left = p->Right = NULL;
	return p;
}
void Init_Dictionary(AVLTreeDictionary& tr) {
	tr.Root = NULL;
}

int Height(AVLDictNode* root) {
	if (root == NULL) return 0;
	return 1 + Max(Height(root->Left), Height(root->Right));
}
//them phan tu
//xoay cay
//xoay trai khi lech phai
void RotateLeft(AVLDictNode*& root) {
	AVLDictNode* t = root->Right;
	root->Right = t->Left;
	t->Left = root;
	//setup chieu cao
	t->Height = 1 + Max(Height(t->Left), Height(t->Right));
	root->Height = 1 + Max(Height(root->Left), Height(root->Right));
	root = t;
}
//xoay phai khi lech trai
void RotateRight(AVLDictNode*& root) {
	AVLDictNode* t = root->Left;
	root->Left = t->Right;
	t->Right = root;
	//setup chieu cao
	t->Height = 1 + Max(Height(t->Left), Height(t->Right));
	root->Height = 1 + Max(Height(root->Left), Height(root->Right));
	root = t;
}
//them
void Add_Dictionary(AVLDictNode*& root, AVLDictNode* p) {
	if (root == NULL) {
		p->Height = 1;
		root = p;
		return;
	}
	if (p->Data.Vocabulary < root->Data.Vocabulary) {
		Add_Dictionary(root->Left, p);
	}
	else if (p->Data.Vocabulary > root->Data.Vocabulary) {
		Add_Dictionary(root->Right, p);
	}
	else return;//bang thi khong them
	//setup
	root->Height = 1 + Max(Height(root->Right), Height(root->Left));
	//xoay cay
	int valbalance = Height(root->Left) - Height(root->Right);
	//>1 lech phai, <-1 lech trai
	//cac truong hop mat can bang
	//lech trai
	if (valbalance > 1 && p->Data.Vocabulary < root->Left->Data.Vocabulary) {//ll
		RotateRight(root);
		return;
	}
	if (valbalance > 1 && p->Data.Vocabulary > root->Left->Data.Vocabulary) {//lr
		RotateLeft(root->Left);
		RotateRight(root);
		return;
	}
	//lech phai
	if (valbalance < -1 && p->Data.Vocabulary > root->Right->Data.Vocabulary) {//rr
		RotateLeft(root);
		return;
	}
	if (valbalance < -1 && p->Data.Vocabulary < root->Right->Data.Vocabulary) {//rl
		RotateRight(root->Right);
		RotateLeft(root);
		return;
	}
	return;
}
//input
void InputDictionary(AVLDictNode*& root) {
	ifstream file("Dictionary.txt");
	string s;
	while (getline(file, s)) {
		Dictionary x;
		stringstream ss(s);
		getline(ss, x.Vocabulary, '-');
		getline(ss, x.Meaning, '-');
		Add_Dictionary(root, CreateDictNode(x));
	}
	file.close();
	cout << "Done!" << endl;
	return;
}
//Nhap de in cay
void InputDictionaryDemo(AVLDictNode*& root) {
	ifstream file("DictionaryDemo.txt");
	string s;
	while (getline(file, s)) {
		Dictionary x;
		stringstream ss(s);
		getline(ss, x.Vocabulary, '-');
		getline(ss, x.Meaning, '-');
		Add_Dictionary(root, CreateDictNode(x));
	}
	file.close();
	cout << "Done!" << endl;
	return;
}
//LNR
void TraverseDct(AVLDictNode* root) {
	if (root == NULL) return;
	TraverseDct(root->Left);
	cout << root->Data.Vocabulary << " ";
	TraverseDct(root->Right);
}
int cntvcl(AVLDictNode* root) {
	if (root == NULL) return 0;
	return 1 + cntvcl(root->Left) + cntvcl(root->Right);
}
//kiemtra can bang
bool CheckBalance(AVLDictNode* root) {
	if (root == NULL) return true;
	if (abs(Height(root->Left) - Height(root->Right)) == 1 || abs(Height(root->Left) - Height(root->Right)) == 0 && CheckBalance(root->Left) && CheckBalance(root->Right)) {
		return true;
	}
	else return false;
	CheckBalance(root->Left);
	CheckBalance(root->Right);
}
//Cap nhat phan tu vao cay
void UpdateData(AVLDictNode*& root, string s) {
	stack<AVLDictNode*> st;
	if (root == NULL) return;
	AVLDictNode* p = root;
	ofstream file(s);
	//duyet cay khong de quy bang stack;
	while (1) {//duyet NLR
		while (p != NULL) {
			file << p->Data.Vocabulary + " - " << p->Data.Meaning << endl;
			st.push(p);
			p = p->Left;
		}
		if (!st.empty()) {
			AVLDictNode* t = st.top();
			if (t->Right == NULL) {
				st.pop();
			}
			else {
				p = t->Right;
				st.pop();
			}
		}
		else break;
	}
	file.close();
	return;
}
//xoa 1 phan tu
int Valbalance(AVLDictNode* root) {
	if (root == NULL) return 0;
	return Height(root->Left) - Height(root->Right);
}
AVLDictNode* FindDictNodeReplace(AVLDictNode* root) {
	AVLDictNode* t = root->Left;
	while (t->Right != NULL) {
		t = t->Right;
	}
	return t;
}
void Dlt_Vocabulary(AVLDictNode*& root, string s) {
	if (root == NULL) return;
	if (s < root->Data.Vocabulary) {
		Dlt_Vocabulary(root->Left, s);
	}
	else if (s > root->Data.Vocabulary) {
		Dlt_Vocabulary(root->Right, s);
	}
	else {
		//truong hop la nut la 
		if (root->Left == NULL && root->Right == NULL) {
			AVLDictNode* t = root;
			root = NULL;
			delete t;
		}
		//truong hop co 1 con
		else if (root->Left == NULL) {
			AVLDictNode* t = root;
			root = root->Right;
			delete t;
		}
		else if (root->Right == NULL) {
			AVLDictNode* t = root;
			root = root->Left;;
			delete t;
		}
		//truowng hop co 2 con
		else if (root->Left == NULL && root->Right == NULL) {
			AVLDictNode* t = FindDictNodeReplace(root);
			root->Data = t->Data;
			Dlt_Vocabulary(root->Left, t->Data.Vocabulary);
		}
		return;
	}
	//setup lai chi so
	root->Height = 1 + Max(Height(root->Left), Height(root->Right));
	int valbalance = Height(root->Left) - Height(root->Right);
	//cac truong hop mat can bang
	//lech trai
	if (valbalance > 1 && Valbalance(root->Left) >= 0) {//ll
		RotateRight(root);
		return;
	}
	if (valbalance > 1 && Valbalance(root->Left) < 0) {//lr
		RotateLeft(root->Left);
		RotateRight(root);
		return;
	}
	//lech phai
	if (valbalance < -1 && Valbalance(root->Right) <= 0) {//rr
		RotateRight(root);
		return;
	}
	if (valbalance < -1 && Valbalance(root->Right) > 0) {//rl
		RotateRight(root->Right);
		RotateLeft(root);
		return;
	}
	return;
}
//xoa toan bo cay
void Dlt_Dct(AVLDictNode*& root) {
	if (root == NULL) return;
	Dlt_Dct(root->Left);
	Dlt_Dct(root->Right);
	AVLDictNode* t = root;
	root = NULL;
	delete t;
	return;
}
//so sanh 2 xau
string upperstr(string s) {
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] >= 97 && s[i] <= 122) {
			s[i] -= 32;
		}
	}
	return s;
}
int CompareStr(string s1, string s2) {
	if (upperstr(s1) == upperstr(s2))  return 0;
	else if (upperstr(s1) < upperstr(s2)) return -1;
	else if (upperstr(s1) > upperstr(s2)) return 1;
}
AVLDictNode* Translate(AVLDictNode* root, string s) {
	if (root == NULL || CompareStr(s,root->Data.Vocabulary) == 0) return root;
	if (CompareStr(s,root->Data.Vocabulary) == -1)
		return Translate(root->Left, s);
	else
		return Translate(root->Right, s);
}