#include<iostream>
using namespace std;

void heapify(int a[],int n,int i){

    int largest = i;

    int l = 2*i+1;
    int r = 2*i +2;

    if(l<n && a[l]>a[largest]){
        largest = l;
    }
    if(r<n && a[r]>a[largest]){
        largest = r;
    }

    if(largest!=i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}

int heapsort(int a[],int n){

    for(int i = n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i = n-1; i>0; i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

void printarr(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    
    int a[] = {12,45,67,13,11,0,8};
    int n = sizeof(a)/sizeof(a[0]);

    heapsort(a,n);

    printarr(a,n);

    return 0;
}