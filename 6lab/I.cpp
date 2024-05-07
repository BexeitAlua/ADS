#include<iostream>
using namespace std;
int partition(string &  s,int l,int r){
    int i = l-1;
    int pivot = r;
    for(int j = l; j<r;j++){
        if(s[j]<s[pivot]){
            i++;
            swap(s[j],s[i]);
        }
    }
    swap(s[i+1],s[pivot]);
    return i+1;
}
void qsort(string & s,int l,int r){
    if(l<r){
        int pivot = partition(s,l,r);
        qsort(s,l,pivot-1);
        qsort(s,pivot+1,r);
    }
}
int main(){
    string s;
    cin>>s;
    qsort(s,0,s.size()-1);
    cout<<s;
    return 0;
}