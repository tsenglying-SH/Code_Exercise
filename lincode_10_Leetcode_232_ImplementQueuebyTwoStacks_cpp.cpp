class MyQueue {
	stack<int> S1;
	stack<int> S2;
public:
	MyQueue() {
		// do intialization if necessary
	}

	/*
	* @param element: An integer
	* @return: nothing
	*/
	void push(int element) {
		// write your code here
		while (S1.size() > 0) {
			S2.push(S1.top());
			S1.pop();
		}
		S1.push(element);
		while (S2.size() > 0) {
			S1.push(S2.top());
			S2.pop();
		}
	}

	/*
	* @return: An integer
	*/
	int pop() {
		// write your code here
		int temp = S1.top();
		S1.pop();
		return temp;
	}

	/*
	* @return: An integer
	*/
	int top() {
		// write your code here
		return S1.top();
	}
};