// finding the "CATALAN NUMBER" for the implementation of "ENUMERATION OF BINARY TREE"
#include<iostream>
#include<climits>
using namespace std;

// NOTE:- The idea is to consider all possible pair of counts for nodes in left and right subtrees
// 		  and multiply the counts for a particular pair. Finally add results of all pairs.


// RECURCIVE FUNCTION TO FIND THE Nth CATALAN NUMBER
int catrecur(int n)
{
	if(n<=0)return 1;
	int res=0;
	for(int i=0;i<n;i++)
		res+=(catrecur(i)*catrecur(n-i-1));
	return res;
}
// DP SOLUTION OF CATALAN NUMBER OF [O(N*N)] TIME COMPLEXITY
int catarr[105];
void catdp()
{
	catarr[0]=catarr[1]=1;
	for(int n=2;n<=100;n++)
	{
		int res=0;
		for(int i=0;i<n;i++)
			res+=(catarr[i]*catarr[n-i-1]);
		catarr[n]=res;
	}
}
// THE BINOMIAL COEFFICIENT SOLUTION OF CATALAN NUMBERS OF O(N) TIME COMPLEXITY;
// CATALAN NUMBER = (2*N)!/(N+1)!(N)!
//				  =  2nCn/(n+1)

int binoCoeff(int n,int r)
{
	if(n-r<r)
		r=n-r;
	int res=1;
	for(int i=0;i<r;i++)
	{
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}

int catbino(int n)
{
	int res=binoCoeff(2*n,n);
	res/=(n+1);
	return res;
}



int main()
{
	int n;
	cout<<"enter a number to find catalan number\n";
	cin>>n;

	//IMPLEMENTATION OF CATALAN NUMBER USING RECURSION
	cout<<"IMPLEMENTATION OF CATALAN NUMBER USING RECURSION\n";
	cout<<catrecur(n)<<"\n";

	// IMPLEMETATION OF CATALAN NUMBER USING D.P.
	catdp();
	cout<<"IMPLEMETATION OF CATALAN NUMBER USING D.P.\n";
	cout<<catarr[n]<<"\n";

	// IMPLEMENTATION OF CATALAN NUMBER USING BINOMIAL COEFFICIENT
	cout<<"IMPLEMENTATION OF CATALAN NUMBER USING BINOMIAL COEFFICIENT\n";

	cout<<catbino(n)<<"\n";

}
/*
 * SOME STARTING CATALAN NUMBERS:-
 *  1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
 */
