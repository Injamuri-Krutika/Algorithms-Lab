#include<stdio.h>
#include<stdlib.h>
#define FOR(i,num) for(int i;i<num;i++)
#define INFINITE 99999



int min(int a,int b){
	return (a<b)?a:b;
}

void printArr(int * arr,int num){
	for(int i=0;i<num;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}


void printCoinstUsed(int *arr1,int *arr2,int* coins,int totAmt){

	int temp=totAmt;
	while(temp>0){
		int denomUsed=coins[arr2[temp]];
		temp-=denomUsed;
		printf("%d ",denomUsed);
	}


}


int main(){
	FILE *fp =fopen("input.txt","r");
	int numOfKeys=0;
	fscanf(fp,"%d",&numOfKeys);
	int keyVal[numOfKeys],keyFreq[numOfKeys],final[numOfKeys][numOfKeys],roots[numOfKeys][numOfKeys];
	for(int i=0;i<numOfKeys;i++){ 
		fscanf(fp,"%d",&keyVal[i]);
	}
	for(int i=0;i<numOfKeys;i++){
		fscanf(fp,"%d",&keyFreq[i]);
	}

	for(int i=0;i<numOfKeys;i++){
		for(int j=0;j<numOfKeys;j++){
			final[i][j]=0;
			roots[i][j]=0;
		}
	}

	for(int l=1;l<=numOfKeys;l++){
		for(int i=0;i<(numOfKeys-l+1);i++){
			int j=i+l-1;
			if(i==j){
				final[i][i]=keyFreq[i];
				roots[i][j]=i;
			}else{
				int sum=0,min=INFINITE,minIndex=-1;
				for(int k=i;k<=j;k++){
					sum+=keyFreq[k];
					int left=((k-1)>=0)?final[i][k-1]:0;
					int right=((k+1)<numOfKeys)?final[k+1][j]:0;
					if(min>(left+right) && (left+right)>0){	
						min=left+right;
						minIndex=k;
					}
						  
				}
				printf("%f sum, %f val\n",sum,left+right);
				final[i][j]=sum+min;
				roots[i][j]=minIndex;
			}
		}
	}
	
	for(int i=0;i<numOfKeys;i++){
		for(int j=0;j<numOfKeys;j++){
			printf("%d\t",final[i][j]);
		}
		printf("\n");
	}
	printf("Root Matrix\n");
	for(int i=0;i<numOfKeys;i++){
		for(int j=0;j<numOfKeys;j++){
			printf("%d\t",roots[i][j]);
		}
		printf("\n");
	}
	printf("Final obst cost :  %d\n",final[0][numOfKeys-1]);
	printf("Root :  %d\n",roots[0][numOfKeys-1]);
	
	return 0;
}


