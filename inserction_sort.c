#include<stdio.h>
void inserction_sort();
void display();
void main(){
	int size;
	printf("Enter the size : ");
	scanf("%d",&size);
	int a[size],i;
	for(i=0;i<size;i++){
		printf("Enter the element %d : ",i+1);
		scanf("%d",&a[i]);
	}
	printf("Before sorting : ");
	display(size,a);
	printf("After sorting  :  ");
	inserction_sort(size,a);
	display(size,a);
}
void inserction_sort(int size,int a[])
{
	int i,j,temp;
	for(i=1;i<size;i++){
		temp=a[i];
		j=i-1;
		while(j>=0&&a[j]>temp){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	
}
void display(int size,int a[]){
	int i;
	for(i=0;i<size;i++){
		printf(" %d ",a[i]);
	}
	printf("\n");
}
