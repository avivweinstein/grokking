using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KLargestNumbers {
 public:
  struct greater {
    bool operator()(const int& a, const int& b) const { return a > b; }
  };
  static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
    //first, we put 'k' numbers into our min-heap

    priority_queue<int, vector<int>, greater> minHeap;  //make our min heap
    for(int i = 0; i < k; i++){                             //add elements into it
        minHeap.push(nums[i]);
    }

    //now we go through the rest of the input array, comparing the current value in the array
    //to the min. If the value we are looking at is bigger than the top (smallest element),
    //then we remove the top number from the minHeap and add in the element from the array
    //we are looking at.

    for(int i = k; i < nums.size(); i++){
        if(nums[i] > minHeap.top()){
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }

    vector<int> res;

    while(!minHeap.empty()){
        res.push_back(minHeap.top());
        minHeap.pop();
    }

    return res;
    
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = 
          KLargestNumbers::findKLargestNumbers(vector<int>{3, 1, 5, 12, 2, 11}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KLargestNumbers::findKLargestNumbers(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
