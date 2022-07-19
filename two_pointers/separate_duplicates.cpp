using namespace std;

#include <iostream>
#include <vector>

class RemoveDuplicates {
 public:
  static int remove(vector<int>& arr) {
      int nonDuplicates = 1;
      int current = 0;
      int next = 0;

        if(arr.size() == 0){
            return 0;
        }

        while(next < arr.size()){
            if(arr[current] == arr[next]){
                next++;
            }
            else if(arr[current] != arr[next]){
                nonDuplicates++;
                current = next;
            }
        }

      return nonDuplicates;
  }
};

int main(int argc, char* argv[]) {
  vector<int> arr = {2, 3, 3, 3, 6, 9, 9};
  cout << "Array new length: " << RemoveDuplicates::remove(arr) << endl;

  arr = vector<int>{2, 2, 2, 11};
  cout << "Array new length: " << RemoveDuplicates::remove(arr) << endl;
}