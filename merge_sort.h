#include <bits/stdc++.h>
using namespace std;

template< typename T >
void merge(vector<T> &v, int p, int q, int r) {
  
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<T> L(n1);
    vector<T> M(n2);
    for (int i = 0; i < n1; i++)
        L[i] = v[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = v[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            v[k] = L[i];
            i++;
        } 
        else {
            v[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = M[j];
        j++;
        k++;
    }
}

template<typename T>
void _mergeSort(vector<T> &v, int l, int r) {
  if (l < r) 
  {
    
    int m = l + (r - l) / 2;
    _mergeSort<T>(v, l, m);
    _mergeSort<T>(v, m + 1, r);

    merge<T>(v, l, m, r);
  }
}

template <typename T>
vector<T>  mergeSort(vector<T> v, int n){
    _mergeSort<T>(v, 0, n-1);
    return v;
}