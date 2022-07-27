using namespace std;

#include <iostream>
#include <vector>

class MissingNumber {
 public:
  static int findMissingNumber(vector<int> &nums) {
    int index = 0;

    while(index < nums.size()){
        if(nums[index] < nums.size() && nums[index] != nums[nums[index]]){
            swap(nums, index, nums[index]);
        }
        else{
            index++;
        }
    }

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != i){
            return i;
        }
    }

    return nums.size(); // if we get here, then it means the last element is the missing one.

    
  }

 private:
  static void swap(vector<int> &vec, int a, int b){     //swaps two values in a vector
    int temp = vec[a];
    vec[a] = vec[b];
    vec[b] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {4, 0, 3, 1};
  cout << MissingNumber::findMissingNumber(v1) << endl;
  v1 = {8, 3, 5, 2, 4, 6, 0, 1};
  cout << MissingNumber::findMissingNumber(v1) << endl;
}