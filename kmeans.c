#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int i,old1,old2,dist1,dist2;
	int arr1[15],arr2[15],arr3[15];
	FILE * fptr = fopen("data_kmeans.txt","r");
	for(i=0;i<15;i++){
		fscanf(fptr, "%d", &arr1[i]);
	}
	int m1,m2;
	printf("Enter mean1 and mean2: ");
	scanf("%d %d",&m1,&m2);

	do{
		old1=m1;
		old2=m2;
		int j=0, k=0;
		for(i=0;i<15;i++){
			dist1=arr1[i]-m1;
			if(dist1 < 0){
				dist1=-dist1;
			}
			dist2=arr1[i]-m2;
			if(dist2 < 0){
				dist2=-dist2;
			}

			if(dist1<dist2){
				arr2[j]=arr1[i];
				j++;
			}
			else{
				arr3[k]=arr1[i];
				k++;
			}
		}
		dist2=0;
		for(dist1=0;dist1<j;dist1++){
			dist2+=arr2[dist1];
		}
		m1=dist2/j;
		dist2=0;
		for(dist1=0;dist1<k;dist1++){
        	dist2+=arr3[dist1];
    	}
    	m2=dist2/k;

    	printf("Mean1: %d\n", m1);
    	printf("mean2: %d\n", m2);
 
    	
	}while(m1!=old1 && m2!=old2);

}
