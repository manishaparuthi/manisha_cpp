vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	// DO STUFF HERE AND POPULATE result

    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   int cols=A[0].size();
   int rows=A.size();
    int TR=0;
    int BR=rows-1;
    int LC=0;
    int RC=cols-1;
    int dir=0;
    while( (TR<=BR) && (LC<=RC) )
    {
        if(dir==0)
        {
            for(int i=LC;i<=RC;i++)
            {
                result.push_back(A[TR][i]);
            }
            TR++;
            dir=1;
        }
        else if(dir==1)
        {
            for(int i=TR;i<=BR;i++)
            {
                result.push_back(A[i][RC]);
                
            }
            RC--;
            dir=2;
        }
        else if(dir==2)
        {
            for(int i=RC;i>=LC;i--)
            {
                result.push_back(A[BR][i]);
            }
            BR--;
            dir=3;
        }
         else if(dir==3)
        {
            for(int i=BR;i>=TR;i--)
            {
                result.push_back(A[i][LC]);
            }
            LC++;
            dir=0;
        }
    }
    return result;
}
