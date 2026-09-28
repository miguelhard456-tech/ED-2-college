#include "Heaps.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getpai(int i) {
    return (i - 1) / 2;
}

int getfilhoesq(int i) {
    return 2 * i + 1;
}

int getfilhodir(int i) {
    return 2 * i + 2;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Heap* criarheap(int capacity) {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->arr = (int *)malloc(capacity * sizeof(int));
    heap->size = 0;         
    heap->capacity = capacity;
    return heap;
}

void heapify(Heap *heap, int i) {
    int menori = i;
    int l = getfilhoesq(i);
    int r = getfilhodir(i);

    if (l < heap->size && heap->arr[l] < heap->arr[menori]) {
        menori = l;
    }
    if (r < heap->size && heap->arr[r] < heap->arr[menori]) {
        menori = r;
    }

    if (menori != i) {
        swap(&heap->arr[i], &heap->arr[menori]);
        heapify(heap, menori);
    }
}

void buildheap(Heap *heap) {
    int n = heap->size;
    for (int i = (n / 2) - 1; i >= 0; i--) { 
        heapify(heap, i);
    }
}

void heapsort(int arr[], int n) {
    Heap *heap = criarheap(n);
    memcpy(heap->arr, arr, n * sizeof(int));
    heap->size = n;

    buildheap(heap);

    for (int i = n - 1; i > 0; i--) {
        swap(&heap->arr[0], &heap->arr[i]);
        heap->size--;          
        heapify(heap, 0);    
    }

    memcpy(arr, heap->arr, n * sizeof(int));
    free(heap->arr);
    free(heap);
}