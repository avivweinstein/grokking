using namespace std;

#include <iostream>
#include <string>
#include <vector>

class FindCorruptNums {
 public:
  static vector<int> findNumbers(vector<int> &n) {
    int j = 0;

    while(j < n.size()){
        if(n[j] != n[n[j]-1]){
            swap(n,j, n[j]-1);
        }
        else{
            j++;
        }
    }


    vector<int> res;

    for(int i = 0; i < n.size(); i++){
        if(n[i] != i+1){
            res.push_back(n[i]);
            res.push_back(i+1);
            break;
        }
    }

    return res;
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {3, 1, 2, 5, 2};
  vector<int> nums = FindCorruptNums::findNumbers(v1);
  cout << nums[0] << ", " << nums[1] << endl;

  v1 = {3, 1, 2, 3, 6, 4};
  nums = FindCorruptNums::findNumbers(v1);
  cout << nums[0] << ", " << nums[1] << endl;
}