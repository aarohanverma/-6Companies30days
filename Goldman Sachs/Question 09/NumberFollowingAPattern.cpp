// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        string res="";
        string ans="";
        for(int i=1;i<=S.size()+1;i++)
        {
            res=res+to_string(i);
        }
        int i=0;
        int cnt;
        int pos;
        while(i<res.size()-1)
        {
            if(S[i]=='I')
            {
                while(S[i]=='I')
                {
                    i++;    
                }
            }
            else
            {
                cnt=0;
                pos=i;
                while(S[i]=='D')
                {
                    cnt++;
                    i++;
                }
                string temp=res.substr(pos,cnt+1);
                
                reverse(temp.begin(),temp.end());
                for(int k=0;k<=cnt;k++)
                {
                    res[pos+k]=temp[k];
                }
            }
        }
        return res;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
