#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

TNo* createNFill(int key){
  TNo* novo = (TNo*) malloc(sizeof(TNo));
  if (novo != NULL){
    novo->left = NULL;
    novo->right = NULL;
    novo->p = NULL;
    novo->key = key;
  }
  return novo;
}

BinTree* BinTree_create(){
    BinTree* novo = (BinTree*)malloc(sizeof(BinTree));
    if(novo != NULL){
        novo->root = NULL;
    }
    return novo;
}

void BinTree_preorder(TNo* root){
    if(root != NULL){
        printf("%d, ", root->key);
        BinTree_preorder(root->left);
        BinTree_preorder(root->right);
    }
}

void BinTree_posorder(TNo* root){
    if(root != NULL){
        BinTree_posorder(root->left);
        BinTree_posorder(root->right);
        printf("%d, ", root->key);
    }
}

void BinTree_inorder(TNo* root){
    if(root != NULL){
        BinTree_inorder(root->left);
        printf("%d, ", root->key);
        BinTree_inorder(root->right);
    }
}

TNo* TNo_inverter(TNo* no) {
    if(no == NULL){
        return NULL
    }

    TNo* temp = no->left;
    no->left = no->right;
    no->right = temp;

    TNo_inverter(no->left);
    TNo_inverter(no->right);

    return no;
}

void BinTree_invert(BinTree* tree) {
    if(tree != NULL) {
        tree->root = TNo_inverter(tree->root);
    }
}

// APRENDER AINDA !!!!!
TNo* BinTree_ReadTree(char* binStr, int* current){
  TNo* root = NULL;
  if(binStr[(*current)++]=='('){
    if(binStr[*current] !=')'){
      int key;
      sscanf(&binStr[*current], "%d", &key);
      while(binStr[*current]!='(' && binStr[*current]!=')')
        (*current)++;
      root = createNFill(key);
      if(binStr[*current]=='('){
        root->left = BinTree_ReadTree(binStr, current);
        if(root->left!=NULL) 
            root->left->p = root;
        root->right = BinTree_ReadTree(binStr, current);
        if(root->right!=NULL) 
            root->right->p = root;
      }
    }
    (*current)++;
  }
  return root;
}
