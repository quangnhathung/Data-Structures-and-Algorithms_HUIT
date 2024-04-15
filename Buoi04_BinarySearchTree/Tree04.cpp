//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include "BSTWithFraction.h"
#include "input.h"
#include "ASCIInode.h"
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
	cout << "8. Tong cac phan so trong cay." << endl;
	cout << "9. Phan so nho nhat, phan so lon nhat." << endl;
	cout << "10. Liet ke phan so lon hown 1, be hon 1." << endl;
	cout << "11. Liet ke cac phan so o muc k." << endl;
	cout << "12. Dem luong phan so o muc k." << endl;
	cout << "13. Tong phan so o muc k." << endl;
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
			cout << "Tong cac phan so co trong cay la: " << SumTreeFrct(tr.Root) << endl;
			End();
			break;
		}
		case 9: {
			Fraction min, max;
			print_ascii_treeFrct(tr.Root);
			min.Tu = 99999;
			min.Mau = 1;
			TreeNodeFrct* Min = CreateTreeNodeFrct(min);
			MinTreeFrct(tr.Root, Min);
			max.Tu = -99999;
			max.Mau = 1;
			TreeNodeFrct* Max = CreateTreeNodeFrct(max);
			MaxTreeFrct(tr.Root, Max);
			cout << "Phan tu lon nhat co gia tri la: ";
			if (Max->data.Mau == 1) {
				cout << Max->data.Tu << " ";
			}
			else {
				cout << Max->data.Tu << "/" << Max->data.Mau << " ";
			}
			cout << endl << "Phan tu be nhat co gia tri la: ";
			if (Min->data.Mau == 1) {
				cout << Min->data.Tu << " ";
			}
			else {
				cout << Min->data.Tu << "/" << Min->data.Mau << " " << endl;
			}
			End();
			break;
		}
		case 10: {
			cout << "Cac phan so lon hon 1 la: ";
			ListedGreaterThanFrct(tr.Root);
			cout << endl << "Cac phan so be hon 1 la: ";
			ListedlowerThanFrct(tr.Root);
			cout << endl;
			End();
			break;
		}
		case 11: {
			int k;
			int x = HeightTreeFrct(tr.Root);
			cout << "Nhap muc k ban muon: "; cin >> k;
			if (k > x) {
				cerr << "Muc k khong ton tai!"<<endl;
				break;
			}
			cout << "Cac phan tu o muc k la: ";
			ListedLevelFrct(tr.Root, k);
			cout << endl;
			End();
			break;
		}
		case 12: {
			int k;
			int x = HeightTreeFrct(tr.Root);
			cout << "Nhap muc k ban muon: "; cin >> k;
			if (k > x) {
				cerr << "Muc k khong ton tai!"<<endl;
				break;
			}
			cout << "So phan tu o muc k la : "<<CountnodeLevelFrct(tr.Root,k);
			cout << endl;
			End();
			break;
		}
		case 13: {
			int k;
			int x = HeightTreeFrct(tr.Root);
			cout << "Nhap muc k ban muon: "; cin >> k;
			if (k > x) {
				cerr << "Muc k khong ton tai!"<<endl;
				break;
			}
			cout << "Tong phan tu o muc k la : " << SumLevelFrct(tr.Root, k);
			cout << endl;
			End();
			break;
		}
		}
	} while (z != 0);
	return 0;
}