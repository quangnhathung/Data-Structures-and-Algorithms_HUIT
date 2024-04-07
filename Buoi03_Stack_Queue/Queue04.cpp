//Link github: https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<vector>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;
//fifo
//Tao Cau truc
struct Hanghoa {
	string Mahang;
	string Ten;
	string Donvi;
	int Soluong;
};
struct QueueNode {
	Hanghoa Data;
	QueueNode* Next;
};
struct Queue {
	QueueNode* Head;
	QueueNode* Tail;
};
//ham
void Init_Queue(Queue& sl) {
	sl.Head = sl.Tail = NULL;
}
bool IsEmpty(Queue sl) {
	if (sl.Head == NULL) return true;
	return false;
}
//Tao node
QueueNode* CreaateQueueNode(Hanghoa x) {
	QueueNode* p = new QueueNode;
	p->Data = x;
	p->Next = NULL;
	return p;
}
//Them Node
void push(Queue& sl, QueueNode* p) {
	if (IsEmpty(sl)) {
		sl.Head = sl.Tail = p;
		return;
	}
	p->Next = sl.Head;
	sl.Head = p;
	return;
}
QueueNode* Get_NodePrv(Queue sl, QueueNode* p) {
	QueueNode* q = sl.Head;
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
void pop(Queue& sl) {
	if (sl.Head == NULL) return;
	if (sl.Head == sl.Tail) {
		QueueNode* p = sl.Head;
		Init_Queue(sl);
		delete p;
		return;
	}
	QueueNode* p = sl.Tail;
	QueueNode* q = Get_NodePrv(sl, sl.Tail);
	sl.Tail = q;
	sl.Tail->Next = NULL;
	delete p;
}
Hanghoa front(Queue sl) {
	return sl.Tail->Data;
}
//void ShowQueue(Queue sl) {
//	if (IsEmpty(sl)) {
//		cerr << "Queue rong!";
//		return;
//	}
//	QueueNode* p = sl.Head; {
//		while (p != NULL) {
//			cout << p->Data << endl;
//			p = p->Next;
//		}
//	}
//
//}
void Input(Queue& qu) {
	ifstream Input("input04.txt");
	if (!Input.is_open()) {
		cerr << "Mo file that bai!";
		return;
	}
	string s;
	while (getline(Input, s)) {
		Hanghoa x;
		stringstream ss(s);
		getline(ss, x.Mahang, ',');
		getline(ss, x.Ten, ',');
		getline(ss, x.Donvi, ',');
		ss >> x.Soluong;
		ss.ignore();
		push(qu, CreaateQueueNode(x));
	}
	Input.close();
}
void reset(Queue& qu) {
	while (!IsEmpty(qu)) {
		pop(qu);
	}
}
void NhapHang(Queue& qu) {
	ofstream file("input04.txt", ios::app);
	Hanghoa a;
	cout << "Ma hang hoa: "; getline(cin, a.Mahang);
	cout << "Ten hang hoa: "; getline(cin, a.Ten);
	cout << "Don vi: "; getline(cin, a.Donvi);
	cout << "So luong: "; cin >> a.Soluong;
	file << endl << a.Mahang + "," << a.Ten + ',' << a.Donvi + ',' << a.Soluong;
	file.close();
	reset(qu);
	Input(qu);
}
//Mat hang moi nhap vao kho
void NK(Queue qu) {
	Hanghoa a = qu.Head->Data;
	cout << "Ma hang hoa: " << a.Mahang << endl;
	cout << "Ten hang hoa: " << a.Ten << endl;
	cout << "So luong: " << a.Soluong << " " + a.Donvi << endl;
}
//mat hang sap xuat kho
void XK(Queue qu) {
	Hanghoa a = front(qu);
	cout << "Ma hang hoa: " << a.Mahang << endl;
	cout << "Ten hang hoa: " << a.Ten << endl;
	cout << "So luong: " << a.Soluong << " " + a.Donvi << endl;
}
//tim mat hang
QueueNode* GetNode(Queue qu, string s) {
	QueueNode* p = qu.Head;
	while (p != NULL)
	{
		if (p->Data.Ten == s) return p;
	}
	return NULL;
}
void Find(Queue qu, string s) {
	QueueNode* p = GetNode(qu, s);
	if (p == NULL) {
		cerr << "Khong tim thay sanh pham!";
		return;
	}
	cout << "Ma hang hoa: " << p->Data.Mahang << endl;
	cout << "Ten hang hoa: " << p->Data.Ten << endl;
	cout << "So luong: " << p->Data.Soluong << " " + p->Data.Donvi << endl;
}
void XuatHang(Queue qu) {
	ofstream file("Output04.txt");
	QueueNode* p = qu.Head;
	while (p != NULL) {
		file << p->Data.Mahang + "," << p->Data.Ten + ',' << p->Data.Donvi + ',' << p->Data.Soluong << endl;
		p = p->Next;
	}
	file.close();
}
//Xem hang hoa trong kho
void Show(Queue qu) {
	if (IsEmpty(qu)) {
		cerr << "Kho rong!";
		return;
	}
	cout << endl << "***************************************************************" << endl;
	cout << setw(5) << left << "STT" << setw(12) << "Ma hang" << setw(20) << left << "Ten hang" << setw(9) << "Don vi" << setw(10) << "So luong" << endl;
	cout << "***************************************************************" << endl;
	int cnt = 1;
	QueueNode* p = qu.Head;
	while (p != NULL) {
		cout << setw(5) << left << cnt << setw(12) << p->Data.Mahang << setw(20) << left << p->Data.Ten << setw(10) << p->Data.Donvi << setw(10) << p->Data.Soluong << endl;
		cnt++;
		p = p->Next;
	}
	cout << endl;
}
void Menu() {
	cout << "****************************************" << endl;
	cout << "0. Thoat" << endl;
	cout << "1. Nhap danh sach hang" << endl;
	cout << "2. Nhap them san pham moi vao kho." << endl;
	cout << "3. Thoong tin mat hang sap xuat kho." << endl;
	cout << "4. Xuat kho 1 mat hang." << endl;
	cout << "5. Thong tin mat hang moi nhap vao kho." << endl;
	cout << "6. Tim kiem san pham" << endl;
	cout << "7. Xuat toan bo hang trong kho." << endl;
	cout << "8. Danh sach mat hang!" << endl;
	cout << "****************************************" << endl;
	cout << "\tOPTION: ";
}
int main() {
	Queue qu;
	Init_Queue(qu);
	int z;
	do {
		Menu();
		cin >> z;
		system("cls");
		switch (z) {
		case 1: {
			Input(qu);
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			cin.ignore();
			NhapHang(qu);
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			cout << "Mat hang sap xuat kho: " << endl;
			XK(qu);
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			cout << "Xuat kho mat hang: " << endl;
			XK(qu);
			pop(qu);
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			cout << "Mat hang moiws nhap kho: " << endl;
			NK(qu);
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			cin.ignore();
			string s;
			cout << "Nhap ten san pham can tim: "; getline(cin, s);
			Find(qu, s);
			system("pause");
			system("cls");
			break;
		}
		case 7: {
			XuatHang(qu);
			cout << "Da xuat hang! Vao file \'Ouput04.txt\ de kiem tra!'" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 8: {
			Show(qu);
			system("pause");
			system("cls");
			break;
		}
		}
	} while (z != 0);
	return 0;
}