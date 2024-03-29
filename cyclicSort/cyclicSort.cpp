using namespace std;

#include <iostream>
#include <vector>

class CyclicSort {
 public:
  static void sort(vector<int> &nums) {
    int i = 0;
    while(i < nums.size()){
        int j = nums[i] - 1;
        if(nums[i] != nums[j]){
            swap(nums, i, j);
        }
        else{
            i++;
        }
    }
 }
  private:
    static void swap(vector<int> & vec, int i, int j){
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }
};

int main(int argc, char *argv[]) {
  vector<int> arr = {3, 1, 5, 4, 2};
  CyclicSort::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;

  arr = vector<int>{2, 6, 4, 3, 1, 5};
  CyclicSort::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;

  arr = vector<int>{1, 5, 6, 4, 3, 2};
  CyclicSort::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;
}