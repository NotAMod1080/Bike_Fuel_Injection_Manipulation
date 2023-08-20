/*BST To load Fuel Map into
V 0.0.1*/


#include "BST.h"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
//#include <arduino.h> to be used when creating arduino libraries

    

class BST {
    public:
    BST(){
        root = NULL;
    }
    node* root;
    node* newNode(int key, int data)  {
        //node* temp = (node*)malloc(sizeof(node)); this isnt C
        node* temp = new node;
        temp->key = key;
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    node* insert(node* _root,int key, int data) {
        if(_root == NULL){       //detect new BST construction
            return newNode(key,data);
        }
        if(key < _root->key){
            _root->left = insert(_root->left,key,data);
    }
        else if(key > _root->key){
            _root->right = insert(_root->right,key,data);
        }
        return _root;
    }
    int findclosestkey(node* _root, int key,int closest)    {
        if(_root == NULL)
            return closest;
        else if(abs(_root->key - key) < abs(closest-key)){  // regress through untill the smallest value is found then extract the data for the array position value
            closest = _root->data;
    }
        if(key < _root->key)   { //look left if its still less than
            return findclosestkey(_root->left,key,closest);
        }
        else{ //look right if its still greater than
            return findclosestkey(_root->right,key,closest);
        }
    }
    void inorder(node* _root) {
        if(_root == NULL)
            return;
        inorder(_root->left);
        std::cout << _root->key << " " << _root->data << "\n";
        inorder(_root->right);
    }
};
/*Create BST object
This keeps the data inside the object and can be named as such
To use insert mybst.root = mybst.insert(mybst.root,key,data)
To use inorder mybst.inorder(mybst.root)
The Closest key will find 0-500 as data 0, 501-999 as data 1, 1000-1499 as data 2, and so on
*/

int main()   { //testing function to validate functionality
    BST mybst = BST();
    int j = 0;
    for(int i = 500; i < 10501; i+=500) {
        mybst.root = mybst.insert(mybst.root,i,j);
        j++;
    }
    mybst.inorder(mybst.root);
    std::cout << mybst.findclosestkey(mybst.root,499,0) << "\n";
    std::cout << mybst.findclosestkey(mybst.root,500,0) << "\n";
    std::cout << mybst.findclosestkey(mybst.root,501,0) << "\n";
    std::cout << mybst.findclosestkey(mybst.root,999,0) << "\n";
    std::cout << mybst.findclosestkey(mybst.root,1000,0) << "\n";
    std::cout << mybst.findclosestkey(mybst.root,1001,0) << "\n";
    std::cout << mybst.findclosestkey(mybst.root,1499,0) << "\n";
    std::cout << mybst.findclosestkey(mybst.root,1500,0) << "\n";
    std::cout << mybst.findclosestkey(mybst.root,1501,0) << "\n";
    return 0;
 }

