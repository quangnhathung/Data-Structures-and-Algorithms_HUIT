//Link github: https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;
//Tao cau truc phan so
struct phanso {
	int tu;
	int mau;
};
//tao danh sach lien ket
struct SNode {
	phanso Data;
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
SNode* CreaateSNode(phanso x) {
	SNode* p = new SNode;
	p->Data.tu = x.tu;
	p->Data.mau = x.mau;
	p->Next = NULL;
	return p;
}
//Them Node vao cuoi
void Add_Tail(SList& sl, SNode* p) {
	if (IsEmpty(sl)) {
		sl.Head = sl.Tail = p;
		return;
	}
	sl.Tail->Next = p;
	sl.Tail = p;
}
//xuat danh sach
void PrintList(SList& sl) {
	SNode* p = sl.Head;
	if (IsEmpty(sl)) {
		cout << "Danh sach rong !!" << endl;
		return;
	}
	while (p != NULL) {
		if (p->Data.mau == 1) cout << p->Data.tu << "  ";
		else if (p->Data.tu == 0) cout << "0  ";
		else cout << p->Data.tu << "/" << p->Data.mau << "  ";
		p = p->Next;
	}
	cout << endl;
}
//nhap phan so tu dong
void InputRandom(SList& sl, int n) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		//random tu -99 -> 100
		phanso z;
		z.tu = -99 + rand() % (100 - -99 + 1);
		z.mau = 0;
		while (z.mau == 0) {//random ra mau =0 thi nhap lai
			z.mau = -99 + rand() % (100 - -99 + 1);
		}
		Add_Tail(sl, CreaateSNode(z));
	}
	cout << "successfully!!" << endl;
}
//toi gian phan so
int UCLN(int a, int b) {//tim ucln
	/*a = abs(a);
	b = abs(b);
	while (a != b) {
		if (a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}
	return a;*/
	int ucln = 1;
	for (int i = 1; i <= a || i <= b; i++) {
		if (a % i == 0 && b % i == 0) ucln = i;
	}
	return ucln;
}
void SimplifyFraction(int& a, int& b) {
	while (UCLN(a, b) != 1) {
		int x = UCLN(a, b);
		a /= x;
		b /= x;
	}
}
//dinh dang phan so (tu +,mau- thi doi dau/tu, mau - thi doi thanh +
void format(int& a, int& b) {
	if (b == 0) return;
	if (a > 0 && b < 0) {
		a *= -1;
		b *= -1;
	}
	if (a < 0 && b < 0) {
		a *= -1;
		b *= -1;
	}
	SimplifyFraction(a, b);
	return;
}
void FormatList(SList& sl) {
	SNode* p = sl.Head;
	while (p != NULL) {
		format(p->Data.tu, p->Data.mau);
		p = p->Next;
	}
}
//phan so lon nhat, phan so nho nhat.
int tru(int a, int b, int c, int d) {
	return a * d - b * c;
}
int ssfraction(SNode* p, SNode* q) {
	int x = tru(p->Data.tu, p->Data.mau, q->Data.tu, q->Data.mau);
	if (x < 0) return -1;
	if (x == 0) return 0;
	return 1;
}
SNode* Max(SList sl) {
	SNode* p = sl.Head;
	SNode* max = p;
	while (p != NULL) {
		if (ssfraction(max, p) == -1) max = p;
		p = p->Next;
	}
	return max;
}
SNode* Min(SList sl) {
	SNode* p = sl.Head;
	SNode* min = p;
	while (p != NULL) {
		if (ssfraction(min, p) == 1) min = p;
		p = p->Next;
	}
	return min;
}
//tang moi phan so cua danh sach len 1 don vi
SNode* Cong(SNode* p) {
	p->Data.tu = p->Data.mau + p->Data.tu;
	return p;
}
void PlusList(SList& sl) {
	SNode* p = sl.Head;
	while (p != NULL) {
		p = Cong(p);
		p = p->Next;
	}
}
//in phan so lon hon 1
void Printthanone(SList sl) {
	SNode* p = sl.Head;
	cout << "Cac phan so lon hon 1: ";
	while (p != NULL) {
		if (p->Data.tu > p->Data.mau) {
			cout << p->Data.tu << "/" << p->Data.mau << " ";
		}
		p = p->Next;
	}
	cout << endl;
}
//tim phan so
SNode* Find(SList sl, int x, int y) {
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data.tu == x && p->Data.mau == y) return p;
		p = p->Next;
	}
	return NULL;//khong thay thi tra ve NULL
}
int Pos(SList sl, SNode* p) {//ham tra ve vi tri phan so tim thay
	if (p == NULL) {
		return 0;
	}
	int pos = 0;
	SNode* q = sl.Head;
	while (q != NULL) {
		pos++;
		if (q->Data.tu == p->Data.tu && q->Data.mau == p->Data.mau) {
			break;
			return pos;
		}
		q = q->Next;
	}
	return pos;
}
//sap xep tang dan
void swap(SNode* p, SNode* q) {//ham doi gia tri
	phanso temp = p->Data;
	p->Data = q->Data;
	q->Data = temp;
}
void Sort(SList sl) {
	for (SNode* p = sl.Head; p != NULL; p = p->Next) {
		for (SNode* q = p; q != NULL; q = q->Next) {
			if (ssfraction(p, q) == 1) swap(p, q);
		}
	}
}
//xoa
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
void Dlt_Value(SList& sl, SNode* p) {
	if (p == NULL) {
		cerr << "Khong tim thay du lieu!";
		return;
	}
	if (p == sl.Head) {
		Dlt_Head(sl);
		return;
	}
	if (p == sl.Tail) {
		Dlt_Tail(sl);
		return;
	}
	if (sl.Head == sl.Tail && sl.Head==p) {
		SNode* p = sl.Head;
		Init_Slist(sl);
		delete p;
		return;
	}
	SNode* x, * y;
	x = Get_NodePrv(sl, p);
	y = p->Next;
	x->Next = y;
	delete p;
	return;
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
SNode* GetNode(SList sl, int a, int b) {
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data.tu == a && p->Data.mau == b) {
			return p;
		}
		p = p->Next;
	}
	return NULL;//lhoong tim thaays
}
bool check(SNode* p) {
	if (p->Data.tu > 0 && p->Data.mau > 0 && p->Data.tu > p->Data.mau) {
		return true;
	}
	return false;
}
void Dlt(SList& sl) {
	if (IsEmpty(sl)) return;
	SNode* p = sl.Head;
	while (p != NULL) {
		if (check(p)) {
			SNode* q = p;
			p = p->Next;
			Dlt_Node(sl, q);
			continue;
		}
		p = p->Next;
	}
}
void Dlt_All(SList& sl) {
	if (IsEmpty(sl)) return;
	SNode* p = sl.Head;
	while (p != NULL) {
		SNode* q = p;
		p = p->Next;
		Dlt_Node(sl, q);
	}
	return;
}
void Menu() {
	cout << endl << "**************************************" << endl;
	cout << "0. Thoat chuong trinh.\n1. Nhap Phan so\n2. Xuat danh sach." << endl;
	cout << "3. Tim min, max trong danh sach.\n4. Tang moi so cua danh sach len 1 don vi." << endl;
	cout << "5. Xuat cac phan so lon hon 1.\n6. Tim phan so.\n7. Sap xep tang dan.\n8. Format danh sach" << endl;
	cout << "9. Xoa." << endl;
	cout << "**************************************" << endl;
	cout << "\tOPTION: ";
}
int main() {
	int x;
	SList sl;
	Init_Slist(sl);
	do {
		Menu();
		cin >> x;
		system("cls");
		switch (x) {
		case 1: {
			cout << "Ban muon co bao nhieu phan tu: ";
			int n; cin >> n;
			InputRandom(sl, n);
			break;
		}
		case 2: {
			PrintList(sl);
			break;
		}
		case 3: {
			SNode* p = Min(sl);
			SNode* q = Max(sl);
			cout << "Phan so lon nhat la: " << q->Data.tu << "/" << q->Data.mau << endl;
			cout << "Phan so nho nhat la: " << p->Data.tu << "/" << p->Data.mau << endl;
			break;
		}
		case 4: {
			PlusList(sl);
			break;
		}
		case 5: {
			Printthanone(sl);
			break;
		}
		case 6: {
			int x, y;
			cout << "Nhap tu phan so muon tim: "; cin >> x;
			cout << "Nhap mau phan so muon tim: "; cin >> y;
			if (Pos(sl, Find(sl, x, y)) == 0) {
				cout << " khong tim thay phan so!!" << endl;
				break;
			}
			else cout << "Phan so can tim o vi tri thu " << Pos(sl, Find(sl, x, y)) << " trong danh sach" << endl;
			break;
		}
		case 7: {
			Sort(sl);
			break;
		}
		case 8: {
			FormatList(sl);
			break;
		}
		case 9: {
			int z;
			do {
				cout << "0. Thoat chuonng trinh" << endl;
				cout << "1. Xoa phan tu dau." << endl;
				cout << "2. Xoa phan tu cuoi." << endl;
				cout << "3. Xoa gia tri tu chon." << endl;
				cout << "4. Xoa phan so co gia tri lon hon 1." << endl;
				cout << "5. Xoa toan bo danh sach." << endl;
				cout << "\tOPTION: "; cin >> z;
				system("cls");
				switch (z) {
				case 1: {
					Dlt_Head(sl);
					cout << "Done!" << endl;
					system("pause");
					break;
				}
				case 2: {
					Dlt_Tail(sl);
					cout << "Done!" << endl;
					system("pause");
					break;
				}
				case 3: {
					cout << "Phan so ban muon xoa co tu va mau lan luot la: ";
					int a,b; cin >>a>>b;
					Dlt_Value(sl, GetNode(sl, a,b));
					cout << "Done!" << endl;
					system("pause");
					break;
				}
				case 4: {
					Dlt(sl);
					cout << "Done!" << endl;
					system("pause");
					break;
				}
				case 5: {
					Dlt_All(sl);
					cout << "Done!" << endl;
					system("pause");
					break;
				}
				}
			} while (z != 0);
			break;
		}
		}
	} while (x != 0);
	return 0;
}