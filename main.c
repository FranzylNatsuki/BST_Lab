/*
Code is a store inventory simulator, with a main inventory, a
store tree that records all sales made, and a goods receipt tree
that contains all obtained goods. This is all implemented with a
linked list Binary Tree ADT.
Franzyl Bjorn L. Macalua
Date Started: 9/18/2025
Data Finished: 9/ /2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

#define Flush while(getchar() != '\n')

typedef struct item_generic {
    char itemNumber[3+1];
    char itemName[30];
    int quantity;
    float price;
} ITEM;

typedef struct sales {
    int sales_number;
    int quantity_sold;
    char itemNumber[3];
    char itemName[30];
} SALES;

typedef struct goods_receipt {
    int goods_number;
    int quantity_sold;
    char itemNumber[3];
    char itemName[30];
} GOODS;

typedef struct item_node *ItemNd;
struct item_node {
    ITEM item;
    ItemNd left;
    ItemNd right;
} BST_ITEM;

typedef struct salesNode *SalesNd;
struct salesNode {
    SALES data;
    SalesNd left;
    SalesNd right;
} BST_SALES;

typedef struct goodsNode *GoodsNd;
struct goodsNode {
    GOODS data;
    GoodsNd left;
    GoodsNd right;
} BST_GOODS;

void menu(void);
ITEM input(ItemNd root);
void add_Record(ItemNd *root, ITEM item);
void add_Sales(SalesNd *root, SALES item);
void add_Goods(GoodsNd *root, GOODS item);
bool check_Duplicate(ItemNd root, char search_term[]);
bool search_Record(ItemNd root, ItemNd *search_result, char search_term[]);
int edit_ask(void);
void edit_Record(ItemNd *root);
void sales(ItemNd i_root, SalesNd *root, int *sales_number_generate);
void goods(ItemNd i_root, GoodsNd *s_root, int *goods_number_generate);
void Display_All(ItemNd ptr);
void Display_Sales(SalesNd ptr);
void Display_Goods(GoodsNd ptr);

void menu(void) {
    printf("1] Add New Item\n");
    printf("2] Edit Item Information\n");
    printf("3] Sales\n");
    printf("4] Goods Receipt\n");
    printf("5] Display Sales\n");
    printf("6] Display Goods Receipt\n");
    printf("7] Display All Items\n");
    printf("8] Exit\n");
}

ITEM input(ItemNd root) {
    bool isValid = false;
    ITEM input;
    // Flush;
    while (!isValid) {
        printf("Enter Item Number: ");
        gets(input.itemNumber);
        input.itemNumber[strcspn(input.itemNumber, "\n")] = '\0';

        if (check_Duplicate(root, input.itemNumber)) {
            printf("Item Number already exists\n");
            isValid = false;
            continue;
        }

        isValid = true;
    }
    printf("Enter Item Name: ");
    gets(input.itemName);
    printf("Enter Quantity: ");
    scanf("%d", &input.quantity);
    Flush;
    printf("Enter Price: ");
    scanf("%f", &input.price);
    Flush;
    return input;
}

void add_Record(ItemNd *root, ITEM item) {
    ItemNd ptr, ptr1, temp;

    temp = malloc(sizeof(BST_ITEM));
    if (temp == NULL) {
        exit(1);
    }
    temp->item = item;
    temp->left = NULL;
    temp->right = NULL;

    if (*root == NULL) {
        *root = temp;
    } else {
        ptr = *root;
        while (ptr != NULL) {
            ptr1 = ptr;
            if (strcmp(temp->item.itemNumber, ptr->item.itemNumber) < 0) {
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }
        if (strcmp(temp->item.itemNumber, ptr1->item.itemNumber) < 0) {
            ptr1->left = temp;
        } else {
            ptr1->right = temp;
        }
    }
}

void add_Sales(SalesNd *root, SALES item) {
    SalesNd ptr, ptr1, temp;

    temp = malloc(sizeof(BST_SALES));
    if (temp == NULL) {
        exit(1);
    }
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;

    if (*root == NULL) {
        *root = temp;
    } else {
        ptr = *root;
        while (ptr != NULL) {
            ptr1 = ptr;
            if (strcmp(temp->data.itemNumber, ptr->data.itemNumber) < 0) {
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }
        if (strcmp(temp->data.itemNumber, ptr1->data.itemNumber) < 0) {
            ptr1->left = temp;
        } else {
            ptr1->right = temp;
        }
    }
}

void add_Goods(GoodsNd *root, GOODS item) {
    GoodsNd ptr, ptr1, temp;

    temp = malloc(sizeof(BST_GOODS));
    if (temp == NULL) {
        exit(1);
    }
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;

    if (*root == NULL) {
        *root = temp;
    } else {
        ptr = *root;
        while (ptr != NULL) {
            ptr1 = ptr;
            if (strcmp(temp->data.itemNumber, ptr->data.itemNumber) < 0) {
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }
        if (strcmp(temp->data.itemNumber, ptr1->data.itemNumber) < 0) {
            ptr1->left = temp;
        } else {
            ptr1->right = temp;
        }
    }
}

bool check_Duplicate(ItemNd root, char search_term[]) {
    ItemNd ptr = root;
    while (ptr != NULL) {
        if (strcmp(search_term, ptr->item.itemNumber) == 0) {
            return true;
        }
        if (strcmp(search_term, ptr->item.itemNumber) < 0) {
            ptr = ptr->left;
        }
        else {
            ptr = ptr->right;
        }
    }
    return false;
}

bool search_Record(ItemNd root, ItemNd *search_result, char search_term[]) {
    bool isFound = false;
    ItemNd ptr = root;
    while (ptr != NULL) {
        if (strcmp(search_term, ptr->item.itemNumber) == 0) {
            *search_result = ptr;
            isFound = true;
            break;
        }
        if (strcmp(search_term, ptr->item.itemNumber) < 0) {
            ptr = ptr->left;
        }
        else {
            ptr = ptr->right;
        }
    }
    return isFound;
}

int edit_ask(void) {
    printf("Which to edit?: \n");
    printf("1. Item Name\n");
    printf("2. Item Price\n");

    int choice;
    scanf("%d", &choice);
    return choice;
}

void edit_Record(ItemNd *root) {
    char search_term[10];
    printf("Enter Item Number: ");
    // Flush;
    gets(search_term);

    ItemNd ptr = NULL;

    if (search_Record(*root, &ptr, search_term)) {
        int choice = edit_ask();

        if (choice == 1) {
            bool isValid = false;
            char new_item_name[30];
            Flush;
            printf("Enter New Item Name: \n");
            gets(new_item_name);
            strcpy(ptr->item.itemName, new_item_name);
        }
        else if (choice == 2) {
            float new_price;
            printf("Enter New Item Price: \n");
            scanf("%f", &new_price);
            Flush;
            ptr->item.price = new_price;
        }
        else  {
            printf("Edit Failed!\n");
            return;
        }
        printf("Edit Successful\n");
    } else {
        printf("Entry Not Found\n");
    }
}

void sales(ItemNd i_root, SalesNd *s_root, int *sales_number_generate) {
    SALES entry;
    char search_term[10];
    int sale_quantity = 0;
    ItemNd ptr_i = NULL;
    bool quantityNotNegative = false;

    printf("Enter Item Number: ");
    //Flush;
    gets(search_term);

    if (search_Record(i_root, &ptr_i, search_term)) {
        while (!quantityNotNegative) {
            printf("Enter Quantity Sold: ");
            scanf("%d", &sale_quantity);
            Flush;
            if (sale_quantity < 0) {
                quantityNotNegative = false;
                printf("Cannot input number below 0!\n");
            } else {
                quantityNotNegative = true;
            }
        }
        if (sale_quantity <= 0 || sale_quantity > ptr_i->item.quantity) {
            printf("Out of stock!\n");
            return;
        }
        strcpy(entry.itemNumber, ptr_i->item.itemNumber);
        strcpy(entry.itemName, ptr_i->item.itemName);
        entry.quantity_sold = sale_quantity;
        entry.sales_number = (*sales_number_generate)++;
        ptr_i->item.quantity -= sale_quantity;
        add_Sales(s_root, entry);
    } else {
        printf("Entry Not Found!\n");
    }
}

void goods(ItemNd i_root, GoodsNd *s_root, int *goods_number_generate) {
    GOODS entry;
    char search_term[10];
    int sale_quantity = 0;
    ItemNd ptr_i = NULL;
    bool quantityNotNegative = false;

    printf("Enter Item Number: ");
    //Flush;
    gets(search_term);

    if (search_Record(i_root, &ptr_i, search_term)) {
        while (!quantityNotNegative) {
            printf("Enter Quantity Received: ");
            scanf("%d", &sale_quantity);
            Flush;
            if (sale_quantity < 0) {
                quantityNotNegative = false;
                printf("Cannot input number below 0!\n");
            } else {
                quantityNotNegative = true;
            }
        }
        strcpy(entry.itemNumber, ptr_i->item.itemNumber);
        strcpy(entry.itemName, ptr_i->item.itemName);
        entry.quantity_sold = sale_quantity;
        entry.goods_number = (*goods_number_generate)++;
        ptr_i->item.quantity += sale_quantity;
        add_Goods(s_root, entry);
    } else {
        printf("Not Found!\n");
    }
}

void Display_All(ItemNd ptr) {
    if (ptr == NULL) return;
    if (ptr->left != NULL) {
        Display_All(ptr->left);
    }
    printf("Item Number: %s\n", ptr->item.itemNumber);
    printf("Item Name: %s\n", ptr->item.itemName);
    printf("Quantity: %d\n", ptr->item.quantity);
    printf("Price: %.2f\n", ptr->item.price);
    printf("-------------------------------\n");
    if (ptr->right != NULL) {
        Display_All(ptr->right);
    }
}

void Display_Sales(SalesNd ptr) {
    if (ptr == NULL) return;
    if (ptr->left != NULL) {
        Display_Sales(ptr->left);
    }
    printf("Item Number: %s\n", ptr->data.itemNumber);
    printf("Item Name: %s\n", ptr->data.itemName);
    printf("Quantity: %d\n", ptr->data.quantity_sold);
    printf("Sales Transaction #: %d\n", ptr->data.sales_number);
    printf("-------------------------------\n");
    if (ptr->right != NULL) {
        Display_Sales(ptr->right);
    }
}

void Display_Goods(GoodsNd ptr) {
    if (ptr == NULL) return;
    if (ptr->left != NULL) {
        Display_Goods(ptr->left);
    }
    printf("Item Number: %s\n", ptr->data.itemNumber);
    printf("Item Name: %s\n", ptr->data.itemName);
    printf("Quantity: %d\n", ptr->data.quantity_sold);
    printf("Goods Receipt Transaction #: %d\n", ptr->data.goods_number);
    printf("-------------------------------\n");
    if (ptr->right != NULL) {
        Display_Goods(ptr->right);
    }
}

int main(void) {
    ItemNd i_root = NULL;
    SalesNd s_root = NULL;
    GoodsNd g_root = NULL;
    int sales_number_generate = 1;
    int goods_number_generate = 1;
    bool isRepeating = true;

    while (isRepeating) {
        int choice;
        menu();
        printf("Input:\n");
        scanf("%d", &choice);
        Flush;
        switch (choice) {
            case 1:
                ITEM entry;
                entry = input(i_root);
                add_Record(&i_root, entry);
                printf("Done...");
                break;
            case 2:
                if (i_root == NULL) {
                    printf("Nothing to edit!\n");
                } else {
                    edit_Record(&i_root);
                }
                break;
            case 3:
                if (i_root == NULL) {
                    printf("Inventory Empty\n");
                } else {
                    sales(i_root, &s_root, &sales_number_generate);
                }
                break;
            case 4:
                if (i_root == NULL) {
                    printf("Inventory Empty!\n");
                } else {
                    goods(i_root, &g_root, &goods_number_generate);
                }
                break;
            case 5:
                if (s_root == NULL) {
                    printf("Inventory Empty!\n");
                } else {
                    Display_Sales(s_root);
                }
                break;
            case 6:
                if (g_root == NULL) {
                    printf("Inventory Empty!\n");
                } else {
                    Display_Goods(g_root);
                }
                break;
            case 7:
                if (i_root == NULL) {
                    printf("Inventory Empty!\n");
                } else {
                    Display_All(i_root);
                }
                break;
            case 8:
                isRepeating = false;
                printf("Exiting...\n");
                exit(0);
            default:
                exit(1);
        }
        printf("\nPress Any Button to continue\n");
        getch();
        system("cls");
    }
}