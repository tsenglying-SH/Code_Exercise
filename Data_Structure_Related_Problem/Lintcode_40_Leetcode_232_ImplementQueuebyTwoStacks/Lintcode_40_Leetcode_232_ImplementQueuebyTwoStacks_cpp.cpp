// pop O(1), top O(1), empty O(1), push O(n)
class MyQueue {
private:
	stack<int> S1;
	stack<int> S2;
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		while (!S2.empty()) {
			S1.push(S2.top());
			S2.pop();
		}
		S1.push(x);
		while (!S1.empty()) {
			S2.push(S1.top());
			S1.pop();
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int tmp = S2.top(); S2.pop();
		return tmp;
	}

	/** Get the front element. */
	int peek() {
		return S2.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return S2.empty();
	}
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue* obj = new MyQueue();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->peek();
* bool param_4 = obj->empty();
*/