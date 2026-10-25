#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    float price;
} Product;

typedef struct {
    Product *items;
    int size;
    int capacity;
} Inventory;

Inventory* createInventory(int initialCapacity) {
    Inventory *inv = (Inventory*)malloc(sizeof(Inventory));
    if (inv == NULL) return NULL;

    inv->items = (Product*)malloc(initialCapacity * sizeof(Product));
    if (inv->items == NULL) {
        free(inv);
        return NULL;
    }

    inv->size = 0;
    inv->capacity = initialCapacity;
    return inv;
}

int addProduct(Inventory *inv, int id, const char *name, float price) {
    if (inv->size >= inv->capacity) {
        int newCapacity = inv->capacity * 2;
        Product *temp = (Product*)realloc(inv->items, newCapacity * sizeof(Product));
        
        if (temp == NULL) {
            printf("Error: Failed to reallocate memory!\n");
            return 0;
        }

        inv->items = temp;
        inv->capacity = newCapacity;
        printf("[Log] Capacity expanded to: %d\n", inv->capacity);
    }


    inv->items[inv->size].id = id;
    strncpy(inv->items[inv->size].name, name, sizeof(inv->items[inv->size].name) - 1);
    inv->items[inv->size].name[sizeof(inv->items[inv->size].name) - 1] = '\0';
    inv->items[inv->size].price = price;
    inv->size++;

    return 1;
}

void displayInventory(const Inventory *inv) {
    printf("\n--- Current Inventory (Items: %d / Capacity: %d) ---\n", inv->size, inv->capacity);
    for (int i = 0; i < inv->size; i++) {
        Product *p = inv->items + i; 
        printf("ID: %d | Name: %-12s | Price: $%.2f\n", p->id, p->name, p->price);
    }
    printf("----------------------------------------------------\n\n");
}

// Safely clean up all allocated memory to prevent memory leaks
void freeInventory(Inventory *inv) {
    if (inv != NULL) {
        free(inv->items); 
        free(inv);  
        printf("[Log] Memory successfully freed.\n");
    }
}

int main() {

    Inventory *store = createInventory(2);
    if (store == NULL) {
        printf("Failed to initialize store inventory.\n");
        return 1;
    }

    addProduct(store, 101, "Mechanical KB", 89.99f);
    addProduct(store, 102, "Gaming Mouse", 49.50f);
    displayInventory(store);

    addProduct(store, 103, "IPS Monitor", 199.99f);
    displayInventory(store);


    freeInventory(store);

    return 0;
}