#include<stdio.h>
typedef struct tree tree;
struct tree
{
    int value;
    tree *left,*right;
};
tree *root=NULL;
tree *copy;
int main()
{
    int *errorcode;
    int n,flag=1,value,error=-1;
    while(flag)
    {
        printf("\n\n --------------------------------------------------------------------");
        printf("\n\n|-------------------->1.Insert in a tree.                            |");
        printf("\n\n|-------------------->2.search in a tree.                            |");
        printf("\n\n|-------------------->0.to exit                                      |");;
        printf("\n\n --------------------------------------------------------------------\n\n\t");
        printf("\n\t\tEnter your choice:");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("\t   Enter the value o be inserted.");
            scanf("%d",&value);
            insert(value);
            if(error==-1)
            {
                printf("\tThe value you are trying to insert is already present.");
                break;
            }
            printf("\t\tInsertion Successful!");
            break;
        case 2:
            printf("\t   enter the value to be searched.");
            scanf("%d",&value);
            copy=root;
            error=search(value);
            if(error==-1)
            {
                printf("\t   Sorry the element does not exists.");
            }
            else if(error=1)
            {
                printf("\t   Yes,%d is pressent in the tree.",value);
            }
            break;
        case 0:
            flag=0;break;
        default :
            printf("\n\t\tInvalid entry!retry");
        }
    }
    return 0;
}
void insert(int value)
{
    if(root==NULL)
    {
        root=(tree *)malloc(sizeof(tree));
        root->value=value;
        root->left=root->right=NULL;
        copy=root;
    }
    else
    {
        if(value==copy->value)
        {
               printf("\n\tSorry! the value you are trying to insert is already present.");
                exit(0);
        }
        if(value<copy->value)
        {
            if(copy->left==NULL)
            {
                copy->left=(tree *)malloc(sizeof(tree));
                copy->left->value=value;
                copy->left->left=copy->left->right=NULL;
            }
            else
            {
                copy=copy->left;
                insert(value);
            }
        }
        else if(value>copy->value)
        {
            if(copy->right==NULL)
            {
                copy->right=(tree *)malloc(sizeof(tree));
                copy->right->value=value;
                copy->right->left=copy->right->right=NULL;
            }
            else
            {
                copy=copy->right;
                insert(value);
            }
        }
    }
    copy=root;
}
int search(int value)
{
    if(copy==NULL)
    {
        return -1;
    }
    else
    {
        if(value==copy->value)
        {
            return 1;
        }
        else if(value<copy->value)
        {
            copy=copy->left;
            search(value);
        }
        else if(value>copy->value)
        {
            copy=copy->right;
            search(value);
        }
    }
}