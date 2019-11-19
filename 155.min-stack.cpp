/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (39.00%)
 * Likes:    2161
 * Dislikes: 235
 * Total Accepted:    355.6K
 * Total Submissions: 910.8K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 * 
 * 
 */

// @lc code=start
// class MinStack {
// public:
//     /** initialize your data structure here. */
//     MinStack() {
           
//     }

//     void push(int x) {
//         stack_size++;
//         datas.push_back(x);
//         if(minimum > x) minimum = x;
//     }
    
//     // Guarantee the minimum value is right after poping.
//     void pop() {
//         if(stack_size==0) return;
//         // compare the last element in vector with the current minimum.
//         auto last_elment = datas.back();
//         datas.pop_back();
//         stack_size--;
//         // Update the minimum.
//         if(last_elment>minimum){
//             return;
//         }
//         else{
//             minimum = INT_MAX;
//             for(auto data : datas){
//                 if(minimum > data)
//                 {
//                     minimum = data;
//                 }
//             }
//         }
//     }
    
//     int top() {
//         if(stack_size >= 1){
//             return datas.back();
//         }else{
//             return INT_MIN;
//         }
//     }
    
//     int getMin() {
//         return minimum;
//     }
// private:
//     int stack_size = 0;
//  // Initialize value.
//     int minimum = INT_MAX;
//     vector<int> datas;
// };
class MinStack {
public:
    vector<int> a;
    vector<int> min;
    MinStack() {
        min.push_back(2147483647);
    }
    void push(int x) {
        a.push_back(x);
        if (x < min.back()) {
            min.push_back(x);
        } else {
            min.push_back(min.back());
        }
    }

    void pop() {
        a.pop_back();
        min.pop_back();
    }

    int top() {
        return a.back();
    }

    int getMin() {
        return min.back();
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

