#include <iostream>

using namespace std;

void swap(int& x, int& y){
	int temp=x;
	x=y;
	y=temp;
}

int partition(int* A, int l, int h){
	int P = A[l];
	int i = l+1;
	for(int j=l+1;j<=h;j++){
		if(A[j]<P){
			swap(A[i],A[j]);
			i++;
		}
	}
	swap(A[l],A[i-1]);
	return i-1;
}

int RSelect(int* A, int l, int h, int i){
	if(l==h) return A[l];
	int p = partition(A, l, h);
	if(p==i) return A[p];
	else if(p>i) return RSelect(A, l, p-1, i);
	else return RSelect(A, p+1, h, i);

}

int main(){
	int A[] = {2, 5, 1, 8, 3, 9, 6};
	int n=sizeof(A)/sizeof(int);
	int x;
	cout << "Enter the order of statistics to be selected: ";
	cin >> x;
	cout << x << "th smallest element in the given array: " << RSelect(A, 0, n-1, x-1) << endl;

}