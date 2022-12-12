#include<stdio.h>
void main()
{
	int size;
	printf("Entet the size : ");
	scanf("%d",&size);
	int a[size],i;
	for(i=0;i<size;i++){
		printf("Enter the element %d : ",i+1);
		scanf("%d",&a[i]);
	}
	shellSort(size,a);
	display(size,a);
}

void shellSort(int size,int a[])
{
	int gap,i,j,temp;
	for(gap=size/2;gap>=1;gap=gap/2){     //or decreament of gap
		for(j=gap;j<size;j++){           //for moving 1 bit forward
			for(i=j-gap;i>=0;i=i-gap){  //for checking backword elements is there or not
				if(a[i]>a[gap+i]){
					temp=a[i];
					a[i]=a[gap+i];
					a[gap+i]=temp;
				}
				else
				break;
			}
		}
	}
}

void display(int size,int a[])
{
	int i=0;
	while(i<size){
		printf("%d  ",a[i]);
		i++;
	}
}
