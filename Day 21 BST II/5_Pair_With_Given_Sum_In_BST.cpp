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

class BSTIterator {

private:

    stack<TreeNode*> st;
    bool reverse=false;

    void push_nodes(TreeNode* node){
        while(node!=NULL){
            st.push(node);
            if(reverse == false)    node = node->left;
            else node = node->right;
        }
        return;
    }

public:

    BSTIterator(TreeNode* node, bool isrev) {    
        reverse = isrev;
        push_nodes(node);    
    }
    
    int next() {
        TreeNode* curr = st.top();
        st.pop();
        if(!reverse)    push_nodes(curr->right);
        else push_nodes(curr->left);
        return curr->val;
    }
    
    bool hasNext() {    return !st.empty();    }

};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        BSTIterator inc(root, false);
        BSTIterator dec(root, true);

        int l=inc.next();
        int r=inc.next();

        while(l<r){
            if(l+r==k)  return true;
            else if(l+r<k)  l=inc.next();
            else r=inc.next();
        }
        return false;
    }
};

