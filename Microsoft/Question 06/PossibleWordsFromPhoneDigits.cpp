// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    string pad(int i)
    {
        switch(i)
        {
            case 2:
                return "abc";
            case 3:
                return "def";
            case 4:
                return "ghi";
            case 5:
                return "jkl";
            case 6:
                return "mno";
            case 7:
                return "pqrs";
            case 8:
                return "tuv";
            case 9:
                return "wxyz";
        }
    }
    void helper(int a[],int i,int N,vector<string> &ans,string temp)
    {
        if(i==N)
        {
            ans.push_back(temp);
            return;
        }
        string x=pad(a[i]);
        for(int j=0;j<x.size();j++)
        {
            helper(a,i+1,N,ans,temp+x[j]);
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> ans;
        helper(a,0,N,ans,"");
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends
