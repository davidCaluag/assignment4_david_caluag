#include <iostream>
#include "BTree.h"

using namespace std;


int main() {

	BTreeNode* node = new BTreeNode(1);

	node->left = new BTreeNode(2);
	node->right = new BTreeNode(3);
	node->right->left = new BTreeNode(4);
	node->right->left->right = new BTreeNode(5);

	BTree* bTree = new BTree(node);

	cout << "Preorder Traversal of the tree:" << endl;
	bTree->preOrder(bTree->root);
	cout << "****************************" << endl;

	cout << "inorder Traversal of the tree:" << endl;
	bTree->inOrder(bTree->root);
	cout << "****************************" << endl;

	cout << "Postorder Traversal of the tree:" << endl;
	bTree->postOrder(bTree->root);
	cout << "****************************" << endl;

	cout << "The number of nodes in this binary tree is: " << bTree->numNodes(bTree->root) << endl;

	cout << "The number of leaves in this binary tree is: " << bTree->numLeaves(bTree->root) << endl;

	cout << "The height of this binary tree is: " << bTree->height(bTree->root) << endl;

}