#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
 
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}


void inorderTraversal(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Function for non-recursive preorder traversal
void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        struct Node* current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL)
            stack[++top] = current->right;

        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

// Function for non-recursive postorder traversal
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100];
    int top = -1;
    struct Node* prev = NULL;

    do {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }

        while (root == NULL && top != -1) {
            struct Node* temp = stack[top];

            if (temp->right == NULL || temp->right == prev) {
                printf("%d ", temp->data);
                top--;
                prev = temp;
            } else {
                root = temp->right;
            }
        }
    } while (top != -1);
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("\nBinary Tree Operations\n");
        printf("1. Insert an element\n");
        printf("2. Non-recursive Inorder traversal\n");
        printf("3. Non-recursive Preorder traversal\n");
        printf("4. Non-recursive Postorder traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder Traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder Traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
