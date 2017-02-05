#include <iostream>
#include <list>

using namespace std;

class Graph{
	int V;
	list<int> *A;
public:
	Graph(int v);
	void addEdge(int s, int d);
	void printGraph();
	friend void BFS(Graph G, int s);
};	

Graph::Graph(int v){
	this->V = v;
	A = new list<int>[V];
}

void Graph::addEdge(int s, int d){
	A[s].push_back(d);
}

void Graph::printGraph(){
	for(int v=0;v<this->V;++v){
		cout << "Adjacency List of vertex " << v << ":\n head";
		for(list<int>::iterator i = (this->A[v].begin());i!=(this->A[v].end());i++){
			cout << " -> " << *i;
		}
		cout << endl;
	}
}

void BFS(Graph G, int s){
	bool* visited = new bool[G.V];
	for(int i=0;i<G.V;i++){
		visited[i] = false;
	}
	int* spath=new int[G.V];
	for(int i=0;i<G.V;i++){
		spath[i]=0;
	}
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	int temp;
	while(!queue.empty()){
		temp = queue.front();
		cout <<  temp << " ";
		queue.pop_front();
		for(list<int>::iterator i = G.A[temp].begin();i != G.A[temp].end();i++){
			if(visited[*i]==false){
				visited[*i]=true;
				spath[*i] = spath[temp]+1;
				queue.push_back(*i);
			}
		}

	}
	cout << endl;
	for(int i=0;i<G.V;i++){
		cout << spath[i] << " ";
	}
	cout << endl;
}

int main(){
	Graph G(4);
	G.addEdge(0,1);
	G.addEdge(0,2);
	G.addEdge(1,2);
	G.addEdge(2,0);
	//G.addEdge(1,4);
	G.addEdge(2,3);
	G.addEdge(3,3);
	G.printGraph();
	BFS(G,0);

}



/*#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
	int dest;
	struct node* next;
};

struct list{
	struct node* head;
};

struct graph{
	int V;
	struct list* G;
};

struct node* newNode(int dest){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

struct graph* createGraph(int V){
	struct graph* Graph = (struct graph*) malloc(sizeof(struct graph));
	Graph->V = V;
	Graph->G = (struct list*) malloc(V * sizeof(struct list));

	int i;
	for(i=0;i<V;i++){
		Graph->G[i].head=NULL;
	}

	return Graph;
}

void addEdge(struct graph* Graph, int src, int dst){
	struct node* Node = newNode(dst);
	Node->next = Graph->G[src].head;
	Graph->G[src].head = Node;

	Node = newNode(src);
	Node->next = Graph->G[dst].head;
	Graph->G[dst].head = Node;
}

void printGraph(struct graph* Graph){
	int v;
	for(v=0;v<Graph->V;++v){
		struct node* N = Graph->G[v].head;
		cout << "Adjacency List of vertex " << v << ":\n head";
		while(N){
			cout << " -> " << N->dest;
			N = N->next;
		}
		cout << endl;
	}
}

int main(){
	int V = 5;
    struct graph* Graph = createGraph(V);
    addEdge(Graph, 0, 1);
    addEdge(Graph, 0, 4);
    addEdge(Graph, 1, 2);
    addEdge(Graph, 1, 3);
    addEdge(Graph, 1, 4);
    addEdge(Graph, 2, 3);
    addEdge(Graph, 3, 4);
 
    // print the adjacency list representation of the above graph
    printGraph(Graph);
 
    return 0;
}*/

