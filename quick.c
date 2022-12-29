#include<stdio.h>
void quick(int [] ,int ,int);
int merge(int[], int ,int);
void display(int[], int);
void swap(int, int ,int[]);
void main(){
	int size;
	printf("Enter the size : ");
	scanf("%d",&size);
	int arr[size],i;
	for(i=0;i<size;i++){
	printf("Enter the element %d : ",i+1);
	scanf("%d",&arr[i]);
	}
	quick(arr,0,size-1);
	display(arr,size);
}
void quick(int arr[], int low, int high){
	int j;
	if(low < high){
		j = merge(arr,low,high);
		quick(arr,low,j-1);
		quick(arr,j+1,high);
	}
}
int merge(int arr[], int low, int high){
	int pivot = low,i = low,j = high,tem;
	while(i < j){
		while(arr[i]<=arr[pivot])
			i++;
		while(arr[j]>arr[pivot])
			j--;
		if(i < j)
			swap(i, j, arr);
	}
	swap(low, j , arr);
	return j;
}
void swap(int a, int b,int arr[]){
	int tem = arr[a];
	arr[a] = arr[b];
	arr[b] = tem;
}
void display(int arr[], int size){
	int i;
	for(i=0;i<size;i++)
		printf("%d  ",arr[i]);	
}
