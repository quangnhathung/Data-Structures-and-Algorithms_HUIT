#include "BinarySearchTree.h"
#include "Input.h"
#include "CalculateTree.h"
#include "ASCIInode.h"

using namespace std;
void Menu() {
	cout << "*****************************"<<endl;
	cout << "0. Thoat." << endl;
	cout << "1. Tao cay nhi phan." << endl;
	cout << "2. Duyet cay theo NLR"<<endl;
	cout << "3. Tim kiem 1 nut bat ky" << endl;
	cout << "4. Tinh chieu cao cua cay." << endl;
	cout << "5. Dem so nut la o muc k." << endl;
	cout << "****************************" << endl;
	cout << "\tOPTION: ";
}
void Menu1() {
	cout << "**********************" << endl;
	cout << "1. Tu mang" << endl;
	cout << "2. Nhap tu ban phim." << endl;
	cout << "3. Random." << endl;
	cout << "4. Tu file cho truoc." << endl;
	cout << "**********************" << endl;
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
		Menu();
		cin >> z;
		system("cls");
		switch (z) {
		case 1: {
			int x;
			Menu1();
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
			TraverseNLR(tr.Root);
			cout << endl << endl;
			print_ascii_tree(tr.Root);
			cout << endl;
			End();
			break;
		}
		case 3: {
			int x;
			cout << "Nhap gia tri muon tim kiem: "; cin >> x;
			if (FindTreeNode(tr.Root, x) != NULL) {
				cout << "Tim thay!" << endl;
			}
			else {
				cout << "Khong tim thay!" << endl;
			}
			End();
			break;
		}
		case 4: {
			cout << "Chieu cao cua cay la: " <<HeightTree(tr.Root) << endl;
			End();
			break;
		}
		case 5: {
			int k;
			cout << "Nhap Nut k: "; cin >> k;
			cout << "So nut la o muc " << k << "la: " << CountleafofLevel(tr.Root, k) << endl;
			End();
			break;
		}
		}
	} while (z != 0);
	return 0;
}