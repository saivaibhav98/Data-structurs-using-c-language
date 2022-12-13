#include<stdio.h>
void radix();
void countsort();
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
	radix(a,size);
	display(a,size);
}

void radix(int a[],int size)
{
	 int max=a[0],i;
	 for(i=1;i<size;i++){
	 	if(a[i]>max){
	 		max=a[i];
		 }
	 }
	 int pos;
	 for(pos=1;max/pos>0;pos=pos*10){
	 	countsort(a,size,pos);
	 }
	 
}

void countsort(int a[],int size,int pos)
{
	int count[10],i;
	for(i=0;i<=10;i++){
		count[i]=0;
	}
	for(i=0;i<size;i++){
		count[(a[i]/pos)%10]++;
	}
	for(i=1;i<=10;i++){
		count[i]=count[i]+count[i-1];
	}
	int b[size];
	for(i=size-1;i>=0;i--){
		b[--count[(a[i]/pos)%10]]=a[i];
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
