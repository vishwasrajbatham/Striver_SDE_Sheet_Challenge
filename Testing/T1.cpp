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

struct node {
  int data;
  struct node * left, * right;
};

bool isLeaf(node * root) {
  return !root -> left && !root -> right;
}

void addLeftBoundary(node * root, vector < int > & res) {
	node * cur = root -> left;
	while (cur) {
		if (!isLeaf(cur)) res.push_back(cur -> data);
		if (cur -> left) cur = cur -> left;
		else cur = cur -> right;
	}
}

void addRightBoundary(node * root, vector < int > & res) {
	node * cur = root -> right;
	vector < int > tmp;
	while (cur) {
		if (!isLeaf(cur)) tmp.push_back(cur -> data);
		if (cur -> right) cur = cur -> right;
		else cur = cur -> left;
	}
	for (int i = tmp.size() - 1; i >= 0; --i) {
		res.push_back(tmp[i]);
	}
}

void addLeaves(node * root, vector < int > & res) {
	if (isLeaf(root)) {
		res.push_back(root -> data);
		return;
	}
	if (root -> left) addLeaves(root -> left, res);
	if (root -> right) addLeaves(root -> right, res);
}

vector < int > printBoundary(node * root) {
  vector < int > res;
  if (!root) return res;

  if (!isLeaf(root)) res.push_back(root -> data);

  addLeftBoundary(root, res);

  // add leaf nodes
  addLeaves(root, res);

  addRightBoundary(root, res);
  return res;
}

/*

 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

1 2 4 7 8 9 10 11 12 3

1 2 4 8 9 10 11 12 7 3


1 2 4 7 10 11 12 3
1 2 4 10 11 12 7 3
*/