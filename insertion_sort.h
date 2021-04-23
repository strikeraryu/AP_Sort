#include <bits/stdc++.h>
using namespace std;


template< typename T >
vector<T> insertionSort(vector<T> arr, int n)
{
    int i, j;
    T key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr;
}