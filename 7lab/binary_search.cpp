#include<iostream>
using namespace std;

int binary_search(int a[],int target,int size){
    int l = 0;
    int r = size-1;
    while(l<r){
        int mid=l+(r-l)/2;
        if(target>a[mid]){
            l = mid+1;
        }else if(target<a[mid]){
            r = mid-1;
        }
    }
    return l;
}