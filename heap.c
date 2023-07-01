# include <stdio.h>
# include <stdlib.h>
# include <time.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[],int size,int root){
    int largest = root;
    int left = 2*root + 1;
    int right = 2*root + 2;
    while(left<size){
        if(arr[left] > arr[largest]){
            largest = left;
        }
        if(right < size && arr[right] > arr[largest]){
            largest = right;
        }
        if(largest!=root){
            swap(&arr[root],&arr[largest]);
            root = largest;
            left = 2*root + 1;
            right = 2*root + 2;
        }else{
            break;
        }
    }
}
void heapsort(int arr[],int size){
    for (int i=size/2-1; i>=0;i--){
        heapify(arr,size,i);
    }
    for (int i=size-1; i>0 ;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i, 0);
    }
}
int main(int argc, char const *argv[])
{
    int *arr;
    int size; // take input from the user
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
    clock_t start=clock();
    heapsort(arr,size);clock_t end=clock();
    printf("\n\nSorted Array elements....\n");
    for (int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\nTime taken to operate: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");
    return 0;
}
