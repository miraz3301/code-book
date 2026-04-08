
#include<bits/stdc++.h>
using namespace std;

int current_soln=0;

struct item_list
{


    float weight;
    float value;
    float per_unit;


};

bool compare_item(const item_list &a, const item_list &b)
{

    return a.per_unit>b.per_unit;
}

int ub_fn(item_list arr[],int v,int w,int W,int i)
{

    return v+(W-w)*arr[i].per_unit;
}

void BB(item_list arr[],int i,int v,int w,int W,int n)
{
    if(w>W){
        return ;
    }
    if(i==n) {

        if(current_soln<v)
            current_soln=v;
        return;

    }

    int ub=ub_fn(arr,v,w,W,i);
    if(ub<current_soln) return;

    for(int k=0; k<2; k++)
    {

        if(k==1) /// will take this item
        {
            BB(arr,i+1,v+arr[i].value,w+arr[i].weight,W,n);
        }
        else /// will skip
        {
            BB(arr,i+1,v,w,W,n);
        }
    }


}

int main()
{
    int n;

    cin>>n;

    item_list arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i].value>>arr[i].weight;
        arr[i].per_unit= arr[i].value/arr[i].weight;
    }



    sort(arr,arr+n,compare_item);


    for(int i=0; i<n; i++)
    {

        cout<<"Value and weight of item "<<i<<" : "<<arr[i].value<<" "<<arr[i].weight<<" "<<arr[i].per_unit<<endl;
    }


    /// passing array, starting item 'i', till now profit 'v', till now filled weight 'w', total capacity 'W',list items
    BB(arr,0,0,0,10,n);
    cout<<current_soln<<endl;

    return 0;
}
/*

4
40 4
42 7
12 3
25 5
*/



