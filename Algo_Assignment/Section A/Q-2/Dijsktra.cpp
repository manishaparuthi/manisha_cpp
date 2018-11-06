
#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 
  

typedef pair<int, int> Pair; 
 
class Graph 
{ 
    int V;    // No. of vertices 
    list< Pair > *adj; // array of edges

  
public: 
    Graph(int V);  
    void addEdge(int u, int v, int w); 
    void dijkstra_shortest_path(int s); 
}; 
  

Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<Pair> [V]; 
} 
  
void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 
  

void Graph::dijkstra_shortest_path(int src) 
{ 
    
    priority_queue< Pair, vector <Pair> , greater<Pair> > pq; 
  
    vector<int> dist(V, INF); 
  
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!pq.empty()) 
    { 
       
        int u = pq.top().second; 
        pq.pop(); 
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            
            int v = (*i).first; 
            int weight = (*i).second; 
  
          
            if (dist[v] > dist[u] + weight) 
            { 
                
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
   
   cout<<"Vertex   Distance from Source\n"; 
    for (int i = 0; i < V; ++i) 
    {   cout<<"   "<<i<<"       "<<dist[i]<<"  "; 
    cout<<"\n";
}
} 
  
 
int main() 
{ 
  
    cout<<"Enter No of Vertices:";
    int V;
    cin>>V;
    cout<<"\nEnter no of Edges:";
    int E;
    cin>>E;
    Graph g(V);
     int src, dest, wht;
     for (int i=0; i<E; i++) {

		cout<<"\n-----------------Edge "<<i+1<<"--------------------";
                cout << "\nEnter Source Vertex: ";
		cin >> src;
		
	       cout << "\nEnter Destination Vertex: ";
		cin >> dest;

		cout << "\nEnter Weight: ";
		cin >> wht;
                g.addEdge(src, dest, wht); 

		
	}
    cout<<"\n\nEnter vertex from which you want shortest path: ";
    int s;
    cin>>s;
    g.dijkstra_shortest_path(s); 
  
    return 0; 
} 
