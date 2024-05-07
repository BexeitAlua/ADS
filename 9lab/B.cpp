#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(string s){
    vector<int> p(s.length());
    for(int i=1;i<s.length();i++){
        int j =p[i-1];
        while(j>0 && s[i]!=s[j]) j =p[i-1];
        if(s[i]==s[j]) j++;
        p[i] =j;
    }
    return p;
}
void KMP(string t,string f,int n){
    int cnt = 0;

    string concat = t+'#'+f;
    vector<int> p = prefix(concat);
    for(int i = f.size()+1;i<concat.size();i++){
        if(p[i]== f.size()){
            cnt++;
            if(cnt==n){
                cout<<"YES";
                return;
            }
        }

    }
    cout<<"NO";
}

int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    string t;
    cin>>t;
    KMP(t,s,n);
    return 0;
}