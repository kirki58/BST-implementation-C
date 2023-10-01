#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* init_node(int val){
    Node* bstn = (Node*) malloc(sizeof(Node));
    bstn->data = val;
    bstn->left = NULL;
    bstn->right = NULL;
    return bstn;
}
Node* insert(Node** root, int val){
    Node* newNode = init_node(val);
    if(*root == NULL){
        *root = newNode;
        return *root;
    }
    Node* temp = *root;
    if(val > temp->data){
        if(temp->right != NULL){
            insert(&temp->right, val);
        }
        else{
            temp->right = newNode;
            return newNode;
        }
    }

    // if val <= temp->data
    if(temp->left != NULL){
        insert(&temp->left,val);
    }
    else{
        temp->left = newNode;
        return newNode;
    }
}
Node* search(Node* root, int val){
    if(root == NULL){
        return NULL;
    }
    Node* temp = root;
    if(temp->data == val){
        return temp;
    }
    else if(temp->data > val){
        return search(temp->left,val);
    }
    else if(temp->data < val){
        return search(temp->right,val);
    }
}
bool isInTree(Node* root, int val){
    return(search(root,val) != NULL);
}
Node** rightmost(Node** root){
    if((*root) == NULL){
        printf("rightmost call on NULL node returned NULL\n");
        return NULL;
    }
    if((*root)->right == NULL){
        return (root);
    }
    else{
        return rightmost(&((*root)->right));
    }
}
Node** leftmost(Node** root){
    if((*root) == NULL){
        printf("leftmost call on NULL node returned NULL\n");
        return NULL;
    }
    if((*root)->left == NULL){
        return (root);
    }
    else{
        return leftmost(&((*root)->left));
    }
}
int max(Node* root){
    return( (*rightmost(&root))->data );
}
int min(Node* root){
    return( (*leftmost(&root))->data );
}

void rm_node(Node** root, int val){
    if(!isInTree(*root,val)){
        printf("No value as %d\n",val);
    }
    else{
        if((*root)->data == val){
            if((*root)->right == NULL && (*root)->left == NULL){
                *root = NULL;
                free(*root);
            }
            else if((*root)->right == NULL && (*root)->left != NULL){
                (*root) = (*root)->left; 
            }
            else if((*root)->right != NULL && (*root)->left == NULL){
                (*root) = (*root)->right; 
            }
            else{
                Node** rm = rightmost(&((*root)->right));
                (*root)->data = (*rm)->data;
                (*rm) = NULL;
                free(*rm);
            }
            return;
        }
        else if(val > (*root)->data){
            rm_node(&((*root)->right), val);
        }
        else{
            rm_node(&((*root)->left), val);
        }
    }
}

static int maxVal(int i1, int i2){
    if(i1>=i2){
        return i1;
    }
    else{
        return i2;
    }
}
static int height(Node* root, int ht){
    if(root == NULL){
        return 0;
    }
    int h = ht;
    if(root->right == NULL && root->left == NULL){
        return h;
    }
    return maxVal(height(root->left,h+1),height(root->right,h+1));
}
int get_height(Node* root){
    return height(root,0);
}
static int depth(Node* root, Node* nd, int dt){
    if(!isInTree(root,nd->data)){
        printf("No node as \n",nd->data);
        return -1;
    }
    else{
        int d = dt;
        if(root == nd){
            return d;
        }
        else if(nd->data > root->data){
            return depth(root->right,nd,d+1);
        }
        else{
            return depth(root->left,nd,d+1);
        }
    }
}
int get_depth(Node* root, Node* nd){
    return depth(root,nd,0);
}
