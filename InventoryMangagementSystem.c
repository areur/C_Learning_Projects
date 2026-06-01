#include <stdio.h>

typedef struct { //typedef makes this struct a type for variables
    int id;
    char * name;

    float price;
    int amount;

} item;

typedef struct {
    item * items; //list of items
    int storageCapacity; 
    int stockLevel;

} inventory;

inventory initInventory(int initialCapacity) {
    inventory inv; 
    inv.storageCapacity = initialCapacity;

    //allocate memory for the item list
    inv.items = (item *) malloc(sizeof(item) * initialCapacity);

    //error handling for memory allocation
    if (inv.items == NULL) {
        printf("ERROR: Memory Allocation failed");
        exit(1);
    }

    return inv;
}


int main() {

    return 0;
}