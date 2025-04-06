#include<iostream>

using namespace std;
int main()
{	
    int n;
    cout<<"enter the number of elements:";
    cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cout<<"enter a no: ";
		cin>>a[i];
    }
    cout<<"\nyou entered:\n";
	for(int i=0;i<n;i++)
	{
	    cout<<a[i]<<endl;
    }
	return 0;
}
