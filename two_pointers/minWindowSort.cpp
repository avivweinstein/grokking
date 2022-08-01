using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ShortestWindowSort {
 public:
  static int sort(const vector<int>& arr) {

    //finding first element out of sorted order from left
    int maxFromLeft = 0
    int leftIndex;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] < maxFromLeft){
            leftIndex = i;
            break;
        }
        maxFromLeft = max(arr[i], maxFromLeft);
    }




    //finding first element out of sorted order from right



  }
};

int main(int argc, char* argv[]) {
  cout << ShortestWindowSort::sort(vector<int>{1, 2, 5, 3, 7, 10, 9, 12}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{1, 3, 2, 0, -1, 7, 10}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{1, 2, 3}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{3, 2, 1}) << endl;
}