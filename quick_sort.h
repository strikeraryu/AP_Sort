#include <bits/stdc++.h>
using namespace std;

template< typename T >
void swap(T *a, T *b) {
  T t = *a;
  *a = *b;
  *b = t;
}

template< typename T >
int partition(vector<T> &v, int low, int high) {
    
  T pivot = v[high]; 
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (v[j] <= pivot) {
        
      i++;

      swap<T>(&v[i], &v[j]);
    }
  }
  
  swap<T>(&v[i + 1], &v[high]);
  
  return (i + 1);
}

template< typename T >
void _quickSort(vector<T> &v, int low, int high) {
  if (low < high) {
      
    int pi = partition<T>(v, low, high);

    _quickSort<T>(v, low, pi - 1);

    _quickSort<T>(v, pi + 1, high);
  }
}

template< typename T >
vector<T> quickSort(vector<T> &v, int n)
{
  _quickSort<T>(v,0,n-1);
  return v;
}