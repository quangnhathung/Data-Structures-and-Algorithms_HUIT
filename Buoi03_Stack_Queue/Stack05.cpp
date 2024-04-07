//Link github: https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<vector>
#include<string>
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
//kiem tra ngoac hop le
int Checkstring(string s) {
	Stack st;
	Init_Stack(st);
	for (int i = 0; i < s.size(); i++) {
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
int main() {
	string s;
	cout << "Nhap chuoi can kiem tra: ";
	getline(cin, s);
	if (Checkstring(s)) {
		cout << "Hop le!" << endl;
	}
	else cout << "Khong hop le!";
	return 0;
}