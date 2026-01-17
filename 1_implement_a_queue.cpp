//my code
//Time Complexity: O(1) per operation
//Space Complexity: O(N)

#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int s;
    int f;
    int rear;
public:
    Queue() {
        // Implement the Constructor
        s=100001;
        arr=new int[s];
        f =0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(f==rear) return true;
        return false;
    }

    void enqueue(int data) {
        if(rear==s) return;  
        arr[rear++]=data;
    }

    int dequeue() {
        if(f==rear) return -1;
        int ans=arr[f];
        arr[f]=-1;
        f++;
        if(f==rear){
            f=0;
            rear=0;
        }
        return ans;
    }

    int front() {
        if(f==rear) return -1;
        return arr[f];
    }
};
