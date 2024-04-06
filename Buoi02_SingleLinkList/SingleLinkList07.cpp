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
//them
void Add_Tail(SList& sl, SNode* p) {
	if (IsEmpty(sl)) {
		sl.Head = sl.Tail = p;
		return;
	}
	sl.Tail->Next = p;
	sl.Tail = p;
}
void Add_Head(SList& sl, SNode* p) {
	if (IsEmpty(sl)) {
		sl.Head = sl.Tail = p;
		return;
	}
	p->Next = sl.Head;
	sl.Head = p;
	return;
}
void Input(SList& sl) {
	int n;
	cout << "Ban muon nhap so bao nhieu chu so: "; cin >> n;
	while (n--) {
		int x; cin >> x;
		Add_Tail(sl, CreaateSNode(x));
	}
}
int Size(SList sl) {
	int cnt = 0;
	SNode* p = sl.Head;
	while (p != NULL) {
		cnt++;
		p = p->Next;
	}
	return cnt;
}
SNode* p(SList sl, int x) {
	SNode* p = sl.Head;
	SNode* q = NULL;
	while (p != NULL) {
		if (p->Data == x) {
			q = p;
		}
	}
	return q;
}
//phep toan
void Cong(SList sl1, SList sl2, SList& sl) {
	int x = Size(sl1), y = Size(sl2);
	if (x > y) {
		int c = x - y;
		while (c--) {
			Add_Head(sl2, CreaateSNode(0));
		}
	}
	if (x < y) {
		int c = y - x;
		while (c--) {
			Add_Head(sl1, CreaateSNode(0));
		}
	}
	SNode* p = sl1.Head;
	SNode* q = sl2.Head;
	while (p != NULL && q != NULL) {
		if (p == sl1.Head && q == sl2.Head && p->Data + q->Data >= 10 && IsEmpty(sl)) {
			int n = p->Data + q->Data;
			while (n) {
				Add_Head(sl, CreaateSNode(n % 10));
				n /= 10;
			}
			p = p->Next;
			q = q->Next;
			continue;
		}
		int x = p->Data + q->Data;
		if (x >= 10) {
			sl.Tail->Data++;
			Add_Tail(sl, CreaateSNode(x % 10));
			p = p->Next;
			q = q->Next;
			continue;
		}
		Add_Tail(sl, CreaateSNode(x));
		p = p->Next;
		q = q->Next;
	}
}

//tru
void Tru(SList sl1, SList sl2, SList& sl) {
	int x = Size(sl1), y = Size(sl2);
	if (x > y) {
		int c = x - y;
		while (c--) {
			Add_Head(sl2, CreaateSNode(0));
		}
	}
	if (x < y) {
		int c = y - x;
		while (c--) {
			Add_Head(sl1, CreaateSNode(0));
		}
	}
	SNode* p = sl1.Head;
	SNode* q = sl2.Head;
	while (p != NULL && q != NULL) {
		if (p == sl1.Head && q == sl2.Head && p->Data < q->Data && IsEmpty(sl)) {
			Tru(sl2, sl1, sl);
			sl.Head->Data *= -1;
			return;
		}
		if (q->Data > p->Data) {
			int x = 10 + p->Data - q->Data;
			sl.Tail->Data--;
			Add_Tail(sl, CreaateSNode(x));
			p = p->Next;
			q = q->Next;
			continue;
		}
		int x = p->Data - q->Data;
		Add_Tail(sl, CreaateSNode(x));
		p = p->Next;
		q = q->Next;
	}
}
//Nhan chia ???????????????????????????????
int pos = 0;
void Nhan(SList sl1, SList sl2, SList& sl, SNode* q) {
	int check = 0;
	SNode* p = sl1.Head;
	SList tam;
	Init_Slist(tam);
	int du = 0;
	int n;
	if (q == NULL) return;
	if (Size(sl2) == 1) {
		while (p != NULL) {
		if (p == sl1.Head && q == sl2.Head && p->Data * q->Data >= 10) {
				n = p->Data * q->Data;
				int x = n;
				Add_Head(sl, CreaateSNode(x % 10));
				x /= 10;
				Add_Head(sl, CreaateSNode(x % 10));
				p = p->Next;
				continue;
			}
			if (p->Data * q->Data >= 10) {
				int z = p->Data * q->Data;
				int temp = z % 10;
				z /= 10;
				du = z % 10;
				sl.Tail->Data += du;
				Add_Tail(sl, CreaateSNode(temp));
				p = p->Next;
				continue;
			}
			int z = p->Data * q->Data;
			Add_Tail(sl, CreaateSNode(z));
			p = p->Next;
			continue;
		}
		return;
	}
	while (p != NULL){
		if (p == sl1.Head && q == sl2.Head && p->Data * q->Data >= 10) {
			n = p->Data * q->Data;
			int x = n;
			Add_Head(tam, CreaateSNode(x % 10));
			x /= 10;
			Add_Head(tam, CreaateSNode(x % 10));
			p = p->Next;
			check++;
			continue;
		}
		if (p->Data * q->Data >= 10 && (p!=sl.Head || p!=sl.Tail)) {
			int z = p->Data * q->Data;
			int temp = z % 10;
			z /= 10;
			du = z % 10;
			tam.Tail->Data += du;
			Add_Tail(tam, CreaateSNode(temp));
			p = p->Next;
			continue;
		}
		int z = p->Data * q->Data;
		Add_Tail(tam, CreaateSNode(z));
		p = p->Next;
	}
	int pos1 = 0;
	SNode* t = tam.Head;
	SNode* s = sl.Head;
	while (t != NULL) {
		pos1++;
		if (pos == 0) {
			Add_Tail(sl, CreaateSNode(t->Data));
			t = t->Next;
			continue;
		}
		if (check != 0) {
			if (pos1 - 1 > pos) {
				s->Data += t->Data;
				t = t->Next;
				s = s->Next;
				continue;
			}
		}
		if (pos1 > pos) {
			s->Data += t->Data;
			t = t->Next;
			s = s->Next;
			continue;
		}
		t = t->Next;
		s = s->Next;
	}
	pos++;
	Nhan(sl1, sl2, sl, q->Next);
}
void Print(SList sl) {
	SNode* p = sl.Head;
	while (p != NULL) {
		cout << p->Data;
		p = p->Next;
	}
}
int main() {
	int z;
	do {
		cout << "0. Thoat" << endl;
		cout << "1. Cong" << endl;
		cout << "2. Tru" << endl;
		cout << "3. Nhan" << endl;
		cout << "   OPTION: "; cin >> z;
		system("cls");
		switch (z)
		{
		case 1: {
			SList sl1;
			Init_Slist(sl1);
			Input(sl1);
			SList sl2;
			Init_Slist(sl2);
			Input(sl2);
			SList sl;
			Init_Slist(sl);
			Cong(sl1, sl2, sl);
			Print(sl1); cout << " + "; Print(sl2); cout << "= "; Print(sl); cout << endl;
			break;
		}
		case 2: {
			SList sl1;
			Init_Slist(sl1);
			Input(sl1);
			SList sl2;
			Init_Slist(sl2);
			Input(sl2);
			SList sl;
			Init_Slist(sl);
			Tru(sl1, sl2, sl);
			Print(sl1); cout << " - "; Print(sl2); cout << "= "; Print(sl); cout << endl;
			break;
		}
		case 3: {
			SList sl1;
			Init_Slist(sl1);
			Input(sl1);
			SList sl2;
			Init_Slist(sl2);
			Input(sl2);
			SList sl;
			Init_Slist(sl);
			Nhan(sl1, sl2, sl, sl2.Head);
			Print(sl1); cout << " * "; Print(sl2); cout << "= "; Print(sl); cout << endl;
		}
		}
	} while (z != NULL);
	return 0;
}