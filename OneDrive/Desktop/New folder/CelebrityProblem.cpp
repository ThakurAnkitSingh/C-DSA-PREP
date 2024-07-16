/*

A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
Follow Up: Can you optimize it to O(N)

*/


class Solution 
{
    private:
    
    bool knows(vector<vector<int> >& M, int a, int b, int n){
        if(M[a][b]) return true;
        else return false;
    }
    
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>st;
        
        for(int i=0; i<n; i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(knows(M, a, b, n)) st.push(b);
            else st.push(a);
        }
        
        int potentialCelebrity = st.top();
        int rowCnt=0;
        int colCnt=0;
        for(int i=0; i<n; i++){
            if(M[potentialCelebrity][i] == 0){
                rowCnt++;
            }
            if(M[i][potentialCelebrity] == 1){
                colCnt++;
            }
        }
        
        if(rowCnt == n && colCnt == n-1) return potentialCelebrity;
        return -1;
    }
};