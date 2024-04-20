//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include "CalculateTree.h"
#include "ASCIInode.h"
#include "Input.h"
#include"DeleteTree.h"
using namespace std;
void TraverseNLR_withoutRecursion(TreeNode* root) {
	stack<TreeNode*> st;
	TreeNode* p = root;
	while (1) {
		while (p != NULL) {
			cout << p->data << " ";
			st.push(p);
			p = p->Left;
		}
		if (!st.empty()) {
			TreeNode* t = st.top();
			if (t->Right == NULL) {
				st.pop();
			}
			else {
				p = t->Right;
				st.pop();
			}
		}
		else break;
	}
}
void Menu1() {
	cout << "********************************************" << endl;
	cout << "0. Thoat" << endl;
	cout << "1. Tao cay nhi phan tim kiem." << endl;
	cout << "2. Duyet cay." << endl;
	cout << "3. Them nut vao cay." << endl;
	cout << "4. Kiem tra x co ton tai tren cay hay khong." << endl;
	cout << "5. Liet ke cac phan tu co gia tri lon hon x." << endl;
	cout << "6. Tinh toan tren cay!" << endl;
	cout << "7. Xoa." << endl;
	cout << "8. Duyet NLR khong de quy." << endl;
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
	cout << "*************************************************" << endl;
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
	cout << "10. Dem so nut lon hon x,be hon x." << endl;
	cout << "11. Dem so luong nut co trong 1 doan." << endl;
	cout << "12. Tim nut max/min." << endl;
	cout << "13. Liet ke cac nut o muc k." << endl;
	cout << "14. Dem so nut o muc k" << endl;
	cout << "15. Dem so nut la o muc k." << endl;
	cout << "16. Tim phan tu co gia tri gan voi x nhat" << endl;
	cout << "17. Tim phan tu co gia tri xa voi x nhat." << endl;
	cout << "18. Tong gia tri cua cay (khong dung de quy)." << endl;
	cout << "19. Tinh tong cac loai so cua cay." << endl;
	cout << "**************************************************" << endl;
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
			do {
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
				case 10: {
					int a;
					cout << "Nhap gia tri x: "; cin >> a;
					cout << "So nut lon hon x la:" << CountNodeGreater(tr.Root, a) << endl;
					cout << "So nut be hon x la:" << CountNodeLower(tr.Root, a) << endl;
					End();
					break;
				}
				case 11: {
					int a, b;
					cout << "Nhap can trai: "; cin >> a;
					cout << "Nhap can phai: "; cin >> b;
					cout << "So luong phan tu trong khoang la : "<<CountNodeInRange(tr.Root,a,b);
					End();
					break;
				}
				case 12: {
					TreeNode* max = CreateTreeNode(-1000);
					TreeNode* min = CreateTreeNode(1000);
					MaxTree(tr.Root, max);
					MinTree(tr.Root, min);
					cout << "Phan tu be nhat trong cay la: " << min->data<<endl;
					cout << "Phan tu lon nhat trong cay la: " << max->data << endl;
					End();
					break;
				}
				case 13: {
					int k;
					cout << "Nhap muc k: "; cin >> k;
					cout << "Cac nut o muc k la: ";
					ListedLevel(tr.Root, k);
					cout << endl;
					End();
					break;
				}
				case 14: {
					int k;
					cout << "Nhap muc k: "; cin >> k;
					cout << "So luong phan tu muc k la: "<<CountNodeLevel(tr.Root,k)<<endl;
					End();
					break;
				}
				case 15: {
					int k;
					cout << "Nhap muc k: "; cin >> k;
					cout << "So luong nut la o muc k la: " << CountleafofLevel(tr.Root, k) << endl;
					End();
					break;
				}
				case 16: {
					int min1, min2, value;
					cout << "Nhap gia tri x: "; cin >> value;
					min1=9999;
					min2 = 9999;
					MinDistance(tr.Root, min1, value, min2);
					cout << "Phan tu gan voi gia tri " << value << " la: " << FindTreeNode(tr.Root, min2)->data << endl;
					End();
					break;
				}
				case 17: {
					int max1, max2, value;
					cout << "Nhap gia tri x: "; cin >> value;
					max1 = 9999;
					max2 = 9999;
					MinDistance(tr.Root, max1, value, max2);
					cout << "Phan tu xa voi gia tri " << value << " la: " << FindTreeNode(tr.Root, max2)->data << endl;
					End();
					break;
				}
				case 18: {
					cout << "Tong cac phan tu cua cay la: " << SumTreeWithoutRecursion(tr.Root) << endl;
					End();
					break;
				}
				case 19: {
					cout << "Tong cac so nguyen to trong cay la: " << SumPrimeNum(tr.Root) << endl;
					cout << "Tong cac so chinh phuong trong cay la: " << SumPerfectSquare(tr.Root) << endl;
					cout << "Tong cac so hoan thien trong cay la: " << SumPerfectNumber(tr.Root) << endl;
					cout << "khong tim thay du lieu ve so thinh vuong."<< endl;
					cout << "Khong tim thay du lieu ve so yeu."<< endl;
					End();
					break;
				}
				}
			} while (x != 0);
			break;
		}
		case 7: {
			cout << "0. Thoat.\n1. Xoa phan tu co gia tri x.\n2. Xoa trai.\n";
			cout << "3. Xoa phai.\n4.Xoa toan bo cay." << endl;
			cout << "\tOPTION: "; int x; cin >> x;
			switch (x) {
			case 0: {
				break;
			}
			case 1: {
				int a;
				cout << "Nhap gia tri ban muon xoa: "; cin >> a;
				TreeNode* p = FindTreeNode(tr.Root, a);
				if (p == NULL) {
					cout << "khong tim thay phan tu" << endl;
					End();
					break;
				}
				else
					Dlt_TreeNode(tr.Root, a);
				End();
				break;
			}
			case 2: {
				int a;
				cout << "Nhap gia tri phan tu ban muon xoa ben trai: "; cin >> a;
				TreeNode* p = FindTreeNode(tr.Root, a);
				if (p == NULL) {
					cout << "khong tim thay phan tu" << endl;
					End();
					break;
				}
				else if (p->Left != NULL) {
					TreeNode* q = FindTreeNode(tr.Root, p->Left->data);
					if (q == NULL) {
						cout << "khong tim thay phan tu" << endl;
						End();
						break;
					}
					else Dlt_TreeNode(tr.Root, q->data);
				}
				else {
					cout << "khong tim thay phan tu" << endl;
					End();
					break;
				}
				End();
				break;
			}
			case 3: {
				int a;
				cout << "Nhap gia tri phan tu ban muon xoa ben phai: "; cin >> a;
				TreeNode* p = FindTreeNode(tr.Root, a);
				if (p == NULL) {
					cout << "khong tim thay phan tu" << endl;
					End();
					break;
				}
				else if (p->Right != NULL) {
					TreeNode* q = FindTreeNode(tr.Root, p->Right->data);
					if (q == NULL) {
						cout << "khong tim thay phan tu" << endl;
						End();
						break;
					}
					else Dlt_TreeNode(tr.Root, q->data);
				}
				else {
					cout << "khong tim thay phan tu" << endl;
					End();
					break;
				}
				End();
				break;
			}
			case 4: {
				dlt_Tree(tr.Root);
				cout << endl << "Done!" << endl;
				End();
				break;
			}
			}
			End();
			break;
		}
		case 8: {
			print_ascii_tree(tr.Root);
			cout << "NLR: ";
			TraverseNLR_withoutRecursion(tr.Root);
			cout << endl;
			End();
			break;
		}
		}
	} while (z != 0);
	return 0;
}