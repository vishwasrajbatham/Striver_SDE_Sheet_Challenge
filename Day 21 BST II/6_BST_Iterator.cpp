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
    void push_nodes(TreeNode* node){
        while(node!=NULL){
            st.push(node);
            node=node->left;
        }
        return;
    }
public:
    BSTIterator(TreeNode* node) {    push_nodes(node);    }
    
    int next() {
        TreeNode* curr=st.top();
        st.pop();
        push_nodes(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
