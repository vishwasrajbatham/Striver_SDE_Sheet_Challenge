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
//Approach 1
/*
void create_inorder(TreeNode* root, vector<int> &inorder){
    if(root==NULL)  return;
    create_inorder(root->left, inorder);
    inorder.push_back(root->val);
    create_inorder(root->right, inorder);
    return;
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder={};
        create_inorder(root, inorder);
        return inorder[k-1];
    }
};
*/

//Approach 2


TreeNode* kthsmallest(TreeNode* root,int &k)
{
	if(root==NULL)	return NULL;
	
	TreeNode* left=kthsmallest(root->left,k);

	if(left!=NULL)  return left;

	k--;

	if(k==0)    return root;
	
	return kthsmallest(root->right,k);
}    

