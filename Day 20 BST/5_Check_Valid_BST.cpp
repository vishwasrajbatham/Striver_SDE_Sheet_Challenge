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
class Solution {
private:
    bool check(TreeNode* node, long maxi, long mini){
        if(node==NULL)  return true;
        if(node->val >= maxi || node->val <= mini )   return false;
        return (check(node->left, node->val, mini) && check(node->right, maxi, node->val));
    }

public:
    bool isValidBST(TreeNode* node) {
        if(node==NULL)  return true;
        return check(node, LONG_MAX, LONG_MIN);
    }
};

//Approach 2 -> Better One
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }

    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
    
};