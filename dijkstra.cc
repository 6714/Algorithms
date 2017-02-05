#include <iostream>
#include <vector>
#include <utility>

using namespace std;


void addEdge(vector<pair<int, int> > G[], int u, int v, int w){
	G[u].push_back(make_pair(v, w));
}

void printGraph(vector<pair<int, int> > G[], int V){
	int v, w;
	for(int i=0;i<V;i++){
		for(vector<pair<int, int> >::iterator it = G[i].begin();it!=G[i].end();it++){
			v = it->first;
			w = it->second;
			cout << i << " ---> " << v << " = " << w << "\n";
		}
		cout << endl;
	}
}

void dijkstra(vector<pair<int, int> > G[], int V, int s){
	int* A = new int[V];
	int* B = new int[V];
	for(int i=0;i<V;i++){
		A[i] = -1;
		B[i] = -1;
	}

	A[s] = 1;
	int count = 1;
	B[s] = 0;
	int min = 9999;
	int v, w;
	int j=0;
	int i=0;
	int temp1, temp2;
	while(1){
		if(A[j]==1){
			for(vector<pair<int, int> >::iterator k = G[j].begin(); k!=G[j].end();k++){
				v = k->first;
				w = k->second;
				//cout << v << " " << w << "; ";
				if(A[v]==-1){
					if(min > B[j] + w){
						min = B[j] + w;
						temp1 = v;
						//cout << min << endl;
						i++;
					}
				}
			}
			//cout << endl;
		}
		j++;
		//cout << j << endl;
		//cout << v << " " << w << "; ";
		if(j==V){
			B[temp1] = min;
			A[temp1] = 1;
			min = 9999;
			count++;
			j=0;
		}
		if(count==V) break;
	}

	for(int i=0;i<V;i++){
		cout << "B[" << i << "]= " << B[i] << " "; 
	}
	cout << endl;
	cout << i <<endl;
}

int main(){

	int V = 4;

	vector<pair<int, int> > G[V];

	addEdge(G,0,1,1);
	addEdge(G,0,2,4);
	addEdge(G,1,2,2);
	addEdge(G,1,3,6);
	addEdge(G,2,3,3);

	printGraph(G,V);
	dijkstra(G,V,0);

}