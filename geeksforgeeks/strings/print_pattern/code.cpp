#include<bits/stdc++.h>

using namespace std;
int length_of_longest_word ( string input )
{
	int count = 0 ;
	int temp = 0;
	for ( int i = 0 ; i < input.size() ; i++ )
	{
		
		if (input[i] == ' ' )
		{
			if( count < temp )
			{
				count = temp ;
			}
			
			temp = 0;
		}
		else
		{
			temp++ ;
		}
	}
	if ( temp > count )
	{
		count = temp ;
	}
	return count ;
}
void print_jth_character ( string input , int j )
{
	int size = input.size() ;
	bool flag = true ;
	//cout <<" \nsize of "<<input<<" is "<< size;
	for ( int i = 0 ; i < size ; i ++ )
	{
		if ( i == j )
		{
			cout << input[i] ;
			flag = false;
		}
		
	}
	for ( int i = 0 ; i < size ; i ++ )
	{
		
			cout << " ";
		
		
	}
	if (flag)
		cout <<" ";

}
void print_pattern ( string input )
{
	int size = input.size() ;
	//cout << "size :" <<size;
	int i = 0 ;
	int j = 0 ;
	int k = 0 ;
	string word = "" ;
	int iteration = length_of_longest_word (input) ;
	//cout << "\n Starting while loop ";
	while ( i < iteration )
	{
		k = 0 ;
		//cout << " \niteration changing " ;
		while ( k < size )
		{
			
			//cout << " [k]: " << k ;
			if ( input[k] != ' ')
			{
				
				word = "";
				
				while ( input[k] != ' ' )
				{
					if(k < size)
					{
						word += input[k] ;
						
					}
					k++ ;
					
				}

				//cout << "\nword: " << word ;
				print_jth_character ( word , j );
				//cout <<" ";
				
			}
			//cout << " " ;
			k++;
		}
		j++ ;
		i++ ;
		cout << "\n";
	}
}

int main () 
{
	string input ; 
	getline ( cin , input ) ;
	print_pattern ( input ) ;
	return 0 ;
}
