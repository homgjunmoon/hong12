#include<stdio.h>
//#include<stdlib.h>
#define SIZE 8

#define SWAP(x,y,t)((t)=(x), (x)=(y),(y)=(t))

int list[SIZE] = {4,1,8,2,7,3,6,5};

int partition(int list[], int left, int right){
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do{
        do
            low++;
        while(list[low]<pivot);
        do
            high--;
        while(list[high]>pivot);
        if (low<high) SWAP(list[low],list[high],temp);
    }while(low<high);

    SWAP(list[left], list[high], temp);
    return high;
}
void quick_sort(int list[], int left, int right){
        if(left<right){
            int q = partition(list, left, right);
            quick_sort(list, left,q-1);
            quick_sort(list,q+1,right);

    }
}
int main(){
    quick_sort(list, 0, SIZE-1);
    for(int i=0;i<SIZE;i++)
        printf("%d ",list[i]);
    printf("\n");
    return 0;
}
