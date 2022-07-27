using namespace std;

#include <iostream>
#include <vector>

class FirstSmallestMissingPositive {
 public:
  static int findNumber(vector<int> &nums) {
    int i = 0;
    cout << "initial vec: ";
    printVec(nums);
    // cout << endl;
    while(i < nums.size()){
        if(nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i]-1]){
            swap(nums, i, nums[i]-1);
            cout << "swap" << endl;
        }
        else{
            cout << "increment" << endl;
            i++;
        }
        printVec(nums);
    }

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != i+1){
            return i+1;
        }
    }
    return nums.size() + 1;
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
  static void printVec(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {-3, 1, 5, 4, 2};
  cout << FirstSmallestMissingPositive::findNumber(v1) << endl;

  v1 = {3, -2, 0, 1, 2};
  cout << FirstSmallestMissingPositive::findNumber(v1) << endl;

  v1 = {3, 2, 5, 1};
  cout << FirstSmallestMissingPositive::findNumber(v1) << endl;
}