#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct HashTable {
    int n;
    int* bucket[SIZE];
    int (*h)(int, int);
} HashTable;

int mi_Mod(int x, int n) {
    return x % n;
}

void insert(HashTable* ht, int x) {
    int index = ht->h(x, ht->n);
    ht->bucket[index] = (int*)realloc(ht->bucket[index], (ht->bucket[index][0] + 2) * sizeof(int));
    ht->bucket[index][0] += 1;
    ht->bucket[index][ht->bucket[index][0]] = x;
}

int delete(HashTable* ht, int x) {
    int index = ht->h(x, ht->n);
    int* poss = ht->bucket[index];
    for (int i = 1; i <= poss[0]; i++) {
        if (poss[i] == x) {
            int deleted = poss[i];
            for (int j = i; j < poss[0]; j++) {
                poss[j] = poss[j + 1];
            }
            poss[0] -= 1;
            poss = (int*)realloc(poss, (poss[0] + 1) * sizeof(int));
            ht->bucket[index] = poss;
            return deleted;
        }
    }
    return -1;
}

int find(HashTable* ht, int x) {
    int index = ht->h(x, ht->n);
    int* poss = ht->bucket[index];
    for (int i = 1; i <= poss[0]; i++) {
        if (poss[i] == x) {
            return poss[i];
        }
    }
    return -1;
}

int randomFn(int x, int n) {
    return rand() % n;
}

int* RandomHashFun(int M, int n) {
    int* fnTable = (int*)malloc(M * sizeof(int));
    for (int x = 0; x < M; x++) {
        fnTable[x] = rand() % n;
    }
    return fnTable;
}
