//my code
//Time Complexity: O(n)
//Space Complexity: O(k) (due to auxiliary stack)
//“Can we do it without extra space?”
//Using recursion is possible, but it still uses O(k) call stack space, so auxiliary space cannot be avoided completely.

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        int n=q.size();
        if(n<k) return q;
        stack<int>st;
        for(int i=0;i<k;i++){
            st.push(q.front());
            q.pop();
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        for(int i=0;i<n-k;i++){
            int element=q.front();
            q.pop();
            q.push(element);
        }
        return q;
    }
};
