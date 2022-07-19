using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

class PairWithTargetSum {
public:
  static pair<int, int> search(const vector<int> &arr, int targetSum) {
      
      pair<int, int> indexes;
      indexes.first = -1;
      indexes.second = -1;
      unordered_map<int, int> seenNumbers;

      //X + Y = targetSum
      //X = arr[i]
      //Y = targetSum - X
      
      int Y = 0;

      for(int i = 0; i < arr.size(); i++){
          Y = targetSum - arr[i];
          
        //   cout << "Y: " << Y << endl;
        //   cout << "arr[i]: " << arr[i] << endl;

          if(seenNumbers.find(Y) != seenNumbers.end()){
              indexes.second = i;
              indexes.first = seenNumbers[Y];
              return indexes;
          }
          else{
              seenNumbers[arr[i]] = i;
          }
      }
    return indexes;
  }
};

int main(int argc, char *argv[]) {
  auto result = PairWithTargetSum::search(vector<int>{1, 2, 3, 4, 6}, 6);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" 
       << endl;
  result = PairWithTargetSum::search(vector<int>{2, 5, 9, 11}, 11);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" 
       << endl;
}
