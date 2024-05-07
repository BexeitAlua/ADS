#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node * l;
    node * r;

    node(int val){
        val =val;
        l = NULL;
        r = NULL;
    }
};

struct bst{
    node * root;

    bst(){
        this->root = NULL;
    }

    node * insert(node * cur,int val){
        if(!cur) return new node(val);
        else if (val>cur->val){
            cur->r = insert(cur->r,val);
        }
        else if(val<cur->val){
            cur->l = insert(cur->l,val);
        }
         return cur;
    }
    int rightmost(node * cur){
        if(!cur) return -1;
        if(!cur->r) return cur->val;
        rightmost(cur->r);
    }
   node * remove(node * cur,int target){
    if(!cur) return NULL;
    if(cur->val == target){
        
    }
    }
   
};