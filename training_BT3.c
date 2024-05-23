#include<stdio.h>

#define SIZE 10
#define DataType int

typedef struct Tnode{
    struct Tnode *left;
    DataType data;
    struct Tnode *right;
}Tnode;

typedef struct LinkedBT{
    Tnode *root;
}LinkedBT;

void inorder(Tnode *root){
    if(root){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int evaluate_tree(Tnode *root){
    if(!root) return NULL;
    if(!root->left && !root->right) return root->data;
    else{
        int opd1 = evaluate_tree(root->left);
        int opd2 = evaluate_tree(root->right);
        switch(root->data){
            case '+': return opd1 + opd2;
            case '-': return opd1 - opd2;
            case '*': return opd1 * opd2;
            case '/': return opd1 / opd2;
            case '%': return opd1 % opd2;
        }
    }
}
typedef struct ArrayQueue{
    int front, rear;
    int queue[SIZE];
}ArrayQueue;

void init_queue(ArrayQueue *AQ){
    AQ->front = AQ->rear = 0;
}

int is_queue_empty(ArrayQueue *AQ){
    return AQ->front == AQ->rear;
}

void enqueue(ArrayQueue *AQ, int data){
    AQ->rear = (AQ->rear+1) % SIZE;
    AQ->queue[AQ->rear] = data;
}

int dequeue(ArrayQueue *AQ){
    AQ->front = (AQ->front+1)%SIZE;
    return AQ->queue[AQ->front];
}

void print_BT(Tnode *root){
    ArrayQueue queue;
    init_queue(&queue);

    if(root){
        enqueue(&queue, root);
        while(!is_queue_empty(&queue)){
            root = dequeue(&queue);
            printf("\n%c\n", root->data);
            if(root->left){
                printf("LC: %d, RC: %d", root->left->data, root->right->data);
                enqueue(&queue, root->left);
            }
            else{
                printf("LC: %d, RC: %d", root->left->data, root->right->data);
                enqueue(&queue, root->right);
            }
        }
    }
}

int search(Tnode *root, DataType data){
    while(root){
        if(root->data == data){
            printf("'%d'를 찾음\n",root->data);
            return root;
        }
        if(data < root->data) root=root->left;
        else root=root->right;
    }
    printf("'%d'은 없어요\n", data);
    return 0;
}

void insert(Tnode **root, DataType data){
    Tnode *searched = *root;
    Tnode *parent = NULL;

    while(searched){
        parent = searched;
        if(data < searched->data){
            searched = searched -> left;
        }
        else if(data>searched->data){
            searched = searched -> right;
        }
        else {
        printf("이미 값이 있어요\n");
        return 0;
        }
    }
    Tnode *new = (Tnode*)malloc(sizeof(Tnode));
    new->data = data;
    new-> left = new->right = NULL;

    if(!parent) *root = new;
    if(data < parent->data) parent->left = new;
    else parent->right = new;
}

int main(){
Tnode node1 = {NULL,1,NULL};
Tnode node2 = {NULL,3,NULL};
Tnode node3 = {NULL,5,NULL};
Tnode node4 = {&node1,2,&node2};
Tnode node5 = {&node4,4,&node3};

LinkedBT BT;
BT.root = &node5;

search(BT.root, 1);
search(BT.root, 8);

inorder(BT.root);

insert(&(BT.root),7);

inorder(BT.root);
print_BT(BT.root);

return 0;


}
