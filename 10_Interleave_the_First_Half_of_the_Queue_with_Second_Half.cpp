//Approach -1 using queue data structure
// Rearrange Queue (GFG)
// Problem: Interleave the first half of the queue with the second half
// Constraint: Queue size is even (as per GFG)
// Time Complexity:  O(n)
// Space Complexity: O(n)

class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        queue<int> temp;
        int n = q.size();

        // Store first half
        for (int i = 0; i < n / 2; i++) {
            temp.push(q.front());
            q.pop();
        }

        // Interleave both halves
        while (!temp.empty()) {
            q.push(temp.front());
            temp.pop();
            q.push(q.front());
            q.pop();
        }
    }
};



------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//approach - 2  using stack
// Time Complexity:  O(n)
// Space Complexity: O(n)

class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        stack<int> st;
        int n = q.size();

        // Step 1: Push first half of queue into stack
        for (int i = 0; i < n / 2; i++) {
            st.push(q.front());
            q.pop();
        }

        // Step 2: Push stack elements back into queue
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        // Step 3: Move first half elements to back of queue
        for (int i = 0; i < n / 2; i++) {
            q.push(q.front());
            q.pop();
        }

        // Step 4: Again push first half into stack
        for (int i = 0; i < n / 2; i++) {
            st.push(q.front());
            q.pop();
        }

        // Step 5: Interleave elements
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
            q.push(q.front());
            q.pop();
        }
    }
};
