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
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int height(struct Node* root) {
    if (root == NULL) {
        return -1;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}
int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }
}

int findMin(struct Node* root) {
    if (root == NULL) {
        printf("Error: Tree is empty.\n");
        return -1;
    } else if (root->left == NULL) {
        return root->data;
    } else {
        return findMin(root->left);
    }
}

int findMax(struct Node* root) {
    if (root == NULL) {
        printf("Error: Tree is empty.\n");
        return -1;
    } else if (root->right == NULL) {
        return root->data;
    } else {
        return findMax(root->right);
    }
}

struct Node* mirrorImage(struct Node* root) {
    if (root == NULL) {
        return NULL;
    } else {
        struct Node* temp;

        // Recursively convert left subtree to mirror
        root->left = mirrorImage(root->left);

        // Recursively convert right subtree to mirror
        root->right = mirrorImage(root->right);

        // Swap the left and right subtrees
        temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
    
}

void printLeafNodes(struct Node* root) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void printNodesLevelWise(struct Node* root, int level) {
    if (root == NULL) {
        return;
    }

    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printNodesLevelWise(root->left, level - 1);
        printNodesLevelWise(root->right, level - 1);
    }
}

void printLevelOrder(struct Node* root) {
    int h = height(root);
    for (int i = 1; i <= h + 1; i++) {
        printf("Level %d: ", i);
        printNodesLevelWise(root, i);
        printf("\n");
    }
}

int main() {
    struct Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 4);
    root = insertNode(root, 15);
    root = insertNode(root, 18);
    root = insertNode(root, 8);
    root = insertNode(root, 12);

    int choice, data;
    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert Element\n");
        printf("2. Find Height\n");
        printf("3. Count Nodes\n");
        printf("4. Count Leaf Nodes\n");
        printf("5. Find Minimum\n");
        printf("6. Find Maximum\n");
        printf("7. Create Mirror Image\n");
        printf("8. Print Leaf Nodes\n");
        printf("9. Print Nodes Level Wise\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            printf("Exiting...\n");
            break;
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            root = insertNode(root, data);
            break;
        case 2:
            printf("Height of the tree: %d\n", height(root));
            break;
        case 3:
            printf("Number of nodes in the tree: %d\n", countNodes(root));
            break;
        case 4:
            printf("Number of leaf nodes in the tree: %d\n", countLeafNodes(root));
            break;
        case 5:
            printf("Minimum element in the tree: %d\n", findMin(root));
            break;
        case 6:
            printf("Maximum element in the tree: %d\n", findMax(root));
            break;
        case 7:
            root = mirrorImage(root);
            printf("Mirror image of the tree created.\n");
            break;
        case 8:
            printf("Leaf nodes in the tree: ");
            printLeafNodes(root);
            printf("\n");
            break;
        case 9:
            printf("Printing nodes level wise:\n");
            printLevelOrder(root);
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
