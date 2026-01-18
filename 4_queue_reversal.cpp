//my code
//TC-O(n)
//SC-O(n)


//Approach-1
class Solution {
  public:
    void solve(queue<int> &q){
        if(q.empty())   return;
        
        int x=q.front();
        q.pop();
        solve(q);
        q.push(x);
    }
    void reverseQueue(queue<int> &q) {
        // code here
        solve(q);
    }
};


------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Approach-2

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        stack<int>st;
        while(!q.empty()){
            int x=q.front();
            st.push(x);
            q.pop();
        }
        while(!st.empty()){
            int x=st.top();
            q.push(x);
            st.pop();
        }
    }
};
