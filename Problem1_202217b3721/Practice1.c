#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Function declarations
void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n, i, pos, e, p;

void main() {
    int ch;
    char g = 'y';

    do {
        printf("\nMain Menu");
        printf("\n1. Create");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Insert");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nEnter the correct choice:");
        }

        printf("\nDo you want to continue (y/n)?: ");
        scanf(" %c", &g); // Added space before %c to skip whitespace

    } while (g == 'y' || g == 'Y');
}

void create() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("\nNumber of nodes exceeds maximum limit.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);

    if (pos >= n || pos < 0) {
        printf("\nInvalid location.\n");
        return;
    }

    for (i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }
    n--;

    printf("\nThe elements after deletion:\n");
    display();
}

void search() {
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value is at position %d\n", i);
            return;
        }
    }
    printf("Value %d is not in the list.\n", e);
}

void insert() {
    printf("\nEnter the position you need to insert: ");
    scanf("%d", &pos);

    if (pos > n || pos < 0) {
        printf("\nInvalid location.\n");
        return;
    }

    if (n == MAX) {
        printf("\nList is full. Cannot insert.\n");
        return;
    }

    for (i = n; i > pos; i--) {
        b[i] = b[i - 1];
    }

    printf("\nEnter the element to insert: ");
    scanf("%d", &p);
    b[pos] = p;
    n++;

    printf("\nThe list after insertion:\n");
    display();
}

void display() {
    printf("\nThe elements of the list are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}
