#include <iostream> 
#include <list> 
using namespace std; 
  
//undirected graph 
class Graph 
{ 
    int V;    // vertexlerin sayi
    list<int> *adj;    // A dynamic array of adjacency lists 
public: 
    // Constructor and destructor 
    Graph(int V)   { this->V = V; adj = new list<int>[V]; } 
    ~Graph()       { delete [] adj; } 
  
    // function to add an edge to graph 
    void ADDedge(int v, int w); 
  
    // Prints coloring
    void COLORING(); 
}; 
  
void Graph::ADDedge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 
  
 
void Graph::COLORING() 
{ 
    int result[V]; 
  
    //  the first color to first vertex 
    result[0]  = 0; 
  
    // Initialize V-1 vertices as unassigned 
    for (int u = 1; u < V; u++) 
        result[u] = -1;  // -1 renglenmeyeni gosterir
  
    // qonshular renglenende True olur
    bool AvailableRengler[V]; 
    for (int cr = 0; cr < V; cr++) 
        AvailableRengler[cr] = false; 
  

    for (int u = 1; u < V; u++) 
    { 
        // qonshulari unavilable edir
        list<int>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (result[*i] != -1) 
                AvailableRengler[result[*i]] = true; 
  
        // Finding the first AvailableRengler color 
        int cr; 
        for (cr = 0; cr < V; cr++) 
            if (AvailableRengler[cr] == false) 
                break; 
  
        result[u] = cr; // tapilan assign olunur
  
        // Готовимся для следующей итерации
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (result[*i] != -1) 
                AvailableRengler[result[*i]] = false; 
    } 
  
    //Результаты печатаем
    for (int u = 0; u < V; u++) 
        cout << "Vertex " << u << " --->  Color "
             << result[u] << endl; 
} 
  

int main() 
{ 
 
  
    Graph exampleGraph1(5); 
    exampleGraph1.ADDedge(0, 1); 
    exampleGraph1.ADDedge(0, 2); 
    exampleGraph1.ADDedge(1, 2); 
    exampleGraph1.ADDedge(1, 3); 
    exampleGraph1.ADDedge(3, 4); 
    exampleGraph1.ADDedge(4, 2); 
    cout << "\nColoring of the graph  \n"; 
    exampleGraph1.COLORING(); 
  
    return 0; 
} 
