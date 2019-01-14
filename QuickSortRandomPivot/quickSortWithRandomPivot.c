#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void exchange(int * val1,int * val2){
	int temp=*val1;
	*val1=*val2;
	*val2=temp;
}

void printArray(int arr[],int length){
	int i;
	for(i=0;i<length;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int partition(int arr[],int startIndex,int endIndex){
	int pivot=arr[startIndex];
	int i=startIndex,j;
	for(j=startIndex+1;j<=endIndex;j++){
		if(arr[j]<=pivot){
			i++;
			exchange(&arr[i],&arr[j]);
		}
	}
	exchange(&arr[i],&arr[startIndex]);
	return (i);
}

int partitionRandom(int arr[],int startIndex,int endIndex){
	int random=rand()%(endIndex-startIndex+1)+startIndex;
	exchange(&arr[random],&arr[startIndex]);
	return partition(arr,startIndex,endIndex);
	
}
	


void quickSort(int arr[],int startIndex,int endIndex){
	if(startIndex<endIndex){
		int partitionIndex = partitionRandom(arr,startIndex,endIndex);
		quickSort(arr,startIndex,partitionIndex-1);
		quickSort(arr,partitionIndex+1,endIndex);
	}
}



	


int main(){
	FILE *fp,*fp1;
	srand(time(NULL));
	int num,i;
	printf("Enter the number of numbers to be sorted\n");
	fp=fopen("data.txt","w");
	scanf("%d",&num);
	for(i=0;i<num;i++){
		fprintf(fp,"%d\n",rand()%5000);
	}
	
	fclose(fp);
	num=5;
	int randomNumber,arr[num],j=0;

	fp1=fopen("data.txt","r");
	while(fscanf(fp1,"%d",&randomNumber)!=EOF){
		arr[j++]=randomNumber;
	}
	fclose(fp1);
	printArray(arr,num);
	printf("%s","--------------\n");
	quickSort(arr,0,num-1);
	printArray(arr,num);
	fp=fopen("data2.txt","w");
	for(i=0;i<num;i++){
		fprintf(fp,"%d\n",arr[i]);
	}
	fclose(fp);
	return 0;
}

