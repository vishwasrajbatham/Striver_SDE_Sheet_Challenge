#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next): val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)  return root;
        queue<Node*> q;
        Node* node=root;
        q.push(node);
        int s;
        while(!q.empty()){
            s=q.size();
            for(int i=0;i<s;i++){
                node=q.front();
                q.pop();
                if(i!=s-1)    node->next=q.front();
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
        }
        return root;
    }
};