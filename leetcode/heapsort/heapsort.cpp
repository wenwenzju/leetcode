// #include <iostream>
// #include <vector>
// #include <algorithm>
// 
// using namespace std;
// 
// class Heap
// {
// public:
// 	void max_heapify(vector<int>& nums, int i)		//1.find max value of node, node's left child and node's right child; 2.exchange node with max value node; 3.note that all operations are done within heap_size
// 	{
// 		int idx = i;
// 		int l = left_child(i);
// 		int r = right_child(i);
// 		if (l < heap_size && nums[idx] < nums[l]) idx = l;
// 		if (r < heap_size && nums[idx] < nums[r]) idx = r;
// 		if (idx != i) {swap(nums[idx], nums[i]);max_heapify(nums, idx);}
// 	}
// 	void build_max_heap(vector<int>& nums)		//1.nodes of index n/2, n/2+1, ... , n-1 are max_heap; 2.loop from n/2-1 to 0, and make each node a max_heap in turn
// 	{
// 		heap_size = nums.size();
// 		for (int i = (heap_size>>1)-1; i >= 0; --i)
// 		{
// 			max_heapify(nums, i);
// 		}
// 	}
// 	void sort(vector<int>& nums)		//1.build max_heap; 2.loop: exchange max value nums[0] with nums[heap_size-1]; heap_size--; make nums[0] a max_heap
// 	{
// 		build_max_heap(nums);
// 		while (heap_size > 1)
// 		{
// 			swap(nums[0], nums[heap_size-1]);
// 			heap_size--;
// 			max_heapify(nums, 0);
// 		}
// 	}
// private:
// 	int heap_size;
// 	inline int parent(int i) {return (i-1)>>1;}
// 	inline int left_child(int i) {return (i<<1)+1;}
// 	inline int right_child(int i) {return (i<<1)+2;}
// };
// 
// #define MAX_VAL 20
// #define MAX_NUM 2
// #define PRINT_VECTOR(v) for_each(v.begin(), v.end(), [](int i){cout << i << " ";});cout << endl;
// int main()
// {
// 	Heap h;
// 	vector<int> nums;
// 	for (int i = 0; i < MAX_NUM; ++i) nums.push_back(rand()%MAX_VAL+1);
// 	PRINT_VECTOR(nums);
// 
// 	h.sort(nums);
// 	PRINT_VECTOR(nums);
// 
// 	return 1;
// }

//#include <iostream>
//#include <vector>
//#include <numeric>
//#include<limits>
//#include <random>
//
//using namespace std;
//default_random_engine e;
//normal_distribution<double> n1, n2;
///** 请完成下面这个函数，实现题目要求的功能 **/
///** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
//double leartCurve(double mu1, double sigma1, double mu2, double sigma2) {
//	double x,y;
//	int re=0;
//	for(int i=0;i<100000;i++){
//		x= n1(e);
//		y= n2(e);
//		double x2 = x*x, y2 = y*y;
//		if ((x2+y2-1)*(x2+y2-1)*(x2+y2-1)-x2*y2<0){
//			re=re+1;
//		}
//	}
//	return 1.0*re/100000;
//
//}
//
//
//int main() {
	//double res;

	//double _mu1;
	//cin >> _mu1;
	//cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

	//double _sigma1;
	//cin >> _sigma1;
	//cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

	//double _mu2;
	//cin >> _mu2;
	//cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

	//double _sigma2;
	//cin >> _sigma2;
	//cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

	//n1 = normal_distribution<double>(_mu1, _sigma1);
	//n2 = normal_distribution<double>(_mu2, _sigma2);
	//res = leartCurve(_mu1, _sigma1, _mu2, _sigma2);
	//cout << res << endl;

	//return 0;
//
//}

#include <iostream>
#include <vector>
#include <numeric>
#include<limits>
#include<random>
#include <iomanip>

using namespace std;

default_random_engine e;

double lcValue(double x, double y)
{
	double x2 = x*x, y2 = y*y;
	double tmp = x2+y2-1;
	return tmp*tmp*tmp-x2*y2*y;
}
/** 请完成下面这个函数，实现题目要求的功能 **/
/** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
double leartCurve(double mu1, double sigma1, double mu2, double sigma2) {
	const int tot = 100000;
	int inCur = 0;
	normal_distribution<double> n1(mu1, sigma1);
	normal_distribution<double> n2(mu2, sigma2);
	for (int i = 0; i < tot; ++i){
		double x = n1(e);
		double y = n2(e);
		if (lcValue(x,y) < 0) inCur++;
	}
	return 1.*inCur/tot;
}

int main() {
	double res;
	double _mu1, _sigma1, _mu2, _sigma2;
	//cin >> _mu1 >> _sigma1 >> _mu2 >> _sigma2;

	while (cin >> _mu1)
	{
		//cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> _sigma1;
		//cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> _mu2;
		//cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> _sigma2;
		//cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

		res = leartCurve(_mu1, _sigma1, _mu2, _sigma2);
		cout <<setiosflags(ios::fixed) << setprecision(1) << res << endl;
	}
	//res = leartCurve(_mu1, _sigma1, _mu2, _sigma2);
	//cout << res << endl;

	return 0;

}
