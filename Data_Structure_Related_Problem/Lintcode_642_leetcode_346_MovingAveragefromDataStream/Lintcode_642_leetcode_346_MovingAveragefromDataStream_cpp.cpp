// concise version, and note that sum should be long or double, or may cause WA.
class MovingAverage {
private:
	int window_size;
	std::queue<int> window;
	long sum;

public:
	/*
	* @param size: An integer
	*/MovingAverage(int size) {
	// do intialization if necessary
	window_size = size;
	sum = 0;
}

	  /*
	  * @param val: An integer
	  * @return:
	  */
	  double next(int val) {
		  // write your code here
		  if (window.size() == window_size) {
			  sum -= window.front();
			  window.pop();
		  }

		  sum += val;
		  window.push(val);
		  return sum / window.size();
	  }
};