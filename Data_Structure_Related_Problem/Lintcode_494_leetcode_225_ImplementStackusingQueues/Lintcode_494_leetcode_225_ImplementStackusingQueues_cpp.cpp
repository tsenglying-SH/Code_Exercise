// implement stack via queue
class MyStack {
private:
	std::queue<int> Q;
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		int size = Q.size();
		Q.push(x);
		for (int i = 0; i < size; i++) {
			int temp = Q.front(); Q.pop();
			Q.push(temp);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int top_e = Q.front();
		Q.pop();
		return top_e;
	}

	/** Get the top element. */
	int top() {
		return Q.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return Q.empty();
	}
};