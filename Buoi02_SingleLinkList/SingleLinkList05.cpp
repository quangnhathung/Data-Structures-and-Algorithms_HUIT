//Link github: https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<vector>
using namespace std;

struct DonThuc {
	int Heso;
	int Bac;
};
//Tao Cau truc
struct SNode {
	DonThuc Data;
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
SNode* CreaateSNode(DonThuc x) {
	SNode* p = new SNode;
	p->Data = x;
	p->Next = NULL;
	return p;
}
void Add_Tail(SList& sl, SNode* p) {
	if (IsEmpty(sl)) {
		sl.Head = sl.Tail = p;
		return;
	}
	sl.Tail->Next = p;
	sl.Tail = p;
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
void Input(SList& sl) {
	DonThuc x;
	cout << "Nhap den khi he so bang 0" << endl;
	do {
		cout << "Nhap he so: "; cin >> x.Heso;
		cout << "Bac cua don thuc la: "; cin >> x.Bac;
		Add_Tail(sl, CreaateSNode(x));
	} while (x.Heso != 0);
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
SNode* GetNode(SList sl, int x) {//lay node co gia tri x
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data.Heso == x) return p;
		p = p->Next;
	}
	return NULL;//khong tim thay
}
//Xoa don thuc khi biet bac
void Xoadonthuc(SList sl, int x) {
	SNode* p = GetNode(sl, x);
	if (p == NULL) {
		cerr << " khong tim thay don thuc co bac " << x << "." << endl;
		return;
	}
	Dlt_Node(sl, p);
}

void swap(SNode* p, SNode* q) {//ham doi gia tri
	DonThuc temp = p->Data;
	p->Data = q->Data;
	q->Data = temp;
}
void ZtoA(SList& sl) {
	for (SNode* p = sl.Head; p != NULL; p = p->Next) {
		for (SNode* q = p; q != NULL; q = q->Next) {
			if (p->Data.Heso < q->Data.Heso) {
				swap(p, q);
			}
		}
	}
}
void ThemDonthuc(SList& sl) {
	DonThuc x;
	cout << "Nhap he so: "; cin >> x.Heso;
	cout << "Bac cua don thuc la: "; cin >> x.Bac;
	if (x.Heso == 0) {
		return;
	}
	Add_Tail(sl, CreaateSNode(x));
}
void RutgonDaThuc(SList sl) {
	SNode* p = sl.Head;
	while (p != NULL) {
		SNode* q = p->Next;
		while (q != NULL) {
			if (p->Data.Bac == q->Data.Bac) {
				p->Data.Heso += q->Data.Heso;
				SNode* w = q;
				q = q->Next;
				Dlt_Node(sl, w);
				continue;
			}
			q = q->Next;
		}
		p = p->Next;
	}
}
//Phep toan tren da thuc
void Cong(SList sl1, SList sl2, SList& sl) {
	SNode* p = sl1.Head;
	SNode* q = sl2.Head;
	while (p != NULL) {
		Add_Tail(sl, p);
		p = p->Next;
	}
	while (q != NULL) {
		Add_Tail(sl, q);
		q = q->Next;
	}
	RutgonDaThuc(sl);
}
void Tru(SList sl1, SList sl2, SList& sl) {
	SNode* p = sl1.Head;
	SNode* q = sl2.Head;
	while (p != NULL) {
		p->Data.Heso *= -1;
		Add_Tail(sl, p);
		p = p->Next;
	}
	while (q != NULL) {
		q->Data.Heso *= -1;
		Add_Tail(sl, q);
		q = q->Next;
	}
	RutgonDaThuc(sl);
}
void Nhan(SList sl1, SList sl2, SList& sl) {
	SNode* p = sl1.Head;
	SNode* q = sl2.Head;
	SNode* x = NULL;
	while (p != NULL) {
		while (q != NULL) {
			x->Data.Bac = p->Data.Bac + q->Data.Bac;
			x->Data.Heso = p->Data.Heso + q->Data.Heso;
			Add_Tail(sl, x);
			q = q->Next;
		}
		p = p->Next;
	}
	RutgonDaThuc(sl);
}
double Tinhsgiatri(SList sl, double x) {
	double value = 0;
	SNode* p = sl.Head;
	while (p != NULL) {
		value += p->Data.Heso * pow(x, p->Data.Bac);
		p = p->Next;
	}
	return value;
}
void Print(SList sl) {
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data.Heso == 0) {
			p = p->Next;
			continue;
		}
		cout << p->Data.Heso << "*X^" << p->Data.Bac;
		if (p->Next != NULL) {
			cout << " + ";//In dau cong
		}
		p = p->Next;
	}
}
void Menu() {
	cout << "*************************************************" << endl;
	cout << "0. Thoat" << endl;
	cout << "1. Them down thuc vao da thuc" << endl;
	cout << "2. Xoa 1 don thuc khi biet bac" << endl;
	cout << "3. Tinh gia tri da thuc." << endl;
	cout << "4. Cong 2 da thuc." << endl;
	cout << "5. Tru 2 da thuc." << endl;
	cout << "6. Nhan 2 da thuc." << endl;
	cout << "***************************************************" << endl;
	cout << "\tOPTION: ";
}
int main() {
	int x;
	do {
		Menu();
		cin >> x;
		system("cls");
		switch (x) {
		case 1: {
			SList sl;
			Init_Slist(sl);
			Input(sl);
			RutgonDaThuc(sl);
			ZtoA(sl);
			cout << "X: ";
			Print(sl);
			cout << endl;
			system("pause");
			ThemDonthuc(sl);
			cout << "X: ";
			Print(sl);
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			SList sl;
			Init_Slist(sl);
			Input(sl);
			RutgonDaThuc(sl);
			ZtoA(sl);
			cout << "X: ";
			Print(sl);
			cout << endl;
			system("pause");
			int z;
			cout << "Ban muon xoa bac may: "; cin >> z;
			Xoadonthuc(sl, z);
			cout << "X: ";
			Print(sl);
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			SList sl;
			Init_Slist(sl);
			Input(sl);
			RutgonDaThuc(sl);
			ZtoA(sl);
			cout << "X: ";
			Print(sl);
			cout << endl;
			system("pause");
			int z;
			cout << "Ban muon cho x bang bao nhieu: "; cin >> z;
			cout << "X= " << Tinhsgiatri(sl, z) << endl;
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			SList sl1;
			Init_Slist(sl1);
			Input(sl1);
			RutgonDaThuc(sl1);
			ZtoA(sl1);
			cout << "X: ";
			Print(sl1);
			SList sl2;
			Init_Slist(sl2);
			Input(sl2);
			RutgonDaThuc(sl2);
			ZtoA(sl2);
			cout << "Y: ";
			Print(sl2);
			SList sl;
			Init_Slist(sl);
			Cong(sl1, sl2, sl);
			cout << "X+Y= ";
			Print(sl);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			SList sl1;
			Init_Slist(sl1);
			Input(sl1);
			RutgonDaThuc(sl1);
			ZtoA(sl1);
			cout << "X: ";
			Print(sl1);
			SList sl2;
			Init_Slist(sl2);
			Input(sl2);
			RutgonDaThuc(sl2);
			ZtoA(sl2);
			cout << "Y: ";
			Print(sl2);
			SList sl;
			Init_Slist(sl);
			Tru(sl1, sl2, sl);
			cout << "X+Y= ";
			Print(sl);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			SList sl1;
			Init_Slist(sl1);
			Input(sl1);
			RutgonDaThuc(sl1);
			ZtoA(sl1);
			cout << "X: ";
			Print(sl1);
			SList sl2;
			Init_Slist(sl2);
			Input(sl2);
			RutgonDaThuc(sl2);
			ZtoA(sl2);
			cout << "Y: ";
			Print(sl2);
			SList sl;
			Init_Slist(sl);
			Nhan(sl1, sl2, sl);
			cout << "X+Y= ";
			Print(sl);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		}

	} while (x != 0);
	return 0;
}