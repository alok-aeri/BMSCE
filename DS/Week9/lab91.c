#include <stdio.h>  
#include <stdlib.h>  

typedef struct TreeNode  
{  
    int value;  
    struct TreeNode *leftChild;  
    struct TreeNode *rightChild;  
}TreeNode;  

TreeNode* createNewNode(int num)  
{  
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));  
    node->value = num;  
    node->leftChild = NULL;  
    node->rightChild = NULL;  
    return node;  
}  

TreeNode* addNode(TreeNode *rootNode, int num)  
{  
    if (rootNode == NULL)  
    {  
        return createNewNode(num);  
    }  
    if (num < rootNode->value)  
    {  
        rootNode->leftChild = addNode(rootNode->leftChild, num);  
    }  
    else if (num > rootNode->value)  
    {  
        rootNode->rightChild = addNode(rootNode->rightChild, num);  
    }  
    return rootNode;  
}  

void inOrder(TreeNode *rootNode)  
{  
    if (rootNode != NULL)  
    {  
        inOrder(rootNode->leftChild);  
        printf("%d ", rootNode->value);  
        inOrder(rootNode->rightChild);  
    }  
}  

void preOrder(TreeNode *rootNode)  
{  
    if (rootNode != NULL)  
    {  
        printf("%d ", rootNode->value);  
        preOrder(rootNode->leftChild);  
        preOrder(rootNode->rightChild);  
    }  
}  

void postOrder(TreeNode *rootNode)  
{  
    if (rootNode != NULL)  
    {  
        postOrder(rootNode->leftChild);  
        postOrder(rootNode->rightChild);  
        printf("%d ", rootNode->value);  
    }  
}  

void showTree(TreeNode *rootNode)  
{  
    printf("Tree Elements:\n");  
    printf("\nIn-Order: ");  
    inOrder(rootNode);  
    printf("\nPre-Order: ");  
    preOrder(rootNode);  
    printf("\nPost-Order: ");  
    postOrder(rootNode);  
}  

int main()  
{  
    int num;  
    char continueInput;  
    TreeNode *treeRoot = NULL;  
    do {  
        printf("\nEnter value: ");  
        scanf("%d", &num);  
        treeRoot = addNode(treeRoot, num);  
        printf("\nMore values? (y/n): ");   
        getchar();  
        scanf("%c", &continueInput);  
    } while (continueInput == 'y' || continueInput == 'Y');  

    showTree(treeRoot);  
    return 0;  
}
