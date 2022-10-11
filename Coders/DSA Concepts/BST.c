#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

//initializes the tree
void init(Node **root)
{
    root = NULL;
    return;
}

//inserts a node in the tree recursively
void insert(Node **tree, int val)
{
    Node *temp = NULL;
    if (!(*tree))
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = val;
        int i = 0;
        *tree = temp;
        return;
    }
    if ((*tree)->data == val)
    {
        return;
    }
    else if (val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if (val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}

//inorder traversal of the tree recursively
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

//searches for a node in the tree recursively
Node *search(Node *root, int val)
{
    if (root == NULL || root->data == val)
    {
        return root;
    }
    if (val > root->data)
    {
        search(root->right, val);
    }
    else if (val < root->data)
    {
        search(root->left, val);
    }
}
Node *minValue(Node *root)
{
    Node *ptr = root;
    while (ptr && ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr;
}

//deletes a node from the tree recursively
Node *deleteNode(Node *root, int d)
{
    Node *res = search(root, d);
    if (res)
    {
        // Case 1: Empty tree
        if (root == NULL)
        {
            return root;
        }
        if (root->data > d)
        {
            root->left = deleteNode(root->left, d);
        }
        else if (root->data < d)
        {
            root->right = deleteNode(root->right, d);
        }
        else
        {
            // Node has only 1 or 0 children
            if (root->left == NULL)
            {
                Node *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                free(root);
                return temp;
            }
            else
            {
                Node *temp = minValue(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }
    else
    {
        printf("Not Found\n");
    }
}

//destroy the complete tree
void _deleteTree(Node *Node)
{
    if (Node == NULL)
        return;
    _deleteTree(Node->left);
    _deleteTree(Node->right);
    printf("Deleting Node: %d\n", Node->data);
    free(Node);
}
void destroyTree(Node **Node_ref)
{
    _deleteTree(*Node_ref);
    *Node_ref = NULL;
}

//level order traversal of the tree
void level(Node *root, int lev)
{
    if (root == NULL)
    {
        return;
    }
    if (lev == 0)
    {
        printf("%d\n", root->data);
        return;
    }
    else if (lev > 0)
    {
        level(root->left, lev - 1);
        level(root->right, lev - 1);
    }
}


int main()
{
    int oper;
    Node *root = NULL;
    int insertVal;
    int delVal;
    int searchVal;
    int ilevel;
    char name[500];
    printf("\n0:For quitting\n1.Initializing BST\n2.Inserting in a BST\n3.Removing a node from BST\n4.Searching a Node\n5.Displaying Node at ith level\n6.Destroy BST\n");
    printf("Enter the operation you want to perform\n");
    scanf("%d", &oper);
    while (oper)
    {
        switch (oper)
        {
        case 1:
            init(&root);
            break;
        case 2:
        {
            printf("Enter the data you want to insert in BST: ");
            scanf("%d", &insertVal);
            printf("\n");
            insert(&root, insertVal);
            break;
        }
        case 3:
        {
            printf("Enter data of the node you want to delete\n");
            scanf("%d", &delVal);
            deleteNode(root, delVal);
            break;
        }
        case 4:
        {
            printf("Enter data of the node you want to search\n");
            scanf("%d", &searchVal);
            if (search(root, searchVal))
            {
                printf("Found!\n");
            }
            else
            {
                printf("Not Found!\n");
            }
            break;
        }
        case 5:
            printf("Enter the level of nodes\n");
            scanf("%d", &ilevel);
            level(root, ilevel);
            break;
        case 6:
            printf("Destroying BST\n");
            destroyTree(&root);
            break;
        default:
            printf("Invalid Operation Entered\n");
            break;
        }
        printf("Enter the operation you want to perform\n");
        scanf("%d", &oper);
    }
    return 0;
}
