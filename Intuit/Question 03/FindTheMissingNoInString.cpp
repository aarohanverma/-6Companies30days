// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/

void helper(const string &str,int temp,int &ans,int len,int new_pos,int &final)
{
    if(new_pos==str.size())
    {
        final=ans;
        return;
    }
    if(new_pos>str.size())
    {
        return;
    }
    int temp1=-1;
    int temp2=-1;
    bool valid=false;
    int temp_new_pos=new_pos;
    int temp_temp=temp;
    int temp_len=len;
    if(temp_new_pos+temp_len-1<str.size())
    {
        temp1=stoi(str.substr(temp_new_pos,len));
        //cout<<temp_temp<<" "<<temp1<<endl;
        if(temp1-temp_temp==2)
        {
            temp=temp1;
            ans=(temp_temp+temp1)/2;
            new_pos=temp_new_pos+len;
            valid=true;
        }
        else if(temp1-temp_temp==1)
        {
            temp=temp1;
            new_pos=temp_new_pos+len;
            valid=true;
        }
    }
    if(temp_new_pos+temp_len<str.size())
    {
        temp2=stoi(str.substr(temp_new_pos,len+1));
        //cout<<temp_temp<<" "<<temp2<<endl;
        if(temp2-temp_temp==2)
        {
            temp=temp2;
            ans=(temp_temp+temp2)/2;
            len=temp_len+1;
            new_pos=temp_new_pos+len;
            valid=true;
        }
        else if(temp2-temp_temp==1)
        {
            temp=temp2;
            len=temp_len+1;
            new_pos=temp_new_pos+len;
            valid=true;
        }
    }
    if(valid==false)
    {
        return;
    }
    helper(str,temp,ans,len,new_pos,final);
}
int missingNumber(const string& str)
{
    int ans=-1;
    int final=-1;
    for(int i=1;i<=6;i++)
    {
        if(str.size()>=i*2)
        {
            int temp=stoi(str.substr(0,i));
            helper(str,temp,ans,i,i,final);
        }
    }
    return final;
}
