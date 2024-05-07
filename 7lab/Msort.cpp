#include <bits/stdc++.h>
using namespace std;

void merge(int a[],int l,int mid,int r){
    int n1 = mid-l+1;
    int n2 = r-mid;

    int e[n1],o[n2];

    for(int i =0;i<n1;i++){
        e[i]=a[l+i];
    }
    for(int i=0;i<n2;i++){
        o[i]=a[r+i+1];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    while(i<n1 && j<n2){
        if(e[i]<=o[j]){
            a[k]=e[i];
            i++;

        }else{
            a[k]=o[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        a[k]=e[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=o[j];
        j++;
        k++;
    }




}

void msort(int a[],int l,int r){
    if(l<r){
        int m= l+(r-l)/2;

        msort(a,l,m);
        msort(a,m+1,r);
        merge(a,l,m,r);
    }

}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  msort(arr, 0, size - 1);

  cout << "Sorted array: \n";
  printArray(arr, size);
  return 0;
}