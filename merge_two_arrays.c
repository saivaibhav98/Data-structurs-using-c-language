#include<stdio.h>
void main()
{
	int a[]={1,3,5,7,9};
	int b[]={2,4,5,6,8};
	merge(a,b,5,5);
}
void merge(int a[],int b[],int m,int n)
{
		int r[m+n];
		int i=0,j=0,k=0;
		while(i<m&&j<n){
			if(a[i]<b[j])
			{
				r[k]=a[i];
				k++;
				i++;
			}
			else
			{
				r[k]=b[j];
				k++;
				j++;
				
			}
		}
		while(i<m)
		{
			r[k]=a[i];
			k++;
			i++;
		}
		while(j<n)
		{
			r[k]=a[j];
			k++;
			j++;
		}
		for(i=0;i<m+n;i++)
		printf("%d ",r[i]);
}
