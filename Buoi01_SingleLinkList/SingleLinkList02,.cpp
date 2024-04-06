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
void Menu() {
	cout <<endl<< "**************************************" << endl;
	cout << "0. Thoat chuong trinh.\n1. Nhap Phan so\n2. Xuat danh sach." << endl;
	cout << "3. Tim min, max trong danh sach.\n4. Tang moi so cua danh sach len 1 don vi." << endl;
	cout << "5. Xuat cac phan so lon hon 1.\n6. Tim phan so.\n7. Sap xep tang dan.\n8. Format danh sach" << endl;
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
		}
	} while (x != 0);
	return 0;
}