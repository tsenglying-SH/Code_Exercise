// 重构了以后，将两种情况的重叠部分合并了大家都要加上val 压入val求平均的
class MovingAverage {
private:
	int window_size;
	std::queue<int> window;
	double sum;

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