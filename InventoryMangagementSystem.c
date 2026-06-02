#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { //typedef makes this struct a type for variables
    int id;
    char name[50];

    float price;
    int amount;

} item;

typedef struct {
    item * items; //list of items
    int storageCapacity; 
    int stockLevel;

} inventory;

void initInventory(inventory *inv,int initialCapacity) {
    inv->storageCapacity = initialCapacity;
    inv->stockLevel = 0;

    //allocate memory for the item list
    inv->items = (item *)malloc(sizeof(item) * initialCapacity);

    //error handling for memory allocation
    if (inv->items == NULL) {
        printf("ERROR: Memory Allocation failed");
        exit(1);
    }

}

void addItem(inventory *inv, int ID, char *name, float price, int amount) {
    if (inv->stockLevel == inv->storageCapacity) { //no memory space, allocate more
        inv->storageCapacity *= 3;
        inv->items = realloc(inv->items, sizeof(item) * inv->storageCapacity);
        printf("added more space guys");
    }

    item *currentItem = &(inv->items[inv->stockLevel]);

    currentItem->id = ID;
    strcpy(currentItem->name, name);
    currentItem->price = price;
    currentItem->amount = amount;
    inv->stockLevel = (inv->stockLevel+amount);
    
    printf("Added Item: %s with id: %d\n",name ,ID);
}

void freeInventory(inventory *inv) {
    free(inv->items);
    inv->items = NULL;
    inv->stockLevel = 0;
    inv->storageCapacity = 0;
}

int main() {
    inventory inv;
    initInventory(&inv,50);

    char name[50] = "son";
    addItem(&inv ,1 ,name ,6.99 ,3);

    freeInventory(&inv);

    return 0;
}