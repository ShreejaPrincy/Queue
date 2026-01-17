//my code
//Time Complexity:
//Enqueue → O(1)
//Dequeue → O(1)
//Space Complexity: O(N)

#include <bits/stdc++.h> 
class CircularQueue{

    int *arr;
    int rear;
    int front;
    int size;

    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size=n;
        arr=new int[n];
        rear=-1;
        front=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if(front==(rear+1)%size)   return false;
        else if(front==rear&&rear==-1){
            front=rear=0;
            arr[rear]=value;
        }
        else{
            rear=(rear+1)%size;
            arr[rear]=value;
        }
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front==-1&&rear==-1) return -1;
        
        int ans = arr[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else
            front=(front+1)%size;
        return ans;
    }
};

