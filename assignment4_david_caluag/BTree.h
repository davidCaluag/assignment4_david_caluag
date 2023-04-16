#pragma once

#include<iostream>

using namespace std;

class BTreeNode {
public:

	int  data;
	BTreeNode* left;
	BTreeNode* right;

	BTreeNode(int num) {

		data = num;
		left = NULL;
		right = NULL;
	};

};

class BTree {
public:

	BTreeNode* root;
	BTree(BTreeNode* node) {
		root = node;
	}


	void preOrder(BTreeNode* node) { 
		if (node != NULL) { 
			cout << node->data << " ";
			preOrder(node->left);
			preOrder(node->right); 
		} 
	} //end preOrder 

	void postOrder(BTreeNode* node) {
		if (node != NULL) {
			
			postOrder(node->left);
			postOrder(node->right);
			cout << node->data << " ";
		}
	} //end postOrder


	void inOrder(BTreeNode* node) {
		if (node != NULL) {

			inOrder(node->left);
			cout << node->data << " ";
			inOrder(node->right);
			
		}
	} //end postOrder

	int numNodes(BTreeNode* root) {

		if (root == NULL)
			return 0;
		return 1 + numNodes(root->left) + numNodes(root->right);
	}

	int numLeaves(BTreeNode* root) {

		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return 1;
		else
			return numLeaves(root->left) + numLeaves(root->right);
		
	}

	int max(int a, int b) {

		return (a > b) ? a : b;
	}

	int height(BTreeNode* root) {

		if (root == NULL)
			return 0;
		return 1 + max(height(root->left),height(root->right));

	}




};
