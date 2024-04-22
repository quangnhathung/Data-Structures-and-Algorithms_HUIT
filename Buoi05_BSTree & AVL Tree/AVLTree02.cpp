#include"AVLtreeFrct.h"
#include "ASCIInode.h"
#include<cstdlib>
#include"Input.h"
using namespace std;

void menu() {
	cout << "**************************************************" << endl;
	cout << "0. Thoat." << endl;
	cout << "1. Khoi tao cay avl." << endl;
	cout << "2. Duyet cay." << endl;
	cout << "3. Them nut." << endl;
	cout << "4. Xoa nut." << endl;
	cout << "5. Dem nut lon hon 1." << endl;
	cout << "6. Liet ke phan so co cung mau so voi phan so x." << endl;
	cout << "7. Toi gian cay avl" << endl;
	cout << "8. Xoa toan bo cay" << endl;
	cout << "***************************************************" << endl;
	cout << "\tOPTION:";
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
	AvlTreeFrct tr;
	InitAVLTreeFrct(tr);
	srand(time(NULL));
	int z;
	do {
		menu();
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
				InputfromKeyboardAVLFrct(tr.Root);
				End();
				break;
			}
			case 2: {
				InputfromKeyboardAVLFrct(tr.Root);
				End();
				break;
			}
			case 3: {
				InputRandomAVLFrct(tr.Root);
				End();
				break;
			}
			case 4: {
				InputFromFileAVLFrct(tr.Root);
				End();
				break;
			}
			}
			break;
		}
		case 2: {
			cout << "Cay nhi phan da tao: " << endl;
			print_ascii_treeFrctAVL(tr.Root);
			cout << endl;
			cout << "DUYET CAY: " << endl;
			cout << "LNR: "; TraverseLNRFrctAVL(tr.Root);
			cout << endl << "RNL: "; TraverseRNLFrctAVL(tr.Root);
			cout << endl << "LRN: "; TraverseLRNFrctAVL(tr.Root);
			cout << endl << "RLN: "; TraverseRLNFrctAVL(tr.Root);
			cout << endl << "NRL: "; TraverseNRLFrctAVL(tr.Root);
			cout << endl << "NLR: "; TraverseNLRFrctAVL(tr.Root);
			cout << endl;
			End();
			break;
		}
		case 3: {
			Fraction x;
			cout << "Cay nhi phan da tao: " << endl;
			print_ascii_treeFrctAVL(tr.Root);
			cout << endl;
			cout << "Nhap tu: "; cin >> x.Tu;
			do {
				cout << "Nhap mau: "; cin >> x.Mau;
			} while (x.Mau == 0);
			Add_AvlTreeFrct(tr.Root, CreateAVLNodeFrct(x));
			cout << "Cay nhi phan sau khi them:" << endl;
			print_ascii_treeFrctAVL(tr.Root);
			cout << endl;
			End();
			break;
		}
		case 4: {
			Fraction x;
			cout << "Cay nhi phan da tao: " << endl;
			print_ascii_treeFrctAVL(tr.Root);
			cout << endl;
			cout << "Nhap tu: "; cin >> x.Tu;
			do {
				cout << "Nhap mau: "; cin >> x.Mau;
			} while (x.Mau == 0);
			Dlt_AvlNodeFrct(tr.Root,x);
			cout << "Cay nhi phan sau khi xoa:" << endl;
			print_ascii_treeFrctAVL(tr.Root);
			cout << endl;
			End();
			break;
		}
		case 5: {
			print_ascii_treeFrctAVL(tr.Root);
			cout << endl;
			cout << "So nut lon hon 1 la: " << CountFractionAvlTree(tr.Root)<<endl;
			End();
			break;
		}
		case 6: {
			Fraction x;
			cout << "Cay nhi phan da tao: " << endl;
			print_ascii_treeFrctAVL(tr.Root);
			cout << endl;
			cout << "Nhap tu: "; cin >> x.Tu;
			do {
				cout << "Nhap mau: "; cin >> x.Mau;
			} while (x.Mau == 0);
			cout << endl << "Cac phan so co mau trung la: ";
			Listed(tr.Root,x.Mau);
			End();
			break;
		}
		case 7: {
			FormatAVLTree(tr.Root);
			cout << "Done!" << endl;
			End();
			break;
		}
		case 8: {
			Dlt_avlTree(tr.Root);
			cout << "Done!" << endl;
			End();
			break;
		}
		}
	} while (z != 0);
	return 0;
 }