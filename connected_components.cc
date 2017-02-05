#include <iostream>
#include <list>

using namespace std;


class Graph{
	int V;
	list<int> *A;
public:
	Graph(int v);
	void addEdge(int s, int d);
	int vertex() { return V;}
	friend void BFS(Graph G, int s, bool* X);
};

Graph::Graph(int v){
	this->V = v;
	A = new list<int>[V]; 
}

void Graph::addEdge(int s, int d){
	A[s].push_back(d);
	A[d].push_back(s);
}

void BFS(Graph G, int s, bool* X){
	list<int> queue;
	X[s] = true;
	queue.push_back(s);
	int temp;
	while(!queue.empty()){
		temp = queue.front();
		queue.pop_front();
		for(list<int>::iterator i = G.A[temp].begin();i != G.A[temp].end();i++){
			if(X[*i]==false){
				X[*i] = true;
				queue.push_back(*i);

			}
		}
	}

}



int main(){

	Graph G(10);
	G.addEdge(0,4);
	G.addEdge(0,2);
	G.addEdge(2,4);
	G.addEdge(3,5);
	G.addEdge(6,8);
	G.addEdge(1,3);
	G.addEdge(5,7);
	G.addEdge(5,9);
	G.addEdge(7,9);

	bool* visited = new bool[G.vertex()];
	for(int i=0;i<G.vertex();i++){
		visited[i] = false;
	}

	int count = 0;

	for(int i=0;i<G.vertex();i++){
		if(visited[i]==false){
			BFS(G,i,visited);
			count++;
		}
	}

	cout << count << endl;
}
