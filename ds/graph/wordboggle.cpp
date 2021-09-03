
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    bool dfsRec(
                    vector<vector<char>> &board, 
                    string word, 
                    vector<vector<bool>> &visited, 
                    int row, 
                    int col, 
                    int wordIndex
                )
    {
        if(wordIndex == word.size())
        {
            return true;
        }
        
        if(
                row >= 0 and row < board.size() and 
                col >= 0 and col < board[0].size() and 
                visited[row][col] == false and
                board[row][col] == word[wordIndex]
            )
        {
            visited[row][col] = true;
            
            if(
                    dfsRec(board, word, visited, row - 1, col - 1, wordIndex + 1) or
                    dfsRec(board, word, visited, row - 1, col + 0, wordIndex + 1) or
                    dfsRec(board, word, visited, row - 1, col + 1, wordIndex + 1) or
                    dfsRec(board, word, visited, row + 0, col - 1, wordIndex + 1) or
                    dfsRec(board, word, visited, row + 0, col + 1, wordIndex + 1) or
                    dfsRec(board, word, visited, row + 1, col - 1, wordIndex + 1) or
                    dfsRec(board, word, visited, row + 1, col + 0, wordIndex + 1) or
                    dfsRec(board, word, visited, row + 1, col + 1, wordIndex + 1)
                )
                {
                    return true;
                }
            
            visited[row][col] = false;
        }
        
        return false;
    }
    
    bool findWords(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        
        int wordIndex = 0;
        
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(board[row][col] == word[wordIndex])
                {
                    if(dfsRec(board, word, visited, row, col, wordIndex) == true)
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    public:
    vector<string> wordBoggle(vector<vector<char>> &board, vector<string> &dictionary) 
    {
        vector<string> res;
        
        for(auto x: dictionary)
        {
            if(findWords(board, x))
            {
                res.push_back(x);
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
