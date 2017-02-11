// PROBLEM :: SORT ELEMENTS BY THEIR FREQUENCY

// SOLUTION USING STL(C++)

#include <bits/stdc++.h>
using namespace std;


struct pack
{
	int val;
	int freq;
};


bool myComp(pair<int,int>a,pair<int,int>b)
{
	return a.second>b.second;
}

void printFreq(int arr[],int n)
{
	map<int,int>mp;
	for(int i=0;i<n;i++)
	{
		if(mp[arr[i]]==0)
			mp[arr[i]]=1;
		else
			mp[arr[i]]++;
	}

	vector<pair<int,int> >v;

	map<int ,int >::iterator it;
	for(it=mp.begin();it!=mp.end();++it)
		v.push_back(make_pair((*it).first,(*it).second));

	sort(v.begin(),v.end(),myComp);

	vector<pair<int,int > >::iterator it2;

	for(it2=v.begin();it2!=v.end();++it2)
	{
		while((*it2).second>0)
		{
			cout<<(*it2).first<<" ";
			((*it2).second)--;
		}
	}
}

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}
int main()
{
    int arr[] = {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12};
    int n = sizeof(arr)/sizeof(arr[0]);

    display(arr,n);
    cout<<"\nthe elements after the frequency is sorting is :: \n\n";
    printFreq(arr,n);

}
