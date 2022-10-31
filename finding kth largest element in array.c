#include<stdio.h>
#include<stdlib.h>

void swap(int *p,int *q){
	int temp=*p;
	*p=*q;
	*q=temp;
}
int partition(int a[],int p,int r){
	int x=a[r];
	int i=p-1;
	int j;
	for(j=p;j<r;j++){
		if(a[j]<=x){
			i=i+1;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[r]);
	return i+1;
}
void quicksort(int a[],int p,int r){
	int q;
	if(p<r){
		 q=partition(a,p,r);
	
	quicksort(a,p,q-1);
	quicksort(a,q+1,r);
}
}

int deldup(int arr[],int n){
    int k,i,j;
    for(i=0;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if(arr[j]==arr[i]){
                 k=j;
                while(k!=n){
                arr[k]=arr[k+1];
                k++;
                }
                n=n-1;
                j--;
            }
        }
    }
    return (arr,n);
}

int main(){
	int n,i=0,k;
	printf("Enter number of elements in array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements->");
	while(i<n){
		scanf("%d",&a[i]);
		i++;
	}
	 a,n=deldup(a,n);
	quicksort(a,0,n-1);
	printf("Enter the value of k for kth largest element: ");
	scanf("%d",&k);
	printf("%d is kth largest element\n",a[n-k]);
	

return 0;
}
