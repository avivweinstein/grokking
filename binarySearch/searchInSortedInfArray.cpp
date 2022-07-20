using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ArrayReader {
 public:
  vector<int> arr;

  ArrayReader(const vector<int> &arr) { this->arr = arr; }

  virtual int get(int index) {
    if (index >= arr.size()) {
      return numeric_limits<int>::max();
    }
    return arr[index];
  }
};

class SearchInfiniteSortedArray {
 public:
  static int search(ArrayReader *reader, int key) {
    int result = -1;
    int start = 0;
    int end = 1;
    //first, we find the searchable bounds of the array
    while(reader->get(end) < key){
        int newStart = end+1;
        end += (end - start + 1)* 2;
        start = newStart;
    }

    //Now that we have found the bound that the key is in, if it exisits, we can binary search
    while(start <= end){
        int mid = start + (end-start)/2;
        if(reader->get(mid) == key){
            return mid;
        }
        else if(reader->get(mid) < key){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  ArrayReader *reader =
      new ArrayReader(vector<int>{4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30});
  cout << SearchInfiniteSortedArray::search(reader, 16) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 11) << endl;
  reader = new ArrayReader(vector<int>{1, 3, 8, 10, 15});
  cout << SearchInfiniteSortedArray::search(reader, 15) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 200) << endl;
  delete reader;
}