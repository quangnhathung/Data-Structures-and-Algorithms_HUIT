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
struct KhachHang {
	string CCCD;
	string HoTen;
	int Namsinh;
};
struct QueueNode {
	KhachHang Data;
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
QueueNode* CreaateQueueNode(KhachHang x) {
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
KhachHang front(Queue sl) {
	return sl.Tail->Data;
}
void Input(Queue& qu) {
	ifstream Input("input05.txt");
	if (!Input.is_open()) {
		cerr << "Mo file that bai!";
		return;
	}
	string s;
	while (getline(Input, s)) {
		KhachHang x;
		stringstream ss(s);
		getline(ss, x.CCCD, ',');
		getline(ss, x.HoTen, ',');
		ss >> x.Namsinh;
		ss.ignore();
		push(qu, CreaateQueueNode(x));
	}
	Input.close();
}
void reset(Queue& qu) {
	while (!IsEmpty(qu)) {
		pop(qu);
	}
}//them pt
void ThemKh(Queue& qu) {
	ofstream file("input05.txt", ios::app);
	KhachHang a;
	cout << "CCCD: "; getline(cin, a.CCCD);
	cout << "Ten khach: "; getline(cin, a.HoTen);
	cout << "Nam sinh: "; cin >> a.Namsinh;
	file << endl << a.CCCD + "," << a.HoTen + ',' << a.Namsinh << endl;
	file.close();
	reset(qu);
	Input(qu);
}
//xuat danh sach
void Show(Queue qu) {
	if (IsEmpty(qu)) {
		cerr << "Kho rong!";
		return;
	}
	cout << endl << "***************************************************************" << endl;
	cout << setw(5) << left << "STT" << setw(13) << "CCCD" << setw(25) << left << "Ho ten" << setw(9) << "Nam sinh" << endl;
	cout << "***************************************************************" << endl;
	int cnt = 1;
	QueueNode* p = qu.Head;
	while (p != NULL) {
		cout << setw(5) << left << cnt << setw(13) << p->Data.CCCD << setw(25) << left << p->Data.HoTen << setw(9) << p->Data.Namsinh << endl;
		cnt++;
		p = p->Next;
	}
	cout << endl;
}
void XemKhachhang(QueueNode* p) {
	cout << "Can cuoc: " << p->Data.CCCD << endl;
	cout << "Ten hang hoa: " << p->Data.HoTen << endl;
	cout << "Nam sinh: " << p->Data.Namsinh << endl;
}
void LuuKhach(Queue& qu) {
	ofstream file("Output05.txt");
	QueueNode* p = qu.Head;
	while (p != NULL) {
		file << endl << p->Data.CCCD + "," << p->Data.HoTen + ',' << p->Data.Namsinh << endl;
		p = p->Next;
	}
	file.close();
	reset(qu);
}
void Menu() {
	cout << "****************************************" << endl;
	cout << "0. Thoat" << endl;
	cout << "1. Nhap danh sach khach hang" << endl;
	cout << "2. Khach hang moi dang ky mua ve." << endl;
	cout << "3. Thong tinh k/h dau/cuoi danh sach " << endl;
	cout << "4. Ban ve xe lua cho khach hang." << endl;
	cout << "5. Thong tin khach hang moi dang ky." << endl;
	cout << "6. Xu ly ve cho toan bo khach hang." << endl;
	cout << "7. Danh sach Khach hang!" << endl;
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
			ThemKh(qu);
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			cout << "Khach hang tiep theo nhan ve: " << endl;
			XemKhachhang(qu.Tail);
			cout << "Done!" << endl;
			cout << "Khach hang cuoi nhan ve: " << endl;
			XemKhachhang(qu.Head);
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			cout << "Thong tin khach hang: " << endl;
			XemKhachhang(qu.Tail);
			pop(qu);
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			cout << "Khach hang moi dang ky: " << endl;
			XemKhachhang(qu.Head);
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			LuuKhach(qu);
			cout << "Da thanh ly toan bo khach hang! Vao file \'Ouput05.txt\' de kiem tra!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 7: {
			Show(qu);
			system("pause");
			system("cls");
			break;
		}
		}
	} while (z != 0);
	return 0;
}