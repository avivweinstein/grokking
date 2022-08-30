using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KClosestElements {
 public:
  struct numCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { return x.first > y.first; }
  };

  static vector<int> findClosestElements(const vector<int> &arr, int K, int X) {
    int index = binarySearch(arr, X);
    int low = index - K, high = index + K;
    low = max(low, 0);  // 'low' should not be less than zero
    // 'high' should not be greater the size of the array
    high = min(high, (int)arr.size() - 1); 

    priority_queue<pair<int, int>, vector<pair<int, int>>, numCompare> minHeap;
    // add all candidate elements to the min heap, sorted by their absolute difference 
   // from 'X'
    for (int i = low; i <= high; i++) {
      minHeap.push(make_pair(abs(arr[i] - X), i));
    }

    // we need the top 'K' elements having smallest difference from 'X'
    vector<int> result;
    for (int i = 0; i < K; i++) {
      result.push_back(arr[minHeap.top().second]);
      minHeap.pop();
    }

    sort(result.begin(), result.end());
    return result;
  }

 private:
 //returns the index of a the target number in an array.
 //if the number is not in the array, then we return 
  static int binarySearch(const vector<int> &arr, int target) {

    int start = 0;
    int end = arr.size()-1;
    int result;

    while(start <= end){
        int mid = start + (end-start)/2;

        if(arr[mid] == target){
            result = mid;
            return result;
        }
        if(arr[mid] < target){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    result = start;
    return result;
    
  }
};

int main(int argc, char *argv[]) {
  vector<int> result = 
        KClosestElements::findClosestElements(vector<int>{5, 6, 7, 8, 9}, 3, 7);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = 
        KClosestElements::findClosestElements(vector<int>{2, 4, 5, 6, 9}, 3, 6);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}