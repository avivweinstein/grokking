using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletSumToZero {
public:
  static vector<vector<int>> searchTriplets(vector<int> &arr) {
    vector<vector<int>> triplets; //output vector

    sort(arr.begin(), arr.end());   //sort the array into ascending order

    int targetSum = 0;
    int leftPtr = 0;
    int rightPtr = arr.size();
    int numSolutions = 0;

    vector<int> singleTriplet;

    // cout << "Entering for loop" << endl;


    for(int i = 0; i < arr.size() - 2; i++){
      if(i > 0 && (arr[i] == arr[i-1])){
        continue;
      }
      else{
        targetSum = (-1 * arr[i]);
        leftPtr = i + 1;
        rightPtr = arr.size() - 1;

        // cout << "targetSum: " << targetSum << endl;
        // cout << "leftPtr: " << leftPtr << endl;
        // cout << "rightPtr: " << rightPtr << endl;
        // cout << "i: " << i << endl;
      }
      while(leftPtr < rightPtr){
        if(arr[i] + arr[leftPtr] + arr[rightPtr] == 0){
        //   cout << "we have found a solution!" << endl;
        //   cout << "i: " << i << endl;
        //   cout << "leftPtr: " << leftPtr << endl;
        // cout << "rightPtr: " << rightPtr << endl;
          // cout << endl;
          singleTriplet.push_back(arr[i]);
          //  cout << "adding i" << endl;
          singleTriplet.push_back(arr[leftPtr]);
          // cout << "adding left" << endl;
          singleTriplet.push_back(arr[rightPtr]);
          // cout << "adding right" << endl;
          triplets.push_back(singleTriplet);
          singleTriplet.clear();
          break;
        }
        else if(arr[i] + arr[leftPtr] + arr[rightPtr] > 0){
          rightPtr--;
          // cout << "moving right ptr" << endl;
          // cout << endl;
        }
        else if(arr[i] + arr[leftPtr] + arr[rightPtr] < 0){
          leftPtr++;
          // cout << "moving left ptr" << endl;
          // cout << endl;
        }

      }
    }
      return triplets;
  }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {-3, 0, 1, 2, -1, 1, -2};
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
}