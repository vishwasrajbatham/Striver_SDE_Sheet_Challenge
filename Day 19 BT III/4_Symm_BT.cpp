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
    bool checkSymmetry(TreeNode* l, TreeNode* r){
        if(!r and !l) return true;
        if( (l and !r) or (!l and r) or (l->val != r->val) )    return false;
        return (checkSymmetry(l->left, r->right) and checkSymmetry(r->left, l->right));
    }
public:
    bool isSymmetric(TreeNode* root) {
        return checkSymmetry(root->left, root->right);
    }
};