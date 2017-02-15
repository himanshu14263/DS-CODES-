#include <bits/stdc++.h>
using namespace std;
void possibleCombo(int arr[],int ans[],int n,int i,int indx,int k)
{
	if(indx==k)
	{
		for(int i=0;i<k;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}

	if(i>=n)
	{
		return;
	}

	ans[indx]=arr[i];

	possibleCombo(arr,ans,n,i+1,indx+1,k);
	possibleCombo(arr,ans,n,i+1,indx,k);
}
int main()
{
	int arr[]={1,2,3,4,5,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k;
	cout<<"enter the value of k\n";
	cin>>k;
	int ans[n];
	possibleCombo(arr,ans,n,0,0,k);
}
