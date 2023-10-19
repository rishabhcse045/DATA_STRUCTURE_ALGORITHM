#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct TreeNode {
    int data;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    return newNode;
}

void insert(struct TreeNode* tree[], int index, int data) {
    if (index < MAX_SIZE) {
        tree[index] = createNode(data);
    }
    else {
        printf("Array is full. Cannot insert more elements.\n");
    }
}

void display(struct TreeNode* tree[], int index, int n) {
    if (index < n && tree[index] != NULL) {
        printf("%d ", tree[index]->data);
        display(tree, 2 * index + 1, n); // Recursively display left subtree
        display(tree, 2 * index + 2, n); // Recursively display right subtree
    }
}

int main() {
    struct TreeNode* tree[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = NULL;
    }

    int n;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("The array size is too small to insert that many elements.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insert(tree, i, data);
    }

    // Display the tree
    printf("Binary Tree: ");
    display(tree, 0, n);

    return 0;
}
