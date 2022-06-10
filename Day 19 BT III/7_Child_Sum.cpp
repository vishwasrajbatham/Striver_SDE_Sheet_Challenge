#include<bits/stdc++.h>
using namespace std;

struct BinaryTreeNode {
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode() : data(0), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
};

void changeTree(BinaryTreeNode * root) {
    
    if (root == NULL) return;
    int child = 0;
    
    if (root -> left)   child += root -> left -> data;
    
    if (root -> right)   child += root -> right -> data;
    

    if (child < root -> data) {

        if (root -> left)       root -> left -> data = root -> data;

        else if (root -> right)     root -> right -> data = root -> data;
        
    }

    changeTree(root -> left);
    changeTree(root -> right);

    int tot = 0;
    if (root -> left)     tot += root -> left -> data;

    if (root -> right)     tot += root -> right -> data;
    
    if (root -> left || root -> right)    root -> data = tot;

    return;

}