// �ع����Ժ󣬽�����������ص����ֺϲ��˴�Ҷ�Ҫ����val ѹ��val��ƽ����
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