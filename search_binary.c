#include<stdio.h>

//순환 호출 버전_이진탐색

int search(int list[], int key, int low, int high, int count){
    int mid;

    if(low<=high){
        mid = (low+high)/2;
        printf("\n%d번째 연산: mid = (%d + %d)/2\n", ++count,low,high);

        if(key == list[mid])
            return printf("성공 mid: %d \n", mid);
        else if (key<list[mid])
            return search(list, key,low,mid-1,count);
        else
            return search(list, key,mid+1,high,count);
    }
    return printf("탐색 실패\n");
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    int count = 0;

    search(arr,15,0,13,count);
}
