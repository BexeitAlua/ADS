#include<iostream>
#include<queue>
using namespace std;
int main() {
    queue<int> b,n;
    for(int i=0;i<5;i++){
        int x;
        cin>>x;
        b.push(x);
    }
    for(int i=0;i<5;i++){
        int y;
        cin>>y;
        n.push(y);
    }
    int cnt=0;
    while(true){
        cnt++;
        if(cnt==1000000){
            cout<<"blin nichya";
            return 0;
        }

        int f1 = b.front();
        int f2 =n.front();
        b.pop();
        n.pop();
        if(f1==0 && f2==9){
            b.push(f1);
            b.push(f2);
        }
         else if(f1==9 && f2==0 ){
            n.push(f1);
            n.push(f2);
        } else if(f1>f2){
            b.push(f1);
            b.push(f2);
        } else if(f1<f2){
            n.push(f1);
            n.push(f2);
        }

        if(b.size()==0){
            cout<<"Nursik"<<" "<<cnt;
        }
        if(n.size()==0){
            cout<<"Boris"<<" "<<cnt;
        }

    }
    return 0;}