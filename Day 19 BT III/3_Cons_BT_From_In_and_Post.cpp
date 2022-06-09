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

struct TreeNode* newNode(int data)
{
    TreeNode* Node = new TreeNode();
    Node->val = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return (Node);
}

class Solution {
private:
    TreeNode* buildit(int pres, int prend, map<int,int> m, vector<int>& preorder){
        if (pres > prend) return NULL;
        
        int elindex=m[preorder[pres]];

        int noele=elindex-pres;

        TreeNode* root= new TreeNode(preorder[pres],buildit(pres+1, pres+noele, m, preorder),buildit(pres+noele+1, prend, m, preorder));
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int prestart=0,prend=preorder.size()-1;
        map<int,int> m;
        for(int i=0;i<=prend;i++)    m[inorder[i]]=i;
        return buildit(prestart, prend, m, preorder);
    }
};  