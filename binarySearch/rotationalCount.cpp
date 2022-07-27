using namespace std;

#include <iostream>
#include <vector>

class RotationCountOfRotatedArray {
 public:
  static int countRotations(const vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;
    int minVal = arr[0];
    int minValIdx = 0;

    for(int i = 0; i < end; i++){
        if(minVal > arr[i]){
            minVal = arr[i];
            minValIdx = i;
        }
    }

    return minValIdx;

  }
};

int main(int argc, char* argv[]) {
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{10, 15, 1, 3, 8}) 
       << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{4, 5, 7, 9, 10, -1, 2}) 
       << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{1, 3, 8, 10}) << endl;
}