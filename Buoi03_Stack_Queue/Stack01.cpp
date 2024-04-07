//Link github: https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<vector>
using namespace std;
//Tao Cau truc
struct StackNode {
	int Data;
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
StackNode* CreaateStackNode(int x) {
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
int top(Stack sl) {
	return sl.Head->Data;
}
int main() {
	int n;
	cout << "Nhap n: "; cin >> n;
	cout << "Nhap he muon chuyen doi(2<= x <=9): ";
	int x; cin >> x;
	Stack st;
	Init_Stack(st);
	int temp = n;
	while (temp) {
		push(st, CreaateStackNode(temp % x));
		temp /= x;
	}
	cout << "Doi " << n << " ra he "<<x<<" co gia tri la : ";
	while (!IsEmpty(st)) {
		cout << top(st);
		pop(st);
	}
	return 0;
}