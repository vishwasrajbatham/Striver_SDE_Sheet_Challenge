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
    int fun(TreeNode* node, bool &bal){
        
        if(!node)   return 0;
        int lh=fun(node->left,bal);
        int rh=fun(node->right,bal);
        if()
    }
public:
    bool isBalanced(TreeNode* root) {
        
    }
};