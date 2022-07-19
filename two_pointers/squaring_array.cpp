using namespace std;

#include <iostream>
#include <vector>

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
      vector<int> result;
      int posPointer = 0;
      int negPointer = 0;

      int negSquare = 0;
      int posSquare = 0;

      for(int i = 0; i < arr.size(); i++){
          if(arr[i] > 0){
              posPointer = i;
              negPointer = i - 1;
            //   cout << "posPointer: " << posPointer << endl;
            //   cout << "negPointer: " << negPointer << endl;
              break;
          }
      }

      while(negPointer >= 0 && posPointer < arr.size()){
          negSquare = arr[negPointer] * arr[negPointer];
          posSquare = arr[posPointer] * arr[posPointer];

        // cout << "posPointer: " << posPointer << endl;
        // cout << "negPointer: " << negPointer << endl;

        //   cout << "negSquare: " << negSquare << endl;
        //   cout << "posSquare: " << posSquare << endl;

          if(negSquare <= posSquare){
            //   cout << "negative is smaller or equal" << endl;
              result.push_back(negSquare);
              if(negPointer >= 0){
                  negPointer--;
              }
          }
          else{
            //   cout << "positive is smaller" << endl;
              result.push_back(posSquare);
              if(posPointer <= arr.size()){
                  posPointer++;
              }
          }
      }
        // cout << "'leaving while loop'" << endl;
        // cout << endl;
        // cout << "posPointer: " << posPointer << endl;
        // cout << "negPointer: " << negPointer << endl;
        // cout << "arr.size(): " << arr.size() << endl;

        if(negPointer < 0 && posPointer < arr.size()){
            while(posPointer < arr.size()){
                result.push_back(arr[posPointer] * arr[posPointer]);
                posPointer++;
            }
        }
        else if(negPointer >=0 && posPointer == arr.size()){
            while(negPointer >= 0 ){
                result.push_back(arr[negPointer] * arr[negPointer]);
                negPointer--;
            }
        }

    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = SortedArraySquares::makeSquares(vector<int>{-2, -1, 0, 2, 3});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
// vector<int> result;
  result = SortedArraySquares::makeSquares(vector<int>{-3, -1, 0, 1, 2});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}