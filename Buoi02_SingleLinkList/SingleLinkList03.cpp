//Link github: https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include<iostream>
#include<sstream>
#include<fstream>
#include<iomanip>
using namespace std;
struct Music {
	string Name;
	string Tacgia;
	string CaSi;
	int Thoiluong;
};
struct SNode {
	Music Data;
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
void Add_Head(SList& sl, SNode* p) {
	if (IsEmpty(sl)) {
		sl.Head = sl.Tail = p;
		return;
	}
	p->Next = sl.Head;
	sl.Head = p;
	return;
}
void Add_Tail(SList& sl, SNode* p) {
	if (IsEmpty(sl)) {
		sl.Head = sl.Tail = p;
		return;
	}
	sl.Tail->Next = p;
	sl.Tail = p;
}
SNode* CreateSNode(Music x) {

	SNode* p = new SNode;
	p->Data = x;
	p->Next = NULL;
	return p;
}
void InputFromFile(SList& sl) {
	string s;
	ifstream File("Input.txt"); 
	if (!File.is_open()){
		cerr << "Mo file that bai!!";
		return;
	}
	while (getline(File, s)) {
		stringstream ss(s);
		Music x;
		getline(ss, x.Name, ',');
		getline(ss, x.Tacgia, ',');
		getline(ss, x.CaSi, ',');
		ss >> x.Thoiluong;
		ss.ignore();
		Add_Tail(sl, CreateSNode(x));
	}
	File.close();
	return;
}
Music Input() {
	Music x;
	cout << "Ten cua bai hat nay la: "; getline(cin, x.Name);
	cout << "Tac gia la: "; getline(cin, x.Tacgia);
	cout << "Ca si trinh bay: "; getline(cin, x.CaSi);
	cout << "Thoi luong (tinh bang giay): "; cin >> x.Thoiluong;
	return x;
}
void PrintList(SList sl) {
	cout << "**************************************************************************" << endl;
	cout << "*                                LIST NHAC                               *" << endl;
	cout << "**************************************************************************" << endl;
	SNode* p = sl.Head;
	cout << setw(20) << left << "*Ten Bai Hat" << setw(20) <<left<< "Tac gia" << setw(20) << left<< "Ca si"  << "Thoi luong(s)*" << endl;
	cout << "**************************************************************************" << endl;
	while (p != NULL) {
		cout << setw(20) << left << p->Data.Name << setw(20) << left << p->Data.Tacgia << setw(24) << left << p->Data.CaSi << p->Data.Thoiluong << endl;
		p = p->Next;
	}
}
//tinh nang
//tong thoi gian nghe het danh sach
int Sum(SList sl) {
	if (IsEmpty(sl)) return 0;
	SNode* p = sl.Head;
	int sum = 0;
	while (p != NULL) {
		sum += p->Data.Thoiluong;
		p = p->Next;
	}
	return sum;
}
void SumTime(int n) {
	int phut, giay;
	phut = n/60;
	giay = n % 60;
	cout << "Can " << phut << "phut" << giay << "giay de nghe het danh sach" << endl;
	return;
}
//xoa mot bai khoi danh sach
SNode* GetNode(SList sl,  string s) {
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data.Name == s) return p;
		p = p->Next;
	}
	return NULL;//khong tim thay
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
//ktra xem baif hats cos trong danh sach hay khong
int  FindName(SList sl, string s) {
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data.Name == s) return 1;
		p = p->Next;
	}
	return 0;//khong tim thay
}
//sap xep
void Swap(SNode* p, SNode* q) {
	Music temp = p->Data;
	p->Data = q->Data;
	q->Data = temp;
}
void Sort1(SList& sl) {//sap xep theo ten nhac
	SNode* p = sl.Head;
	while (p != NULL) {
		SNode* q = p;
		while (q != NULL) {
			if (p->Data.Name > q->Data.Name) {
				Swap(p, q);
			}
			q = q->Next;
		}
		p = p->Next;
	}
}
void Sort2(SList& sl) {//sap xep theo ten ca si
	SNode* p = sl.Head;
	while (p != NULL) {
		SNode* q = p;
		while (q != NULL) {
			if (p->Data.CaSi < q->Data.CaSi) {
				Swap(p, q);
			}
			q = q->Next;
		}
		p = p->Next;
	}
}
//dua 1 bai hat len dau
void Move(SList& sl, string s) {
	if (!IsEmpty(sl)) {
		cerr << "Danh sach rong!";
		return;
	}
	SNode* p = GetNode(sl, s);
	if (p == NULL) {
		cerr << "Bai hat khong ton tai!!";
		return;
	}
	Swap(sl.Head , p);
}
void Menu() {
	cout << "*************************************************" << endl;
	cout << "0. Thoat" << endl;
	cout << "1. Nhap danh sach" << endl;
	cout << "2. Tong thoi gian de nghe het danh sach." << endl;
	cout << "3. Them 1 bai nhac moi vao dau/ cuoi danh sach." << endl;
	cout << "4. Xoa 1 bai hat." << endl;
	cout << "5. Tim bai hat." << endl;
	cout << "6. Sap xep list theo alphabet." << endl;
	cout << "7. Sap xep list theo ten ca si." << endl;
	cout << "8. In danh sach." << endl;
	cout << "***************************************************" << endl;
	cout << "\tOPTION: ";
}
int main() {
	SList sl;
	Init_Slist(sl);
	int z;
	do {
		Menu();
		cin >> z;
		system("cls");
		switch (z) {
		case 1: {
			InputFromFile(sl);
			cout << "Successfully!"<<endl;
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			int x=Sum(sl);
			SumTime(x);
			cout << "DONE!"<<endl;
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			int c;
			cout << " Ban muon them dau hay cuoi: \n0. Huy.\n1. Them dau.\n2. Them cuoi." << endl;
			cout << "\tOPTION: "; cin >> c;
			switch (c) {
			case 0: {
				system("cls");
				break;
			}
			case 1: {
				cin.ignore();
				Music x = Input();
				Add_Head(sl, CreateSNode(x));
				cout << "DONE!" << endl;
				system("pause");
				system("cls");
				break;
			}
			case 2: {
				cin.ignore();
				Music x = Input();
				Add_Tail(sl, CreateSNode(x));
				cout << "DONE!" << endl;
				system("pause");
				system("cls");
				break;
			}
			}
			break;
		}
		case 4: {
			string s;
			cin.ignore();
			cout << "Nhap ten sach can xoa: "; getline(cin, s);
			SNode* p = GetNode(sl, s);
			if (p == NULL) {
				cerr << "Khong tim thay ten nhac: " << endl;
				system("pause");
				system("cls");
				break;
			}
			Dlt_Node(sl, p);
			cout << "DONE!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			string s;
			cin.ignore();
			cout << "Nhap ten sach can tim: "; getline(cin, s);
			if (FindName(sl, s)) {
				cout << "Tim thay!"<<endl;
				cout << "**************************************************************************" << endl;
				SNode* p = sl.Head;
				cout << setw(20) << left << "*Ten Bai Hat" << setw(20) << left << "Tac gia" << setw(20) << left << "Ca si" << "Thoi luong(s)*" << endl;
				cout << "**************************************************************************" << endl;
				while (p != NULL) {
					if (p->Data.Name == s) {
						cout << setw(20) << left << p->Data.Name << setw(20) << left << p->Data.Tacgia << setw(24) << left << p->Data.CaSi << p->Data.Thoiluong << endl;
					}
					p = p->Next;
				}
				system("pause");
				system("cls");
				break;
			}
			else {
				cout << "Khong tim thay trong danh sach!";
				system("pause");
				system("cls");
				break;
			}
		}
		case 6: {
			Sort1(sl);
			cout << "DONE!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 7: {
			Sort2(sl);
			cout << "DONE!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 8: {
			PrintList(sl);
			system("pause");
			system("cls");
			break;
		}
		}
	} while (z != 0);
	return 0;
}

