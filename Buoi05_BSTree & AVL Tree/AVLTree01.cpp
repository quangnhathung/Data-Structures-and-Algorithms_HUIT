//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include"AVLTree.h"
#include "ASCIInode.h"
#include<cstdlib>
using namespace std;

//Do thoi gian hoc ly thuyet ngan,nen thay chi day thuaatj toan
// vi vay em khong hieu code trong sach(phan BalFactor) nen em danh hoc tu been ngoai
// em xin loi vi dieu nay a!

void Menu() {
	cout << "*************************" << endl;
	cout << "0. Thoat." << endl;
	cout << "1. Khoi tao cay avl." << endl;
	cout << "2. Duyet cay NLR." << endl;
	cout << "3. Them nut." << endl;
	cout << "4. Xoa nut." << endl;
	cout << "5. Tim kiem nut." << endl;
	cout << "*************************" << endl;
	cout << "\tOPTION:";
}
void End() {
	system("pause");
	system("cls");
}
int main() {
	AVLTree tr;
	Init_AVLTree(tr);
	int z;
	do{
		Menu();
		cin >> z;
		system("cls");
		switch (z) {
		case 1: {
			int n; 
			srand(time(NULL));
			cout << "Nhap so luong phan tu ban muon them vao cay: "; cin >> n;
			cout << "Them ngau nhien: " << endl;
			for (int i = 0; i < n; i++) {
				int x = rand() % 100;
				cout << "Them gia tri " << x << " vao cay: " << endl;
				Add_AvlTree(tr.Root, CreateAVLNode(x));
				cout << endl;
				print_ascii_treeAVL(tr.Root);
			}
			cout << endl;
			End();
			break;
		}
		case 2: {
			cout << endl;
			print_ascii_treeAVL(tr.Root);
			cout << endl<<"NLR: ";
			TraverseAVLtree_NLR(tr.Root);
			End();
			break;
		}
		case 3: {
			int x;
			cout << "Nhap gia tri cua nut can them: "; cin >> x;
			Add_AvlTree(tr.Root, CreateAVLNode(x));
			cout << endl;
			print_ascii_treeAVL(tr.Root);
			cout << endl;
			End();
			break;
		}
		case 4: {
			int x;
			cout << endl;
			print_ascii_treeAVL(tr.Root);
			cout << endl;
			cout << "Nhap gia tri cua nut can xoa: "; cin >> x;
			Dlt_AvlNode(tr.Root, x);
			cout << endl;
			print_ascii_treeAVL(tr.Root);
			cout << endl;
			End();
			break;
		}
		case 5: {
			int x;
			cout << "Nhap gia tri cua nut can tim: "; cin >> x;
			if (FindAvlNode(tr.Root, x) != NULL) {
				cout << "Ton tai!" << endl;
			}
			else {
				cout << "Khong ton tai!" << endl;
			}
			cout << endl;
			print_ascii_treeAVL(tr.Root);
			cout << endl;
			End();
			break;
		}
		}
		
	} while (z != 0);
	return 0;
}