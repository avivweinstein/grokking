using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletSumToZero {
public:
  static vector<vector<int>> searchTriplets(vector<int> &arr) {
      sort(arr.begin(), arr.end());
      vector<vector<int>> result;   //store our resulting triplet

      for(int i = 0; i < arr.size() - 2; i++){
          if(i > 0 && arr[i] == arr[i-1]){
              continue;
          }
          findPair(arr, (-1 * arr[i]), i+1, result);
      }
    return result;
  }

private:
    static void findPair(const vector<int> &myVec, int targetSum, int leftPtr, vector<vector<int>> &result){
        int rightPtr = myVec.size() - 1;
    
        while(leftPtr < rightPtr){
          int currentSum = myVec[leftPtr] + myVec[rightPtr];
          if(currentSum == targetSum){ //we found a result!
                result.push_back({-1*targetSum, myVec[leftPtr], myVec[rightPtr]});
                leftPtr++;
                rightPtr--;
              while(left < right && myVec[leftPtr] == myVec[leftPtr-1]){
                leftPtr++;
                cout << "moving left pointer because of duplicate" << endl;
              }
              while(left < right && myVec[rightPtr] == myVec[rightPtr+1]){
                rightPtr--;
                cout << "moving right pointer because of duplicate" << endl;
              }
            }
            else if(targetSum > currentSum){
              leftPtr++;
            }
            else{
              rightPtr--;
            }
        }
    }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {-3, 0, 1, 2, -1, 1, -2};
  cout << "begin results" <<endl;
  auto result = TripletSumToZero::searchTriplets(vec);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;

  vec = {-5, 2, -1, -2, 3};
  result = TripletSumToZero::searchTriplets(vec);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;

vec = {-2, -1,-1,-1,0,1,1,1,2,2,2,3,3,3,3};
  result = TripletSumToZero::searchTriplets(vec);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;
}