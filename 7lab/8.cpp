#include<iostream>
#include<vector>
using namespace std;
struct heap{
    vector<int> v;

    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i-1;
    }
    int right(int i){
        return 2*i+2;
    }

    void insert(int val){
        v.push_back(val);
        int i = v.size()-1;
        while(i!=0 && v[parent(i)]<=v[i]){
            swap(v[parent(i)],v[i]);
            i = parent(i);
        }
    }
    int get_min(){
    if(v.size()==0) return INT_MAX;
    if(v.size()==1){
        int root = v[0];
        v.pop_back();
        return root;

    }

    int root = v[0];
    v[0]=v[v.size()-1];
    v.pop_back();
    heapify(0);
    return root;
}

int heapify(int i){
    int small = i;
    int l = left(i);
    int r = right(i);

    if(l<v.size()&& v[l]<v[small]){
        small =l;
    }
    if(r<v.size() && v[r]<v[small]){
        small = r;
    }

    if(small!=i){
        swap(v[i],v[small]);
        heapify(small);
    }
}
};

