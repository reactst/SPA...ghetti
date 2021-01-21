#ifndef TREE_H
#define TREE_H
#include <string.h>
//opet se zali ovaj glupi program(nesto vezano za c++)
#pragma warning(disable : 4996)
#define max_velicina 1280
// �vor stabla sa pokaziva�om na rije� i na djecu �vora
typedef struct Node {
	char *word;
	struct Node *left, *right;
} Node;

// Stablo odnosno pokaziva� na korijen stabla
typedef Node* BSTree;

BSTree NewBSTree();

void AddNode(BSTree *bst, char *word);

int BSTHeight(BSTree bst);

void PrintBSTree(BSTree bst);

void SaveBSTree(BSTree bst, FILE *fd);

void DeleteBSTree(BSTree bst);

BSTree LoadBSTree(FILE *fd);

#endif