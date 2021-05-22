#include <iostream>
#include <bits/stdc++.h>
#include<array>
#include <chrono>
typedef long long int sortType;

using namespace std;
using namespace std::chrono;

map<sortType, int> mp;

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
        vec[i]=a+i*d;
        mp[vec[i]] = i;
        if(int((vec[i]-a)/d) != i)cout<<"yes"<<endl;
        // vec[i]=rand()%1000000;
        // if(i%2)
        // vec[i] = 10000;
        // else vec[i] = 1000;
    }
    cout<<a<<" "<<d<<endl;
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


template< typename T >
vector<T> apSort(vector<T> v, int n)       //arithmetic sorting
{
    T ma=*max_element(v.begin(),v.end());
    T mi=*min_element(v.begin(),v.end());

    int last_gap = n-1;
    int col = 0;
    vector<T> sor_vec(n,mi-1);

    float d = ((ma-mi)/float(n-1));
    cout<<d<<endl;
    cout<<mi<<endl;
    for(int i=0 ; i<n ; i++)
    {
        int indx = round((v[i]-mi)/d);
        if(indx!=mp[v[i]])cout<<mp[v[i]]<<" "<<indx<<" "<<v[i]<<endl;
        if(sor_vec[indx]!=(mi-1))
        {
            col++;
            bool right=false;
            int ele = v[i];

            int j;
            for(j = indx; j < n; j++){
                if(j>=last_gap){
                    j = n-1;
                    break;
                }
                if(sor_vec[j]==mi-1){
                    sor_vec[j] = ele;
                    right = true;
                    break;
                }
                else if(ele < sor_vec[j]){
                    T tmp = ele;
                    ele = sor_vec[j];
                    sor_vec[j] = tmp;
                }
            }

            if(!right)last_gap = indx;

            for(j = j-1;!right && j>=0;j--){
                if(sor_vec[j]==mi-1){
                    sor_vec[j] = ele;
                    break;
                }
                else if(ele > sor_vec[j]){
                    T tmp = ele;
                    ele = sor_vec[j];
                    sor_vec[j] = tmp;
                }
            }
        }
            
        else
            sor_vec[indx]=v[i];
            
    }
    cout<<"col - "<<col<<endl;
    return sor_vec;
    
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

    // cout<<"Initial array: ";
    // pri_arr<sortType>(v,n);


    // cout<<"Sorted array: ";
    // pri_arr<sortType>(sor_vec,n);


    start = high_resolution_clock::now();
    sor_vec=apSort<sortType>(v,n);
    stop = high_resolution_clock::now();
    cout << "Time taken by apsort: " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;

    // start = high_resolution_clock::now();
    // sor_vec=insertionSort<sortType>(v,n);
    // stop = high_resolution_clock::now();
    // cout << "Time taken by insertion sort: " << fixed << (duration_cast<milliseconds>(stop - start)).count() << endl;


    
    return 0;
}