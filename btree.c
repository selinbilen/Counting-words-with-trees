#include "btree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct treeNode {
	char * payload;
	int count;
	struct treeNode * left;
	struct treeNode * right;
};

node newNode(char * word){
	node newnode = (node) malloc(sizeof(struct treeNode));
	newnode -> payload = strdup(word);
	newnode -> count = 1;
	newnode -> left = NULL;
	newnode -> right = NULL;
	return newnode;
}

void addTree(node root, char * word){
	assert (root != NULL);
	if (strcmp(word, root->payload)==0){
		root-> count++;
		return;
	}
	else if (strcmp(word, root->payload)<0){
		if (root->left == NULL){
			root->left = newNode(word);
		}
		else{
			addTree(root->left, word);
		}
	}
	else{
		if (root->right == NULL){
			root -> right= newNode(word);
		}
		else{
			addTree(root->right, word);
		}
	}
}

void printTree(node root){
	if (root == NULL) return;
	printTree(root->left);
	printf("%4d: %s\n", root->count, root->payload);
	printTree(root->right);
}

void freeTree(node root){
	if (root == NULL) return;
	freeTree(root -> left);
	freeTree(root -> right);
	free(root->payload);
	free(root);
}
