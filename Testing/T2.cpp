#include<bits/stdc++.h>
using namespace std;

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	int c=0,p=N-1,index;
    for(int i=0;i<N;i++){
        index=inorder[i]-1;
        if(index<=p){
            c++;
            p=index-1;
        }
        if(p<0) return c;
    }
}