#include "Binarysearchtreewithint.h"
#include<fstream>
using namespace std;
//Nhap tu ban phim
void InputfromKeyboard(TreeNode* &root){
	int n;
	cout << "So luong phan tu muon them vao cay: "; cin >> n;
	cout << "Nhap phan tu: ";
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		Add_Tree(root, CreateTreeNode(x));
	}
	cout << "Done!" << endl;
}
//Nhap tu mang
void InputFromArray(TreeNode* &root) {
	int n; cout << "Nhap so luong phan tu cua mang: ";
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		Add_Tree(root, CreateTreeNode(a[i]));
	}
	cout << "Done!" << endl;
}
//Nhau nhien
void InputRandom(TreeNode* &root) {
	srand(time(NULL));
	int n;
	cout << "So luong phan tu muon them vao cay: "; cin >> n;
	for (int i = 0; i < n; i++) {
		int x=rand()%100; 
		Add_Tree(root, CreateTreeNode(x));
	}
	cout << "Done!" << endl;
}
//Nhap tu file 
void InputFromFile(TreeNode* &root) {
	ifstream file("inputtree.txt");
	int n;
	cout << "So luong phan tu muon them vao cay: "; cin >> n;
	while (n) {
		int x;
		file >> x;
		Add_Tree(root, CreateTreeNode(x));
		n--;
	}
	file.close();
	cout << "Done!"<<endl;
}
