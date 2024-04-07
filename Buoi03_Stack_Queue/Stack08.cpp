//Link github: https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
//Danh sach lien ket don khong duyet nguowc duoc ne dung mang tinh
//Tao Cau truc
struct Doanxet {
	int BatDau;
	int ketthuc;
};
struct StackNode {
	Doanxet Data;
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
StackNode* CreaateStackNode(Doanxet x) {
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
Doanxet top(Stack sl) {
	return sl.Head->Data;
}
//quick sort dung de quy
//ham phan hoach
void Swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}
int Partition(int a[], int l, int r) {
	int x = (l + r) / 2;
	int pivot = a[x];
	while (l <= r) {
		while (a[l] < pivot) {
			l++;
		}
		while (a[r] > pivot) {
			r--;
		}
		if (l <= r) {
			Swap(a[l], a[r]);
			l++;
			r--;
		}
	}
	return l;
}
void QuickSortWithRecursion(int a[], int l, int r) {
	int i = Partition(a, l, r);
	if (l < i - 1) {
		QuickSortWithRecursion(a, l, i - 1);
	}
	if (i < r) {
		QuickSortWithRecursion(a, i, r);
	}
}
//Khu de quy quicksort
void QuicksortWithoutRecursion(int a[], int l, int r) {
	int i = Partition(a, l, r);
	Stack st;
	Init_Stack(st);
	if (l < i - 1) {
		Doanxet x;
		x.BatDau = l;
		x.ketthuc = i - 1;
		push(st, CreaateStackNode(x));
	}
	if (i < r) {
		Doanxet x;
		x.BatDau = i;
		x.ketthuc = r;
		push(st, CreaateStackNode(x));
	}
	while (!IsEmpty(st)) {
		int i = Partition(a, l, r);
		Doanxet z = top(st);
		l = z.BatDau;
		r = z.ketthuc;
		pop(st);
		if (l < i - 1) {
			Doanxet x;
			x.BatDau = l;
			x.ketthuc = i - 1;
			push(st, CreaateStackNode(x));
		}
		if (i < r) {
			Doanxet x;
			x.BatDau = i;
			x.ketthuc = r;
			push(st, CreaateStackNode(x));
		}
	}

}
int main() {
	int a[10];
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		int x = rand() % 10;
		a[i] = x;
	}
	cout << "Demo voi day co 10 so!" << endl;
	cout << "Mang chua sap xep: ";
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	QuicksortWithoutRecursion(a, 0, 9);
	cout << "\nMang da sap xep: ";
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	return 0;
}