//Link github: https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<string>
#include<cctype>
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
StackNode* CreaateStackNode(char x) {
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
bool IsOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') return true;
	return false;
}
int Checkstring(string s) {
	Stack st;
	Init_Stack(st);
	for (size_t i = 0; i < s.size(); i++) {
		if (IsEmpty(st) && (s[i] == ')' || s[i] == '}' || s[i] == ']')) return 0;
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			push(st, CreaateStackNode(s[i]));
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
int Uutien(char c) {
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/' || c == '^') return 2;
	return 0;
}
string InfixtoPosdix(string s) {
	Stack st;
	Init_Stack(st);
	string Postfix;
	if (Checkstring(s) == 0) {
		return s;
	}
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			push(st, CreaateStackNode(s[i]));
		}
		else if (isalnum(s[i])) {
			Postfix += s[i];
		}
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
			while (!IsEmpty(st) && (top(st) != '(' && top(st)== '{' && top(st) != '[')) {
				Postfix += top(st);
				pop(st);
			}
			pop(st);
		}
		else if (IsOperator(s[i])) {//toans hangj
			while (!IsEmpty(st) && (Uutien(top(st)) >= Uutien(s[i]))) {
				Postfix += top(st);
				pop(st);
			}
			push(st, CreaateStackNode(s[i]));
		}
	}
	while (!IsEmpty(st)) {
		if (top(st) == '(') {
			pop(st);
			continue;
		}
		Postfix += top(st);
		pop(st);
	}
	return Postfix;
}
int main() {
	string s;
	cout << "Nhap bieu thuc INFIX: ";
	getline(cin, s);
	string Postfix=InfixtoPosdix(s);
	if (Postfix == s) {
		cerr << "Bieu thuc khong hop le" << endl;
		return 0;
	}
	cout << "Postfix: " << Postfix<<endl;
	return 0;
}
