#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node * next;
    node * prev;

    node(int val){
        val=val;
        next = NULL;
        prev = NULL;
    }
};

struct dll{
    node * head ;
    node * tail;
    dll(){
        head = NULL;
        tail = NULL;
    }

    void add(int val){
        node * temp = new node (val);
        if(head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
};

int binary_search(int a[],int target,int size){
    int l =0;
    int r = size-1;
    while(l<r){
        int mid = l+(r-l)/2;
        if(target>a[mid]){
            l = mid +1;
        }
        else if(target<a[mid]){
            r = mid-1;

        }
    }
    return l;
}

