//Implement a hash table using quadratic probing with formula:h(k, i) = (h(k) + i*i) % m
#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1
#define DELETED -2

typedef struct {
    int *table;
    int size;
} HashTable;


HashTable* createTable(int m) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = m;
    ht->table = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
        ht->table[i] = EMPTY;

    return ht;
}


int hash(int key, int m) {
    return key % m;
}


void insert(HashTable* ht, int key) {
    int m = ht->size;
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (ht->table[index] == EMPTY || ht->table[index] == DELETED) {
            ht->table[index] = key;
            printf("Inserted %d at index %d\n", key, index);
            return;
        }
    }

    printf("Hash table is full, cannot insert %d\n", key);
}


int search(HashTable* ht, int key) {
    int m = ht->size;
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (ht->table[index] == EMPTY)
            return -1;

        if (ht->table[index] == key)
            return index;
    }

    return -1;
}


void display(HashTable* ht) {
    printf("\nHash Table:\n");
    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i] == EMPTY)
            printf("%d : EMPTY\n", i);
        else
            printf("%d : %d\n", i, ht->table[i]);
    }
}


int main() {
    int m = 10;
    HashTable* ht = createTable(m);

    insert(ht, 10);
    insert(ht, 20);
    insert(ht, 30);
    insert(ht, 25);
    insert(ht, 35);

    display(ht);

    int key = 25;
    int pos = search(ht, key);

    if (pos != -1)
        printf("\nKey %d found at index %d\n", key, pos);
    else
        printf("\nKey %d not found\n", key);

    return 0;
}