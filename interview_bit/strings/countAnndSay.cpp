/*
The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.
*/
int count (string str,int index,char num)
{
    int cnt=0;
    int i=index;
   // cout<<endl<<"counting "<<num<<" from "<<index<<" index.";
    while(str[i] == num && i< str.size())
    {
        cnt++;
        i++;
        
    }
  //  cout<<" count is: "<<cnt;
    return cnt;
}
string Solution::countAndSay(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

   int i=1;
    int j,k;
    string result="1";
    int count_index;
    int next_index;
    char number;

    
    while(i!=A)
    {
        
        string temp;
        //cout<<endl<<"temp: "<<temp;
        //cout<<endl<<"result: "<<result;
        int index=0;
        //cout<<endl<<"first num: "<<result[index];
        int j=0;
        

        while(index<result.size())
        {
            number=(char)result[index];
           // cout<<endl<<"number: "<<number;
           // cout<<endl<<"counting number...";
            count_index = count(result,index,number);
            //cout<<endl<<number<<"number count is: "<<count_index;
            next_index=index+count_index;
           // cout<<endl<<"next_index: "<<next_index;
            
           
            temp+=(char)(count_index|48);
         //    cout<<endl<<"temp: "<<temp;
            temp+=number;
         //   cout<<" temp= "<<temp;

            index=next_index;
            j++;
         
        }
        result=temp;
        i++;
    }
    return result;
}

/*
  char to int
    char var;
    cout<<(int)var-48;

    int to char
    int var;
    cout<<(char)(var|48);
    
    */
