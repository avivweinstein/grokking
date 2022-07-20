using namespace std;

#include <iostream>
#include <vector>
#include <climits>

class MinimumDifference {
 public:
  static int searchMinDiffElement(const vector<int>& arr, int key) {
    int s = 0;
    int e = arr.size()-1;
    int curDiff = INT_MAX;
    int bestChoice = -1;
    int mid;

    while(s <= e){
        mid = s + (e-s)/2;
        if(arr[mid] == key){
            return arr[mid];
        }
        else if(arr[mid] < key){
            s = mid + 1;
            if(curDiff > key-arr[mid]){
                bestChoice = arr[mid];
                curDiff = key-arr[mid];
            }
        }
        else{
            e = mid - 1;
            if(curDiff > arr[mid] - key){
                bestChoice = arr[mid];
                curDiff = arr[mid] - key;
            }
        }
    }
    return bestChoice;
  }
};

int main(int argc, char* argv[]) {
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 7) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 4) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{1, 3, 8, 10, 15}, 12) 
       << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 17) << endl;
}