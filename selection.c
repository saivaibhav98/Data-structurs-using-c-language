#include<stdio.h>

void sel_Sort();
void display();

void main()
{
	int size;
	printf("Enter the size : ");
	scanf("%d",&size);
	int a[size],i;
	for(i=0;i<size;i++){
		printf("Enter the element %d : ",i+1);
		scanf("%d",&a[i]);
	}
	sel_Sort(size,a);
	display(size,a);
}

void sel_Sort(int size,int a[])
{
	int i,j,min,temp;
	for(i=0;i<size-1;i++){
		min=i;
		for(j=i+1;j<size;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
		}
}

void display(int size,int a[])
{
	int i;
	for(i=0;i<size;i++){
		printf("%d  ",a[i]);
	}
}
