#include <bits/stdc++.h>
using namespace std;

#define unll unsigned long long 

int myHash(string s){
    unll p = 1;
    unll q = 1e9+7;

    int x = 11;
    unll answer = 0;

    for(int i =0; i <s.size();i++){
        answer =(answer + ((s[i]-47)*p)%q)%q;
        p = (p*x)%q;

    }

    return answer;


}

int main(){
    int n;
    cin>>n;

    unordered_map<string,string> m;
    unordered_map<string,string> :: iterator it;

    vector<int> v;

    for(int i =0;i<2*n;i++){
        string s;
        cin>>s;

        if(m.find(s)==m.end()){
            m[s] = to_string(myHash(s));
        }
    }

    for(it = m.begin();it!=m.end();it++){
        cout<<"Hash of string " << "\"" << (*it).first<<"\""<<" is "<<(*it).second<<endl;
    }
}