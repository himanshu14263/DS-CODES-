// PROBLEM :: FINDING THE MINIMUM AND THE MAXIMUM IN ARRAY WITH MINIMUM NUMBER OF COMPARISON

// REQUIRED TC :: O(log n)

// refer note book for explanation

#include<bits/stdc++.h>
using namespace std;

struct pairMM
{
	int min;
	int max;
};

typedef struct pairMM pairMM;



// TOURNAMENT METHOD :: NO. OF COMPARISONS ARE :: (3N/2)-2
pairMM func(int arr[],int l,int h)
{
	pairMM minMax,mml,mmr;

	if(l==h)
	{
		minMax.min=arr[l];
		minMax.max=arr[l];
		return minMax;
	}

	if((l+1)==h)
	{
		if(arr[l]<arr[h])
		{
			minMax.min=arr[l];
			minMax.max=arr[h];
		}
		else
		{
			minMax.min=arr[h];
			minMax.max=arr[l];
		}
		return minMax;
	}

	int md=(l+h)/2;

	mml=func(arr,l,md);
	mmr=func(arr,md+1,h);

	if(mml.min<mmr.min)
		minMax.min=mml.min;
	else
		minMax.min=mmr.min;

	if(mml.max>mmr.max)
		minMax.max=mml.max;
	else
		minMax.max=mmr.max;

	return minMax;
}
int main()
{
	int arr[]={1,1,1,3,3,3,4,5,5,5,5,5,5,5,5};
	int n=sizeof(arr)/sizeof(arr[0]);

	pairMM p=func(arr,0,n-1);

	cout<<p.min<<" "<<p.max;

}

