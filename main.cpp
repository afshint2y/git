#include <iostream>
using namespace std;
int fact(int n)
{
	int c=1;
	for(int i=1 ;i<=n; i ++)
	{
		c*=i;
	}
	return c;
}
int main ()
{
	int n;
	cin>>n;
	cout<<fact(c);
	return 0;
}
