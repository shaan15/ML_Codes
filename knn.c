#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char sex[15];
	float weight[15];
	char opt[15];

	int i;

	FILE * fptr = fopen("data_knn.txt","r");
	for(i=0;i<15;i++){
		fscanf(fptr, "%c", &sex[i]);
	}
	for(i=15;i<24;i++){
		fscanf(fptr, "%f", &weight[i-15]);
	}
	for(i=24;i<36;i++){
		fscanf(fptr, "%c", &opt[i-24]);
	}

	fclose(fptr);
	printf("Enter tuple to be processed (weight,sex): ");
	char w,s;
	scanf("%f %c",&w,&s);
	printf("Enter Threshold: ");
	int t;
	scanf("%d",&t);

	float dist[15][2];
	int j,k,l;
	for(i=0;i<15;i++){
		dist[i][0]=i;
		k=weight[i]-w;
		if(k<0){
			dist[i][1]=-k;
		}
		else{
			dist[i][1]=k;
		}
	}

	for(i=0;i<14;i++){
		for(j=0;j<14;j++){
			if(dist[j][1]>dist[j+1][1]){
				k=dist[j][1];
				dist[j][1]=dist[j+1][1];
				dist[j+1][1]=k;

				l=dist[j][0];
				dist[j][0]=dist[j+1][0];
				dist[j+1][0]=l;

			}
		}
	}

	int num_fat=0, num_healthy=0, num_thin=0;

	for(i=0;i<t;i++){
		l=dist[i][0];
		if(opt[l]=='F'){
			num_fat++;
		}
		else if(opt[l]=='H'){
			num_healthy++;
		}
		else if(opt[l]=='T'){
			num_thin++;
		}

	}

	if(num_fat>num_healthy && num_fat>num_thin){
		printf("Fat\n");
	}
	else if(num_thin>num_fat && num_thin>num_healthy){
		printf("Thin\n");
	}
	else if(num_healthy>num_thin && num_healthy>num_fat){
		printf("Healthy\n");
	}
}