#include <bits/stdc++.h>
using namespace std;


template< typename T >
void swap_ele(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template< typename T >
void apSort(vector<T> &v, int n)       //arithmetic sorting
{
    T ma=*max_element(v.begin(),v.end());
    T mi=*min_element(v.begin(),v.end());

    vector<bool> fill(n, false);
    vector<int> cnts(n, 0);

    float d = ((ma-mi)/float(n-1));

    for(int i=0; i<n; i++)
    {
        int indx = round((v[i]-mi)/d);
        cnts[indx]+=1;
    }

    int prev = 0;   
    for(int i=0; i<n; i++){
        if(cnts[i] > 0){
            int tmp = cnts[i];
            cnts[i]=prev;
            prev = prev+tmp;
        }
    }

    for(int i=0; i<n;){
        while(i<n && fill[i])
            i++;

        if(i>=n)break;

        int indx = round((v[i]-mi)/d);

        swap_ele<T>(v[cnts[indx]], v[i]);
        fill[cnts[indx]] = true;

        for(int j=cnts[indx]; j>0 && fill[j-1]; j--){
            if(v[j]<v[j-1]) 
                swap_ele<T>(v[j], v[j-1]);
            else break;
        }
        cnts[indx]++;
    }
}