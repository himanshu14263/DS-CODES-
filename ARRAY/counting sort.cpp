// PROBLEM :: COUNTING SORT.

// TIME COMLEXITY :: O(n*d) // where n is the number of elements and 
//							   d is the number of digits in the max element of the array.

#include <bits/stdc++.h>
using namespace std;

void countSort(char arr[],int n)
{
    char output[n];

    int count[256]={0};

    for(int i = 0; i<n; ++i)
        ++count[arr[i]];

    for (int i = 1; i <=255; ++i)
        count[i] += count[i-1];

    for (int i = 0; arr[i]; ++i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
    for (int i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

int main()
{
    char arr[] = "geeksforgeeks";
    int n=sizeof(arr)/sizeof(arr[0]);

    countSort(arr,n);

    printf("Sorted character array is %s\n", arr);
    return 0;
}
