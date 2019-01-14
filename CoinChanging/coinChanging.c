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
	int numOfDenom=0,sumAmount=0;
	fscanf(fp,"%d",&sumAmount);
	fscanf(fp,"%d",&numOfDenom);
	int coins[numOfDenom],arr1[sumAmount+1],arr2[sumAmount+1],solns[sumAmount+1];
	for(int i=0;i<numOfDenom;i++){
		fscanf(fp,"%d",&coins[i]);
	}
	for(int i=0;i<=sumAmount;i++){
		arr1[i]=(i==0)?0:INFINITE;
		arr2[i]=-1;
		solns[i]=0;
	}
	
	printArr(arr1,(sumAmount+1));
	printArr(arr2,(sumAmount+1));
	for(int j=0;j<numOfDenom;j++){
		for(int i=0;i<=sumAmount;i++){
			if(coins[j]>i)
				continue;
			else{
				int prevVal=arr1[i];
				arr1[i]=min(arr1[i],(1+arr1[i-coins[j]]));
				
				if(arr1[i]!=prevVal){
					arr2[i]=j;
					solns[i]+=1;
				}

			}

		}
		
	}
	printArr(arr1,(sumAmount+1));
	printArr(arr2,(sumAmount+1));
	printArr(solns,(sumAmount+1));
	int numOfConisUsed=arr1[sumAmount];
	printf("Number of coins used : %d\n",numOfConisUsed);
	printCoinstUsed(arr1,arr2,coins,sumAmount);
	return 0;
}


