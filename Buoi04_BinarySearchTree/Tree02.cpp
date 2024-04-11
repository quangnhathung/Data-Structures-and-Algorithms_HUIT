#include "CalculateTree.h"
#include "ASCIInode.h"
#include "input.h"
using namespace std;
void Menu1() {
	cout << "********************************************" << endl;
	cout << "0. Thoat" << endl;
	cout << "1. Tao cay nhi phan tim kiem." << endl;
	cout << "2. Duyet cay." << endl;
	cout << "3. Them nut vao cay." << endl;
	cout << "4. Kiem tra x co ton tai tren cay hay khong." << endl;
	cout << "5. Liet ke cac phan tu co gia tri lon hon x." << endl;
	cout << "6. Tinh toan tren cay!" << endl;
	cout << "********************************************" << endl;
	cout << "\tOPTION: ";
}
void Menu2() {
	cout << "**********************" << endl;
	cout << "1. Tu mang" << endl;
	cout << "2. Nhap tu ban phim." << endl;
	cout << "3. Random." << endl;
	cout << "4. Tu file cho truoc." << endl;
	cout << "**********************" << endl;
	cout << "\tOPTION: ";
}
void Menu3() {
	cout << "*****************************" << endl;
	cout << "0. Thoat" << endl;
	cout << "1. Dem nut tren cay" << endl;
	cout << "2. Dem so nut la." << endl;
	cout << "3. Dem so nut co 1 nut con" << endl;
	cout << "4. Dem so nut co 2 nut con" << endl;
	cout << "5. Tinh tong cac nut tren cay" << endl;
	cout << "6. Tinh tong cac nut la" << endl;
	cout << "7. Tinh tong cac nut co 1 con" << endl;
	cout << "8. Tinh tong cac nut co 2 con" << endl;
	cout << "9. Tinh chieu cao cua cay." << endl;
	cout << "*****************************" << endl;
	cout << "\tOPTION: ";
}
void End() {
	system("pause");
	system("cls");
}
int main() {
	BinarySearchTree tr;
	Init_BinarySearchTree(tr);
	int z;
	do {
		Menu1();
		cin >> z;
		system("cls");
		switch (z) {
		case 1: {
			int x;
			Menu2();
			cin >> x;
			system("cls");
			switch (x) {
			case 1: {
				InputFromArray(tr.Root);
				End();
				break;
			}
			case 2: {
				InputfromKeyboard(tr.Root);
				End();
				break;
			}
			case 3: {
				InputRandom(tr.Root);
				End();
				break;
			}
			case 4: {
				InputFromFile(tr.Root);
				End();
				break;
			}
			}
			break;
		}
		case 2: {
			cout << "Cay nhi phan da tao: " << endl;
			print_ascii_tree(tr.Root);
			cout << endl;
			cout << "DUYET CAY: " << endl;
			cout << "LNR: "; TraverseLNR(tr.Root);
			cout << endl << "RNL: "; TraverseRNL(tr.Root);
			cout << endl << "LRN: "; TraverseLRN(tr.Root);
			cout << endl << "RLN: "; TraverseRLN(tr.Root);
			cout << endl << "NRL: "; TraverseNRL(tr.Root);
			cout << endl << "NLR: "; TraverseNLR(tr.Root);
			cout << endl;
			End();
			break;
		}
		case 3: {
			int x;
			cout << "Nhap gia tri nut muon them vao cay: "; cin >> x;
			Add_Tree(tr.Root, CreateTreeNode(x));
			cout << "Done!" << endl;
			End();
			break;
		}
		case 4: {
			int x;
			cout << "Nhap gia tri x muon kiem tra: "; cin >> x;
			if (FindTreeNode(tr.Root, x) != NULL) {
				cout << "Tim thay gia tri " << FindTreeNode(tr.Root, x)->data << " trong cay." << endl;
			}
			else {
				cout << "Khong tim thay gia tri nao bang " << x << " trong cay!" << endl;
			}
			End();
			break;
		}
		case 5: {
			int x;
			cout << "Nhap gia tri x: "; cin >> x;
			ListedGreaterThanx(tr.Root, x);
			cout << endl;
			End();
			break;
		}
		case 6: {
			int x;
			do{
			Menu3();
			cin >> x;
			system("cls");
			switch (x) {
			case 1: {
				cout << "Cay hien tai co " << CountPat(tr.Root) << " nut." << endl;
				End();
				break;
			}
			case 2: {
				cout << "Cay hien tai co " << CountLeaf(tr.Root) << " nut la." << endl;
				End();
				break;
			}
			case 3: {
				cout << "So nut co 1 con: " << CountNodeHasOneChild(tr.Root) << endl;
				End();
				break;
			}
			case 4: {
				cout << "So nut co 2 con: " << CountNodeHasTwoChild(tr.Root) << endl;
				End();
				break;
			}
			case 5: {
				cout << "Tong cac nut tren cay la: " << SumTree(tr.Root) << endl;
				End();
				break;
			}
			case 6: {
				cout << "Tong cac nut la tren cay la: " << SumLeaf(tr.Root) << endl;
				End();
				break;
			}
			case 7: {
				cout << "Tong cac nut co 1 con tren cay la: " << SumNodeHasOneChild(tr.Root) << endl;
				End();
				break;
			}
			case 8: {
				cout << "Tong cac nut co 2 con tren cay la: " << SumNodeHasTwoChild(tr.Root) << endl;
				End();
				break;
			}
			case 9: {
				cout << "Chieu cao cua cay la: " << HeightTree(tr.Root) << endl;
				End();
				break;
			}
			}
		}while (x != 0);
		break;
		}
		}
	} while (z != 0);
	return 0;
}