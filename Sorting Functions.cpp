#include<iostream>
using namespace std;

void insertion(int arr[], int n)
{
    for(int j=1; j<n; j++)
    {
        int key = arr[j];
        int i = j - 1;

        while(i >= 0 && arr[i] > key)
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;

        cout << "\nStep " << j << " (key = " << key << ") : ";
        for(int k=0; k<n; k++)
        {
            cout << arr[k] << " ";
        }
    }

    cout << "\nSorted (Insertion Ascending): ";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selection(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int maxPos = i;

        for(int j=i+1; j<n; j++)
        {
            if(arr[j] > arr[maxPos])
            {
                maxPos = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[maxPos];
        arr[maxPos] = temp;

        cout << "\nStep " << i+1 << " : ";
        for(int k=0; k<n; k++)
        {
            cout << arr[k] << " ";
        }
    }

    cout << "\nSorted (Selection Descending): ";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubble(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

        cout << "\nStep " << i+1 << " : ";
        for(int k=0; k<n; k++)
        {
            cout << arr[k] << " ";
        }
    }

    cout << "\nSorted (Bubble Ascending): ";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[] = {33,66,22,99,77,11,91,55,88,44};
    int arr2[] = {33,66,22,99,77,11,91,55,88,44};
    int arr3[] = {33,66,22,99,77,11,91,55,88,44};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    cout << "Original Array: ";
    for(int i=0; i<n; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << "\n\n--- Insertion Sort (Ascending) ---\n";
    insertion(arr1, n);

    cout << "\n\n--- Selection Sort (Descending) ---\n";
    selection(arr2, n);

    cout << "\n\n--- Bubble Sort (Ascending) ---\n";
    bubble(arr3, n);

    return 0;
}
