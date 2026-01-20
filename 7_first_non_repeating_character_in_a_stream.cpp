//my code
//Time Complexity = O(n)
//Space Complexity = O(1)           (String contains only lowercase English letter)


class Solution {
  public:
    string firstNonRepeating(string &s) {
        unordered_map<char,int>m;
        queue<char>q;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            if(m[s[i]]==1){
                q.push(s[i]);
            }
            while(!q.empty()&&m[q.front()]>1){
                q.pop();
            }
            if(q.empty())   s[i]='#';
            else    s[i]=q.front();
        }
        return s;
    }
};
