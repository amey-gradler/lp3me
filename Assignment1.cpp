#include <iostream>
using namespace std;

int recurfib(int n)
{
	if (n <= 1)
	{
	    return n;
	}
	return recurfib(n - 1) + recurfib(n - 2);
}

int nonrecurfib(int k)
{
    int f[k + 2];
    int i;
    f[0] = 0;
    f[1] = 1;
 
    for(i = 2; i <= k; i++)
    {
       f[i] = f[i - 1] + f[i - 2];
    }
    return f[k];
}

int main()
{
    int n;
    cin>>n;
    cout<<"Recursive :"<<recurfib(n);
    cout<<"\n";
	cout<<"Non Recursive :"<<nonrecurfib(n);
	return 0;
}