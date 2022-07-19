using namespace std;

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <climits>

class TripletSumCloseToTarget {
 public:
  static int searchTriplet(vector<int>& arr, int targetSum) {
    sort(arr.begin(), arr.end());
    int smallestDifference = INT_MAX;
    int targetDiff = INT_MAX;
    
    for(int i = 0; i < arr.size()-2; i++){
      int leftPtr = i+1;
      int rightPtr = arr.size()-1;

     while(leftPtr < rightPtr){
        targetDiff = targetSum - (arr[i] + arr[leftPtr] + arr[rightPtr]);

        if(targetDiff == 0){
          return targetSum;
        }
        else if (targetDiff > 0){
          leftPtr++;
        }
        else if(targetDiff < 0){
          rightPtr--;
        }

      }
    }


    return smallestDifference;
  }
};

int main(int argc, char* argv[]) {
  vector<int> vec = {-2, 0, 1, 2};
  cout << TripletSumCloseToTarget::searchTriplet(vec, 2) << endl;
  vec = {-3, -1, 1, 2};
  cout << TripletSumCloseToTarget::searchTriplet(vec, 1) << endl;
  vec = {1, 0, 1, 1};
  cout << TripletSumCloseToTarget::searchTriplet(vec, 100) << endl;
}