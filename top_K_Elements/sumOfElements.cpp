using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class SumOfElements {
 public:
  struct numCompare {
    bool operator()(const int &x, const int &y) { return x > y; }
  };

  static int findSumOfElements(const vector<int> &nums, int k1, int k2) {
    int res = 0;        //running sum storage
    priority_queue<int, vector<int>, numCompare> minHeap; //min heap to store all values of our input array

    for(int i = 0; i < nums.size(); i++){
        minHeap.push(nums[i]);
    }

    for(int i = 0; i < k1; i++){
        // cout << "minHeap.top(): " << minHeap.top() << endl;
        minHeap.pop();
    }

    for(int i = k1+1; i < k2; i++){
        // cout << "i:" << i << endl;
        int temp = minHeap.top();
        // cout << "temp: " << temp << endl;
        minHeap.pop();
        res += temp;
        // cout <<   "res: " << res << endl;
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  int result = SumOfElements::findSumOfElements(vector<int>{1, 3, 12, 5, 15, 11}, 3, 6);
  cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;

  result = SumOfElements::findSumOfElements(vector<int>{3, 5, 8, 7}, 1, 4);
  cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;
}