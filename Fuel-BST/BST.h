#ifndef BST_h
#define BST_h

struct node {
        int key;
        int data;
        node* left;
        node* right;
    };

node* newNode(int key, int data);
node* insert(node* _root,int key, int data);
int findclosestkey(node* _root, int key,int closest);
void inorder(node* _root);

#endif
