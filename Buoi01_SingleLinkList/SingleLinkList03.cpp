//Link github: https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<vector>
using namespace std;

//Tao Cau truc
struct SNode {
	int Data;
	SNode* Next;
};
struct SList {
	SNode* Head;
	SNode* Tail;
};
//ham
void Init_Slist(SList& sl) {
	sl.Head = sl.Tail = NULL;
}
bool IsEmpty(SList sl) {
	if (sl.Head == NULL) return true;
	return false;
}
//Tao node
SNode* CreaateSNode(int x) {
	SNode* p = new SNode;
	p->Data = x;
	p->Next = NULL;
	return p;
}
void swap(SNode* p, SNode* q) {//ham doi gia tri
	int temp = p->Data;
	p->Data = q->Data;
	q->Data = temp;
}
void AtoZ(SList& sl) {
	if (sl.Head == sl.Tail) {
		return;
	}
	for (SNode* p = sl.Head; p != NULL; p = p->Next) {
		for (SNode* q = p; q != NULL; q = q->Next) {
			if (p->Data > q->Data) {
				swap(p, q);
			}
		}
	}
}
void Add_Tail(SList& sl, SNode* p) {
	if (IsEmpty(sl)) {
		sl.Head = sl.Tail = p;
		return;
	}
	sl.Tail->Next = p;
	sl.Tail = p;
}
void ZtoA(SList& sl) {
	for (SNode* p = sl.Head; p != NULL; p = p->Next) {
		for (SNode* q = p; q != NULL; q = q->Next) {
			if (p->Data < q->Data) {
				swap(p, q);
			}
		}
	}
}
void InputRandom(SList& sl, int n) {
	srand(time(0));
	int y;
	for (int i = 0; i < n; i++) {
		y = rand() % 100;
		Add_Tail(sl, CreaateSNode(y));
	}
}
//find 
int check(SList sl, int x) {
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data == x) return 1;
		p = p->Next;
	}
	return 0;
}

SNode* Get_NodePrv(SList sl, SNode* p) {
	SNode* q = sl.Head;
	if (p == NULL) {
		cerr << "Loi!";
		return NULL;
	}
	if (p == sl.Head) {
		return NULL;
	}
	while (q->Next != p) {
		q = q->Next;
	}
	return q;
}
void Dlt_Tail(SList& sl) {
	if (sl.Head == NULL) return;
	if (sl.Head == sl.Tail) {
		SNode* p = sl.Head;
		Init_Slist(sl);
		delete p;
		return;
	}
	SNode* p = sl.Tail;
	SNode* q = Get_NodePrv(sl, sl.Tail);
	sl.Tail = q;
	sl.Tail->Next = NULL;
	delete p;
}
void Dlt_Head(SList& sl) {
	if (sl.Head == NULL) return;
	if (sl.Head == sl.Tail) {
		SNode* p = sl.Head;
		Init_Slist(sl);
		delete p;
		return;
	}
	SNode* p = sl.Head;
	sl.Head = p->Next;
	delete p;
}
void Dlt_Node(SList& sl, SNode* p) {
	if (IsEmpty(sl)) return;
	if (p == sl.Head) {
		Dlt_Head(sl);
		return;
	}
	if (p == sl.Tail) {
		Dlt_Tail(sl);
		return;
	}
	if (sl.Head == sl.Tail && sl.Head == p) {
		Init_Slist(sl);
		delete p;
	}
	SNode* q = Get_NodePrv(sl, p);
	SNode* I = p->Next;
	q->Next = I;
	delete p;
}
void Dlt_lst(SList& sl, int x) {
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data == x) {
			SNode* q = p->Next;
			while (q != NULL) {
				SNode* x = q;
				q = q->Next;
				Dlt_Node(sl, x);
			}
			break;
		}
		p = p->Next;
	}
}
void AppendList(SList& sl1, SList& sl2, int x) {
	if (IsEmpty(sl1)) return;
	if (IsEmpty(sl2)) return;
	if (!check(sl1, x)) return;
	Dlt_lst(sl1, x);
	SNode* p = sl1.Tail;
	SNode* q = sl2.Head;
	while (q != NULL) {
		Add_Tail(sl1, q);
		q = q->Next;
	}
	return;
}
void PrintList(SList sl) {
	SNode* p = sl.Head;
	if (IsEmpty(sl)) {
		cout << "Danh sach rong !!";
		return;
	}
	while (p != NULL) {
		cout << p->Data << " ";
		p = p->Next;
	}
	cout << endl;
}
int main() {
	SList sl, sl1, sl2;
	Init_Slist(sl);
	int n;
	cout << "Ban muon danh sach cua ban co bao nhieu phan tu: "; cin >> n;
	InputRandom(sl, n);
	Init_Slist(sl1);
	Init_Slist(sl2);
	int z;
	do {
		cout << "**********************************" << endl;
		cout << "0. Thoat" << endl;
		cout << "1. Chen x, in ra danh sach tang."<<endl;
		cout << "2. Xuat danh sach giam dan." << endl;
		cout << "3.Noi sl2 vao sau sl1 sau x." << endl;
		cout << "4. In danh sach." << endl;
		cout << "***********************************" << endl;
		cout << "\tOPTION: ";
		cin >> z;
		system("cls");
		switch (z) {
		case 1: {
			int x;
			cout << "Nhap gia tri muon chen: "; cin >> x;
			Add_Tail(sl, CreaateSNode(x));
			AtoZ(sl);
			cout << "Danh sach luc nay la: ";
			PrintList(sl);
			break;
		}
		case 2: {
			ZtoA(sl);
			PrintList(sl);
			break;
		}
		case 3: {
			int x,y;
			cout << "Ban muon danh sach sl1 co bao nhieu phan tu: "; cin >> x;
			cout << "Ban muon danh sach sl2 co bao nhieu phan tu: "; cin >> y;
			InputRandom(sl1, x);
			InputRandom(sl2, y);
			int f;
			cout << "Ban muon noi sl2 sau phan tu nao cua sl1: "; cin >> f;
			AppendList(sl1, sl2, f);
			cout << "Danh sach sau khi noi la: ";
			PrintList(sl1);
			break;
		}
		case 4: {
			PrintList(sl);
			break;
		}
		}
	} while (z != 0);
	system("pause");
	return 0;
}