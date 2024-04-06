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
//ktra chan le
bool Check(int n) {
	if (n % 2 == 0) return true;
	return false;
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
void InputFromKeyBoard(SList& sl) {
	int n;
	cout << "So luon phan tu ban muon: "; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		Add_Tail(sl, CreaateSNode(x));
	}
}
//tron danh sach
void MergeList(SList sl1, SList sl2, SList& sl) {
	SNode* p = sl1.Head;
	SNode* q = sl2.Head;
	while (p != NULL && q != NULL) {
		if (p != NULL) {
			Add_Tail(sl, p);
			p = p->Next;
		}
		if (q != NULL) {
			Add_Tail(sl, q);
			q = q->Next;
		}
	}
}
//chan tang dan le giam dan
void Sort1(SList sl) {
	SNode* p = sl.Head;
	while (p != NULL) {
		SNode* q = p;
		while (q != NULL) {
			if (Check(p->Data) && Check(q->Data) && p->Data > q->Data) swap(p, q);
			else if(!Check(p->Data) && !Check(q->Data) && p->Data < q->Data) swap(p, q);
			q = q->Next;
		}
		p = p->Next;
	}
}
void Sort2(SList sl) {
	int pos1 = 0;
	SNode* p = sl.Head;
	while (p != NULL) {
		pos1++;
		SNode* q = p;
		int pos2 = pos1;
		while (q != NULL) {
			pos2++;
			if (Check(pos1) && Check(pos2) && p->Data > q->Data) swap(p, q);
			else if (!Check(pos1) && !Check(pos2) && p->Data < q->Data) swap(p, q);
			q = q->Next;
		}
		p = p->Next;
	}
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
void Menu() {
	cout << "**********************************" << endl;
	cout << "0. Thoat" << endl;
	cout << "1. Tron 2 danh sach theo thu tu tang." << endl;
	cout << "2. Tron 2 danh sach theo thu tu giam." << endl;
	cout << "3. Tron 2 danh sach chan tang dan, le giam dan." << endl;
	cout << "4. Tron 2 danh sach vi tri chan tang dan, vi tri le giam dan." << endl;
	cout << "***********************************" << endl;
	cout << "\tOPTION: ";
}
int main() {
	SList sl1, sl2;
	Init_Slist(sl1);
	Init_Slist(sl2);
	cout << "Nhap danh sach sl1: " << endl;
	InputFromKeyBoard(sl1);
	cout << "Nhap danh sach sl2: " << endl;
	InputFromKeyBoard(sl2);
	system("cls");
	int z;
	do {
		Menu();
		cin >> z;
		system("cls");
		switch (z) {
		case 1: {
			SList sl;
			Init_Slist(sl);
			MergeList(sl1, sl2, sl);
			AtoZ(sl);
			cout << "Danh sach sau khi tron: ";
			PrintList(sl);
			break;
		}
		case 2: {
			SList sl;
			Init_Slist(sl);
			MergeList(sl1, sl2, sl);
			ZtoA(sl);
			cout << "Danh sach sau khi tron: ";
			PrintList(sl);
			break;
		}
		case 3: {
			SList sl;
			Init_Slist(sl);
			MergeList(sl1, sl2, sl);
			Sort1(sl);
			cout << "Danh sach sau khi tron: ";
			PrintList(sl);
			break;
		}
		case 4: {
			SList sl;
			Init_Slist(sl);
			MergeList(sl1, sl2, sl);
			Sort2(sl);
			cout << "Danh sach sau khi tron: ";
			PrintList(sl);
			break;
		}
		}
	} while (z != 0);
}