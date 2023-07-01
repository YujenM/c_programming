#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void selection(int arr[],int size){
    for (int i=0; i<size-1; i++){
        int min_index = i;
        for (int j=i+1; j<size; j++){
            if (arr[min_index]>arr[j]){
                min_index = j;
            }
        }
        if ( min_index!=i){
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    }
}

int main(int argc, char const *argv[])
{
    int *arr;
    int size; 
    printf("Enter Size of array: ");
    scanf("%d", &size);
    arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++){
    int randomNum = (rand() % size) + 1;
    int duplicateEle = 0;
    for (int j = 0; j < i; j++){
    if (arr[j] == randomNum){
        duplicateEle = 1;
        break;
        }
    }
    if (duplicateEle == 0){
    arr[i] = randomNum;
    }
    else{
    i--;
    }
    }
    printf("Array elements....\n");
    for (int i = 0; i < size; i++){
    printf("%d ", arr[i]);
    }
    clock_t begining=clock();
    selection(arr,size);
    clock_t end=clock();
    printf("\nSorted array\n");
    for(int i=0 ;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\nTime to operate code : %f microseconds\n", (double)(end - begining) / CLOCKS_PER_SEC*1000000);
    return 0;
}
