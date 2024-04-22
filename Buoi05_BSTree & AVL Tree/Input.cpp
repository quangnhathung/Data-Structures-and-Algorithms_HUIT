//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include "BinarySearchTree.h"
#include<fstream>
#include "BinarySearchTreeWithFraction.h"
#include "Input.h"
using namespace std;
//Nhap tu ban phim
void InputfromKeyboard(TreeNode*& root) {
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
void InputFromArray(TreeNode*& root) {
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
void InputRandom(TreeNode*& root) {
	srand(time(NULL));
	int n;
	cout << "So luong phan tu muon them vao cay: "; cin >> n;
	for (int i = 0; i < n; i++) {
		int x = rand() % 100;
		Add_Tree(root, CreateTreeNode(x));
	}
	cout << "Done!" << endl;
}
//Nhap tu file 
void InputFromFile(TreeNode*& root) {
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
	cout << "Done!" << endl;
}
//*********************FRACTION**************************
//Nhap tu ban phim
void InputfromKeyboardFrct(TreeNodeFrct*& root) {
	int n;
	cout << "So luong phan tu muon them vao cay: "; cin >> n;
	for (int i = 0; i < n; i++) {
		Fraction x;
		cout << "Nhap phan tu thu " << i + 1 << ":" << endl;
		cout << "\tTu:"; cin >> x.Tu;
		cout << "\tMau:"; cin >> x.Mau;
		Add_TreeFrct(root, CreateTreeNodeFrct(x));
	}
	cout << "Done!" << endl;
}
//Nhap tu mang
void InputFromArrayFrct(TreeNodeFrct*& root) {
	int n; cout << "Nhap so luong phan tu cua mang: ";
	cin >> n;
	Fraction a[1000];
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << ":<<endl;";
		cout << "\tTu:"; cin >> a[i].Tu;
		cout << "\tMau:"; cin >> a[i].Mau;
		Add_TreeFrct(root, CreateTreeNodeFrct(a[i]));
	}
	cout << "Done!" << endl;
}
//Nhau nhien
void InputRandomFrct(TreeNodeFrct*& root) {
	srand(time(NULL));
	int n;
	cout << "So luong phan tu muon them vao cay: "; cin >> n;
	for (int i = 0; i < n; i++) {
		Fraction x;
		x.Tu = rand() % 100;
		x.Mau = rand() % 100;
		Add_TreeFrct(root, CreateTreeNodeFrct(x));
	}
	cout << "Done!" << endl;
}

//Nhap tu file 
void InputFromFileFrct(TreeNodeFrct*& root) {
	ifstream file("inputtree.txt");
	int n;
	cout << "So luong phan tu muon them vao cay: "; cin >> n;
	while (n) {
		Fraction x;
		file >> x.Tu;
		file >> x.Mau;
		Add_TreeFrct(root, CreateTreeNodeFrct(x));
		n--;
	}
	file.close();
	cout << "Done!" << endl;
}
//****************AVL FRACTION*****************
//Nhap tu ban phim
void InputfromKeyboardAVLFrct(AvlNodeFrct* &root) {
	int n;
	cout << "So luong phan tu muon them vao cay: "; cin >> n;
	for (int i = 0; i < n; i++) {
		Fraction x;
		cout << "Nhap phan tu thu " << i + 1 << ":" << endl;
		cout << "\tTu:"; cin >> x.Tu;
		cout << "\tMau:"; cin >> x.Mau;
		Add_AvlTreeFrct(root, CreateAVLNodeFrct(x));
	}
	cout << "Done!" << endl;
}
//Nhap tu mang
void InputFromArrayAVLFrct(AvlNodeFrct*& root) {
	int n; cout << "Nhap so luong phan tu cua mang: ";
	cin >> n;
	Fraction a[1000];
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << ":<<endl;";
		cout << "\tTu:"; cin >> a[i].Tu;
		cout << "\tMau:"; cin >> a[i].Mau;
		Add_AvlTreeFrct(root, CreateAVLNodeFrct(a[i]));
	}
	cout << "Done!" << endl;
}
//Nhau nhien
void InputRandomAVLFrct(AvlNodeFrct*& root) {
	srand(time(NULL));
	int n;
	cout << "So luong phan tu muon them vao cay: "; cin >> n;
	for (int i = 0; i < n; i++) {
		Fraction x;
		x.Tu = rand() % 100;
		x.Mau = rand() % 100;
		Add_AvlTreeFrct(root, CreateAVLNodeFrct(x));
	}
	cout << "Done!" << endl;
}

//Nhap tu file 
void InputFromFileAVLFrct(AvlNodeFrct*& root) {
	ifstream file("inputtree.txt");
	int n;
	cout << "So luong phan tu muon them vao cay: "; cin >> n;
	while (n) {
		Fraction x;
		file >> x.Tu;
		file >> x.Mau;
		Add_AvlTreeFrct(root, CreateAVLNodeFrct(x));
		n--;
	}
	file.close();
	cout << "Done!" << endl;
}