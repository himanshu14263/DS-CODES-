#include <bits/stdc++.h>
using namespace std;
void QS(int a[],int x,int y)
{
	if(x<y)
	{
		int i=x;
		int j=y;
		int temp;
		int key=a[x];
		while(i<j)
		{
			while(key>=a[i] && i<y)
				i++;
			while(key<a[j] && j>x)
				j--;
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[x];
		a[x]=a[j];
		a[j]=temp;
		QS(a,x,j-1);
		QS(a,j+1,y);
	}
}
int main()
{
	int a[5];
	cout<<"enter the data in array\n";
	for(int i=0;i<5;i++)
		cin>>a[i];
	QS(a,0,4);
	for(int i=0;i<5;i++)
		cout<<a[i]<<" ";
}