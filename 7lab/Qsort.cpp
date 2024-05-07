#include <bits/stdc++.h>
using namespace std;
int partition(int a[],int l,int r){
    int pivot = a[r];
    int i = l-1;
    
    for(int j = l;j<r;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
   
   swap(a[i+1],a[r]);
   return i+1;


}

void qsort(int a[],int l,int r){
    if(l<r){
    int pivot = partition(a,l,r);

    qsort(a,l,pivot-1);
    qsort(a,pivot+1,r);
    }
}
int main() {
  int arr[]={10,7,8,9,1,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  // Function call
  qsort(arr,0,n-1);
  //Print the sorted array
  cout<<"Sorted Array\n";
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}