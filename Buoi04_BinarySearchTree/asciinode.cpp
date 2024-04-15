﻿//Github:https://github.com/quangnhathung/Data-Structures-and-Algorithms_HUIT
#include"ASCIInode.h"
#define MAX_HEIGHT 100
int lprofile[MAX_HEIGHT];
int rprofile[MAX_HEIGHT];

//===============================================================================
int MIN(int X, int Y)
{
    return ((X) < (Y)) ? (X) : (Y);
}
//===============================================================================
int MAX(int X, int Y)
{
    return ((X) > (Y)) ? (X) : (Y);
}
//===============================================================================
//adjust gap between left and right nodes
int gap = 3;
//used for printing next node in the same level, 
//this is the x coordinate of the next char printed
int print_next;
asciinode* build_ascii_tree_recursive(TreeNode* t)
{
    asciinode* node;

    if (t == NULL) return NULL;

    node = new asciinode;
    node->left = build_ascii_tree_recursive(t->Left);
    node->right = build_ascii_tree_recursive(t->Right);

    if (node->left != NULL)
    {
        node->left->parent_dir = -1;
    }

    if (node->right != NULL)
    {
        node->right->parent_dir = 1;
    }

    sprintf_s(node->label, "%d", t->data);
    node->lablen = strlen(node->label);
    return node;
}
asciinode* build_ascii_tree_recursiveFrct(TreeNodeFrct* t)
{
    asciinode* node;

    if (t == NULL) return NULL;

    node = new asciinode;
    node->left = build_ascii_tree_recursiveFrct(t->Left);
    node->right = build_ascii_tree_recursiveFrct(t->Right);

    if (node->left != NULL)
    {
        node->left->parent_dir = -1;
    }

    if (node->right != NULL)
    {
        node->right->parent_dir = 1;
    }
    if (t->data.Mau == 1) {
        sprintf_s(node->label, "%d", t->data.Tu);
    }
    else {
        sprintf_s(node->label, "%d/%d", t->data.Tu,t->data.Mau);
    }
    node->lablen = strlen(node->label);
    return node;
}
asciinode* build_ascii_tree_recursiveChar(TreeNodeChar* t)
{
    asciinode* node;

    if (t == NULL) return NULL;

    node = new asciinode;
    node->left = build_ascii_tree_recursiveChar(t->Left);
    node->right = build_ascii_tree_recursiveChar(t->Right);

    if (node->left != NULL)
    {
        node->left->parent_dir = -1;
    }

    if (node->right != NULL)
    {
        node->right->parent_dir = 1;
    }
    sprintf_s(node->label, "%c", t->Data);
    node->lablen = strlen(node->label);
    return node;
}
//===============================================================================
//Copy the tree into the ascii node structre
asciinode* build_ascii_tree(TreeNode* t)
{
    asciinode* node;
    if (t == NULL) return NULL;
    node = build_ascii_tree_recursive(t);
    node->parent_dir = 0;
    return node;
}
asciinode* build_ascii_treeFrct(TreeNodeFrct* t)
{
    asciinode* node;
    if (t == NULL) return NULL;
    node = build_ascii_tree_recursiveFrct(t);
    node->parent_dir = 0;
    return node;
}
asciinode* build_ascii_treeChar(TreeNodeChar* t)
{
    asciinode* node;
    if (t == NULL) return NULL;
    node = build_ascii_tree_recursiveChar(t);
    node->parent_dir = 0;
    return node;
}
//Free all the nodes of the given tree
void deleteAscii(asciinode* root)
{
    if (root == NULL) return;
    deleteAscii(root->left);
    deleteAscii(root->right);
    delete root;
}
//===============================================================================
//The following function fills in the lprofile array for the given tree.
//It assumes that the center of the label of the root of this tree
//is located at a position (x,y).  It assumes that the edge_length
//fields have been computed for this tree.
void compute_lprofile(asciinode* node, int x, int y)
{
    int i, isleft;
    if (node == NULL) return;
    isleft = (node->parent_dir == -1);
    lprofile[y] = MIN(lprofile[y], x - ((node->lablen - isleft) / 2));
    if (node->left != NULL)
    {
        for (i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++)
        {
            lprofile[y + i] = MIN(lprofile[y + i], x - i);
        }
    }
    compute_lprofile(node->left, x - node->edge_length - 1, y + node->edge_length + 1);
    compute_lprofile(node->right, x + node->edge_length + 1, y + node->edge_length + 1);
}
//===============================================================================
void compute_rprofile(asciinode* node, int x, int y)
{
    int i, notleft;
    if (node == NULL) return;
    notleft = (node->parent_dir != -1);
    rprofile[y] = MAX(rprofile[y], x + ((node->lablen - notleft) / 2));
    if (node->right != NULL)
    {
        for (i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++)
        {
            rprofile[y + i] = MAX(rprofile[y + i], x + i);
        }
    }
    compute_rprofile(node->left, x - node->edge_length - 1, y + node->edge_length + 1);
    compute_rprofile(node->right, x + node->edge_length + 1, y + node->edge_length + 1);
}
//===============================================================================
//This function fills in the edge_length and 
//height fields of the specified tree
void compute_edge_lengths(asciinode* node)
{
    int h, hmin, i, delta;
    if (node == NULL) return;
    compute_edge_lengths(node->left);
    compute_edge_lengths(node->right);

    /* first fill in the edge_length of node */
    if (node->right == NULL && node->left == NULL)
    {
        node->edge_length = 0;
    }
    else
    {
        if (node->left != NULL)
        {
            for (i = 0; i < node->left->height && i < MAX_HEIGHT; i++)
            {
                rprofile[i] = -INFINITY;
            }
            compute_rprofile(node->left, 0, 0);
            hmin = node->left->height;
        }
        else
        {
            hmin = 0;
        }
        if (node->right != NULL)
        {
            for (i = 0; i < node->right->height && i < MAX_HEIGHT; i++)
            {
                lprofile[i] = INFINITY;
            }
            compute_lprofile(node->right, 0, 0);
            hmin = MIN(node->right->height, hmin);
        }
        else
        {
            hmin = 0;
        }
        delta = 4;
        for (i = 0; i < hmin; i++)
        {
            delta = MAX(delta, gap + 1 + rprofile[i] - lprofile[i]);
        }

        //If the node has two children of height 1, then we allow the
        //two leaves to be within 1, instead of 2 
        if (((node->left != NULL && node->left->height == 1) ||
            (node->right != NULL && node->right->height == 1)) && delta > 4)
        {
            delta--;
        }

        node->edge_length = ((delta + 1) / 2) - 1;
    }

    //now fill in the height of node
    h = 1;
    if (node->left != NULL)
    {
        h = MAX(node->left->height + node->edge_length + 1, h);
    }
    if (node->right != NULL)
    {
        h = MAX(node->right->height + node->edge_length + 1, h);
    }
    node->height = h;
}
//===============================================================================
//This function prints the given level of the given tree, assuming
//that the node has the given x cordinate.
void print_level(asciinode* node, int x, int level)
{
	set_Color(0, 0);	//Black=0
    int i, isleft;
    if (node == NULL) return;
    isleft = (node->parent_dir == -1);
    if (level == 0)
    {
        for (i = 0; i < (x - print_next - ((node->lablen - isleft) / 2)); i++)
        {
			set_Color(0, 0);	//Black=0
            printf_s(" ");
        }
        print_next += i;
        //print node
		set_Color(7, 0);		//Light Yellow=14 (E), Green=2		
        printf_s("%s", node->label);
		set_Color(0, 0);		//Black=0
        print_next += node->lablen;
    }
    else if (node->edge_length >= level)
    {
        if (node->left != NULL)
        {
            for (i = 0; i < (x - print_next - (level)); i++)
            {
				set_Color(0, 0);	//Black=0
                printf_s(" ");
            }
            print_next += i;
			set_Color(0, 15);		//Bright White=15	
            printf_s("/");
			set_Color(0, 0);		//Black=0
            print_next++;
        }
        if (node->right != NULL)
        {
            for (i = 0; i < (x - print_next + (level)); i++)
            {
				set_Color(0, 0);	//Black=0
                printf_s(" ");
            }
            print_next += i;
			set_Color(0, 15);		//Bright White=15
            printf_s("\\");
			set_Color(0, 0);		//Black=0
            print_next++;
        }
    }
    else
    {
        print_level(node->left,
            x - node->edge_length - 1,
            level - node->edge_length - 1);
        print_level(node->right,
            x + node->edge_length + 1,
            level - node->edge_length - 1);
    }
}
//===============================================================================
//prints ascii tree for given Tree structure
void print_ascii_tree(TreeNode* t)
{
    asciinode* proot;
    int xmin, i;
    if (t == NULL) return;
    proot = build_ascii_tree(t);
    compute_edge_lengths(proot);
    for (i = 0; i < proot->height && i < MAX_HEIGHT; i++)
    {
        lprofile[i] = INFINITY;
    }
    compute_lprofile(proot, 0, 0);
    xmin = 0;
    for (i = 0; i < proot->height && i < MAX_HEIGHT; i++)
    {
        xmin = MIN(xmin, lprofile[i]);
    }
    for (i = 0; i < proot->height; i++)
    {
        print_next = 0;
        print_level(proot, -xmin, i);
        printf_s("\n");
    }
    if (proot->height >= MAX_HEIGHT)
    {
        printf_s("(This tree is taller than %d, and may be drawn incorrectly.)\n", MAX_HEIGHT);
    }
    deleteAscii(proot);
	set_Color(0, 15);		//Black=0 - Bright White=15
}
void print_ascii_treeFrct(TreeNodeFrct* t)
{
    asciinode* proot;
    int xmin, i;
    if (t == NULL) return;
    proot = build_ascii_treeFrct(t);
    compute_edge_lengths(proot);
    for (i = 0; i < proot->height && i < MAX_HEIGHT; i++)
    {
        lprofile[i] = INFINITY;
    }
    compute_lprofile(proot, 0, 0);
    xmin = 0;
    for (i = 0; i < proot->height && i < MAX_HEIGHT; i++)
    {
        xmin = MIN(xmin, lprofile[i]);
    }
    for (i = 0; i < proot->height; i++)
    {
        print_next = 0;
        print_level(proot, -xmin, i);
        printf_s("\n");
    }
    if (proot->height >= MAX_HEIGHT)
    {
        printf_s("(This tree is taller than %d, and may be drawn incorrectly.)\n", MAX_HEIGHT);
    }
    deleteAscii(proot);
    set_Color(0, 15);		//Black=0 - Bright White=15
}
void print_ascii_treeChar(TreeNodeChar* t)
{
    asciinode* proot;
    int xmin, i;
    if (t == NULL) return;
    proot = build_ascii_treeChar(t);
    compute_edge_lengths(proot);
    for (i = 0; i < proot->height && i < MAX_HEIGHT; i++)
    {
        lprofile[i] = INFINITY;
    }
    compute_lprofile(proot, 0, 0);
    xmin = 0;
    for (i = 0; i < proot->height && i < MAX_HEIGHT; i++)
    {
        xmin = MIN(xmin, lprofile[i]);
    }
    for (i = 0; i < proot->height; i++)
    {
        print_next = 0;
        print_level(proot, -xmin, i);
        printf_s("\n");
    }
    if (proot->height >= MAX_HEIGHT)
    {
        printf_s("(This tree is taller than %d, and may be drawn incorrectly.)\n", MAX_HEIGHT);
    }
    deleteAscii(proot);
    set_Color(0, 15);		//Black=0 - Bright White=15
}
//===============================================================================
void set_Color(int colorBackground, int colorText) {
	HANDLE hColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hColor, colorBackground * 16 + colorText);
	/* BẢNG THÔNG SỐ MÀU SẮC
	0 = Black       8 = Gray
	1 = Blue        9 = Light Blue
	2 = Green       A = Light Green
	3 = Aqua        B = Light Aqua
	4 = Red         C = Light Red
	5 = Purple      D = Light Purple
	6 = Yellow      E = Light Yellow
	7 = White       F = Bright White
	=> set_Color(X); -> X = a*16 + b, a (background) và b (character)
	*/
}