#include<stdio.h>
void countsort();
void display();

void main()
{
	int size;
	printf("Enter the size : ");
	scanf("%d",&size);
	int a[size],i;
	for(i=0;i<size;i++){
		printf("Enetr the element %d : ",i+1);
		scanf("%d",&a[i]);
	}
	countsort(a,size);
	display(a,size);
}
void countsort(int a[],int size)
{
	int max=a[0],i;
	for(i=1;i<size;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	int count[max];
	for(i=0;i<=max;i++){
		count[i]=0;
	}
	for(i=0;i<size;i++){
		count[a[i]]++;
	}
	for(i=1;i<=max;i++){
		count[i]=count[i]+count[i-1];
	}
	int b[size];
	for(i=size-1;i>=0;i--){
		b[--count[a[i]]]=a[i];
	}
	for(i=0;i<size;i++){
		a[i]=b[i];
	}
}

void display(int a[],int size)
{
	int i;
	for(i=0;i<size;i++){
		printf("%d  ",a[i]);
	}
}
