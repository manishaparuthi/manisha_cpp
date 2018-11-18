using namespace std;
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
vector<pair<string,string>> arr;//global array to store card no. and bank account no.


bool equivalenceTester(string cardA,string cardB) // check the equivalence of cards,
{						//cards are equivalent if they correspond to same account
  
	string A,B;
	for(int i=0;i<arr.size();i++)
	{
		if(!arr[i].first.compare(cardA) | !arr[i].first.compare(cardB))
		{
			if(!arr[i].first.compare(cardA))
			{
				A=arr[i].second;
			}
			if(!arr[i].first.compare(cardB))
			{
				B=arr[i].second;
			}

		}
	}
		
	return (!A.compare(B));

	}




int getFrequency(vector<string> array,int i,int j,string x) // computes the frequency of card 'x' in array
{
	int count=0;
	for(int k=i;k<=j;k++)
	{
		if(equivalenceTester(x,array[k]))
			count++;
	}
	return count;
}

string fraudCard(vector<string> cards,int i,int j)
{
	if(i==j)
		return cards[i];
	int k=(i+j)/2;
	string leftMajor = fraudCard(cards,i,k);
	string rightMajor = fraudCard(cards,k+1,j);
	if(equivalenceTester(leftMajor,rightMajor))//for equivalence of cards use equivalence Tester
	{
		return leftMajor;
	}
	int lcount = getFrequency(cards,i,j,leftMajor);
	int rcount = getFrequency(cards,i,j,rightMajor);
	if(lcount > k+1)
		return leftMajor;
	if(rcount > k+1)
		return rightMajor;
	else
		return "No Majority Element";

}

int main()
{
	//read file
	// and store the card no in vector
	//call majority problem
	
	ifstream card_file;
	string temp;
	string x;
	string y;  
	vector<string> cards;
	int i;
	cout<<"Opening File..........\n\n";
	card_file.open("card_no.txt");
	cout<<"Reading File...........\n\n";
	while( std:: getline(card_file,temp))
	{
		i=0;
		x="";
		y="";
		x.append(temp.begin() , temp.begin()+14);//card no length =14
		y.append(temp.begin()+15,temp.begin()+21);//account no length= 6
		arr.push_back({x,y});
		cards.push_back(x);
	}

	cout<<"Detecting............\n\n";
	string fraud_card=fraudCard(cards,0,cards.size()-1);
	if(!fraud_card.compare("No Majority Element"))
	{
		cout<<"No Majority Element";
	}
	else
	{
		cout<<"Majority Element Present and ";
		for(int i=0;i<arr.size();i++)
		{
			if(!arr[i].first.compare(fraud_card))
			{
				cout<<"Fraud Bank Account is "<<arr[i].second;
			}
		}
	}
	cout<<"\n";
			

return 0;
}
