#include"DeleteTree.h"

using namespace std;

void dlt_Tree(TreeNode*& root) {
	if (root == NULL) return;
	//xoa left right truoc. xoa node trc sai
	dlt_Tree(root->Left);
	dlt_Tree(root->Right);
	TreeNode* t = root;
	root = NULL;
	delete t;
	return;
}
//*****************FRACTION*******************
//xoa toan bo cay
void dlt_TreeFrct(TreeNodeFrct*& root) {
	if (root == NULL) return;
	dlt_TreeFrct(root->Left);
	dlt_TreeFrct(root->Right);
	TreeNodeFrct* t = root;
	root = NULL;
	delete t;
	return;
}
//xoa phan so lon hon 2
void Dlt_FractionGreaterthan2(TreeNodeFrct*& root) {
	if (root == NULL) return;
	Dlt_FractionGreaterthan2(root->Left);
	Dlt_FractionGreaterthan2(root->Right);
	if (FractionValue(root->data) > 2) {
		//la nut la
		if (root->Left == NULL && root->Right == NULL) {
			TreeNodeFrct* t = root;
			root = NULL;
			delete t;
		}
		//truowng hop co 1 nut con
		else if (root->Left == NULL) {
			TreeNodeFrct* t = root;
			root = root->Right;
			delete t;
		}
		else if (root->Right == NULL) {
			TreeNodeFrct* t = root;
			root = root->Left;
			delete t;
		}
		//truowg hop co 2 nut con
		else if (root->Left != NULL && root->Right != NULL) {
			TreeNodeFrct* t = FindNodeReplaceFrct(root);
			root->data = t->data;
			//vi cchon phai nhat ben trai nen goi root left
			//goi ham xoa gia tri 1 nut da biet
			Dlt_TreeNodeFrct(root->Left, t->data);
		}
		return;
	}
	return;
}
void Dlt_FractionPrime(TreeNodeFrct*& root) {
	if (root == NULL) return;
	Dlt_FractionPrime(root->Left);
	Dlt_FractionPrime(root->Right);
	if (CheckPrimeNum(root->data.Mau)) {
		//la nut la
		if (root->Left == NULL && root->Right == NULL) {
			TreeNodeFrct* t = root;
			root = NULL;
			delete t;
		}
		//truowng hop co 1 nut con
		else if (root->Left == NULL) {
			TreeNodeFrct* t = root;
			root = root->Right;
			delete t;
		}
		else if (root->Right == NULL) {
			TreeNodeFrct* t = root;
			root = root->Left;
			delete t;
		}
		//truowg hop co 2 nut con
		else if (root->Left != NULL && root->Right != NULL) {
			TreeNodeFrct* t = FindNodeReplaceFrct(root);
			root->data = t->data;
			//vi cchon phai nhat ben trai nen goi root left
			//goi ham xoa gia tri 1 nut da biet
			Dlt_TreeNodeFrct(root->Left, t->data);
		}
		return;
	}
	return;
}

