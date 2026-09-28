#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

int BinTree_insert(BinTree* T, TNo* z){
    TNo *y = NULL 
    TNo *x = T->root;

    while (x!=NULL){
        y = x;
        if(z->key < x->key){
            x->left;
        }else{
            x->right;
        }
    }
    z->p = y;
    if(y == NULL){
        T->root = z;
    }
    if(z->key < y->key){
        y->left = z;
    }else{
        y->right = z;
    }

    return 1;
}

TNo* BinTree_search(BinTree* T, int k){
    TNo* x = T->root;

    while(x != NULL && k != x->key){
        if(k > x->key){
            x->left;
        }else{
            x->right;
        }

    }
    return x;
}

void Transplant(BinTree* T, TNo *u, TNo *v){
    if(u->p == NULL){
        T-root = v;
    }
    if(u == u->p->left){
        u->p->left = v;
    }else{
        u->p->right = v;
    }
    if(v != NULL){
        v-p = u->p;
    }
}

int BinTree_delete(BinTree* T, TNo* z){
    if(T==NULL || T->root == NULL){
        return 0;
    }
    if(z->left == NULL){
        Transplant(T, z, z->right);
    }
    if(z->right == NULL){
        Transplant(T, z, z->left);
    }else{
        TNo* BinTree_min(z->right);
        if(y->p != z){
            Transplant(T, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        Transplant(T, z, y);
        y->left = z->left;
        y->left->p = y;
  }
  free(z);
}

TNo* BinTree_max(TNo* x){
  while(x->right)
    x = x->right;
  return x;
}

TNo* BinTree_min(TNo* y){
    TNo* x = y;
    while(x->left != NULL)
      x = x->left;
  return x;
}

TNo* BinTree_sucessor(TNo* x){
  if(x->right != NULL)
    return BinTree_min(x->right);
  TNo* y = x->p;
  while(y != NULL && x == y->right){
    x = y;
    y = y->p;
  }
}
