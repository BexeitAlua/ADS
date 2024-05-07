#include <bits/stdc++.h>
using namespace std;

void serach(string s, string t){
    vector<int> p_pow(s.length());
    int q = INT_MAX;
    int p =31;
    p_pow[0]=1;
    
    for(int i =1;i<p_pow.size();++i){
        p_pow[i] =( p_pow[i-1]*p)%q;
    }
    vector<int> h(s.length());
    for(int i =0;i<s.length();++i){
        if(i==0) h[i] = (s[i] -'a'+1)%q;
        else h[i] = (h[i-1] + (((s[i]-'a'+1)*p_pow[i])%q))%q; 
    }

    int h_t=0;
    for(int i =0;i<t.length();++i){
        h_t = (h_t + ((t[i]-'a'+1) * p_pow[i])%q)%q;
    }

}


vector<int>  prefix(string s){
    vector<int> p(s.length());

    for(int i =0;i<s.length();++i){
        int j = p[i-1];
        while(j>0 && s[i]!=s[j]) j = p[j-1];
        if(s[i]==s[j]) j++;
        p[i]=j;
    }
    return p;
}

vector<int> KMP(string t,string f){
    vector<int> ans;
    string concat = f + '#' + t;
    vector<int> p = prefix(concat);
    for(int i = f.size()+1;i<concat.size();i++){

        if(f.size()==p[i]){
            ans.push_back(i - 2* f.size());
        }
    }
    return ans;
}