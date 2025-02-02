#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[1000];
bool used[1000];
vector<int> ans;

void dfs(int v){
    used[v] = true;
    for(int i =0;i<g[v].size();i++){
        int to = g[v][i];
        if(!used[to])
        dfs(to);
    }
    ans.push_back(v);
}


void topological_sort(){
   for ( int i =0;i<n;++i){
        used[i] = false;
    ans.clear();
    for(int i =0;i<n;i++){
        if(!used[i])
        dfs(i);

    reverse(ans.begin(),ans.end()); 
        }
   }
}