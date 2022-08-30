using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class MaximumDistinctElements {
 public:
  struct valueCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.second > y.second;
    }
  };

  static int findMaximumDistinctElements(const vector<int> &nums, int k) {
    // 1. First, we will find the frequencies of all the numbers.
    unordered_map<int,int> map;
    for(int i = 0; i < nums.size(); i++){
      // cout << "Adding value: " << nums[i] << endl;
        map[nums[i]]++;
    }

    // 2. Then, push all numbers that are not distinct (i.e., have a frequency higher than one)
    //     in a Min Heap based on their frequencies. At the same time, we will keep a running count 
    //     of all the distinct numbers.
    priority_queue<pair<int,int>, vector<pair<int,int>>, valueCompare> minHeap;
    int numDistinct = 0;

    for(auto entry : map){
      if(entry.second == 1){
        numDistinct++;
      }
      else{
        minHeap.push(entry);
      }
    }
    // cout << "Num Distinct: " << numDistinct << endl;

    // 3. Following a greedy approach, in a stepwise fashion, we will remove the least frequent 
    //     number from the heap (i.e., the top element of the min-heap), and try to make it distinct. 
    //     We will see if we can remove all occurrences of a number except one. If we can, we will increment
    //     our running count of distinct numbers. We have to also keep a count of how many removals we have done.
    while(k > 0 && !minHeap.empty()){
      auto entry = minHeap.top();
      minHeap.pop();
      // k = ((k - entry.second) - 1);
      k -= entry.second - 1; 
      if(k >= 0){
        numDistinct++;
      }
    }

    // 4. If after removing elements from the heap, we are still left with some deletions, we have to remove 
    //     some distinct elements.
    if(k > 0){
      numDistinct = numDistinct - k;
      // numDistinct -= k;
    }

    return numDistinct;

  }
};

int main(int argc, char *argv[]) {
  int result = MaximumDistinctElements::findMaximumDistinctElements(
       vector<int>{7, 3, 5, 8, 5, 3, 3}, 2);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

  result = MaximumDistinctElements::findMaximumDistinctElements(
       vector<int>{3, 5, 12, 11, 12}, 3);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

  result = MaximumDistinctElements::findMaximumDistinctElements(
      vector<int>{1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5}, 2);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;
}