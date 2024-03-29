using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestNumber {
 public:
  static int findKthSmallestNumber(const vector<int> &nums, int k) {
    priority_queue<int> maxHeap;

    int result;

    for(int i = 0; i < k; i++){
        maxHeap.push(nums[i]);
    }

    for(int i = k; i < nums.size(); i++){
        if(nums[i] < maxHeap.top()){
            maxHeap.pop();
            maxHeap.push(nums[i]);
        }
    }

    result = maxHeap.top();

    return result;
  }
};

int main(int argc, char *argv[]) {
  int result = 
        KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 3);
  cout << "Kth smallest number is: " << result << endl;

  // since there are two 5s in the input array, our 3rd and 4th smallest numbers should 
   // be a '5'
  result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 4);
  cout << "Kth smallest number is: " << result << endl;

  result = KthSmallestNumber::findKthSmallestNumber(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Kth smallest number is: " << result << endl;
}
