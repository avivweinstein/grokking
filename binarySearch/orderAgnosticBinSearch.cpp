using namespace std;

#include <iostream>
#include <vector>

class BinarySearch {
 public:
  static int search(const vector<int>& arr, int key) {
    int result = -1;

    int start = 0;
    int end = arr.size()-1;

    bool isAscending;

    if(arr[start] < arr[end]){
        isAscending = true;
    }
    else{
        isAscending = false;
    }

    while(start <= end){
        int mid = (start+end)/2;

        if(arr[mid] == key){
            return mid;
        }
        
        if(isAscending){

             if(arr[mid] < key){
                start = mid + 1;
            }
            else if(arr[mid] > key){
                end = mid - 1;
            }
        }
        else{
            if(arr[mid] > key){
                start = mid + 1;
            }
            else if(arr[mid] < key){
                end = mid - 1;
            }
        }

    }

    return result;
  }
};

int main(int argc, char* argv[]) {
  cout << BinarySearch::search(vector<int>{4, 6, 10}, 10) << endl;
  cout << BinarySearch::search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 10) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 4) << endl;
}