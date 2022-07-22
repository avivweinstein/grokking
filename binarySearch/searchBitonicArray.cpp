using namespace std;

#include <iostream>
#include <vector>

class SearchBitonicArray {
 public:
  static int search(const vector<int> &arr, int key) {

    //First, we find the max of the bitonic array
    int start = 0;
    int end = arr.size()-1;
    int mid;

    while(start < end){
        mid = start + (end-start)/2;

        if(arr[mid] < arr[mid+1]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }

    //at this point, start or end should be at the max value
    // cout << "start: "<< start << endl;
    // cout << "end: "<< end << endl;

    //we now do binary search on 0 through the max value.
    int maxValueIdx = start;
    end = maxValueIdx;
    start = 0;

    while(start <= end){
        mid = start + (end-start)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

    //we now do binary search on the max value through the end of the array
    end = arr.size()-1;
    start = maxValueIdx;
        while(start <= end){
        mid = start + (end-start)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

    return -1;
  }
};

int main(int argc, char *argv[]) {
  cout << SearchBitonicArray::search(vector<int>{1, 3, 8, 4, 3}, 4) << endl;
  cout << SearchBitonicArray::search(vector<int>{3, 8, 3, 1}, 8) << endl;
  cout << SearchBitonicArray::search(vector<int>{1, 3, 8, 12}, 12) << endl;
  cout << SearchBitonicArray::search(vector<int>{10, 9, 8}, 10) << endl;
}