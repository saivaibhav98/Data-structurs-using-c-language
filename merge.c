#include<stdio.h>
void mergesort();
void merge();
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
	mergesort(a,0,size-1);
	display(a,size);
}

void mergesort(int a[],int lb,int ub)
{
	if(lb<ub)
	{
	int mid = lb+(ub-lb)/2;
	mergesort(a,lb,mid);
	mergesort(a,mid+1,ub);
	
	merge(a,lb,mid,ub);
	}
}

void merge(int a[],int lb,int mid,int ub)
{
	int temp1=(mid-lb)+1;
	int temp2=(ub-mid);
	int left[temp1];
	int right[temp2];
	int i,j,k;
	for(i=0;i<temp1;i++){
		left[i]=a[lb+i];
	}
	for(j=0;j<temp2;j++){
		right[j]=a[mid+1+j];
	}
	i=0,j=0,k=lb;
	while(i<temp1&&j<temp2){
		if(left[i]<right[j]){
			a[k]=left[i];
			i++;
			k++;
		}
		else{
			a[k]=right[j];
			j++;
			k++;
		}
	}
	while(i<temp1){
		a[k]=left[i];
		i++;
		k++;
	}
	while(j<temp2){
		a[k]=right[j];
		j++;
		k++;
	}
}
void display(int a[],int size)
{
	int i;
	for(i=0;i<size;i++){
		printf("%d  ",a[i]);
	}
}

