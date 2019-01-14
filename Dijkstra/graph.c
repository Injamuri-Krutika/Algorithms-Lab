#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

typedef struct AdjNode{
	  int destination;
	  int weight;
	  struct AdjNode * next;
}AdjNode;

typedef struct Array{

	  AdjNode * head;
}Array;

typedef struct MinHeapNode{
	  int vertexIndex;
	  int weight;
}MinHeapNode;

typedef struct MinHeap{
	MinHeapNode * head;
	int size;
	int capacity;
}MinHeap;


void swap(MinHeapNode *  val1,MinHeapNode * val2){
	MinHeapNode temp=*val1;
	*val1=*val2;
	*val2=temp;
}

MinHeap * createMinHeap(int capacity){
	MinHeapNode array[capacity];
	MinHeap * minHeap=(MinHeap*)malloc(sizeof(MinHeap));
	minHeap->capacity=capacity;
	minHeap->size=capacity;
	minHeap->head=array;
	return minHeap;
}





void minify(MinHeapNode * array,int rootIndex,int size){
	int minIndex=rootIndex;
	int left=2*rootIndex+1;
	int right=2*rootIndex+2;
	
	if(left<size && array[rootIndex].weight>array[left].weight)
		minIndex=left;
	if(right<size && array[rootIndex].weight>array[right].weight)
		minIndex=right;

	if(minIndex!=rootIndex){
		swap(&array[rootIndex],&array[minIndex]);
		minify(array,minIndex,size);
	}
		
}


void buildMinHeap(MinHeapNode * array,int size){
	for(int i=size/2-1;i>=0;i++){
		minify(array,i,size);
	}
	
}

void decreaseKey(MinHeapNode * array,int index){
		printf("index :: %d ,\n",index);
	/*int parent = (index-1)/2;
	if(parent>=0)
		if(array[parent].weight>array[index].weight){
			swap(&array[parent],&array[index]);
			decreaseKey(array,parent);
		}*/
}



MinHeapNode * extractMin(MinHeap * minHeap){
	MinHeapNode * array =minHeap->head;
	int size=minHeap->size;
for(int i=0;i<5;i++)
		printf("vertex :: %d , weight :: %d\n",(minHeap->head)[i].vertexIndex,(minHeap->head)[i].weight);
	MinHeapNode * min=array;
	
	swap(array,&array[size-2]);
	--minHeap->size;
	minify(array,0,size);
printf("vertex :: %d , weight :: %d. size :: %d\n",min->vertexIndex,min->weight,minHeap->size);
	return min;
}



struct AdjNode * createAdjacentNode(int destination,int weight){
  printf("Inside Create Adjacent Node\n" );
   AdjNode * newNode=( AdjNode *)malloc(sizeof(AdjNode));
  newNode->destination=destination;
  newNode->weight=weight;
  newNode->next=NULL;
  return newNode;
}

void insertAtBegining(Array * array,int source,int destination,int weight){
  AdjNode * newNode=createAdjacentNode(destination,weight);
 newNode->next=array[source].head;
 array[source].head=newNode;
}

bool isEmpty(MinHeap * minHeap){
	if(minHeap->size==0)
		return true;
	return false;
}


void dijkstra(Array * graph, int source,int numberOfVertices){
	
	MinHeap * minHeap=createMinHeap(numberOfVertices);
	MinHeapNode * distance=minHeap->head;
	for(int i=0;i<numberOfVertices;i++){
		distance[i].vertexIndex=i;
		if(i==source){
			
			distance[i].weight=0;
		}
			
		else
			distance[i].weight=INT_MAX;
	}
	for(int i=0;i<5;i++)
		printf("vertex :: %d , weight :: %d\n",(minHeap->head)[i].vertexIndex,(minHeap->head)[i].weight);
	
	
	MinHeapNode * minNode=extractMin(minHeap);
	printf("minNode->vertexIndex :: %d\n",minNode->vertexIndex);

	/*while(!isEmpty(minHeap)){
		MinHeapNode * minNode=extractMin(minHeap);
		printf("minNode->vertexIndex :: %d\n",minNode->vertexIndex);
		AdjNode * graphArrayPointer=graph[minNode->vertexIndex].head;
		while(graphArrayPointer){
			printf("graphArrayPointer->destination :: %d",graphArrayPointer->destination);
			if(distance[graphArrayPointer->destination].weight>graphArrayPointer->weight){
				distance[graphArrayPointer->destination].weight=graphArrayPointer->weight;
				//decreaseKey(distance,graphArrayPointer->destination);
			}
			graphArrayPointer=graphArrayPointer->next;
			
		}
	
	}
	for(int i=0;i<numberOfVertices;i++)
		printf("vertex :: %d , weight :: %d",distance[i].vertexIndex,distance[i].weight);*/
	
	
}





int main(int argc, char const *argv[]) {
  int numberOfVertices=6;
  Array array[numberOfVertices];
  for(int i=0;i<numberOfVertices;i++)
    array[i].head=NULL;

  insertAtBegining(array,0,1,4);
  insertAtBegining(array,0,2,5);
  insertAtBegining(array,0,3,6);
  insertAtBegining(array,1,2,2);
  insertAtBegining(array,2,1,3);
  insertAtBegining(array,2,4,1);
 insertAtBegining(array,2,1,8);
  insertAtBegining(array,3,3,5);
  insertAtBegining(array,4,1,1);
dijkstra(array, 0, numberOfVertices);

//printf("End\n");
  for(int i=0;array[i].head;i++){
    AdjNode *p=array[i].head;
    while(p){
      printf("src :: %d , destination :: %d , weight :: %d, next :: %lu\n",i,p->destination,p->weight,p->next);
      p=p->next;
    }
  }


  return 0;
}
