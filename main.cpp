#include <iostream>
using namespace std;
int main ()
{
	int n,c=1;
	cin>>n;
	for(int i=1 ;i<=n; i ++)
	{
		c*=i;
	}
	cout<<c;
	return 0;
}
