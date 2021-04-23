#include <bits/stdc++.h>
using namespace std;


template< typename T >
vector<T> apSort2(vector<T> v, int n)       //arithmetic sorting
{
    T ma=*max_element(v.begin(),v.end());
    T mi=*min_element(v.begin(),v.end());

    int last_gap_r = n-1;
    int last_gap_l = 0;
    int dir = 0;
    vector<T> sor_vec(n,mi-1);

    float d = ((ma-mi)/float(n-1));

    for(int i=0 ; i<n ; i++)
    {
        int indx=(int)((v[i]-mi)/d);

        if(sor_vec[indx]!=(mi-1))
        {
            if(dir%2)
            {
                bool right=false;
                int ele = v[i];

                int j;
                for(j = indx; j < n; j++){
                    if(j>=last_gap_r){
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

                if(!right)last_gap_r = indx;

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
                dir++;
            }
            else{
                bool right=false;
                int ele = v[i];

                int j;
                for(j = indx; j >= 0; j--){
                    if(j<=last_gap_l){
                        j = 0;
                        break;
                    }
                    if(sor_vec[j]==mi-1){
                        sor_vec[j] = ele;
                        right = true;
                        break;
                    }
                    else if(ele > sor_vec[j]){
                        T tmp = ele;
                        ele = sor_vec[j];
                        sor_vec[j] = tmp;
                    }
                }

                if(!right)last_gap_l = indx;

                for(j = 0;!right && j<n;j++){
                    if(sor_vec[j]==mi-1){
                        sor_vec[j] = ele;
                        break;
                    }
                    else if(ele < sor_vec[j]){
                        T tmp = ele;
                        ele = sor_vec[j];
                        sor_vec[j] = tmp;
                    }
                }
                dir++;
            }
        }
            
        else
            sor_vec[indx]=v[i];
            
    }
    
    return sor_vec;
    
}