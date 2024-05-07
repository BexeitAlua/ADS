#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(string s){
    vector<int> p(s.length());
    for(int i =1;i<s.length();i++){
        int j = p[i-1];
        while(j>0 && s[i]!= s[j]) j =p[j-1];
        if(s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

vector<int> KMP(string t,string f){
    vector<int> ans;
    string concat = f+'#' +t;
    vector<int> p = prefix(concat);
    for(int i = f.size()+1;i<concat.size();i++){
        if(p[i]== f.size()){
            ans.push_back(i - 2* f.size());
        }
    }
    return ans;
}