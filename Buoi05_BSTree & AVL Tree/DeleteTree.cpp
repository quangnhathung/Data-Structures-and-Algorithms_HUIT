#include"DeleteTree.h"
using namespace std;

void dlt_Tree(TreeNode*& root) {
	if (root == NULL) return;
	//xoa left right truoc. xoa node trc sai
	dlt_Tree(root->Left);
	dlt_Tree(root->Right);
	if (root->Left == NULL && root->Right == NULL) {
		TreeNode* t = root;
		root = NULL;
		delete t;
	}

	return;
}