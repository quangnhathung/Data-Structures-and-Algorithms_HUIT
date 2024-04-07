//Link github: https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string>
using namespace std;
//Tao Cau truc
struct Tower {
	int Sodia;
	char BatDau;
	char TrungGian;
	char Dich;
};
struct StackNode {
	Tower Data;
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
StackNode* CreaateStackNode(Tower x) {
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
Tower top(Stack sl) {
	return sl.Head->Data;
}
//tháp hà nội
//de quy
char a[3] = { 'A','B','C' };
void TowerofHNRecursion(int n, int i, int j, int k) {
	if (n == 1) {
		cout << "Chuyen dia " << n << " tu cot " << a[i] << " sang " << a[j] << "." << endl;
	}
	else {
		TowerofHNRecursion(n - 1, i, k, j);
		cout << "Chuyen dia " << n << " tu cot " << a[i] << " sang " << a[j] << "." << endl;
		TowerofHNRecursion(n - 1, k, j, i);

	}
}
void Swapchar(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}
//khu de quy
void TowerofHNWithoutRecursion(int n, char Nguon, char trunggian, char dich) {
	Stack st;
	Init_Stack(st);
	if (n == 1) {
		cout << "Chuyen dia " << n << " tu cot " << a[0] << " sang " << a[2] << "." << endl;
		return;
	}
	while (1) {
		while (n > 1) {
			Tower x;
			x.Sodia = n;
			x.BatDau = Nguon;
			x.TrungGian = trunggian;
			x.Dich = dich;
			push(st, CreaateStackNode(x));
			n--;
			swap(trunggian, dich);
		}
		cout << "Chuyen dia " << n << " tu cot " << Nguon << " sang " << dich << "." << endl;
		if (!IsEmpty(st)) {
			Tower x = top(st);
			pop(st);
			n = x.Sodia;
			Nguon = x.BatDau;
			trunggian = x.TrungGian;
			dich = x.Dich;
			cout << "Chuyen dia " << n << " tu cot " << Nguon << " sang " << dich << "." << endl;
			n--;
			swap(Nguon, trunggian);
		}
		else {
			break;
		}
	}

}
int main() {
	int n;
	cin >> n;
	TowerofHNRecursion(n, 0, 2, 1);
	cout << endl << "Khong de quy: " << endl;
	TowerofHNWithoutRecursion(n, a[0], a[1], a[2]);
	return 0;
}