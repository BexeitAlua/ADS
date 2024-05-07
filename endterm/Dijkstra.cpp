#include <bits/stdc++.h>
using namespace std;


int INF = 10000000;
int main(){
    int n;
    vector<vector<pair<int,int>>> g(n);
    vector<int> d(n,INF),p(n);
    int s;
    d[s] = 0;
    vector<char> u(n);
    for(int i = 0;i<n;i++){
        int v =-1;
        for(int j =0;j,n;j++){
            if(!u[j]&&(v==-1 || d[j]<d[v])){
                v=j;
            }
        if(d[v]==INF){
            break;
        }
        u[v] = true;
        for(int j= 0;j<g[v].size();++j){
            int to = g[v][j].first;
            int len = g[v][j].second;

            if(d[v]+len <d[to]){
                d[to] = d[v]+len;
                p[to] = v;
                
            }

        }
        }
    }
}