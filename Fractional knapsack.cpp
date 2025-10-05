#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
    int n=4;
    int item_w[4]={2,1,5,4};
    int item_b[4]={140,200,150,240};
    float benifit_per_w[4];
    int capacity= 5;
    int weight=0;
    float benifit=0;

    vector<pair<float, pair<int, int> > >itemTable;
    for(int i=0; i<n; i++)
    {
        benifit_per_w[i]=item_b[i]/item_w[i];
        cout<< benifit_per_w[i] <<"\t";
        itemTable.push_back(make_pair(benifit_per_w[i],make_pair(item_b[i],item_w[i])));
    }

    cout<<"\nB/w\tBen\tweight"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<itemTable[i].first<<"\t"<<itemTable[i].second.first<<"\t"<<itemTable[i].second.second<<endl;
    }

    sort(itemTable.begin(), itemTable.end(), greater<>());

    cout<<"\nB/w\tBen\tweight"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<itemTable[i].first<<"\t"<<itemTable[i].second.first<<"\t"<<itemTable[i].second.second<<endl;
    }

    vector<string> selectedItems;

    for(int i=0; i<n; i++)
    {
        int wi = itemTable[i].second.second;
        int bi = itemTable[i].second.first;
        if(weight+wi <= capacity)
        {
            weight= weight+wi;
            benifit= benifit+bi;

            selectedItems.push_back("Item " + to_string(i+1));
        }
        else
        {
            int rem = capacity - weight;
            weight =weight+rem;
            benifit=benifit+ (float)rem*itemTable[i].first;

            selectedItems.push_back("Item " + to_string(i+1) + " (partial)");
            break;
        }
    }

    cout<<"\ntotal Benifit: "<<benifit;

    cout<<"\nSelected Items: ";
    for(int i=0; i<selectedItems.size(); i++)
    {
        cout<<selectedItems[i]<<" ";
    }

}
