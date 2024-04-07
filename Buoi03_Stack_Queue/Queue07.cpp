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
struct Nguoi {
	string CCCD;
	string HoTen;
	int Namsinh;
};
struct QueueNode {
	Nguoi Data;
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
QueueNode* CreaateQueueNode(Nguoi x) {
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
Nguoi front(Queue sl) {
	return sl.Tail->Data;
}
void Input(Queue& qu) {
	ifstream Input("input07.txt");
	if (!Input.is_open()) {
		cerr << "Mo file that bai!";
		return;
	}
	string s;
	while (getline(Input, s)) {
		Nguoi x;
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
void ThemND(Queue& qu) {
	ofstream file("input07.txt", ios::app);
	Nguoi a;
	cout << "CCCD: "; getline(cin, a.CCCD);
	cout << "Ten nguoi dan: "; getline(cin, a.HoTen);
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
void XemNguoi(QueueNode* p) {
	cout << "Can cuoc: " << p->Data.CCCD << endl;
	cout << "Ten nguoi dan: " << p->Data.HoTen << endl;
	cout << "Nam sinh: " << p->Data.Namsinh << endl;
}
void LuuKhach(Queue& qu) {
	ofstream file("Output07.txt");
	QueueNode* p = qu.Head;
	while (p != NULL) {
		file << endl << p->Data.CCCD + "," <<p->Data.CCCD + "," << p->Data.HoTen + ',' << p->Data.Namsinh << endl;
		p = p->Next;
	}
	file.close();
	reset(qu);
}
void Menu() {
	cout << "******************************************" << endl;
	cout << "0. Thoat" << endl;
	cout << "1. Nhap danh sach nguoi dan" << endl;
	cout << "2. Nguoi moi cho cong chung." << endl;
	cout << "3. Thong tinh nguoi dau/cuoi danh sach " << endl;
	cout << "4. Cong chung cho nguoi tiep theo." << endl;
	cout << "5. Thong tin nguoi moi dang ky." << endl;
	cout << "6. Cong chung cho toan bo nguoi dan." << endl;
	cout << "7. Danh sach nguoi!" << endl;
	cout << "******************************************" << endl;
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
			ThemND(qu);
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			cout << "nguoi tiep theo vao Cong chung: " << endl;
			XemNguoi(qu.Tail);
			cout << "Done!" << endl;
			cout << "nguoi cuoi vao Cong chung: " << endl;
			XemNguoi(qu.Head);
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			cout << "Thong tin nguoi den cong chung: " << endl;
			XemNguoi(qu.Tail);
			pop(qu);
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			cout << "nguoi moi dang ky: " << endl;
			XemNguoi(qu.Head);
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			LuuKhach(qu);
			cout << "Da thanh ly toan bo nguoi! Vao file \'Ouput07.txt\' de kiem tra!" << endl;
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