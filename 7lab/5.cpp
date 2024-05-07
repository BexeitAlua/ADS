#include <bits/stdc++.h>
using namespace std;
struct hp{
    int * a;
    int cap;
    int length;
    
    void heap_up(int i){
        if(i>0){
            int p_pos= (i-1)/2;
            if(a[i]<a[p_pos]){
                swap(a[i],a[p_pos]);
                heap_up(p_pos);
            }
        }
    }

    void heap_down(int i){
        int l = 2 * i +1;
        int r = 2 * i + 2;
        int min_pos = i;
        if(l<length && a[min_pos]>a[l]) min_pos= l;
        if(r<length && a[min_pos]>a[r]) min_pos = r;
        if(i!= min_pos){
            swap(a[i],a[min_pos]);
            heap_down(min_pos);
        }
    }

    void cut_min(){
        a[0]= a[length-1];
        length = max(length-1,0);
         heap_down(0);
    }
};