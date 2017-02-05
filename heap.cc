#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int PARENT(int i){
	return (i-1)/2;
}

int LEFT(int i){
	return 2*i+1;
}

int RIGHT(int i){
	return 2*(i+1);
}

void swap(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}

void Heapify(int* A, int n, int i){

	int l = LEFT(i);
	int r = RIGHT(i);
	//cout << l << " " << r << endl;
	int min = i;
	//cout << n << " ";
	if(l<n && A[min]>A[l]){
		min = l;
	}

	if(r<n && A[min]>A[r]){
		min = r;
	}

	if(min!=i){
		swap(A[min],A[i]);
		Heapify(A,n,min);
	}
	
}

void Build_Heap(int* A, int n){
	for(int i=n/2-1;i>=0;i--){
		Heapify(A,n,i);
	}
}

int Heap_Min(int* A){
	return A[0];
}

void Extract_Min(int* A, int& n){
	if(n<1){
		cout << "Error: Underflow";
	}
	else{
		int min = A[0];
		A[0] = A[n-1];
		n = n-1;
		Heapify(A, n, 0);
	}
}

void Update(int* A, int n, int i, int key){
	if(key < A[i]){
		A[i] = key;
		while(i>1 && A[PARENT(i)]>A[i]){
			swap(A[i],A[PARENT(i)]);
			i = PARENT(i);
		}
	}
}

void Insert(int* A, int& n, int x){
	n = n+1;
	A[n-1] = 9999;
	Update(A,n,n-1,x);
}

int main(){
	int n;
	cout << "Enter the size of array: ";
	cin >> n;
	int A[n];
	srand(time(NULL));
	for(int i=0;i<n;i++){
		A[i] = rand()%100+1;
	}

	for(int i=0;i<n;i++){
		cout <<  A[i] << " ";
	}
	cout << endl;

	Build_Heap(A,n);

	for(int i=0;i<n;i++){
		cout <<  A[i] << " ";
	}
	cout << endl;

	Extract_Min(A,n);

	for(int i=0;i<n;i++){
		cout <<  A[i] << " ";
	}
	cout << endl;

	cout << "Enter a no. to insert into heap: ";
	int x;
	cin >> x;
	Insert(A,n,x);

	for(int i=0;i<n;i++){
		cout <<  A[i] << " ";
	}
	cout << endl;

}

//"A[" << i << "] = " <<