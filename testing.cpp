#include <iostream>
#include <bits/stdc++.h>
#include<array>
#include <chrono>
#include "insertion_sort.h"
#include "ap_sort.h"
#include "ap_sort_2.h"
#include "merge_sort.h"
#include "quick_sort.h"
typedef long long int sortType;

using namespace std;
using namespace std::chrono;

template< typename T >
vector<T> randomm(int n)
{
    T a=rand()%(40000)-20000;
    T d=rand()%9900+100;
    T off;
    vector<T> vec(n);
    for(int i=0 ; i<n ; i++)
    {
        // off=(rand()%(d))-d/2;
        // off=(rand()%(d/25))-d/50;
        // vec[i]=a+i*d+off;
        vec[i]=rand();
        // if(i%2)
        // vec[i] = 10000;
        // else vec[i] = 1000;
    }
    
    random_shuffle(vec.begin(),vec.end());
    return vec;
}

//int overlap()
template< typename T >
void pri_arr(vector<T> sor_vec, int n)
{
    for(int i=0 ; i<n ; i++)
        cout<<sor_vec[i]<<" ";
    cout<<endl;
    
}


int main()
{
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    vector<sortType> v=randomm<sortType>(n);


    // cout<<"Initial array: ";
    // pri_arr<sortType>(v,n);

    auto start = high_resolution_clock::now();
    vector<sortType> sor_vec=apSort<sortType>(v,n);
    auto stop = high_resolution_clock::now();
    cout << "Time taken by apsort: " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;

    // cout<<"Sorted array: ";
    // pri_arr<sortType>(sor_vec,n);

    start = high_resolution_clock::now();
    sor_vec=apSort2<sortType>(v,n);
    stop = high_resolution_clock::now();
    cout << "Time taken by apsort2: " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;

    
    start = high_resolution_clock::now();
    sor_vec=mergeSort<sortType>(v,n);
    stop = high_resolution_clock::now();
    cout << "Time taken by merge sort: " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;

    start = high_resolution_clock::now();
    sor_vec=quickSort<sortType>(v,n);
    stop = high_resolution_clock::now();
    cout << "Time taken by quick sort: " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;

    // start = high_resolution_clock::now();
    // sor_vec=insertionSort<sortType>(v,n);
    // stop = high_resolution_clock::now();
    // cout << "Time taken by insertion sort: " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;


    
    return 0;
}