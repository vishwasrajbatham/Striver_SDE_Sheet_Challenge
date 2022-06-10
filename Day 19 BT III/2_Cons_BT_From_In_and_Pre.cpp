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

class Solution {
private:
    TreeNode* buildit(int preStart, int ins, int preEnd, int inEnd, map<int,int> &m, vector<int>& preorder, vector<int>& inorder){
        if (preStart > preEnd || ins > inEnd) return NULL;

        TreeNode* root= new TreeNode(preorder[preStart]);
        
        int elem=m[root->val];

        int nElem=elem-ins;

        root->left = buildit(preStart+1, ins, preStart+nElem, elem-1, m, preorder, inorder);
        
        root->right = buildit(preStart+nElem+1, elem+1, preEnd, inEnd, m, preorder, inorder);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preEnd=preorder.size()-1, inEnd=inorder.size()-1;
        map<int,int> m;
        //fill indexes of inorder elements in map
        for(int i=0; i<=preEnd; i++)    m[inorder[i]]=i;
        return buildit(0, 0, preEnd, inEnd, m, preorder, inorder);   
    }
};  