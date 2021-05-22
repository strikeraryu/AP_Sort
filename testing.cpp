#include <iostream>
#include <bits/stdc++.h>
#include<array>
#include <chrono>
#include "insertion_sort.h"
#include "ap_sort.h"
#include "ap_sort_2.h"
#include "ap_sort_3.h"
#include "ap_sort_4.h"
#include "ap_sort_5.h"
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
    T off = 0;
    vector<T> vec(n);
    for(int i=0 ; i<n ; i++)
    {
        // off=(rand()%(d))-d/2;
        // off=(rand()%(d/25))-d/50;
        // vec[i]=a+i*d + off;
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

    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    vector<sortType> sor_vec;


    
    start = high_resolution_clock::now();
    sor_vec=mergeSort<sortType>(v,n);
    stop = high_resolution_clock::now();
    cout << "Time taken by merge sort: " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;
    
    start = high_resolution_clock::now();
    vector<sortType> sor_vec2=v;
    sort(sor_vec2.begin(), sor_vec2.end());
    stop = high_resolution_clock::now();
    cout << "Time taken by STL sort: " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;

    // start = high_resolution_clock::now();
    // sor_vec=quickSort<sortType>(v,n);
    // stop = high_resolution_clock::now();
    // cout << "Time taken by quick sort: " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;

    // start = high_resolution_clock::now();
    // sor_vec=apSort4<sortType>(v,n);
    // stop = high_resolution_clock::now();
    // cout << "Time taken by apsort4: " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;

    // start = high_resolution_clock::now();
    // sor_vec=apSort2<sortType>(v,n);
    // stop = high_resolution_clock::now();
    // cout << "Time taken by apsort2: " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;

    // start = high_resolution_clock::now();
    // sor_vec=apSort<sortType>(v,n);
    // stop = high_resolution_clock::now();
    // cout << "Time taken by apsort: " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;
    
    start = high_resolution_clock::now();
    sor_vec=apSort5<sortType>(v,n);
    stop = high_resolution_clock::now();
    cout << "Time taken by apsort 5: " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;
    
    // sort check
    // bool flg = true;
    // for(int i=0;i<n;i++){if(sor_vec2[i]!=sor_vec[i]){flg=false;break;}}
    // cout<<flg<<endl;
    
    // cout<<"Initial array: ";
    // pri_arr<sortType>(v,n);

    // cout<<"Sorted array: ";
    // pri_arr<sortType>(sor_vec,n);

    // start = high_resolution_clock::now();
    // sor_vec=insertionSort<sortType>(v,n);
    // stop = high_resolution_clock::now();
    // cout << "Time taken by insertion sort: " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;

    
    return 0;
}