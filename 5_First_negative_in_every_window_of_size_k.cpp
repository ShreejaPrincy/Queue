//my code
//brute force approach
// Time Complexity: O(N * K)
// Space Complexity: O(1)  // excluding output array
// TLE

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int i=0;
        vector<int>arr1;
        while(i<arr.size()){
            int s=i;
            int e=i+k-1;
            if(e>=arr.size())   break;
            bool b=false;
            for(int j=s;j<=e;j++){
                if(arr[j]<0){
                    b=true;
                    arr1.push_back(arr[j]);
                    break;
                }
            }
            if(b==false)    arr1.push_back(0);
            i++;
        }
        return arr1;
    }
};

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//my code
//optimised approach
// Time Complexity: O(N)
// Space Complexity: O(K)  // queue stores indices of negative numbers within window

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int i=0;
        int j=0;
        queue<int>q;
        vector<int>ans;
        while(j<arr.size()){
            if(arr[j]<0)    q.push(j);
            
            if(j==i+k-1){
                while(!q.empty()&&q.front()<i)   q.pop();
                if(q.empty())   ans.push_back(0);
                else ans.push_back(arr[q.front()]);
                i++;
            }
            j++;
        }
        return ans;
    }
};


------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
