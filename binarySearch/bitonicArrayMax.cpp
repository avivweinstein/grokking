using namespace std;

#include <iostream>
#include <vector>

class MaxInBitonicArray {
 public:
  static int findMax(const vector<int>& arr) {
    int s = 0;
    int e = arr.size()-1;
    int mid;

    while(s < e){
        mid = s + (e-s)/2;
        if(arr[mid] < arr[mid + 1]){
            s = mid+1;
        }
        else{
            e = mid;
        }
    }
    return arr[s];
  }
};

int main(int argc, char* argv[]) {
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12, 4, 2}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{3, 8, 3, 1}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{10, 9, 8}) << endl;
}