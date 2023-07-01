#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void linersearch(int arr[],int target,int size){
    int found=0;
    for(int i=0; i<size; i++){
        if (arr[i]==target){
            printf("\nFound at index %d\n",i);
            found=1;
        }
    }
    if (!found){
            printf("Target not found\n");
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
for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
}
int target;


printf("\nEnter Target: ");
scanf("%d", &target);
clock_t begining=clock();
linersearch(arr,target,size);
clock_t end=clock();
printf("\nTime to operate code : %f microseconds\n", (double)(end - begining) / CLOCKS_PER_SEC*1000000);
return 0;
}