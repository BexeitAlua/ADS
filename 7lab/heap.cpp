#include <iostream>
 
using namespace std;
 
 void heapify(int a[],int n,int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

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

 void deleteRoot(int a[],int n){
    int lastElement=a[n-1];

    a[0]= lastElement;
    n = n-1;
    heapify(a,n,0);
 }