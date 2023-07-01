	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	void merge(int arr[], int start, int mid, int last){
		// making left array size
		int left = mid-start+1;
		// making right array size
		int right=last-mid;
		// making left array
		int leftarr[left];
		// making right array
		int rightarr[right];
		// making index to track array
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
		// printf("Left array \n");
		// for (int i = 0; i < left; i++){
		//     printf("%d \n",leftarr[i]);
		// }
		// printf("right array \n");
		// for (int i = 0; i < right; i++){
		//     printf("%d \n",rightarr[i]);
		// }
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
	//     printf("Merged array \n");
	//     for(int i=0; i<=last; i++){
	//         printf("%d \n",arr[i]);
	//     }
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
// printf("Array elements....\n");
// for (int i = 0; i < size; i++){
//     printf("%d ", arr[i]);
// }
int start=0;
int last=size-1;
clock_t begining=clock();
mergesort(arr,start,last);clock_t end=clock();
printf("\nsorted array\n");
for(int i=0; i<size; i++){
	printf("%d ",arr[i]);
}
printf("\nTime to operate code : %f seconds\n", (double)(end - begining) / CLOCKS_PER_SEC);
return 0;
}