#include <iostream>
#include <cmath>

using namespace std;

int nd(long int n){
	int i=0;
	while(n>0){
		n = n/10;
		i++;
	}

	return i;

}

long int multiply(long int x, long int y){
	int n = nd(x);
	int m = nd(y);
	long int tempn = 0, tempm = 0;
	long int a = 0, b = 0, c = 0, d = 0;
	//cout << n << " " << m << endl;
	if(x==0||y==0) return 0;
	if(n==1 && m==1) return x*y;
	if(n%2==0 && m%2==0){
		tempn = pow(10, n/2);
		tempm = pow(10, m/2); 
	}
	else if(n%2==0 && m%2==1){
		tempn = pow(10, n/2); 
		tempm = pow(10, (m+1)/2);
	}
	else if(n%2==1 && m%2==1){
		tempn = pow(10, (n+1)/2); 
		tempm = pow(10, (m+1)/2); 
	}
	else if(n%2==1 && m%2==0){
		tempn = pow(10, (n+1)/2); 
		tempm = pow(10, m/2);
	}

		a = x/tempn; 
		b = x%tempn;
		c = y/tempm; 
		d = y%tempm;
		//cout << a << " " << b << " " << c << " " << d <<endl;
		long int ac = multiply(a,c);
		long int bd = multiply(b,d);
		if(tempm==tempn) return ((tempn * tempm)*multiply(a,c))+ ((tempn)*(multiply(a+b, c+d)-ac-bd )) + multiply(b, d);
		else return ((tempn * tempm)*multiply(a,c)) + ((tempn)*multiply(a, d) + (tempm)*multiply(b,c)) + multiply(b,d);



	/*int temp = 0;
	if(n==1) return x*y;
	if(n%2==0) temp = pow(10, n/2);
	temp = pow(10, n/2);
	int a = x/temp, b = x%temp;
	int c = y/temp, d = y%temp;
	if(n%2==0) return pow(10, n)*multiply(a,c) + pow(10, n/2)*(multiply(a, d) + multiply(b, c)) + multiply(b, d);*/
}

int main(){

	long int a, b;
	cin >> a >> b;

	cout << a*b << endl;
	cout << multiply(a, b) << endl;


}