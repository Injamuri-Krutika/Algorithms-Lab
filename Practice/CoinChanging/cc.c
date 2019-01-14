#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void print(int n1,int n2,int mat[n1+1][n2+1]){
	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}

}

int min(int a,int b){
	printf("a %d , b %d\n",a,b);
	return a<b?a:b;
}

int main(){

int denom[]={1,6,10};
int value=18;
int size=3;
int minSol[size][value+1];
int sol[size+1][value+1];
int tf[size+1][value+1];


for(int i=0;i<=size;i++){
	for(int j=0;j<=value;j++){
		if(i==0)
			sol[i][j]=0;
		if(j==0){
			printf("i %d , j %d\n",i,j);
			sol[i][j]=1;
			
		}else if(i!=0 && j!=0){
			sol[i][j]=0;
			
		}
		minSol[i][j]=0;
		tf[i][j]=0;
	}
}

for(int i=1;i<=size;i++){
	for(int j=1;j<=value;j++){
		
		sol[i][j]=(denom[i-1]>j)?sol[i-1][j]:sol[i-1][j]+sol[i][j-denom[i-1]];
				

		minSol[i][j]=(denom[i-1]>j)?minSol[i-1][j]:(1+minSol[i-1][j-denom[i-1]]);
		
		if((denom[i-1]<j)){
			tf[i][j]=1;
			
		}

	}
}

printf("Possible SOlutions Matrix:\n");
print(size,value,sol);

printf("Minimum SOlution Matrix:\n");
print(size,value,minSol);


printf("True False Matrix:\n");
print(size,value,tf);

int tempVal=value,k=size;
printf("Denominations used:\n");
while(tempVal>0){
	printf("k %d, tempVal %d, minSol[k][tempVal] %d\n",k,tempVal,minSol[k][tempVal]);
	//sleep(1);
	
	//if(tf[k][tempVal]){
		if(minSol[k][tempVal]!=0){
			k--;
			printf("%d ",denom[k]);
			tempVal-=denom[k];
			
		}
	/*}else{
		k--;
		
	}*/	printf("k %d, tempVal %d, minSol[k][tempVal] \n",k,tempVal);
	break;

}printf("\n");





printf("Total possible solutions is %d and the beat solution uses %d coins\n",sol[size][value],minSol[size][value]);
return 0;
}
