using namespace std;

#include <iostream>
#include <vector>

class CeilingOfANumber {
 public:
  static int searchCeilingOfANumber(const vector<int>& arr, int key) {
    int result = -1;

    int start = 0;
    int end = arr.size()-1;
    int mid = 0;

if (key > arr[arr.size() - 1]) {  // if the 'key' is bigger than the biggest element
      return -1;
    }

    while(start<=end){
        mid = (start+end)/2;

        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            start = mid+1;

        }
        else if(arr[mid] > key){
            end = mid-1;
        }

    }
    result = start;
    return result;
 
  }
};

int main(int argc, char* argv[]) {
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 6) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{1, 3, 8, 10, 15}, 12) 
       << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 17) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, -1) << endl;
}