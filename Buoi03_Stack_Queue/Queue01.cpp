//Link github: https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
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
	QueueNode* p = sl.Head; {
		while (p != NULL) {
			cout << p->Data << endl;
			p = p->Next;
		}
	}

}
int main() {
	srand(time(NULL));
	int n;
	Queue qu;
	Init_Queue(qu);
	cout << "So luong muon them vao queue: "; cin >> n;
	for (int i = 0; i < n; i++) {
		int x = rand() % 100;
		push(qu, CreaateQueueNode(x));
	}
	cout << "Hang doi luc nay la: "<<endl;
	ShowQueue(qu);
	cout << endl << "Nhap gia tri them: "; cin >> n;
	push(qu, CreaateQueueNode(n));
	cout << endl<<"Hang doi luc nay la: "<<endl;
	ShowQueue(qu);
	cout <<endl<< "Pop queue!"<<endl;
	cout << "Gia tri " << front(qu) << " da bi xoa!" << endl;
	pop(qu);
	system("pause");
	cout << "Hang doi luc nay la: "<<endl;
	ShowQueue(qu);
	return 0;
}