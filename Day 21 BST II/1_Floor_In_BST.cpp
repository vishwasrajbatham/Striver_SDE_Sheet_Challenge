#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int floorInBST(TreeNode * root, int x)
{
   int floor=-1;
   while(root){
       if(root->val==x) return x;
       
       else if(x<root->val)    root=root->left;
       
       else{
           floor=root->val;
           root=root->right;  
       }
   
   }
return floor;
}

