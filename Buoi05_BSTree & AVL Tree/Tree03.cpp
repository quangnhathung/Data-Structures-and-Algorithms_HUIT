
//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include "BinarySearchTreeWithFraction.h"
#include "input.h"
#include "ASCIInode.h"
#include "DeleteTree.h"
#include "CalculateTree.h"
using namespace std;
void Menu() {
	cout << "********************************************" << endl;
	cout << "0. Thoat" << endl;
	cout << "1. Tao cay nhi phan tim kiem." << endl;
	cout << "2. Duyet cay." << endl;
	cout << "3. Them nut vao cay." << endl;
	cout << "4. In truc quan cay hien tai" << endl;
	cout << "5. Dem cac phan tu co gia tri lon hon 1." << endl;
	cout << "6. Tim Phan tu." << endl;
	cout << "7. Toi gian cay." << endl;
	cout << "8. Xoa 1 phan so x" << endl;
	cout << "9. Xoa nhung phan so lon hon 2" << endl;
	cout << "10. Xoa nhung phan so co mau la so nguyen so" << endl;
	cout << "11. Xoa toan bo danh sach." << endl;
	cout << "********************************************" << endl;
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
	BinarySearchTreeFrct tr;
	Init_BinarySearchTreeFrct(tr);
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
				InputFromArrayFrct(tr.Root);
				End();
				break;
			}
			case 2: {
				InputfromKeyboardFrct(tr.Root);
				End();
				break;
			}
			case 3: {
				InputRandomFrct(tr.Root);
				End();
				break;
			}
			case 4: {
				InputFromFileFrct(tr.Root);
				End();
				break;
			}
			}
			break;
		}
		case 2: {
			cout << "Cay nhi phan da tao: " << endl;
			print_ascii_treeFrct(tr.Root);
			cout << endl;
			cout << "DUYET CAY: " << endl;
			cout << "LNR: "; TraverseLNRFrct(tr.Root);
			cout << endl << "RNL: "; TraverseRNLFrct(tr.Root);
			cout << endl << "LRN: "; TraverseLRNFrct(tr.Root);
			cout << endl << "RLN: "; TraverseRLNFrct(tr.Root);
			cout << endl << "NRL: "; TraverseNRLFrct(tr.Root);
			cout << endl << "NLR: "; TraverseNLRFrct(tr.Root);
			cout << endl;
			End();
			break;
		}
		case 3: {
			Fraction x;
			cout << "Nhap gia tri nut muon them vao cay: " << endl;
			cout << "\tTu: "; cin >> x.Tu;
			cout << "\tMau: "; cin >> x.Mau;
			Add_TreeFrct(tr.Root, CreateTreeNodeFrct(x));
			cout << "Done!" << endl;
			End();
			break;
		}
		case 4: {
			print_ascii_treeFrct(tr.Root);
			cout << endl;
			End();
			break;
		}
		case 5: {
			cout << "So luong phan so lon hown 1 la: " << CountFractionGreaterthan1(tr.Root) << endl;;
			End();
			break;
		}
		case 6: {
			Fraction x;
			cout << "Nhap gia tri x muon kiem tra: " << endl;
			cout << "\tTu: "; cin >> x.Tu;
			cout << "\tMau: "; cin >> x.Mau;
			if (FindTreeNodeFrct(tr.Root, x) != NULL) {
				cout << "Tim thay gia tri X trong cay." << endl;
			}
			else {
				cout << "Khong tim thay gia tri nao bang X trong cay!" << endl;
			}
			End();
			break;
		}
		case 7: {
			SimplifyTree(tr.Root);
			End();
			break;
		}
		case 8: {
			Fraction x;
			cout << "Nhap tu: "; cin >> x.Tu;
			cout << "Nhap mau: "; cin >> x.Mau;
			if (FindTreeNodeFrct(tr.Root, x) != NULL) {
				Dlt_TreeNodeFrct(tr.Root, x);
				cout << "Done!" << endl;
			}
			else {
				cout << "Phan so khong ton tai!"<<endl;
			}
			End();
			break;
		}
		case 9: {
			Dlt_FractionGreaterthan2(tr.Root);
			cout << "Done!" << endl;
			End();
			break;
		}
		case 10: {
			Dlt_FractionPrime(tr.Root);
			cout << "Done!" << endl;
			End();
			break;
		}
		case 11: {
			dlt_TreeFrct(tr.Root);
			if (tr.Root == NULL) cout << "ok" << endl;
			cout << "Done!"<< endl;
			End();
			break;
		}
		}
	} while (z != 0);
	return 0;
}