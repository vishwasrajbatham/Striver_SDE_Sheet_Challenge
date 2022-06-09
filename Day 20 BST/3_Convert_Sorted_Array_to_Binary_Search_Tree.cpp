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
    TreeNode* ret_Tree(int beg, int end, vector<int>& nums){
        if(beg>end) return NULL;
        int mid=(beg+end)>>1;
        TreeNode* l=ret_Tree(beg, mid-1, nums);
        TreeNode* r=ret_Tree(mid+1, end, nums);
        TreeNode* node=new TreeNode(nums[mid], l, r);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return ret_Tree(0, nums.size()-1, nums);
    }
};