// heap based method
class Solution {
private:
	priority_queue<int, vector<int>, greater<int>> minHeap;
	priority_queue<int, vector<int>> maxHeap;

public:
	void insert(int num) {
		if (maxHeap.empty() || num <= maxHeap.top()) {
			maxHeap.push(num);
		}
		else {
			minHeap.push(num);
		}

		while (maxHeap.size() < minHeap.size()) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
		while (maxHeap.size() > minHeap.size() + 1) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
	}

	double getMedian() {
		int total_size = minHeap.size() + maxHeap.size();
		if (total_size & 1) {
			return maxHeap.top();
		}
		return maxHeap.top() / 2.0 + minHeap.top() / 2.0;
	}
};