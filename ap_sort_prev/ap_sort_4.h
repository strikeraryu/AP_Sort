#include <bits/stdc++.h>
using namespace std;


template< typename T >
void swap_ele(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template< typename T >
vector<T> apSort5(vector<T> v, int n)       //arithmetic sorting
{
    T ma=*max_element(v.begin(),v.end());
    T mi=*min_element(v.begin(),v.end());

    int max_dis=0;

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
        while(i<n && fill[i]) {
            max_dis+=1;
            i++;
        }
        max_dis+=1;
        if(i>=n)break;

        int indx = round((v[i]-mi)/d);

        swap_ele<T>(v[cnts[indx]], v[i]);
        fill[cnts[indx]] = true;
        for(int j=cnts[indx]; j>0 && fill[j-1]; j--){
            max_dis++;
            if(v[j]<v[j-1]) 
                swap_ele<T>(v[j], v[j-1]);
            else break;
        }
        cnts[indx]++;
    }
    cout<<"maxd "<<max_dis<<endl;
    return v;
}