#include <bits/stdc++.h>
using namespace std;

int a[101][101];
int n;
vector<int> color;

vector<int>time_in,time_out;
int timer=0;

void dfs(int v){
    time_in[v] = timer++;
    color[v] =1;
    for(int i =0;i<n;i++){
        if(color[i] ==0)
        dfs(i);

    color[v] =2;
    time_out[v] = timer++;
    } 
}
