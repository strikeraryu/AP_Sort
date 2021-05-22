#include <bits/stdc++.h>
using namespace std;


template< typename T >
int findIndx(T mi, T ma, T ele, int n){
    float d = ((ma-mi)/float(n-1));
    int indx = round((ele-mi)/d);
    return indx;
}


template< typename T >
vector<T> apSort3(vector<T> v, int n)       //arithmetic sorting
{
    T ma=*max_element(v.begin(),v.end());
    T mi=*min_element(v.begin(),v.end());

    int last_gap = n-1;
    int col = 0;
    vector<T> sor_vec(n,mi-1);

    for(int i=0 ; i<n ; i++)
    {
        int indx = findIndx(mi, ma, v[i], n);
        int new_indx;
        T tmp_mi = mi, tmp_ma = ma;
        int mi_indx = 0, ma_indx = n-1;
        while(sor_vec[indx]!=(mi-1))
        {
            // if(ma_indx - mi_indx + 1 < 10)
            //     break;
            if(v[i] > sor_vec[indx]){
                tmp_mi = sor_vec[indx];
                mi_indx = indx;
                new_indx = mi_indx + findIndx(tmp_mi, tmp_ma, v[i], ma_indx - mi_indx + 1);
            }
            else{    
                tmp_ma = sor_vec[indx];
                ma_indx = indx;
                new_indx = mi_indx + findIndx(tmp_mi, tmp_ma, v[i], ma_indx - mi_indx + 1);
            }

            if(indx == new_indx)
                break;
            cout<<indx<<" "<<new_indx<<" "<<endl;
            indx = new_indx;
        }
        cout<<"-----------"<<endl;
        if(sor_vec[indx]!=(mi-1)){
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