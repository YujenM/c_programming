#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
int jumpsearch (int arr[], int target, int size){
    int low=0;
    int jump= sqrt(size);
    for(int i=0; i<size; i +=jump){
        if (arr[i]==target){
            return i;
        }if(arr[i]<target){
            low=i;
        }if(arr[i]>target){
            break;
        }
    }
    for(int i=low; i<size; i++){
        if (arr[i]==target){
            return i;
        }
    }
    return -1;
}
void merge(int arr[], int start, int mid, int last){
    int left = mid-start+1;
    int right=last-mid;
    int leftarr[left];
    int rightarr[right];
    int l=0, s=start ,r=0;
    while (l<left)
    {
        leftarr[l]=arr[s];
        l++;
        s++;
    }
    while (r<right)
    {
        rightarr[r]=arr[s];
        r++;
        s++;
    }
    l=0;
    r=0;
    s=start;
    while(l<left && r<right){
        if(leftarr[l]<=rightarr[r]){
            arr[s]=leftarr[l];
            s++;
            l++;
        }else{
            arr[s]=rightarr[r];
            s++;
            r++;
        }
    }
    while(r<right){
        arr[s]=rightarr[r];
        s++;
        r++;
    }
    while (l<left)
    {
        arr[s]=leftarr[l];
        s++;
        l++;
    }
}
void mergesort(int arr[],int start, int last){
    if (start<last){
        int mid=(start+last)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,last);
        merge(arr,start,mid,last);
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
    printf("Randomly generated arrays:\n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    int start=0;
    int last=size-1;
    mergesort(arr,start,last);
    int target;
    printf("\nEnter Target Element: ");
    scanf("%d", &target);
    printf("Array elements....\n");
    for (int i = 0; i < size; i++){
    printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Enter Target Element: ");
    clock_t begining=clock();
    int search=jumpsearch(arr,target,size);
    clock_t end=clock();
    if (search==-1){
        printf("\nElement is not present in the array\n");
    }else{
        printf("\nTarget is at  index %d",search);
    }
    printf("\nTime to operate code : %f microseconds\n", (double)(end - begining) / CLOCKS_PER_SEC*1000000);
    return 0;
}
