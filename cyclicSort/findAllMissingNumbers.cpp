using namespace std;

#include <iostream>
#include <vector>

class AllMissingNumbers {
 public:
  static vector<int> findNumbers(vector<int> &nums) {

    int idx = 0;
    // cout << "Initial: ";
    // printVec(nums);
    // cout << endl;

    while(idx < nums.size()){
        if(nums[idx] != nums[nums[idx] - 1]){
            swap(nums, idx, nums[idx]-1);
        }
        else{
            // cout << "increment" << endl;
            idx++;
        }
        // cout << "idx: " << idx << endl;
        // printVec(nums);
        // cout << endl;
        // cout << endl;
    }

    vector<int> result;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != i+1){
            result.push_back(i+1);
        }
    }

    return result;
  }



private:
    static void swap(vector<int> &vec, int a, int b){
        int temp = vec[a];
        vec[a] = vec[b];
        vec[b] = temp;
    }

    static void printVec(vector<int> &v){
        for(int i = 0; i < v.size(); i++){
            cout << v[i];
            
        }
    }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {2, 3, 1, 8, 2, 3, 5, 1};
  vector<int> missing = AllMissingNumbers::findNumbers(v1);
  cout << "Missing numbers: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {2, 4, 1, 2};
  missing = AllMissingNumbers::findNumbers(v1);
  cout << "Missing numbers: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {2, 3, 2, 1};
  missing = AllMissingNumbers::findNumbers(v1);
  cout << "Missing numbers: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << endl;
}