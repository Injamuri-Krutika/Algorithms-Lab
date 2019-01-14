#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<float.h>
int main(){
char nodes[]={'a','b','c','d'};
float prob[]={0.1,0.2,0.4,0.3};
int numOfNodes=3;
float m[numOfNodes][numOfNodes];

for(int i=0;i<numOfNodes;i++){
	memset(m[i],0,sizeof(m[i]));
}

for(int l=1;l<=numOfNodes;l++){
	for(int i=0;i+l<=numOfNodes;i++){
		int j=i+l-1;
		if(i==j)
			m[i][j]	=prob[i];
		else{
			float min=FLT_MAX-1;
			float sum=0,left=0,right=0;
			for(int k=i ;k<=j;k++){
				sum+=prob[k];
				left=((k-1)>=0 )?m[i][k-1]:0;
				right=(k+1<numOfNodes)?m[k+1][j]:0;
				if(left+right<min &&  (left+right)>0)
					min=left+right;
			}
			printf("%f sum, %f val\n",sum,min);
			m[i][j]=sum+min;
		}
		
	}
}


for(int l=0;l<numOfNodes;l++){
	for(int i=0;i<numOfNodes;i++){
		
		printf("%f ",m[l][i]);
	}
	printf("\n");
}

return 0;
}
