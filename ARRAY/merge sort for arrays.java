// PROBLEM :: MERGE SORT FOR ARRAYS 

package apple;

class maxSum{
	
	
	static void mergeArr(int[] arr, int l, int md , int h)
	{
		int n1=(md-l+1);
		int n2=(h-md);
		
		int L[]=new int[n1];
		int R[]=new int [n2];
		
		for(int i=0;i<n1;i++)
			L[i]=arr[l+i];
		for(int i=0;i<n2;i++)
			R[i]=arr[md+1+i];
		
		int i=0,j=0,k=l;
		
		while(i<n1 && j<n2)
		{
			if(L[i]<=R[j])
			{
				arr[k]=L[i];
				i++;
				k++;
			}
			else
			{
				arr[k]=R[j];
				j++;k++;
			}
		}
		
		while(i<n1)
		{
			arr[k]=L[i];
			i++;k++;
		}
		
		while(j<n2)
		{
			arr[k]=R[j];
			j++;k++;
		}
	}
	
	public void mergeSort(int[] arr,int l,int h)
	{
			if(l<h)
			{
				int md=(l+h)/2;
				mergeSort(arr,l,md);
				mergeSort(arr,md+1,h);
				mergeArr(arr,l,md,h);
			}
	}
	
	public static void main(String args[])
	{
		int[] arr={5,4,3,2,1};
		
		maxSum obj=new maxSum();	
		
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" ");
		System.out.println();
		
		obj.mergeSort(arr,0,arr.length-1);
		
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" ");
	}
}