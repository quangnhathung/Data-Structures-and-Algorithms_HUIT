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
struct BenhNhan {
	string CCCD;
	string BHYT;
	string HoTen;
	int Namsinh;
};
struct QueueNode {
	BenhNhan Data;
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
QueueNode* CreaateQueueNode(BenhNhan x) {
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
BenhNhan front(Queue sl) {
	return sl.Tail->Data;
}
void Input(Queue& qu) {
	ifstream Input("input06.txt");
	if (!Input.is_open()) {
		cerr << "Mo file that bai!";
		return;
	}
	string s;
	while (getline(Input, s)) {
		BenhNhan x;
		stringstream ss(s);
		getline(ss, x.CCCD, ',');
		getline(ss, x.BHYT, ',');
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
void ThemBenhNhan(Queue& qu) {
	ofstream file("input06.txt", ios::app);
	BenhNhan a;
	cout << "CCCD: "; getline(cin, a.CCCD);
	cout << "Ma BHYT: ";getline(cin, a.BHYT);
	cout << "Ten Benh nhan: "; getline(cin, a.HoTen);
	cout << "Nam sinh: "; cin >> a.Namsinh;
	file << endl << a.CCCD + "," << a.BHYT + "," << a.HoTen + ',' << a.Namsinh << endl;
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
	cout << setw(5) << left << "STT" << setw(13) << "BHYT"<< setw(13) << "CCCD" << setw(25) << left << "Ho ten" << setw(9) << "Nam sinh" << endl;
	cout << "***************************************************************" << endl;
	int cnt = 1;
	QueueNode* p = qu.Head;
	while (p != NULL) {
		cout << setw(5) << left << cnt << setw(13) << p->Data.BHYT <<setw(13) << p->Data.CCCD <<setw(25) << left << p->Data.HoTen << setw(9) << p->Data.Namsinh << endl;
		cnt++;
		p = p->Next;
	}
	cout << endl;
}
void XemBenhNhan(QueueNode* p) {
	cout << "Can cuoc: " << p->Data.CCCD << endl;
	cout << "BHYT: " << p->Data.BHYT<< endl;
	cout << "Ten hang hoa: " << p->Data.HoTen << endl;
	cout << "Nam sinh: " << p->Data.Namsinh << endl;
}
void LuuBenhNhan(Queue& qu) {
	ofstream file("Output06.txt");
	QueueNode* p = qu.Head;
	while (p != NULL) {
		file << endl << p->Data.CCCD + ","<<p->Data.BHYT + "," << p->Data.HoTen + ',' << p->Data.Namsinh << endl;
		p = p->Next;
	}
	file.close();
	reset(qu);
}
void Menu() {
	cout << "******************************************" << endl;
	cout << "0. Thoat" << endl;
	cout << "1. Nhap danh sach Benh nhan" << endl;
	cout << "2. Benh nhan moi dang ky mua ve." << endl;
	cout << "3. Thong tinh benh nhan dau/cuoi danh sach " << endl;
	cout << "4. Kham cho Benh nhan tiep theo." << endl;
	cout << "5. Thong tin Benh nhan moi dang ky." << endl;
	cout << "6. Kham cho toan bo Benh nhan." << endl;
	cout << "7. Danh sach Benh nhan!" << endl;
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
			ThemBenhNhan(qu);
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			cout << "Benh nhan tiep theo vao kham: " << endl;
			XemBenhNhan(qu.Tail);
			cout << "Done!" << endl;
			cout << "Benh nhan cuoi vao kham: " << endl;
			XemBenhNhan(qu.Head);
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			cout << "Thong tin Benh nhan: " << endl;
			XemBenhNhan(qu.Tail);
			pop(qu);
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			cout << "Benh nhan moi dang ky: " << endl;
			XemBenhNhan(qu.Head);
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			LuuBenhNhan(qu);
			cout << "Da thanh ly toan bo Benh nhan! Vao file \'Ouput06.txt\' de kiem tra!" << endl;
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