//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include "BSTwithChar.h"
using namespace std;
int CheckStringValid(string s) {
	stack<char> st;
	for (size_t i = 0; i < s.length(); i++) {
		if (st.empty() && s[i] == ')') return 0;
		if (s[i] == '(') {
			st.push(s[i]);
		}
		if (s[i] == ')') {
			if (st.top() == '(') {
				st.pop();
			}
			else {
				return 0;
			}
		}
	}
	if (!st.empty()) return 0;
	return 1;
}
int Uutien(char c) {
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
	if (c == '^') return 3;
	return 0;
}
bool IsOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') return true;
	return false;
}
string InfixtoPostfix(string s) {
	if (CheckStringValid(s) == 0) return s;
	stack<char> st;
	string postfix;
	for (size_t i = 0; i < s.length(); i++) {
		if (isalnum(s[i])) {
			postfix += s[i];
		}
		else if (s[i] == '(') {
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			while (!st.empty() && st.top() != '(') {
				postfix += st.top();
				st.pop();
			}
			st.pop();
		}
		else if (IsOperator(s[i])) {
			while (!st.empty() && Uutien(st.top()) >= Uutien(s[i])) {
				postfix += st.top();
				st.pop();
			}
			st.push(s[i]);
		}

	}
	while (!st.empty()) {
		postfix += st.top();
		st.pop();
	}
	return postfix;
}
void Init_BinarySearchTreeChar(BinarySearchTreeChar& tr) {
	tr.Root = NULL;
}
TreeNodeChar* CreateTreeNodeChar(char x) {
	TreeNodeChar* p = new TreeNodeChar;
	p->Data = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}
bool IsEmptyChar(BinarySearchTreeChar tr) {
	if (tr.Root == NULL) return true;
	return false;
}
void Add_TreeChar(TreeNodeChar*& root,string s) {
	string postfix = InfixtoPostfix(s);
	stack<TreeNodeChar*> st;
	if (postfix == s) {
		cout << "Bieu thuc khong hop le";
		return;
	}
	for (size_t i = 0; i < postfix.length(); i++) {
		if (isalnum(postfix[i])) {
			TreeNodeChar* t = CreateTreeNodeChar(postfix[i]);
			st.push(t);
		}
		else if (IsOperator(postfix[i])) {
			TreeNodeChar* t1 = st.top();
			st.pop();
			TreeNodeChar* t2 = st.top();
			st.pop();
			TreeNodeChar* t3=CreateTreeNodeChar(postfix[i]);
			t3->Left = t2;
			t3->Right = t1;
			st.push(t3);
		}
	}
	root = st.top();
	return;
}
//xoa 1 phan tu x
TreeNodeChar* FindNodeReplaceChar(TreeNodeChar* root) {
	TreeNodeChar* p = root->Left;
	//chon phan tu phai nhat cua caa ben trai
	while (1) {
		p = p->Right;
		if (p->Right == NULL) return p;
	}
}
int Dlt_TreeNodeChar(TreeNodeChar*& root, int x) {
	if (root == NULL) {
		return 0;
	}
	if (x < root->Data) {
		Dlt_TreeNodeChar(root->Left, x);
	}
	else if (x > root->Data) {
		Dlt_TreeNodeChar(root->Right, x);
	}
	else if (x == root->Data) {//tim thay x
		//case 1: x la nut la:
		if (root->Left == NULL && root->Right == NULL) {
			TreeNodeChar* temp = root;
			root = NULL;
			delete temp;
		}
		//case 2: nut cha co 1 con
		else if (root->Left == NULL) {
			TreeNodeChar* temp = root;
			root = root->Right;
			delete temp;
		}
		else if (root->Right == NULL) {
			TreeNodeChar* temp = root;
			root = root->Left;
			delete temp;
		}//case 3: co 2 con
		else if (root->Right != NULL && root->Left) {
			TreeNodeChar* t = FindNodeReplaceChar(root);
			root->Data = t->Data;
			Dlt_TreeNodeChar(root->Left, t->Data);
		}
		return 1;//thuc hien thanh cong
	}
	return 0; //Khong tim thay phan tu x
}
//6 phep duyet cay
void TraverseLNRChar(TreeNodeChar* root) {
	if (root == NULL) return;
	TraverseLNRChar(root->Left);
	cout << root->Data << " ";
	TraverseLNRChar(root->Right);
}
void TraverseRNLChar(TreeNodeChar* root) {
	if (root == NULL) return;
	TraverseRNLChar(root->Right);
	cout << root->Data << " ";
	TraverseRNLChar(root->Left);
}
void TraverseLRNChar(TreeNodeChar* root) {
	if (root == NULL) return;
	TraverseLRNChar(root->Left);
	TraverseLRNChar(root->Right);
	cout << root->Data << " ";
}
void TraverseRLNChar(TreeNodeChar* root) {
	if (root == NULL) return;
	TraverseRLNChar(root->Right);
	TraverseRLNChar(root->Left);
	cout << root->Data << " ";
}
void TraverseNLRChar(TreeNodeChar* root) {
	if (root == NULL) return;
	cout << root->Data << " ";
	TraverseNLRChar(root->Left);
	TraverseNLRChar(root->Right);
}
void TraverseNRLChar(TreeNodeChar* root) {
	if (root == NULL) return;
	cout << root->Data << " ";
	TraverseNRLChar(root->Right);
	TraverseNRLChar(root->Left);
}
//tim kiem 1 phan tu
TreeNodeChar* FindTreeNodeChar(TreeNodeChar* root, int x) {
	if (root == NULL) return NULL;
	if (root->Data == x) return root;
	if (x < root->Data) {
		FindTreeNodeChar(root->Left, x);
	}
	else if (x > root->Data) {
		FindTreeNodeChar(root->Right, x);
	}
}