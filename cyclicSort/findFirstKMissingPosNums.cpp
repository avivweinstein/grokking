using namespace std;

#include <iostream>
#include <unordered_set>
#include <vector>

class FirstKMissingPositive {
 public:
  static vector<int> findNumbers(vector<int> &nums, int k) {
    int i = 0;
    while(i < nums.size()){
        if(nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i]-1]){
            swap(nums, i, nums[i]-1);
        }
        else{
            i++;
        }
    }

    vector<int> res;
    unordered_set<int> extraNums;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != i+1){
            res.push_back(i+1);
            extraNums.insert(nums[i]);
        }
    }

    for(int i = 1; res.size() < k; i++){
        int candidateNumber = i + nums.size();
      // ignore if the array contains the candidate number
      if (extraNums.find(candidateNumber) == extraNums.end()) {
        res.push_back(candidateNumber);
      }
    }

    return res;
  }

 private:
 static void swap(vector<int> &v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
 }

};

int main(int argc, char *argv[]) {
  vector<int> v1 = {3, -1, 4, 5, 5};
  vector<int> missingNumbers = FirstKMissingPositive::findNumbers(v1, 3);
  cout << "Missing numbers: ";
  for (auto num : missingNumbers) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {2, 3, 4};
  missingNumbers = FirstKMissingPositive::findNumbers(v1, 3);
  cout << "Missing numbers: ";
  for (auto num : missingNumbers) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {-2, -3, 4};
  missingNumbers = FirstKMissingPositive::findNumbers(v1, 2);
  cout << "Missing numbers: ";
  for (auto num : missingNumbers) {
    cout << num << " ";
  }
  cout << endl;
}
