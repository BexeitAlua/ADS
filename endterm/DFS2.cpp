#include <bits/stdc++.h>
using namespace std;

int a[101][101];

int n;

vector<char> used;

void dfs(int v){
    used[v]=true;
    for(int i = 0;i<n;i++){
        if(!used[i]){
            dfs(i);
        }
    }
}