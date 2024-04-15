//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include"BSTwithChar.h"
#include<stack>
#include<string>
#include<cctype>
#include "ASCIInode.h"
using namespace std;
float Pheptoan(char c, float a, float b) {
	if (!IsOperator(c)) {
		cerr << "Loi!!" << endl;
		return -1;
	}
	switch (c) {
	case '+': {
		return a + b;
	}
	case '-': {
		return a - b;
	}
	case '*': {
		return a * b;
	}
	case '/': {
		return (float)a / b;
	}
	case '^': {
		return (float)pow((double)a, b);
	}
	}
	return 0;
}
float SolvePostfix(string Postfix) {
	//Stack de luu ket qua
	//Tao Stack moi luu float lam roi
	stack<float> ketqua;
	for (size_t i = 0; i < Postfix.size(); i++) {
		if (isalnum(Postfix[i])) {

			ketqua.push((float)Postfix[i] - '0');
		}
		if (IsOperator(Postfix[i])) {
			float x, y;
			x = ketqua.top();
			ketqua.pop();
			y = ketqua.top();
			ketqua.pop();
			float Kq = Pheptoan(Postfix[i], y, x);
			ketqua.push(Kq);
		}
	}
	return ketqua.top();
}
//Tu cay bieu thuc duyet LRN ddeer ra postfix
string Postfix(TreeNodeChar* root) {
	if (root == NULL) return "";//tra ve chuoi rong 
	return Postfix(root->Left) + Postfix(root->Right) + root->Data;
	//c++ cong thang chuoi vao voi nhau
}
float CalculateExpressiontree(TreeNodeChar* root) {
	string postfix=Postfix(root);
	return SolvePostfix(postfix);
}
int main() {
	string s;
	BinarySearchTreeChar tr;
	Init_BinarySearchTreeChar(tr);
	cout << "Nhap bieu thuc muon them vao cay: ";
	getline(cin, s);
	cout << endl;
	Add_TreeChar(tr.Root, s);
	print_ascii_treeChar(tr.Root);
	cout << "Ket qua cua cay nhi phan la: "<<CalculateExpressiontree(tr.Root);
	return 0;
}