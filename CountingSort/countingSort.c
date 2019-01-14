#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray(int arr[],int length){
	int i;
	for(i=0;i<length;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(){
FILE *fp,*fp1;
	srand(time(NULL));
	int num,i;
	printf("Enter the number of numbers to be sorted\n");
	fp=fopen("data.txt","w");
	scanf("%d",&num);
	for(i=0;i<num;i++){
		fprintf(fp,"%d\n",rand()%500-250);
	}
	
	fclose(fp);
	int randomNumber,arr[num],j=0;

	fp1=fopen("data.txt","r");
	while(fscanf(fp1,"%d",&randomNumber)!=EOF){
		arr[j++]=randomNumber;
	}
	fclose(fp1);
	printArray(arr,num);
	printf("%s","--------------\n");
	countSort(arr);
	printArray(arr,num);
	fp=fopen("data2.txt","w");
	for(i=0;i<num;i++){
		fprintf(fp,"%d\n",arr[i]);
	}
	fclose(fp);
	return 0;
}
