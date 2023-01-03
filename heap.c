#include<stdio.h>

void swap();
void heapify();
void display();
void heapsort();

void main(){
	int size;
	printf("Enter the size : ");
	scanf("%d",&size);
	int arr[size],i;
	for(i=1;i<=size;i++){
		printf("Enter the element %d :",i);
		scanf("%d",&arr[i]);
	}
	
	heapsort(arr,size);
	display(arr,size);
}

void heapsort(int arr[], int n){
	int i;
	for(i=n/2;i>=1;i--){
		heapify(arr,n,i);
	}
	for(i=n;i>=1;i--){
		swap(arr[1],arr[i]);
		heapify(arr,n,1);
	}
}

void swap(int arr[],int a,int b){
	int temp = arr[a];
	arr[a]= arr[b];
	arr[b]= temp;
}

void heapify(int arr[],int n,int i){
	int largest = i;
	int left = 2*i;
	int right = 2*i+1;
	
	if(left<=n && arr[left]>arr[largest]){
		largest = left;
	}
	
	if(right<=n && arr[right]>arr[largest]){
		largest = right;
	}
	
	if(largest != i){
		swap(arr,largest,i);
		heapify(arr,n,largest);
	}
}

void display(int arr[],int n){
	int i;
	for(i=1;i<n;i++){
		printf("%d  ",arr[i]);
	}
}
