#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *right;
    struct node *left;
};

struct node *root = NULL;

struct node *insert(struct node *root, int n) {
    struct node *temp = root;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->right = NULL;
    new->left = NULL;

    if (root == NULL) {
        root = new;
        return root;
    }

    if (n < temp->data)
        temp->left = insert(temp->left, n);
    else if (n > temp->data)
        temp->right = insert(temp->right, n);
    else {
        printf("Element already exists.\n");
        free(new);
    }
    return root;
}

struct node *delete(struct node *root, int m) {
    struct node *pt, *temp, *succ, *succParent;
    pt = NULL;
    temp = root;

    while (temp != NULL) {
        if (temp->data == m)
            break;
        pt = temp;
        temp = (m < temp->data) ? temp->left : temp->right;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return root;
    }

    // Case 1: Leaf Node
    if (temp->left == NULL && temp->right == NULL) {
        if (pt == NULL) return NULL;
        if (pt->left == temp) pt->left = NULL;
        else pt->right = NULL;
        free(temp);
    }

    // Case 2: One child
    else if (temp->left == NULL || temp->right == NULL) {
        struct node *child = (temp->left) ? temp->left : temp->right;
        if (pt == NULL)
            root = child;
        else if (pt->left == temp)
            pt->left = child;
        else
            pt->right = child;
        free(temp);
    }

    // Case 3: Two children
    else {
        succ = temp->right;
        succParent = temp;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        temp->data = succ->data;
        if (succParent->left == succ)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        free(succ);
    }

    return root;
}

void inorder(struct node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Count total nodes
int countNodes(struct node *root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count leaf nodes
int countLeafNodes(struct node *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Find smallest value
int findSmallest(struct node *root) {
    if (root == NULL) return -1;
    struct node *temp = root;
    while (temp->left != NULL) temp = temp->left;
    return temp->data;
}

// Find largest value
int findLargest(struct node *root) {
    if (root == NULL) return -1;
    struct node *temp = root;
    while (temp->right != NULL) temp = temp->right;
    return temp->data;
}

// Find height
int findHeight(struct node *root) {
    if (root == NULL) return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    int ch, n, m;

    do {
        printf("\n\n--- Binary Search Tree Menu ---");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Inorder Traversal");
        printf("\n4. Preorder Traversal");
        printf("\n5. Postorder Traversal");
        printf("\n6. Count Total Nodes");
        printf("\n7. Count Leaf Nodes");
        printf("\n8. Find Smallest Value");
        printf("\n9. Find Largest Value");
        printf("\n10. Find Height of BST");
        printf("\n11. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &n);
                root = insert(root, n);
                break;

            case 2:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Enter element to delete: ");
                    scanf("%d", &m);
                    root = delete(root, m);
                }
                break;

            case 3:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 5:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 6:
                printf("Total nodes: %d\n", countNodes(root));
                break;

            case 7:
                printf("Leaf nodes: %d\n", countLeafNodes(root));
                break;

            case 8:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                    printf("Smallest value: %d\n", findSmallest(root));
                break;

            case 9:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                    printf("Largest value: %d\n", findLargest(root));
                break;

            case 10:
                printf("Height of BST: %d\n", findHeight(root));
                break;

            case 11:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 11);

    return 0;
}
