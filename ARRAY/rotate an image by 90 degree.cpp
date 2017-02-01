// PROBLEM :: ROTATE A 2-D IMAGE BY 90 DEGREE


#include<bits/stdc++.h>
using namespace std;

void rotateImage(int mat[][4],int r,int c)
{
	for(int i=0;i<c;i++)
	{
		for(int j=r-1;j>=0;j--)
			cout<<mat[j][i]<<" ";
		cout<<"\n";
	}
}
int main()
{
	int mat[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int r=3,c=4;

	rotateImage(mat,r,c);
}
