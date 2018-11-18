
#include <bits/stdc++.h> 
using namespace std; 
  

int maximumProfit(vector<int> price) 
{ 
     
	 int size=price.size();
	 int buy = 0;   //buy day initialize
	 int sell = 1; // sell day initialize
	 int temp = 0;
   int max_diff = price[1] - price[0]; 
   int min_el = price[0]; 
   for(int i = 1; i < size; i++) 
   {      
     	if (price[i] - min_el > max_diff) //compare current maximum difference with difference of each day's price with minimum                           
        {
       		max_diff = price[i] - min_element;
       		buy = temp;    //update buy day
       		sell = i;     //update sell day
        }
         
        if (price[i] < min_el) 
        {
       		min_el = price[i];
       		temp = i;
        }                      
    }
     if(max_diff < 1)
     {
     	cout<<"\n\nNo Maximum profit";
     }
     else
     {
     	cout<<"\n\nBuy Day: "<<buy+1<<",Sell Day:  "<<sell+1;
     } 
     
     cout<<"\n";  
     return max_diff; 
}  
  
/* Driver program to test above function */
int main() 
{ 
  int size;
  int x;
  vector<int> price;
  cout << "Enter No. of days: ";
  cin >> size;
  while(size < 2)
  {
  	cout << "\nWrong Input,Atleast 2 days are required.\n\n";
  	cout << "Enter Again: ";
  	cin >> size;
  }
  cout<<"\n\n----------Enter Price for stock----------\n\n";
  for(int i=0;i < size;i++)
  {
  	cout<<"Enter price at day "<<i+1<<": ";
  	cin>>x;
  	price.push_back(x);
  }

    
 int share_num = 1000;
 cout<<"\nNumber of Shares are: "<<share_num; 
  int max_profit = maximumProfit(price);
  if(max_profit > 0)
  	cout << "\nMaximum profit earned is " << share_num * max_profit;
  
  cout<<endl;
  return 0; 
} 
