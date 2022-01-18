// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{    
    string res="";
    char ch;
    int i=0;
    int count;
    while(i<src.size())
    {
        count=0;
        ch=src[i];
        while(src[i]==ch)
        {
            i++;
            count++;
        }
        res=res+ch+to_string(count);
    }
    return res;
}     
 
