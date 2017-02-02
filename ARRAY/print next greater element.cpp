// PROBLEM :: PRINT NEXT GREATER ELEMENT(NGE) OF ALL THE ELEMENTS OF THE ARRAY

// TC :: O(n)

#include <bits/stdc++.h>
using namespace std;

void printNGE(int arr[], int n)
{
	stack<int>st;

	st.push(arr[0]);

	for(int i=1;i<n;i++)
	{
		int next=arr[i];

		if(st.empty()==false)
		{
			int curr=st.top();
			st.pop();

			while(curr<next)
			{
				cout<<curr<<"---->"<<next<<"\n";

				if(st.empty()==true)
					break;

				curr=st.top();
				st.pop();
			}

			if(curr>next)
				st.push(curr);
		}

		st.push(next);
	}

	while(st.empty()==false)
	{
		int next=-1;
		int curr=st.top();
		st.pop();
		cout<<curr<<"---->"<<next<<"\n";
	}
}
int main()
{
	int arr[]={4,5,2,25};
	int n=(sizeof(arr)/sizeof(arr[0]));

	printNGE(arr,n);
}
