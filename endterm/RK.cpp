#include <bits/stdc++.h>
using namespace std;

void search(string s, string t){
    long long q = INT_MAX;
    long long p[s.size()];
    long long h[s.size()];

    p[0]=1;

    for (int i = 1; i<s.size();++i){
        p[i] = (p[i-1] * 31)%q;
    }

    for(int i =0;i<s.size();++i){
        if(i==0) h[i] = s[i] -'a'+1;
        else h[i] =( h[i-1] + ((s[i] - 'a'+ 1) * p[i])%q)%q;
    }

    int h_s =0;
    for(int i=0;i<t.size();++i){
        h_s = (h_s + ((t[i] - 'a'+1)*p[i]) %q )%q;
    }

    
}