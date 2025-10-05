#include<iostream>
using namespace std;
void insertion(int arr[],int n)
{
    for(int j=1; j<n; j++)
    {
        int key=arr[j];
        int i=j-1;
        while(i>=0 && arr[i]>key)
        {
          arr[i+1]=arr[i];
          i--;

        }
        arr[i+1]=key;
        cout<<"\n key : "<<key<<"-: ";
        for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"\t";

    }
    }
    cout<<"\nOutput array size : "<<n<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"\t";

    }

}
int main()
{
    int arr[]={33,66,22,99,77,11,91,55,88,44};
    int n=sizeof (arr)/sizeof(arr[0]);
    cout<<"Input array size : "<<n<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"\t";

    }
    cout<<"\nInsertion"<<endl;
    insertion(arr,n);

}

