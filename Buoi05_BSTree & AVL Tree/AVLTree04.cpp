//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include"Books.h"
#include"ASCIInode.h"
//Do thoi gian hoc ly thuyet ngan,nen thay chi day thuaatj toan
// vi vay em khong hieu code trong sach(phan BalFactor) nen em danh hoc tu been ngoai
// em xin loi vi dieu nay a!

using namespace std;
int Node(AVLBOOK* root) {
	if (root == NULL) return 0;
	return 1 + Node(root->Left) + Node(root->Right);
}
void menu() {
	cout << "**********************************************" << endl;
	cout << "0. Thoat." << endl;
	cout << "1. Nhap danh sach." << endl;
	cout << "2. Duyet danh sach." << endl;
	cout << "3. Dem so luong quyen sach xuat ban vao nam x." << endl;
	cout << "4. Xoa nut co ma z." << endl;
	cout << "5. xoa toan bo cay." << endl;
	cout << "***********************************************" << endl;
	cout << "\tOPTION:";
}
void End() {
	system("pause");
	system("cls");
}
int main() {
	BookAvlTree tr;
	InitBooks_AVL(tr);
	int z;
	do {
		menu();
		cin >> z;
		system("cls");
		switch (z) {
		case 1: {
			cin.ignore();
			InputTree(tr.root);
			End();
			break;
		}
		case 2: {
			cout << Node(tr.root)<<endl;
			print_ascii_treeBooks(tr.root);
			cout << endl << "Duyet cay: " << endl;
			cout << "+ LNR:" << endl; TraverseLNRBooks(tr.root);
			cout << endl;
			cout << "+ RNL:" << endl; TraverseRNLBooks(tr.root);
			cout << endl;
			cout << "+ LRN:" << endl; TraverseLRNBooks(tr.root);
			cout << endl;
			cout << "+ RNL:" << endl; TraverseRNLBooks(tr.root);
			cout << endl;
			cout << "+ LRN:" << endl; TraverseLRNBooks(tr.root);
			cout << endl;
			cout << "+ RLN:" << endl; TraverseRLNBooks(tr.root);
			cout << endl;
			End();
			break;
		}
		case 3: {
			int n; cout << "Nhap nam xuat ban can kiem tra:"; cin >> n;
			cout << "So luong cuon sach co nam xuat ban " << n << " la: " << cnt(tr.root, n)<<endl;
			End();
			break;
		}
		case 4: {
			cin.ignore();
			string s;
			cout << "Nhap ma sach: "; getline(cin, s);
			Dlt_AVLbook(tr.root, s);
			End();
			break;
		}
		case 5: {
			Dlt_Books(tr.root);
			End();
			break;
		}
		}
	} while (z != 0);
	return 0;
}