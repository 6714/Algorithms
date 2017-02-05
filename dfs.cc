#include <iostream>
#include <list>

using namespace std;

class Graph{
	int V;
	list<int> *A;
public:
	Graph(int v);
	int vertex();
	void addEdge(int s, int d);
	friend void dfs(Graph G, int s);
};

Graph::Graph(int v){
	this->V = v;
	A = new list<int>[v];
}

int Graph::vertex(){
	return V;
}

void Graph::addEdge(int s, int d){
	A[s].push_back(d);
	A[d].push_back(s);
}

void dfs(Graph G, int s){
	bool* visited = new bool[G.vertex()];
	for(int i=0;i<G.vertex();i++){
		visited[i] = false;
	}

	list<int> stack;
	visited[s] = true;
	stack.push_front(s);

	int temp;
	while(!stack.empty()){
		temp = stack.front();
		cout << temp << " ";
		stack.pop_front();
		for(list<int>::iterator i = G.A[temp].begin(); i != G.A[temp].end();i++){
			if(visited[*i]==false){
				visited[*i] = true;
				stack.push_front(*i);
			}
		}
	}
	cout << endl;
}


int main(){

	Graph G(6);
	G.addEdge(0,1);
	G.addEdge(0,2);
	G.addEdge(1,2);
	G.addEdge(1,3);
	G.addEdge(2,4);
	G.addEdge(3,4);
	G.addEdge(3,5);
	G.addEdge(4,5);

	dfs(G, 3);

}
