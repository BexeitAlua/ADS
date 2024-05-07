#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(string s){
    vector<int> p(s.length());
    for(int i=1;i<s.length();i++){
        int j = p[i-1];
        while(j>0 && s[i]!=s[j]) j = p[i-1];
        if(s[i]==s[j]) j++;
        p[i]=j;
    }
    return p;
}
int KMP(string t,string f){
    string concat= f  + '#' +t;
    vector<int> p = prefix(concat);
    for(int i= f.size() +1;i<concat.size();i++){
        if(p[i] == f.size()){
            return i-2*f.size();
        }
    }
    return -1;
}

int main(){
    string s,t;
    cin>>s>>t;
    t+=t;
    cout<<KMP(t,s);
    return 0;

}