#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST.", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

int main()
{
    /*  This is the given tree to traverse:

            50
           /  \
         40    60
        /  \     \
      20   45    70

    */
    struct node *p = createNode(50);
    struct node *p1 = createNode(40);
    struct node *p2 = createNode(60);
    struct node *p3 = createNode(20);
    struct node *p4 = createNode(45);
    struct node *p5 = createNode(70);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;

    inOrder(p);
    printf("\n");

    insert(p, 2);
    insert(p, 50);
    printf("\n");
    insert(p, 57);

    printf("Added: %d\n", p->left->left->left->data);
    printf("Added: %d\n", p->right->left->data);

    inOrder(p);

    return 0;
}
