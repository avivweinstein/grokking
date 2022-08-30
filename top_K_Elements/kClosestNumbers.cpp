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
    result = 
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