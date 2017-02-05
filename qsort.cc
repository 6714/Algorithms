#include <iostream>

using namespace std;

void swap(int& X, int& Y){
	int temp = X;
	X = Y;
	Y = temp;
}

int partition(int* A, int x, int y){
	int P = A[x];
	cout << "P = " << P <<endl;
	int i=x+1;
	for(int j=x+1;j<=y;j++){
		if(A[j]<P){
			swap(A[j], A[i]);
			i++;
		}
	}
	swap(A[x], A[i-1]);
	//for(int k=x;k<=y;k++){
	//	cout << A[k] << " ";
	//}
	//cout << endl;
	return i-1;
}

void qsort(int* A,int q, int r){
	if(q<r){
		int p = q;
		int l = partition(A, p, r);
		qsort(A, p, l-1);
		//for(int k=p;k<=l-1;k++){
		//cout << A[k] << " ";
		//}
		//cout << endl;
		qsort(A, l+1, r);
		for(int k=0;k<=sizeof(A)/sizeof(int);k++){
		cout << A[k] << " ";
		}
		cout << endl;
	}
}

int main(){
	int A[] = {5,8,1,3,7,9,2};
	int n = sizeof(A)/sizeof(int);
	//cout << n <<endl;
	//swap(A[1],A[0]);
	//cout << A[0];
	for(int i=0;i<n;i++){
		cout << A[i] << " ";
	}
	cout << endl;

	qsort(A, 0, n-1);
	for(int i=0;i<n;i++){
		cout << A[i] << " ";
	}
	cout << endl;
}