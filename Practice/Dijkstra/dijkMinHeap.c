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


int decreaseKey(int heap[][2],int idx,int val,int size){
	for (int i = 0; i < size; i++) {
		if(heap[i][1]==idx){
			int parent=(i%2==0)?(i/2)-1:i/2;
			heap[i][0]=val;
			
			while(parent>=0){
				//printf("Child %d parent %d , ",idx,parent);
				if(heap[i][0]<heap[parent][0]){
					int temp1=heap[i][0];
					int temp2=heap[i][1];
					heap[i][0]=heap[parent][0];
					heap[i][1]=heap[parent][1];
					heap[parent][0]=temp1;
					heap[parent][1]=temp2;
					i=parent;
					parent=(i%2==0)?(i/2)-1:i/2;
				}else{
					break;
				}

						
			}
		}
		
	}
}





void minHeap(int heap[][2],int i,int size){

	int min=i;
	int left=2*i+1;
	int right=left+1;
	if(left<size && heap[left][0]<heap[min][0])
		min=left;
	if(right<size && heap[right][0]<heap[min][0])
		min=right;
	if(min!=i){
		int temp1=heap[i][0];
		int temp2=heap[i][1];
		heap[i][0]=heap[min][0];
		heap[i][1]=heap[min][1];
		heap[min][0]=temp1;
		heap[min][1]=temp2;
		minHeap(heap,min,size);
	}
}

int buildMinHeap(int heap[][2],int size){
	for(int i=(size%2==1)?(size/2):((size/2)-1);i>=0;i--){
		minHeap(heap,i,size);
	}


}

int extractMin(int heap[][2],int size,int * minIdx){
	*minIdx=heap[0][1];int min=heap[0][0];
	if(size>0){
		int temp1=heap[0][0];
		int temp2=heap[0][1];
		heap[0][0]=heap[size-1][0];
		heap[0][1]=heap[size-1][1];
		heap[size-1][0]=temp1;
		heap[size-1][1]=temp2;		
	}
	
	buildMinHeap(heap,size-1);
	return min;

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

	int src=7;
	int dist[numOfVertices],visited[numOfVertices],pre[numOfVertices],heap[numOfVertices][2];

	for(int i=0;i<numOfVertices;i++){
		if(i==src)
			dist[i]=0;
		else
			dist[i]=INT_MAX;
		heap[i][0]=INT_MAX;
		heap[i][1]=i;
		visited[i]=0;
		pre[i]=src;
	}

	heap[src][0]=0;
	int heapSize=numOfVertices;
	buildMinHeap(heap,heapSize);
	for(int i=0;i<numOfVertices;i++){
		int minIdx=-1;


		int currSrc=extractMin(heap,heapSize,&minIdx);heapSize--;


		visited[minIdx]=1;
		for(int j=0;j<numOfVertices;j++){
			int val=cost[minIdx][j]+currSrc;
			if(cost[minIdx][j] && val<dist[j] && !visited[j]){
				dist[j]=val;
				pre[j]=minIdx;
				decreaseKey(heap,j,val,heapSize);
			}
		}
		
	}

	for(int i=0;i<numOfVertices;i++)
		printf("%d ",dist[i]);
	printf("\n");
	for(int i=0;i<numOfVertices;i++)
		printf("%d ",pre[i]);
	printf("\n");
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
