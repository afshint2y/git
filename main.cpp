#include <iostream>
using namespace std;
int c=1;
int fact(int n , int i=1)
{
	if(i==n)
		return c;
	c*=i;
	return fact(n,i++);
}
int main ()
{
	int n;
	cin>>n;
	cout<<fact(n);
	return 0;
}
