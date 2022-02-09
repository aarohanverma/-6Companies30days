// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    void helper(vector<vector<char>>& board,string word,bool &flag,unordered_map<string,int> &m,int i,int j,int k)
    {
        if(m[to_string(i)+to_string(j)]==1)
        {
            return;
        }
        if(k==word.size())
        {
            flag=true;
            return;
        }
        if(word[k]==board[i][j])
        {
            m[to_string(i)+to_string(j)]=1;
            if(i-1>=0)
            {
                helper(board,word,flag,m,i-1,j,k+1);
            }
            if(i+1<board.size())
            {
                helper(board,word,flag,m,i+1,j,k+1);
            }
            if(j-1>=0)
            {
                helper(board,word,flag,m,i,j-1,k+1);
            }
            if(j+1<board[0].size())
            {
                helper(board,word,flag,m,i,j+1,k+1);
            }
        }
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        unordered_map<string,int> m;
        bool flag=false;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(word[0]==board[i][j])
                {
                    helper(board,word,flag,m,i,j,0);
                }
                if(flag==true)
                {
                    return true;
                }
                m.clear();
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
