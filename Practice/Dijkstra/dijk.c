#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


int getMinIndex(int dist[],int visited[],int n){
	int minIndex=-1,min=INT_MAX;
	for(int i=0;i<n;i++){
		if(dist[i]<min && !visited[i]){
			min=dist[i];
			minIndex=i;
		}
	}
	return minIndex;
}

int main(){
int numOfVertices=8;
char vertices[]={'S','A','B','C','D','E','F','G'};
int cost[8][8]={	{0,1,0,0,4,0,0,10},
		{1,0,2,0,0,0,0,0},
		{0,2,0,3,0,0,0,0},
		{0,0,3,0,6,0,8,0},
		{4,0,0,6,0,0,0,5},
		{0,0,0,0,0,0,7,9},
		{0,0,0,8,0,7,0,0},
		{10,0,0,0,5,9,0,0}};

int src=0;
int dist[numOfVertices],visited[numOfVertices],pre[numOfVertices];

for(int i=0;i<numOfVertices;i++){
	if(i==src)
		dist[i]=0;
	else
		dist[i]=INT_MAX;
	visited[i]=0;
	pre[i]=src;
}


for(int i=0;i<numOfVertices;i++){
	int currSrc=getMinIndex(dist,visited,numOfVertices);
	visited[currSrc]=1;
	for(int j=0;j<numOfVertices;j++){
		if(cost[currSrc][j] && cost[currSrc][j]+dist[currSrc]<dist[j]){
			dist[j]=cost[currSrc][j]+dist[currSrc];
			pre[j]=currSrc;
		}
	}
}

for(int i=0;i<numOfVertices;i++)
	printf("%d ",dist[i]);
printf("\n");
for(int i=0;i<numOfVertices;i++)
	printf("%d ",pre[i]);



for(int i=0;i<numOfVertices;i++){

	printf("Distance : %d , Path : %c",dist[i],vertices[i]);
	int j=i;
	
	do{
		printf(" <- %c",vertices[pre[j]]);
		j=pre[j];
	}while(j!=src);
	printf("\n");

}


return 0;
}
