//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include "Binarysearchtreewithint.h"
#include "ASCIInode.h"
#include "input.h"
#include<stack>
using namespace std;
//LNR
void TraverseLNR_WithoutRecursion(TreeNode* root) {
	stack<TreeNode*> st;
	if (root == NULL) return;
	TreeNode* p = root;
	while (1) {
		while (p != NULL) {
			st.push(p);
			p = p->Left;
		}
		if (!st.empty()) {
			TreeNode* t = st.top();
			if (t->Right == NULL) {
				cout << t->data << " ";
				st.pop();
			}
			else {
				p = t->Right;
				cout << t->data << " ";
				st.pop();
			}
		}
		else {
			break;
		}
	}
}
//RNL
void TraverseRNL_WithoutRecursion(TreeNode* root) {
	if (root == NULL) return;
	stack<TreeNode*> st;
	TreeNode* p = root;
	while (1) {
		while (p != NULL) {
			st.push(p);
			p = p->Right;
		}
		if (!st.empty()) {
			TreeNode* t = st.top();
			if (t->Left == NULL) {
				cout << t->data << " ";
				st.pop();
			}
			else {
				cout << t->data << " ";
				p = t->Left;
				st.pop();
			}
		}
		else {
			break;//dung
		}
	}
}
//NLR
void TraverseNLR_WithoutRecursion(TreeNode* root) {
	if (root == NULL) return;
	stack<TreeNode*> st;
	TreeNode* p = root;
	while (1) {
		while (p != NULL) {
			cout << p->data << " ";
			st.push(p);
			p = p->Left;
		}
		if (!st.empty()) {
			TreeNode* t = st.top();
			if (t->Right == NULL) {
				st.pop();
			}
			else {
				p = t->Right;
				st.pop();
			}
		}
		else {
			break;
		}
	}
}
//NRL
void TraverseNRL_WithoutRecursion(TreeNode* root) {
	if (root == NULL) return;
	stack<TreeNode*> st;
	TreeNode* p = root;
	while (1) {
		while (p != NULL) {
			cout << p->data << " ";
			st.push(p);
			p = p->Right;
		}
		if (!st.empty()) {
			TreeNode* t = st.top();
			if (t->Left == NULL) {
				st.pop();
			}
			else {
				p = t->Left;
				st.pop();
			}
		}
		else {
			break;
		}
	}
}
//LRN
void TraverseLRN_WithoutRecursion(TreeNode* root) {
	if (root == NULL) return;
	stack<TreeNode*> st1, st2;
	TreeNode* p = root;
	st1.push(p);
	while (!st1.empty()) {
		st2.push(st1.top());
		st1.pop();
		if (st2.top()->Left != NULL) {
			st1.push(st2.top()->Left);
		}
		if (st2.top()->Right != NULL) {
			st1.push(st2.top()->Right);
		}
	}
	while (!st2.empty()) {
		cout << st2.top()->data << " ";
		st2.pop();
	}
}
void TraverseRLN_WithoutRecursion(TreeNode* root) {
	if (root == NULL) return;
	stack<TreeNode*> st1, st2;
	TreeNode* p = root;
	st1.push(p);
	while (!st1.empty()) {
		st2.push(st1.top());
		st1.pop();
		if (st2.top()->Right != NULL) {
			st1.push(st2.top()->Right);
		}
		if (st2.top()->Left != NULL) {
			st1.push(st2.top()->Left);
		}
	}
	while (!st2.empty()) {
		cout << st2.top()->data << " ";
		st2.pop();
	}
}
int main() {
	BinarySearchTree tr;
	Init_BinarySearchTree(tr);
	InputfromKeyboard(tr.Root);
	cout << endl;
	print_ascii_tree(tr.Root);
	cout << endl<<"TraverseRLN" << endl;
	TraverseRLN_WithoutRecursion(tr.Root);
	cout << endl << "TraverseLRN" << endl;
	TraverseLRN_WithoutRecursion(tr.Root);
	cout << endl << "TraverseRNL" << endl;
	TraverseRNL_WithoutRecursion(tr.Root);
	cout << endl << "TraverseLNR" << endl;
	TraverseLNR_WithoutRecursion(tr.Root);
	cout << endl << "TraverseNRL" << endl;
	TraverseNRL_WithoutRecursion(tr.Root);
	cout << endl << "TraverseNLR" << endl;
	TraverseNLR_WithoutRecursion(tr.Root);
	cout << endl;
	return 0;
}