#include <bits/stdc++.h>
using namespace std;

int findPeak(vector<int>& a) 
{
    int l = 0, r = a.size() - 1;

    while (l < r) 
    {
        int mid = l + (r - l) / 2;

        if (a[mid] < a[mid + 1])
            l = mid + 1;
        else
            r = mid;
    }

    return l;
}

int main() 
{
    vector<int> a = {1, 3, 20, 4, 1, 0};

    int peak = findPeak(a);

    cout << "Peak Index = " << peak << '\n';
    cout << "Peak Value = " << a[peak] << '\n';
}
