int findPivot(vector<int>& a) 
{
    int l = 0, r = a.size() - 1;

    while (l < r) 
    {
        int mid = l + (r - l) / 2;

        if (a[mid] > a[r])
            l = mid + 1;
        else if (a[mid] < a[r])
            r = mid;
        else
            r--;
    }

    return l;
}
int main() 
{
    vector<int> a = {5, 6, 7, 8, 1, 2, 3, 4};

    int pivot = findPivot(a);

    cout << "Pivot Index = " << pivot << '\n';
    cout << "Smallest Element = " << a[pivot] << '\n';

    return 0;
}
