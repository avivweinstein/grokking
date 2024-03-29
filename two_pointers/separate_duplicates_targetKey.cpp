using namespace std;

#include <iostream>
#include <vector>

class RemoveElement {
 public:
  static int remove(vector<int>& arr, int key) {
      int newLength = arr.size();

      for(int i = 0; i < arr.size(); i++){
          if(arr[i] == key){
              newLength--;
          }
      }
      return newLength; 
  }
};


int main(int argc, char* argv[]) {
  vector<int> arr = {3, 2, 3, 6, 3, 10, 9, 3};
  cout << "Array new length: " << RemoveElement::remove(arr, 3) << endl;

  arr = vector<int>{2, 11, 2, 2, 1};
  cout << "Array new length: " << RemoveElement::remove(arr, 2) << endl;
}