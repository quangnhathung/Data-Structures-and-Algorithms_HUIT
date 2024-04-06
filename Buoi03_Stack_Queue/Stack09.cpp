//Link github: https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string>
#include<cctype>
#include<stack>
using namespace std;
//Tao Cau truc
struct StackNode {
	char Data;
	StackNode* Next;
};
struct Stack {
	StackNode* Head;
	StackNode* Tail;
};
//ham
void Init_Stack(Stack& sl) {
	sl.Head = sl.Tail = NULL;
}
bool IsEmpty(Stack sl) {
	if (sl.Head == NULL) return true;
	return false;
}
//Tao node
StackNode* CreaateSNode(char x) {
	StackNode* p = new StackNode;
	p->Data = x;
	p->Next = NULL;
	return p;
}
//Them Node
void push(Stack& sl, StackNode* p) {
	if (IsEmpty(sl)) {
		sl.Head = sl.Tail = p;
		return;
	}
	p->Next = sl.Head;
	sl.Head = p;
	return;
}
void pop(Stack& sl) {
	if (sl.Head == NULL) return;
	if (sl.Head == sl.Tail) {
		StackNode* p = sl.Head;
		Init_Stack(sl);
		delete p;
		return;
	}
	StackNode* p = sl.Head;
	sl.Head = p->Next;
	delete p;
}
char top(Stack sl) {
	return sl.Head->Data;
}
void ShowStack(Stack sl) {
	StackNode* p = sl.Head; {
		while (p != NULL) {
			cout << p->Data << endl;
			p = p->Next;
		}
	}

}
int Checkstring(string s) {
	Stack st;
	Init_Stack(st);
	for (size_t i = 0; i < s.size(); i++) {
		if (IsEmpty(st) && (s[i] == ')' || s[i] == '}' || s[i] == ']')) return 0;
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			push(st, CreaateSNode(s[i]));
		}
		if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
			if (s[i] == ')') {
				if (top(st) == '(') {
					pop(st);
				}
				else
				{
					return 0;
				}
			}
			if (s[i] == '}') {
				if (top(st) == '{') {
					pop(st);
				}
				else
				{
					return 0;
				}
			}
			if (s[i] == ']') {
				if (top(st) == '[') {
					pop(st);
				}
				else
				{
					return 0;
				}
			}
		}

	}
	if (!IsEmpty(st)) return 0;
	return 1;
}
bool IsOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
		return true;
	}
	return false;
}
int Uutien(char c) {
	if (c == '+' || c == '-') {
		return 1;
	}
	if (c == '*' || c == '/') {
		return 2;
	}
	if (c == '^') {
		return 3;
	}
	return 0;
}
string InfixToPostfix(string s) {
	Stack st;
	Init_Stack(st);
	if (Checkstring(s) == 0) {
		return s;//xau loi
	}
	string Postfix;
	for (size_t i = 0; i < s.size(); i++) {
		if (isalnum(s[i])) {//la toan hang
			Postfix += s[i];
		}
		//dau mo ngoac
		else if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
			push(st, CreaateSNode(s[i]));
		}
		//dau dong ngoac
		else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
			while (!IsEmpty(st) && top(st) != '{' && top(st) != '[' && top(st) != '(') {
				Postfix += top(st);
				pop(st);
			}
			pop(st);//xoa ngoac
		}
		else if (IsOperator(s[i])) {
			while (!IsEmpty(st) && Uutien(top(st)) >= Uutien(s[i])) {
				//top(st) chua chac la toan tu
				Postfix += top(st);
				pop(st);
			}
			push(st, CreaateSNode(s[i]));
		}
	}
	while (!IsEmpty(st)) {
		Postfix += top(st);
		pop(st);
	}
	return Postfix;
}
float Pheptoan(char c, float a, float b) {
	if (!IsOperator(c)) {
		cerr << "Loi!!"<<endl;
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
		return pow((double)a, b);
	}
	}
}
float SolvePostfix(string Postfix) {
	//stack de luu ket qua
	//Tao stack moi luu float lam roi
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
			float Kq=Pheptoan(Postfix[i],y,x);
			ketqua.push(Kq);
		}
	}
	return ketqua.top();
}
int main() {
	string s;
	getline(cin, s);
	cout << "Postfix: " << InfixToPostfix(s) << "= " << SolvePostfix(InfixToPostfix(s));
	return 0;
}