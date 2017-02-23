// FIND COMMON ELEMENTS IN THREE SORTED ARRAY

// REQUIRED TC :: O(n)

#include <bits/stdc++.h>
using namespace std;


void findIntersection(int a[],int b[],int c[],int n1,int n2,int n3)
{
	int i,j,k;
	i=j=k=0;

	while(i<n1 && j<n2 && k<n3)
	{
		if(a[i]==b[j] && b[j]==c[k])
		{
			cout<<a[i]<<" ";
			i++;j++;k++;
		}
		else if(a[i]<b[j])
			i++;
		else if(b[j]<c[k])
			j++;
		else
			k++;
	}
}
int main()
{
	int ar1[] = {1, 5, 10, 20, 40, 80};
	int ar2[] = {6, 7, 20, 80, 100};
	int ar3[] = {3, 4, 15, 20, 30, 70, 80, 120};
	int n1=sizeof(ar1)/sizeof(ar1[0]);
	int n2=sizeof(ar2)/sizeof(ar2[0]);
	int n3=sizeof(ar3)/sizeof(ar3[0]);

	cout<<"the common elements are :: ";
	findIntersection(ar1,ar2,ar3,n1,n2,n3);
}
