using namespace std;

#include <iostream>
#include <vector>

class SearchRotatedArray {
 public:
  static int search(const vector<int>& arr, int key) {
    int start = 0;
    int end = arr.size() - 1;
    int mid;
    bool firstPartSorted = true;

    while(start <= end){
        mid = start + (end-start)/2;
        
        if(arr[mid] == key){
            return mid;
        }

        if(arr[start] <= arr[mid]){
            firstPartSorted = true;
        }
        else{
            firstPartSorted = false;
        }

        if(firstPartSorted){
            if(key >= arr[start] && key < arr[mid]){
                end = mid -1;
            }
            else{
                start = mid + 1;
            }
        }
        else{
            if (key > arr[mid] && key <= arr[end]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
    }

    // we are not able to find the element in the given array
    return -1;
  }
};

int main(int argc, char* argv[]) {
  cout << SearchRotatedArray::search(vector<int>{10, 15, 1, 3, 8}, 15) << endl;
  cout << SearchRotatedArray::search(vector<int>{4, 5, 7, 9, 10, -1, 2}, 10) << endl;
}