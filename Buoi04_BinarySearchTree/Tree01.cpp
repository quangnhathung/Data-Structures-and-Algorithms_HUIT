//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT#include "Binarysearchtreewithint.h"
#include "ASCIInode.h"
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
	BinarySearchTree tr;
	Init_BinarySearchTree(tr);
	int n;
	srand(time(0));
	cout << "Nhap luong so nguyen: "; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		Add_Tree(tr.Root, CreateTreeNode(x));
	}
	cout << "DUYET CAY: " << endl;
	cout << "LNR: "; TraverseLNR(tr.Root);
	cout << endl << "RNL: "; TraverseRNL(tr.Root);
	cout << endl << "LRN: "; TraverseLRN(tr.Root);
	cout << endl << "RLN: "; TraverseRLN(tr.Root);
	cout << endl << "NRL: "; TraverseNRL(tr.Root);
	cout << endl << "NLR: "; TraverseNLR(tr.Root);
	cout << endl;
	system("pause");
	system("cls");
	cout << "Ban muon kiem tra phan tu co gia tri bao nhieu trong cay: ";
	int x; cin >> x;
	if (FindTreeNode(tr.Root,x) != NULL) {
		cout << "Tim thay gia tri " << FindTreeNode(tr.Root, x)->data << " trong cay.";
	}
	else {
		cout << x << " Khong ton tai!" << endl;
	}
	cout << endl << "Chieu cao cua cay la: " << HeightTree(tr.Root);
	return 0;
}