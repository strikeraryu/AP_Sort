#include <iostream>
#include <bits/stdc++.h>
#include<array>
#include <chrono>
#include "insertion_sort.h"
#include "ap_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
typedef long long int sortType;

using namespace std;
using namespace std::chrono;

vector<sortType> sorted;
vector<sortType> reverseSorted;
vector<sortType> highUniform;
vector<sortType> lowUniform;
vector<sortType> unsorted;
vector<sortType> constant;
map<string, vector<sortType>> testCases;


void generateTestCase(int n)
{

    testCases.clear();

    sorted.clear();
    reverseSorted.clear();
    highUniform.clear();
    lowUniform.clear();
    unsorted.clear();
    constant.clear();
    
    sorted.resize(n);
    reverseSorted.resize(n);
    highUniform.resize(n);
    lowUniform.resize(n);
    unsorted.resize(n);
    constant.resize(n);

    // unsorted
    for(int i=0; i<n; i++){
        if(rand()%2)
            unsorted[i] = rand();
        else
            unsorted[i] = -rand();
    }
    testCases["unsorted"] = unsorted;

    //sorted
    sorted = unsorted;
    sort(sorted.begin(), sorted.end());
    testCases["sorted"] = sorted;

    // reverse sorted
    reverseSorted = sorted;
    reverse(reverseSorted.begin(), reverseSorted.end());
    testCases["reverseSorted"] = reverseSorted;

    // constant
    sortType C = rand();
    fill(constant.begin(), constant.end(), C);
    testCases["constant"] = constant;

    // high uniform
    sortType a=rand()%(100000000)-50000000;
    sortType d=rand()%5000 + 2500;
    sortType off = 0;
    for(int i=0 ; i<n ; i++)
    {
        off=(rand()%(d/25))-d/50;
        highUniform[i]=a+i*d + off;
    }
    random_shuffle(highUniform.begin(), highUniform.end());
    testCases["highUniform"] = highUniform;

    // low uniform
    a=rand()%(100000000)-50000000;
    d=rand()%5000 + 2500;
    off = 0;
    for(int i=0 ; i<n ; i++)
    {
        off=(rand()%(d))-d/2;
        lowUniform[i]=a+i*d + off;
    }
    random_shuffle(lowUniform.begin(), lowUniform.end());
    testCases["lowUniform"] = lowUniform;
}

bool isSorted(vector<sortType> v){
    vector<sortType> vSorted = v;
    sort(v.begin(), v.end());
    for(int i=0;i<v.size(); i++)
        if(v[i]!=vSorted[i])
            return false;

    return true;
}

int main()
{
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;

    generateTestCase(n);

    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    vector<sortType> input(n), output(n);
    bool checkSorted = true;

    // merge sort
    for(auto testCase=testCases.begin(); testCase!=testCases.end(); testCase++)
    {
        input = testCase->second;
        start = high_resolution_clock::now();
        output = mergeSort<sortType>(input,n);
        stop = high_resolution_clock::now();
        cout << "merge sort - "<<testCase->first<<" : " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;
        if(checkSorted)
            if(!isSorted(output)) cout<<"not sorted "<<endl;
    }
    cout<<endl;
    
    // STL sort
    for(auto testCase=testCases.begin(); testCase!=testCases.end(); testCase++)
    {
        input = testCase->second;
        output = input;
        start = high_resolution_clock::now();
        sort(output.begin(), output.end());
        stop = high_resolution_clock::now();
        cout << "STL sort - "<<testCase->first<<" : " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;
        if(checkSorted)
            if(!isSorted(output)) cout<<"not sorted "<<endl;
    }
    cout<<endl;
    
    // AP sort
    for(auto testCase=testCases.begin(); testCase!=testCases.end(); testCase++)
    {
        input = testCase->second;
        output = input;
        start = high_resolution_clock::now();
        apSort<sortType>(output, n);
        stop = high_resolution_clock::now();
        cout << "AP sort - "<<testCase->first<<" : " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;
        if(checkSorted)
            if(!isSorted(output)) cout<<"not sorted"<<endl;
    }
    cout<<endl;

    return 0;
}