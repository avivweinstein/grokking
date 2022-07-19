using namespace std;

#include <iostream>
#include <vector>

class PairWithTargetSum {
public:
  static pair<int, int> search(const vector<int> &arr, int targetSum) {
      
      pair<int, int> indexes;
      indexes.first = -1;
      indexes.second = -1;

      int startptr = 0;
      int endPtr = arr.size() - 1;

    //   cout << "startptr: " << startptr << endl;
    //   cout << "endptr: " <<endPtr << endl;

      while(startptr < endPtr){
          if(arr[startptr] + arr[endPtr] == targetSum){
              indexes.first = startptr;
              indexes.second = endPtr;
              return indexes;
          }
          else if(arr[startptr] + arr[endPtr] < targetSum){
              startptr++;
              cout << arr[startptr] << endl;
              cout << arr[endPtr] << endl;
          }
          else if(arr[startptr] + arr[endPtr] > targetSum){
              endPtr--;
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
