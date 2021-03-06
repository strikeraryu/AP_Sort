#include <bits/stdc++.h>
using namespace std;


template< typename T >
vector<T> apSort(vector<T> v, int n)       //arithmetic sorting
{
    T ma=*max_element(v.begin(),v.end());
    T mi=*min_element(v.begin(),v.end());

    int last_gap = n-1;
    int col = 0;
    vector<T> sor_vec(n,mi-1);

    float d = ((ma-mi)/float(n-1));
    for(int i=0 ; i<n ; i++)
    {
        int indx = round((v[i]-mi)/d);
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

            for(j = n-1;!right && j>=0;j--){
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