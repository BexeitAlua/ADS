#include<iostream>
using namespace std;

bool isPrime(int num){
    int cnt=0;
    for(int i=2;i<num;i++){
        if(num%i==0){
            cnt=1;
            break;
        }
    }
    if(cnt==0){
        return true;

    } else{
        return false;
        }

}
int main(){
    int n,num=1;
    int count=0;
    cin>>n;
    while(true){
        num++;
        if(isPrime(num)){
            count++;
        }
        if(count==n){
            cout<<num;
            break;
        }
    }
}
