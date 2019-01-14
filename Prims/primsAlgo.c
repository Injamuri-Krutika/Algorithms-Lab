#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#define MAX_BUFF_SIZE 256
int numberOfVertices;
int sizeOfHeap;

typedef struct AdjacencyNode{
  int edgeWeight;
  int vertex;
  struct AdjacencyNode * next;
}AdjacencyNode;

typedef struct Graph{
  int keyValue;
  AdjacencyNode * head;
}Graph;




typedef struct MinimumSpanningTree{
  int src;
  int dest;
  int weight;
}MinimumSpanningTree;


AdjacencyNode * createAdjacencyNode(int vertex,int distance){
  AdjacencyNode * adjNode=(AdjacencyNode *)malloc(sizeof(AdjacencyNode));
  adjNode->vertex=vertex;
  adjNode->edgeWeight=distance;
  adjNode->next=NULL;
  return adjNode;
}
void addEdge(Graph * graph,int src,int dest,int dist){
  AdjacencyNode * newNode=createAdjacencyNode(dest,dist);
    newNode->next=graph[src].head;
    graph[src].head=newNode;
}

int getMinimumKeyVertex(int * arr,int * mst){
	int min=INT_MAX,minIndex=INT_MAX;
	for(int i=1;i<=numberOfVertices;i++){
		if(min>arr[i] && mst[i]!=1){
			min=arr[i];
			minIndex=i;
		}


	}

return minIndex;
}


void updateKeyVector(int * arr,int edgeWeight,int vertex){
	// printf("edgeWeight :: %d,vertex :: %d\n ",edgeWeight,vertex);
	if(edgeWeight<arr[vertex])
		arr[vertex]=edgeWeight;

}

void prims(Graph * graph,int src){
	int keyVector[numberOfVertices+1],mst[numberOfVertices+1],mstSize=0,prevIndex=src,i=1;
// printf("%d\n",numberOfVertices );
	for(int i=1;i<=numberOfVertices;i++){
		keyVector[i]=INT_MAX;
		mst[i]=0;
		// printf("i:: %d, key :: %d, mst:: %d\n",i,keyVector[i],mst[i]);
    // printf("%d\n",i );

	}
	keyVector[src]=0;
  // printf("keyvector src :: %d,src %d\n",keyVector[src] ,src);
	AdjacencyNode * current;
	MinimumSpanningTree finalMst[numberOfVertices+1];
	while(mstSize!=numberOfVertices){
		// printf("Hi :: %d\n",mstSize);
		int minIndex=getMinimumKeyVertex(keyVector,mst);
		// printf("minIndex ::: %d\n",minIndex);
		if(minIndex!=INT_MAX){
			if(mst[minIndex]!=1){
			mst[minIndex]=1;
			current=graph[minIndex].head;
			while(current!=NULL){

				updateKeyVector(keyVector,current->edgeWeight,current->vertex);
        // printf("inside current!=NULL\n" );

				current=current->next;
			}

			}
		// printf("i :: %d\n",i);
		finalMst[i].src=prevIndex;
		finalMst[i].dest=minIndex;
		if(prevIndex==minIndex)
			finalMst[i].weight=0;
		else
			finalMst[i].weight=keyVector[minIndex];
		i++;
		prevIndex=minIndex;
    mstSize++;
		}


	}

	for(int i=1;i<=numberOfVertices;i++){
		printf("src :: %d, dest:: %d weight :: %d\n",finalMst[i].src,finalMst[i].dest,finalMst[i].weight);

	}





}


int main(int argc, char const *argv[]) {


      FILE * file=fopen("inputFile.txt","r");
    int source;
if(file){
  	char * lineBuffer=(char *)malloc(sizeof(char)*MAX_BUFF_SIZE);

    int count=0;
    bool isValid=true,isValidEdge=false;
    Graph * graph;

  	while(fgets(lineBuffer,MAX_BUFF_SIZE,file)!=NULL)//used to read a line of size MAX_BUFF_SIZE from file

  	{
      // printf("Linebuffer %s\n :: count ::       %d", lineBuffer,count);
      int j=0,s,d,w;
      isValidEdge=false;
      char intCharacter[MAX_BUFF_SIZE]={};
      int charLength=0;
  		for(int i=0;lineBuffer[i-1]!='\n';i++){
  			if(count==0 && lineBuffer[i]!='\n'){
  				numberOfVertices=sizeOfHeap=atoi((char *)&lineBuffer[i]);
          graph=(Graph *)malloc(sizeof(Graph)*(numberOfVertices+1));
          printf("numberOfVertices :: %d\n",numberOfVertices );
          for (int j = 0; j <= numberOfVertices; j++) {
            graph[j].head=NULL;

          }
  			}else if(count==1 && lineBuffer[i]!='\n'){

          source=atoi((char *)&lineBuffer[i]);
          // printf("src :: ------%d\n",source );

        }else{
  				if(lineBuffer[i]!=' ' && lineBuffer[i]!='\n'){
  						intCharacter[charLength++]=lineBuffer[i];
  				}
  				else if(lineBuffer[i]==' ' || lineBuffer[i]=='\n'|| lineBuffer[i]=='\0'){
            intCharacter[charLength]='\n';
            if(j==0){

              s=atoi(intCharacter);
            }

            if(j==1){
              d=atoi(intCharacter);
            }

            if(j==2){
              w=atoi(intCharacter);
              isValidEdge=true;
            }

            j++;
            charLength=0;
  				}else{
  					printf("Worng input format\n");
  					isValid=false;
  					break;
  				}
  			}
  	}

    if(isValid && isValidEdge){
      // printf("Adding edge\n" );
      addEdge(graph,s,d,w);
    }
    count++;
  	}

    // for(int i=1;i<=numberOfVertices;i++){
    // 	AdjacencyNode * p=graph[i].head;
    // 	while(p){
    // 		printf("src %d, dest %d,weight %d\n",i,p->vertex,p->edgeWeight);
    // 		p=p->next;
    //
    // 	}
    // }
    printf("src :: %d\n",source );
    prims(graph,source);

  }else{
    perror("File not found ");
  }


// numberOfVertices=9;
// int source=1;
// Graph graph[numberOfVertices+1];
// for(int i=1;i<=numberOfVertices;i++){
// 	graph[i].head=NULL;
//
// }
//
//  addEdge(graph,1,2,1);
//  addEdge(graph,2,1,1);
//  addEdge(graph,2,3,6);
//  addEdge(graph,3,2,6);
//  addEdge(graph,1,3,6);
//  addEdge(graph,3,1,6);
//  addEdge(graph,1,4,5);
//  addEdge(graph,4,1,5);
//  addEdge(graph,4,6,2);
//  addEdge(graph,6,4,2);
//
//  addEdge(graph,6,3,3);
//  addEdge(graph,3,6,3);
//
//  addEdge(graph,3,6,3);
//  addEdge(graph,3,6,3);
//
//  addEdge(graph,3,5,7);
//  addEdge(graph,5,3,7);
//
//  addEdge(graph,5,8,12);
//  addEdge(graph,8,5,12);
//
//  addEdge(graph,6,8,18);
//  addEdge(graph,8,6,18);
//
//
//  addEdge(graph,7,4,10);
//  addEdge(graph,4,7,10);
//
//
//  addEdge(graph,7,8,7);
//  addEdge(graph,8,7,7);
//
//
//  addEdge(graph,9,7,3);
//  addEdge(graph,7,9,3);
//
//  addEdge(graph,9,8,8);
//  addEdge(graph,8,9,8);
//
//  prims(graph,source);
  return 0;
}
