//Link github: https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<vector>
using namespace std;
//Tao Cau truc
struct SNode{
	int Data;
	SNode *Next;
};
struct SList{
	SNode *Head;
	SNode *Tail;
};
//ham
void Init_Slist(SList &sl){
	sl.Head = sl.Tail = NULL;
}
bool IsEmpty(SList sl){
	if (sl.Head == NULL) return true;
	return false;
}
//Tao node
SNode* CreaateSNode(int x){
	SNode*p = new SNode;
	p->Data = x;
	p->Next = NULL;
	return p;
}
//Them Node
void Add_Head(SList &sl, SNode* p){
	if (IsEmpty(sl)){
		sl.Head = sl.Tail = p;
		return;
	}
	p->Next = sl.Head;
	sl.Head = p;
	return;
}
void Add_Tail(SList &sl, SNode *p){
	if (IsEmpty(sl)){
		sl.Head = sl.Tail = p;
		return;
	}
	sl.Tail->Next = p;
	sl.Tail = p;
}
//Nhap du lieu
void InputByHand(SList &sl,int n){
	cout << "Ban muon kieu them dau hay cuoi:"<<endl;
	cout << "1. Them dau\n2. Them cuoi\n\tOPTION:"<<endl;
	int x;
	cin >> x;
	switch (x){
	case 1:{
			   int y;
			   for (int i = 0; i < n; i++){
				   cin >> y;
				   Add_Head(sl, CreaateSNode(y));
			   }
			   break;
	}
	case 2:
		int y;
		for (int i = 0; i < n; i++){
			cin >> y;
			Add_Tail(sl, CreaateSNode(y));
		}
		break;
	}
}
void InputRandom(SList &sl, int n){
	srand(time(0));
	cout << "Ban muon kieu them dau hay cuoi:" << endl;
	cout << "1. Them dau\n2. Them cuoi\n\tOPTION: " << endl;
	int x;
	cin >> x;
	switch (x){
	case 1:{
			   int y;
			   for (int i = 0; i < n; i++){
				   y=rand()%100;
				   Add_Head(sl, CreaateSNode(y));
			   }
			   break;
	}
	case 2:
		int y;
		for (int i = 0; i < n; i++){
			y = rand() % 100;
			Add_Tail(sl, CreaateSNode(y));
		}
		break;
	}

}
void Menu(){
	cout <<endl<< "***********************************************"<<endl;
	cout << "0. Thoat chuong trinh.\n1. Them phan tu.\n2. Xuat danh sach."<<endl;
	cout << "3. Chen gia tri truoc gia tri tim kiem.\n4. Sap xep tang dan."<<endl;
	cout << "5. Sap xep giam dan.\n6. Dem so nguyen to.\n7. Tinh tong cac so chinh phuong." << endl;
	cout << "8. Gia tri lon nhat, nho nhat.\n9. Dem phan tu lon hon gap doi phan tu sau no." << endl;
	cout << "10. Tao 2 danh sach chan le."<<endl;
	cout << "***********************************************\n\tOPTION:";
}
void PrintList(SList sl){
	SNode *p = sl.Head;
	if (IsEmpty(sl)) {
		cout << "Danh sach rong !!";
		return;
	}
	while (p != NULL){
		cout << p->Data << " ";
		p = p->Next;
	}
	cout << endl;
}
//chen x vao truoc y
SNode* GetPrv(SList sl, SNode* p) {//lay node phia truoc
	SNode* q = sl.Head;
	if (p == NULL) { return NULL; }
	while (q->Next != p) {
		q = q->Next;
	}
	return q;
}
SNode* GetNode(SList sl, int x) {//lay node co gia tri x
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data == x) return p;
		p = p->Next;
	}
	return NULL;//khong tim thay
}
void Add_Prv(SList &sl, SNode* p, SNode* q) {//q nut chua du lieu
	if (p == NULL || q == NULL) {
		cerr << "Loi khong tim thay du lieu"<<endl;
		return;
	}
	if (q == sl.Head) {
		Add_Head(sl, p);
	}
	SNode* pr = GetPrv(sl, q);
	p->Next = q;
	pr->Next = p;
	cout << "thanh cong"<<endl;
}
//sap sep tang dan, giam dan
void swap(SNode* p, SNode* q) {//ham doi gia tri
	int temp = p->Data;
	p->Data = q->Data;
	q->Data = temp;
}
void AtoZ(SList &sl) {
	for (SNode* p = sl.Head; p != NULL; p=p->Next) {
		for (SNode* q = p; q != NULL; q=q->Next) {
			if (p->Data > q->Data) {
				swap(p, q);
			}
		}
	}
}
void ZtoA(SList &sl) {
	for (SNode* p = sl.Head; p != NULL; p=p->Next) {
		for (SNode* q = p; q != NULL; q=q->Next) {
			if (p->Data < q->Data) {
				swap(p, q);
			}
		}
	}
}
//dem so nguyen to
bool checknt(int n) {
	for (int i = 2; i < (int)sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int countnt(SList sl) {
	int cnt = 0;
	SNode* p = sl.Head;
	while (p != NULL) {
		if (checknt(p->Data)) cnt++;
		p = p->Next;
	}
	return cnt;
}
//tinh tong so chinh phuong
bool Squarenumber(int n) {
	int x = (int)sqrt(n);
	if (x * x == n) return true;
	return false;
}
int Sumsqun(SList sl) {
	int sum = 0;
	SNode* p = sl.Head;
	while (p != NULL) {
		if (Squarenumber(p->Data)) sum += p->Data;
		p = p->Next;
	}
	return sum;
}
//Tim min,max
int min(SList sl) {
	int min = sl.Head->Data;
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data < min) min = p->Data;
		p = p->Next;
	}
	return min;
}
int max(SList sl) {
	int max = sl.Head->Data;
	SNode* p = sl.Head;
	while (p != NULL) {
		if (p->Data > max) max = p->Data;
		p = p->Next;
	}
	return max;
}
vector<int> kq;//khai bap ngoia ham main de dung duoc cho that ca cac ham
//dem phan tu co gia tri lon gap doi gia tri phan tu sau no
int count(SList sl) {
	int cnt = 0;
	SNode* p = sl.Head;
	while (p != NULL) {
		SNode* q = p->Next;
		if (q == NULL) break;
		if (p->Data == ((q->Data) * 2)) {
			kq.push_back(p->Data);
			cnt++;
		}
		p = p->Next;
	}
	return cnt;
}
int main(){
	SList sl;
	Init_Slist(sl);
	int x;
	do{
		// ***********
		Menu();
		// ***********
		cin >> x;
		system("cls");
		switch (x){
		case 1:{
				   cout << " Nhap so luong phan tu muon them: ";
				   int n; cin >> n;
				   int j;
				   cout << "Ban muon them kieu nao? \n1. Them thu cong.\n2. Ngau nhien.\n\tOPTION: ";
				   cin >> j;
				   switch (j){
				   case 1:{
							  InputByHand(sl, n);
							  break;
				   }
				   case 2:{
							  InputRandom(sl, n);
							  break;
				   }
				   }
				   system("cls");
				   break;
		}
		case 2:{
				   PrintList(sl);
				   break;
		}
		case 3: {
			if (IsEmpty(sl)) {
				cerr << "Du lieu rong!"<<endl;
					break;
			}
			int x, y;
			cout << "Nhap gia tri muon them: "; cin >> x;
			cout << "banj muon them vaof truoc gia tri bao nhieu?: "; cin >> y;
			Add_Prv(sl, CreaateSNode(x), GetNode(sl,y));
			break;
		}
		case 4: {
			AtoZ(sl);
			break;
		}
		case 5: {
			ZtoA(sl);
			break;
		}
		case 6: {
			if (IsEmpty(sl)) {
				cerr << "Danh sach rong!!";//in loi bang lenh cerr hay cout. cerr nhin trong sang hon
				break;
			}
			cout <<"Co "<< countnt(sl)<< " so nguyen to trong danh dach"<<endl;
			break;
		}
		case 7: {
			if (IsEmpty(sl)) {
				cerr << "Danh sach rong!!";//in loi bang lenh cerr hay cout. cerr nhin trong sang hon
				break;
			}
			cout << "Tong cac so chinh phuong co trong danh sach la: " << Sumsqun(sl) << endl;
			break;
		}
		case 8: {
			cout << "Gia tri lon nhat la: " << max(sl) << endl;
			cout << "Gia tri nho nhat la: " << min(sl) << endl;
		}
		case 9: {
			cout << "Dem duoc " << count(sl) << " so trong danh sach."<<endl;
			cout << "Cac so do la: ";
			for (auto it = kq.begin(); it != kq.end(); it++) {//duyet vecto bang auto
				cout << *it;
			}
			break;
		}
		case 10: {
			SList sl1, sl2;
			Init_Slist(sl1);
			Init_Slist(sl2);
			SNode* p = sl.Head;
			while (p != NULL) {
				if (p->Data % 2 == 0) Add_Tail(sl1, CreaateSNode(p->Data));
				else Add_Tail(sl2, CreaateSNode(p->Data));
				p = p->Next;
			}
			cout << "Danh sach chan la: " << endl;
			PrintList(sl1);
			cout << "Danh sach le la: " << endl;
			PrintList(sl2);
			break;
		}
		}
	} while (x != 0);
	system("pause");
}