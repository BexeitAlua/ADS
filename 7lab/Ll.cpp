#include<iostream>
using namespace std;

struct node{
    int val;
    node*next;
    node*prev;

    node(int val){
        val = val;
        next = NULL;
        prev = NULL;
    }
};

struct ll{
    node * head;
    node * tail;

    ll(){
        head = NULL;
        tail = NULL;
    }

    void add(int val){
        node * temp = new node(val);

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