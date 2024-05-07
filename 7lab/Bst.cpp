#include<iostream>
using namespace std;
struct node{
    int val;
    node*left;
    node* right;

    node(int val){
        val = val;
        left = NULL;
        right = NULL;
    }
};

struct bst{
    node * root;
    bst(){
        root = NULL;
    }

    node * insert(node * cur,int val){
        if(!cur) return new node(val);
        else if(val>cur->val){
            cur->right = insert (cur->right,val);
        } else if(val<cur->val){
            cur->left = insert(cur->left,val);

        }
        return cur;
    }

    void inorder(node * root){
        if(root!=NULL){
            inorder(root->left);
            cout<<root->val;
            inorder(root->right);
        }
    }

};