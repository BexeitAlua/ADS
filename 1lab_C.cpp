#include<iostream>
#include<string>
using namespace std;
string equalty(string s){
    string res;
    for(int i=0;i< s.length();i++){
        char c = res[i];
        if(c=='#'){
            if(!res.empty()){
                res.erase(res.length()-1);
            }
        }else {
            res.push_back(c);
        }

    }
 return res;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    string c1 = equalty(s1);
    string c2 = equalty(s2);
    if(c1==c2){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}