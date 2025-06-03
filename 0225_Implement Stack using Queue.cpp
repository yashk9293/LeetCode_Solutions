// Question Link :- https://leetcode.com/problems/implement-stack-using-queues/
// Implement Stack using Queues

// Approach - 1 (Using 2 queue)
// T.C = O(N)
// S.C = O(2N)
class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }

    int pop() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        //last element in q1
        int x = q1.front();
        q1.pop();
        q1.swap(q2);
        return x;
    }
    
    int top() {
        return q1.back();
    }

    bool empty() {
        return q1.empty();
    }
};



// Approach - 2 (Using 1 queue)
// T.C = O(N)
// S.C = O(N)
class MyStack {
public:
    queue<int> q;

    MyStack() {
        
    }

    void push(int x) {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int n = q.front();
        q.pop();
        return n;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
