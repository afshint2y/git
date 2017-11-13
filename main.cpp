#include <iostream>
using namespace std;
int c=1;
int fact(int n ,int i=1)
{
	c*=i;
	if(i==n)
		return c;
	
	return (n,i+1);
}
int main ()
{
//get n
	int n;
	cin>>n;
	cout<<fact(n);
	return 0;
}
