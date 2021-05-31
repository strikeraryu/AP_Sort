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

    // finding max and min element for finding approx spacing 
    T max_ele = v[0];
    T min_ele = v[0];
    for(T ele : v)
    {
        max_ele = max(max_ele, ele);  
        min_ele = min(min_ele, ele);  
    }

    // creating bool vector(fill) for storing whether stored element is at correct location
    // creating int vector(coll_cnts) to store number of collisions at a specific index
    vector<bool> fill(n, false);
    vector<int> coll_cnts(n, 0);

    // finding approx spacing
    float d = ((max_ele-min_ele)/float(n-1));

    // finding the number of collisions for each possible index
    for(int i=0; i<n; i++)
    {
        int indx;

        // predicting possible index for the element
        // if approx spacing is 0 the index = 0
        if(d==0) 
            indx = 0;
        else
            indx = round((v[i]-mi)/d);

        // increasing collision count if elements get same index
        coll_cnts[indx]+=1;
    }

    // a partition contains the element which collide at a specific index
    // calculating starting points for each possible partition in the array
    // starting point of a partition will be starting point of previous element + size of that partition(number of collisions)
    // starting point for first partition will be 0
    int prev = 0;   
    for(int i=0; i<n; i++){

        // if number of collisions is greater that 0 than there is a partition
        // finding starting point of next partition using starting point of current partion and its len
        if(coll_cnts[i] > 0){
            int tmp = coll_cnts[i];
            coll_cnts[i]=prev;
            prev = prev+tmp;
        }
    }

    // storing each elements in there partition in sorted order
    for(int i=0; i<n;){

        // finding next element which is not at correct location
        while(i<n && fill[i])
            i++;

        // bound check
        if(i>=n)break;

        // predicting possible index
        // if approx spacing is 0 the index = 0
        int indx;
        if(d==0) 
            indx = 0;
        else
            indx = round((v[i]-mi)/d);

        // swaping the element with the element at predicted index
        swap_ele<T>(v[coll_cnts[indx]], v[i]);
        fill[coll_cnts[indx]] = true;

        // storing the element at correct location in the partition so the partition remain sorted
        // swaping elements with the previous element if they are in wrong order or the reached the end of the partition
        for(int j=coll_cnts[indx]; j>0 && fill[j-1]; j--){
            if(v[j]<v[j-1]) 
                swap_ele<T>(v[j], v[j-1]);
            else break;
        }

        // increasing the starting point of that partition 
        // the element before that is already sorted
        coll_cnts[indx]++;
    }
}