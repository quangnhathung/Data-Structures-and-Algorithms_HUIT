//Link github: https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<vector>
using namespace std;
//fifo
//Tao Cau truc
struct QueueNode {
	int Data;
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
QueueNode* CreaateQueueNode(int x) {
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
int front(Queue sl) {
	return sl.Tail->Data;
}
void ShowQueue(Queue sl) {
	if (IsEmpty(sl)) {
		cerr << "Queue rong!";
		return;
	}
	QueueNode* p = sl.Head; {
		while (p != NULL) {
			cout << p->Data << endl;
			p = p->Next;
		}
	}

}
void Menu() {
	cout << "**************************************" << endl;
	cout << "0. Thoat" << endl;
	cout << "1. Nhap queue" << endl;
	cout << "2. Them Phan tu." << endl;
	cout << "3. Lay 1 phan tu ra hang doi." << endl;
	cout << "4. xem gia tri dau/cuoi hang doi" << endl;
	cout << "5. Lay toan bo noi dung ra hang doi" << endl;
	cout << "6. Xem queue!" << endl;
	cout << "**************************************" << endl;
	cout << "\tOPTION: ";
}
int main() {
	int n;
	Queue qu;
	Init_Queue(qu);
	int z;
	do {
		Menu();
		cin >> z;
		system("cls");
		switch (z) {
		case 1: {
			cout << "So luong muon them vao queue: "; cin >> n;
			for (int i = 0; i < n; i++) {
				int x = rand() % 100;
				push(qu, CreaateQueueNode(x));
			}
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			cout << endl << "Nhap gia tri them: "; cin >> n;
			push(qu, CreaateQueueNode(n));
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			ShowQueue(qu);
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			cout << endl << "Pop queue!" << endl;
			cout << "Gia tri " << front(qu) << " da bi xoa!" << endl;
			pop(qu);
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			cout << "Phan tu dau: " << front(qu)<<endl;
			cout << "Phan tu cuoi: " << qu.Head->Data << endl;
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			vector<int> value;
			while (!IsEmpty(qu)) {
				value.push_back(front(qu));
				pop(qu);
			}
			cout << "Da lay tat ca gia tri trong queue! Cac gia tri trong queue: " << endl;
			for (int i = 0; i < value.size(); i++) {
				cout << value[i] << " ";
			}
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	} while (z != 0);
	return 0;
}