#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

int findCeil(TreeNode *node, int x){
    int ceil=-1;
    if(!node)   return ceil;
    while(node){
        if(node->data==x)   return x;
        else if(node->data > x){
            ceil=node->data;
            node=node->left;
        }
        else    node=node->right;
    }
    return ceil;
}