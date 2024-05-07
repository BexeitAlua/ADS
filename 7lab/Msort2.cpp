#include <iostream>
using namespace std;

void merge(int a[],int p,int q,int r){
    int n1 = q-p+1;
    int n2 = r-q;

    int l[n1],m[n2];

    for(int i = 0;i<n1;i++)
    l[i]=a[p+i];
    for(int j = 0;j<n2;j++)
    m[j]=a[q+j+1];

    int i,j,k;
    i=0;
    j=0;
    k=p;

    while(i<n1 && j<n2){
        if(l[i]<=m[j]){
            a[k]=l[i];
            i++;
        }else{
            a[k]=m[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        a[k]=l[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=m[j];
        j++;
        k++;
    }
}

void msort(int a[],int l,int r){
    if(l<r){
    int m = l+(r-m)/2;

    msort(a,l,m);
    msort(a,m+1,r);
    merge(a,l,m,r);}
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int a[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(a) / sizeof(a[0]);

  msort(a, 0, size - 1);

 


  printArray(a, size);
  return 0;
}
