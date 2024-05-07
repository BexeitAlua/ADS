#include<iostream>
#include<vector>
using namespace std;

void heapify(int a[],int n,int i){
    int largest = i;
    int l = 2*i+1;
    int r =2*i+2;

    if(l<n && a[l]>a[largest]){
        largest = l;
    }
    if(r<n && a[r]>a[largest]){
        largest=  r;
    }

    if(largest != i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }

}

void insert(vector<int> & v,int val){
    int size = v.size();
    if(size==0){
        v.push_back(val);
    }
    else{
        v.push_back(val);
    for(int i = size/2 -1;i>=0;i--){
        heapify(v,v.size(),i);
    }
    }
}

void remove(int a[],int n){
    int last = a[n-1];
    a[0] = last;
    n= n-1;
    heapify(a,n,0);
}