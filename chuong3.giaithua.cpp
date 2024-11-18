//Giai thuat de quy tinh giai thua
#include <iostream>
#include <math.h>
using namespace std;
//Ham tinh de quy
long Fact(int n){
	if(n == 0) {
		return 1;
	}
	else return n*Fact(n-1);
}
int main(){
	int n;
	cout<<"Nhap n: "; cin>>n;
	if(n<0){
		cout<<"Giai thua khong dung cho so am, moi nhap laii!";
	}else{
		cout<<n<<"! = "<<Fact(n);
	}
	return 0;
}
