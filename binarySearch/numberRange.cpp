using namespace std;

#include <iostream>
#include <vector>

class FindRange {
 public:
  static pair<int, int> findRange(const vector<int> &arr, int key) {
    pair<int, int> result (-1, -1);

    int start = 0;
    int end = arr.size() - 1;
    int mid = 0;
    int temp = -1;

    while(start <= end){
        mid = start + (end-start)/2;
        if(arr[mid] == key){
            temp = mid;
            end = mid-1;
        }
        else if(arr[mid] > key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }

    result.first = temp;

    start = 0;
    end = arr.size()-1;
    temp = -1;

    while(start <= end){
        mid = start + (end-start)/2;
        if(arr[mid] == key){
            temp = mid;
            start = mid+1;
        }
        else if(arr[mid] > key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }

    result.second = temp;

    return result;

  }
};

int main(int argc, char *argv[]) {
  pair<int, int> result = FindRange::findRange(vector<int>{4, 6, 6, 6, 9}, 6);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 10);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 12);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
}