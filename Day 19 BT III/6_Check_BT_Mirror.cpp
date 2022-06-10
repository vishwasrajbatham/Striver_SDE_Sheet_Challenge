#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        void mirror(Node* node) {
            Node* temp;
            temp=node->left;
            node->left=node->right;
            node->right=temp;
            if(node->left)    mirror(node->left);
            if(node->right)    mirror(node->right);
        }
};