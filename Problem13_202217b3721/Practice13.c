#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *left_child;
    struct node *right_child;
};

// Function to create a new node
struct node* new_node(int x) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = x;
    temp->left_child = NULL;
    temp->right_child = NULL;
    return temp;
}

// Function to search for a value in the BST
struct node* search(struct node *root, int x) {
    if (root == NULL || root->data == x)
        return root;
    if (x > root->data)
        return search(root->right_child, x);
    return search(root->left_child, x);
}

// Function to insert a value into the BST
struct node* insert(struct node *root, int x) {
    if (root == NULL)
        return new_node(x);
    if (x > root->data)
        root->right_child = insert(root->right_child, x);
    else
        root->left_child = insert(root->left_child, x);
    return root;
}

// Function to find the minimum value node in the BST
struct node* find_minimum(struct node *root) {
    if (root == NULL)
        return NULL;
    while (root->left_child != NULL)
        root = root->left_child;
    return root;
}

// Function to delete a value from the BST
struct node* delete(struct node *root, int x) {
    if (root == NULL)
        return NULL;
    if (x > root->data)
        root->right_child = delete(root->right_child, x);
    else if (x < root->data)
        root->left_child = delete(root->left_child, x);
    else {
        if (root->left_child == NULL && root->right_child == NULL) {
            free(root);
            return NULL;
        } else if (root->left_child == NULL || root->right_child == NULL) {
            struct node *temp = (root->left_child != NULL) ? root->left_child : root->right_child;
            free(root);
            return temp;
        } else {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
}

// Inorder traversal of the BST
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left_child);
        printf("%d ", root->data);
        inorder(root->right_child);
    }
}

// Main function to test the BST operations
int main() {
    struct node *root = new_node(20);

    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 15);
    root = insert(root, 9);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 40);
    root = insert(root, 45);
    root = insert(root, 42);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    root = delete(root, 1);
    root = delete(root, 40);
    root = delete(root, 45);
    root = delete(root, 9);

    printf("Inorder traversal after deletions: ");
    inorder(root);
    printf("\n");

    return 0;
}
