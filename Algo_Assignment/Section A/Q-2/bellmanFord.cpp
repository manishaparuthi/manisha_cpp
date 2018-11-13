#include <iostream>
using namespace std;
#define INF 99999


struct Edge 
{
	int src;	//source
	int dest;	//destination
	int weight;	//weight
};

struct Graph 
{
	int V;	
	int E;	
	struct Edge *edge;	//array of edges
};

void bellmanFord(struct Graph *g, int source);
void display(int arr[], int size);


void bellmanFord(struct Graph *g, int source) 
{
	int vertices = g->V;
	int edges = g->E;



	int i, j, u, v, w;
	
	int dist[vertices];//for storing distance 
	int pred[vertices];// for storing predecessor
	
	for (i = 0; i < vertices; i++) 
        {
		dist[i] = INF;   //initialisation
		pred[i] = -1;
	}
	
	
	dist[source] = 0;
	
	
	for(i = 1; i <= vertices-1; i++) 	//loop for V-1 times
        {
		for(j = 0; j < edges; j++) 
                {
			
			u = g->edge[j].src;		//update 
			v = g->edge[j].dest;
			w = g->edge[j].weight;
			
			if(dist[u] != INF && dist[v] > dist[u] + w) 
                        {
				dist[v] = dist[u] + w;
				pred[v] = u;
			}
		}
	}
	
	// detect negative cycle,if value changes then we have a negative cycle in the graph
	
	for(i = 0; i < edges; i++) {
		u = g->edge[i].src;
		v = g->edge[i].dest;
		w = g->edge[i].weight;
		if(dist[u] != INF && dist[v] > dist[u] + w) 
                 {
			cout<<"Negative weight cycle detected!\n";
			return;
		}
	}
	
	cout<<"Distance array: ";
	display(dist,vertices);
	cout<<"\nPredecessor array: ";
	display(pred, vertices);
}

void display(int arr[], int size) 
{
	
	for(int i = 0; i < size; i ++) 
  {
		cout<< arr[i];
	}
	cout<<"\n";
}
int main() 
{

        Graph *g=new Graph;
        cout<<"Enter no of vertices: ";
        int v;
        cin >> v;
        cout<<"Enter no of Edges: ";
        int e;
        cin >> e;
	g->V = v;	//total vertices
	g->E = e;	//total edges
	
	//array of edges for graph
	g->edge = new Edge[e];
	int s,d,w;
	
       for(int i=0;i< e;i++)
       { 
	  cout<<"\n\n------Edge "<<i+1<<"----------";
          cout<<"\nEnter Source vertex: ";
          cin>>s;
          cout<<"\nEnter Destination Vertex: ";
          cin>>d;
          cout<<"\nEnter Weight of the edge: ";
          cin>>w;
	  g->edge[i].src = s;
	  g->edge[i].dest = d;
	  g->edge[i].weight = w;
       }	
	cout<<"\nEnter Source Node : ";
        int sr;
        cin >> sr;
	bellmanFord(g, sr);		
	
	return 0;
}

