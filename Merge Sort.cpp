#include<iostream>
#define INFINITY 999999999
using namespace std;

int mergeCount = 0;

void Merge(int A[], int start, int mid, int endd)
{
    mergeCount++;
    cout << "Merge Call #: " << mergeCount << endl;

    int n1 = mid - start + 1;
    int n2 = endd - mid;
    int L[n1 + 1], R[n2 + 1];

    for(int i = 0; i < n1; i++)
    {
        L[i] = A[start + i];
    }
    for(int j = 0; j < n2; j++)
    {
        R[j] = A[mid + 1 + j];
    }

    L[n1] = INFINITY;
    R[n2] = INFINITY;

    int i = 0, j = 0;
    for(int k = start; k <= endd; k++)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(int Arr[], int start, int End)
{
    if(start < End)
    {
        int mid = (start + End) / 2;

        cout << "Split: [" << start << " to " << mid << "] and [" << mid+1 << " to " << End << "]" << endl;

        merge_sort(Arr, start, mid);
        merge_sort(Arr, mid + 1, End);
        Merge(Arr, start, mid, End);
    }
}

int main()
{
    int Arr[] = {4, 5, 2, 8, 3, 4, 12, -1, 9, -4};
    int len = sizeof(Arr) / sizeof(Arr[0]);

    cout << "Original Array Length: " << len << endl;

    merge_sort(Arr, 0, len - 1);

    cout << "\nSorted Array: ";
    for(int i = 0; i < len; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;

    cout << "Total Merge Calls: " << mergeCount << endl;
}

