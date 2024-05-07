#include <bits/stdc++.h>
using namespace std;

void search(string t,string s){
    long long q = INT_MAX;
    long long p[t.size()]; //  хранит все степени р
    long long h[t.size()]; // хранит хэш от сторки т

    p[0]=1;
    // считаем все степени р
    for(int i =1;i<t.size();++i){
        p[i] = (p[i-1]*31)%q;
    }
    // считаем хэш от строки т
    for(int i = 0;i<t.size();++i){
        if(i==0) h[i] = t[i] - 'a'+1;
        else h[i] = (h[i-1]+((t[i]-'a'+1)*p[i])%q) %q;
    }
    // считаем хэш от подстроки
    long long h_s = 0;
    for(int i = 0;i<s.size();++i){
        h_s = (h_s + (((s[i] -'a'+1)*p[i])%q))%q;
    }
    // сравниваем хэши
    for(int i = 0;i<=t.size()-s.size();++i){
        long long temp = h[i+s.size()-1];
        if(i>0) temp -= h[i-1];
        if(temp == (h_s * p[i]) % q){
            if(t.substr(i,s.size()) ==s){
                cout<<"found";
            }
        }
    }
}