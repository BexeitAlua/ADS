#include <bits/stdc++.h>

using namespace std;

vector<int> v1;
vector<int> v2;


void find(int a,int b){
    queue<int> q;
    q.push(a);

    v1[a] = 0;
    v2[a] = -1;
    while(!q.empty()){
        int c = q.front();
        q.pop();
        int x = c * 2;
        int y = c - 1;
        if(v1[x]>v1[c]+1){
            v1[x] =v1[c]+1;
            q.push(x);
            v2[x] = c;
        }
        if(v1[y]>v1[c]+1){
            v1[y] = v1[c] +1;
            q.push(y);
            v2[y] =c;
        }
    }
}

int main(){
    int a,b;
    cin>>a>>b;
    find(a,b);
    cout<<v1[b-1]<<endl;

    vector<int> v;
    for(int i = b; i != a; i =  v2[i]){
        v.push_back(i);
    }
    for(int i = v.size() -1; i >= 0; i--){
        cout << v[i] << " ";
    }
}