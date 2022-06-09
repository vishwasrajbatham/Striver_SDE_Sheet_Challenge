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
    int findmax(TreeNode* root, int &maxi){
      if(root==NULL)  return NULL;
      int leftpath=max(0,findmax(root->left,maxi));
      int rightpath=max(0,findmax(root->right,maxi));
      maxi=max(maxi,leftpath+rightpath+root->val);
      return max(leftpath,rightpath)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        findmax(root, maxi);
        return maxi;
    }
};

