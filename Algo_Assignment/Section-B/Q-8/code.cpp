using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>

void selectionSort(vector<pair<int,int>> &array)//Selection sort
{
	int max_idx;
	for(int i=0;i<array.size()-1;i++)//select maximum and swap it with first element.
	{                                //select second maximum and swap it with second element...and so on.
		
		max_idx=i;
		for(int j=i+1;j<array.size();j++)
		{
			if(array[max_idx].first < array[j].first)
			{
				max_idx=j;
			}
		}
		array[i].swap(array[max_idx]);
	}
	
}
int minAmount(vector<int>revenue,int base)
{
	int size=revenue.size();
	vector<pair<int,int>> arr;
    for(int i = 0; i < size; ++i)
    {
       arr.push_back({revenue[i],i});
   	}
    selectionSort(arr);//sort the array using selection sort.
    
   /* sort(arr.begin(), arr.end(), [] (const pair<int,int> a, const pair<int,int> b)
     {
        return a.first >  b.first;
     });*/
    cout<<"\n\nOrder in which license should be bought is: ";
    int month=1;
    int rev=0;
    for(int i=0;i<size;i++)
    {
    	rev+=base*arr[i].first*month;
    	cout<<"\nLicense "<<arr[i].second+1<< ", ";
    	cout<<"Amount spent for license "<<arr[i].second+1 <<" is "<<base*arr[i].first*month;
    	cout<<"\n";
    	month++;
    }
return rev;
}
int main()
{
	vector<int> rate;
	int n;
	int base=100;
	cout << "Enter no of license: ";
	cin >> n;
	//cout<< endl;
	int x;
	cout<<"\n\n------------Enter Rate of price growth for license----------\n ";
	for(int i=0;i<n;i++)
	{
		cout<<"\nRate for license No. "<<i+1<<": ";
		cin>>x;
		rate.push_back(x);
	}
	cout<<"\n\nBase Price is : "<<base;
	int min_amount=minAmount(rate,base);
	cout<<"\n\nMinimum Amount spent is: "<<min_amount;
	cout<<"\n";
	return 0;
}
