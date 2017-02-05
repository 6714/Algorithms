#include <iostream>

using namespace std;

static int count = 0;

void merge(int A[],int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int X[n1], Y[n2];
	
	for(int i=0;i<n1;i++){
		X[i] = A[p+i];
	} 
	for(int i=0;i<n2;i++){
		Y[i] = A[q+i+1];
	}

	//X[n1] = 10000;
	//Y[n2] = 10000;
	int i=0, j=0;
	for(int k=p;k<=r;k++){
		if(i==n1){
			A[k] = Y[j++];
			continue;
		}
		else if(j==n2){

			A[k] = X[i++];
			continue;
		}
		else if(X[i] < Y[j]){
			A[k] = X[i++];
			//cout << "X[" << i-1 << "]=" << X[i-1] << " ";
			//cout << "Y[" << j << "]=" << Y[j] << " ";
			//cout << "A[" << k << "]=" << A[k] << "\n";
		}
		else if(Y[j] < X[i]){
			A[k] = Y[j++];
			count += (n1-i);
			//cout << "Y[" << j-1 << "]=" << Y[j-1] << " ";
			//cout << "X[" << i << "]=" << X[i] << " ";
			//cout << "A[" << k << "]=" << A[k] << "\n";
			cout << count << endl;
		}

	}
}

void mergesort(int A[], int p, int r){
	int q=0;
	if(r > p){
		q = (p+r)/2;
		mergesort(A,p,q);
		mergesort(A,q+1,r);
		merge(A,p,q,r);
	}
}

int main(){
	int A[] = {5, 4, 1, 8, 7, 2, 6, 3};
	int n = sizeof(A)/4;
	mergesort(A,0,n-1);
	cout << "Sorted Array: ";
	for(int k=0;k<n;k++){
		cout << A[k] << " " ;
	}
	cout << endl;
	cout << count << endl;

}