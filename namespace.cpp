/*  this program defines the concept of namespaces
you can create your own namespace */ 
#include<iostream>
namespace mynamespace
{
	int var=10;
}
using namespace mynamespace;
//using namespace std;


int main()
{
	int var=5;
	std::cout<<" the variable in mynamespace namespace is:"<<mynamespace:: var;//access using scope resolution
	std::cout<<" \n the variable in std namespace is:"<< var;
	mynamespace:: var=3;
	cout<<" the variable after changing is:"<<mynamespace:: var;
	return 0;
}