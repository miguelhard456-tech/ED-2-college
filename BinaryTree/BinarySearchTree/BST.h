#ifndef BST_H
#define BST_H

#include "BinTree.h"

int BinTree_insert(BinTree*, TNo*);

TNo* BinTree_search(BinTree*, int);

int BinTree_delete(BinTree*, TNo*);

TNo* BinTree_max(TNo*);
TNo* BinTree_min(TNo*);
TNo* BinTree_sucessor(TNo*);

#endif