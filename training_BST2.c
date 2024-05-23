#include<stdio.h>

#define SIZE 10
#define DataType char

typedef struct Tnode{
    struct Tnode *left;
    DataType data;
    struct Tnode *right;
}Tnode;

typedef struct LinkedBT{
    Tnode *root;
}LinkedBT;

void preorder(Tnode *root){
    if(root){
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Tnode *root){
    if(root){
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
    }
}
void postorder(Tnode *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int evaluate_tree(Tnode *root){
    if(!root) return 0;
    if(!root->left && !root->right) return root->data;
    else{
        int opd1 = evaluate_tree(root->left);
        int opd2 = evaluate_tree(root->right);
        switch(root->data){
            case'+': return opd1 + opd2;
            case'-': return opd1 - opd2;
            case'*': return opd1 * opd2;
            case'/': return opd1 / opd2;
            case'%': return opd1 % opd2;
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
    return (AQ->front == AQ->rear);
}

void enqueue(ArrayQueue *AQ, DataType data){
    AQ->rear = (AQ->rear+1)%SIZE;
    AQ->queue[AQ->rear] = data;
}

int dequeue(ArrayQueue *AQ){
    AQ->front = (AQ->front+1)%SIZE;
    return AQ->queue[AQ->front];
}

void print_BT(Tnode *root){
    ArrayQueue queue;
    init_queue(&queue);

    if (root){
        enqueue(&queue, root);
        while(!is_queue_empty(&queue)){
            root = dequeue(&queue);
            printf("%c ", root->data);
            if(root->left){
                printf("좌자식: %c", root->left->data);
                enqueue(&queue, root->left);
            }
            if(root->right){
                printf("우자식: %c", root->right->data);
                enqueue(&queue, root->right);
            }
        }
    }
}

int search(Tnode *root, DataType data){
        while(root){
            if (root->data == data){
                printf("'%c'탐색 성공\n", root->data);
                return data;
            }
            if(root->left){
                root=root->left;
            }
            else{ //
                root=root->right;
            }
        }
        printf("탐색 실패\n"); return 0;
}
void insert(Tnode **root, DataType data){
    if(search(root, data)){
        printf("이미 존재합니다.\n");
        return 0;
    }
    Tnode *searched = *root;
    Tnode *parent = NULL;

    while(searched){
        parent = searched;
        if(data < searched->data) searched = searched->left;
        else searched = searched->right;
    }
    Tnode *new = (Tnode*)malloc(sizeof(Tnode));
    if(!new){
        printf("할당 실패\n");
        exit(1);
    }
    new->data = data;
    new->left = new->right = NULL;

    if(!parent) *root = new;
    else if(data < parent->data)
        parent->left = new;
    else parent->right = new;

}

int main(){
    Tnode node1 = {NULL,'1',NULL};
    Tnode node2 = {NULL,'3',NULL};
    Tnode node3 = {NULL,'5',NULL};
    Tnode node4 = {&node2,'4',&node3};
    Tnode node5 = {&node1,'2',&node4};

    LinkedBT BT;
    BT.root = &node5;

    inorder(BT.root);
    insert(&BT.root, '1');
    inorder(BT.root);
    insert(&BT.root, '9');
    inorder(BT.root);

}
