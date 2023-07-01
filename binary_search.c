#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void binary_search(int arr[], int target, int size){
    int first=0;
    int last=size-1;
    while (first<=last)
    {
        int midpoint= (first+last)/2;
        if (arr[midpoint]==target){
            printf("\nfound at index %d ",midpoint);
            return;
        }else if(target>arr[midpoint]){
            first=midpoint+1;
        }else{
            last=midpoint-1;
        }
    }
    printf("\n not found target");  
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
void mergeSort(int arr[],int start, int last){
    if (start<last){
        int mid=(start+last)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,last);
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
    mergeSort(arr,start,last);
    int target;
    printf("\nArray elements....\n");
    for (int i = 0; i < size; i++){
    printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Enter Target Element: ");
    scanf("%d", &target);
    clock_t begining=clock();
    binary_search(arr,target,size);  
    clock_t end=clock();
    printf("\nTime to operate code : %f microseconds\n", (double)(end - begining) / CLOCKS_PER_SEC*1000000);
    return 0;
}