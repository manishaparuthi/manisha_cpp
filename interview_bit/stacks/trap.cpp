using namespace std;
#include <iostream>
# include<vector>
int max(const vector<int> &A,int start,int end)
{
    int maxel=A[start];
    for(int i=start;i<=end;i++)
    {
        if(A[i]>maxel)
        {
            maxel=A[i];
        }
    }
    return maxel;
}

int trap(const vector<int> &A) {
    int raintrapped=0;
    int min;
    for(int i=0;i<A.size();i++)
    {
        int leftmax=max(A,0,i);
        int rightmax=max(A,i,A.size());
        min=leftmax>rightmax ? rightmax : leftmax;
    
        if(min-A[i]>0)
        {
            raintrapped=raintrapped-A[i]+min;
            cout<<"rain trapped at "<<i<<" is "<<raintrapped<<"\n";
        }
    }
    return raintrapped;
}
int main()
{
	
 int arr[]  ={22, 93, 38, 62, 14, 53, 77, 90, 93, 40, 25, 12, 58, 93, 65, 44, 60, 8, 53, 83, 84, 78, 76, 30, 43, 88, 27, 78, 65, 2, 36, 26, 54, 0, 53, 74, 16, 92, 14, 69, 69, 59, 11, 74, 47, 79, 80, 51, 68, 74, 84, 7, 100, 16, 53, 97, 0, 33, 41, 82, 51, 94, 41, 91, 31, 31, 96, 67, 17, 20, 77, 44, 21, 80, 59, 85, 16, 18, 15, 80, 81, 6, 88, 27, 92, 34, 34, 74, 8, 95, 97, 89, 29, 10, 19, 70, 75, 58, 37, 15, 8, 41, 94, 5, 65, 0, 65, 56, 77, 18, 45, 35, 80, 48, 6, 22, 13, 19, 90, 19, 95, 70, 51, 65, 11, 56, 19, 9, 2, 57, 72, 87, 80, 97, 40, 42, 66, 2, 79, 64, 64, 83, 10, 88, 44, 60, 65, 93, 80, 86, 22, 42, 0, 47, 52, 35, 92, 47, 66, 48, 19, 59, 84, 0, 88, 17, 100, 56, 26, 46, 78, 20, 46, 23, 58, 36, 42, 75, 71, 67, 72, 62, 95, 15, 66, 81, 19, 88, 1, 66, 54, 97, 33, 25, 35, 87, 10, 83, 0, 60, 27, 98, 41, 60, 86, 81, 26, 55, 73, 54, 49, 87, 1, 45, 52, 87, 61, 61, 66, 75};
	int n = sizeof(arr) / sizeof(arr[0]);
 
    vector<int> vect(arr, arr + n);
    int result=trap(vect);
	cout<<"result: "<<result;
	return 0;
}