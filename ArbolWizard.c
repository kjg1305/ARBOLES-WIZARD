#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node* create_node(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    if (node == NULL) {
        fprintf(stderr, "Error: memoria insuficiente\n");
        exit(EXIT_FAILURE);
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return create_node(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL) return NULL;
    if (key == root->key) return root;
    if (key < root->key) return search(root->left, key);
    return search(root->right, key);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

void free_tree(struct Node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void) {
    struct Node* root = NULL;
    int value;

    printf("Ingresa valores para construir el árbol (BST).\n");
    printf("Escribe -1 para terminar.\n");

    while (1) {
        printf("Ingresa un número: ");
        scanf("%d", &value);

        if (value == -1) {
            break; // fin de entrada
        }

        root = insert(root, value);
    }

    printf("\nRecorridos del árbol:\n");

    printf("Inorder (ascendente): ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    free_tree(root);
    return 0;
}
