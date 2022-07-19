using namespace std;

#include <iostream>
#include <vector>

class DutchFlag {
 public:
  static void sort(vector<int> &arr) {
      int lowPtr = 0;
      int highPtr = arr.size()-1;

    //   cout << "highPtr: " << highPtr << endl;

      for(int i = 0; i <= highPtr;){
        //   cout << "lowPtr: " << lowPtr << endl;
        //   cout << "highPtr: " << highPtr << endl;
        //   cout << "i: " << i << endl;
        //   cout << "arr[" << i << "]: " <<  arr[i] << endl;
        //   cout << endl;

          if(arr[i] == 1){
            //   cout << "encountered 1" << endl;
            //   cout << endl;
              i++;
          }
          else if(arr[i] == 0){
            //   cout << "encountered 0" << endl;
            //   cout << endl;
              swap(arr, i, lowPtr);
              lowPtr++;
              i++;

          }
          else if(arr[i] == 2){
            //   cout << "encountered 2" << endl;
            //   cout << endl;
              swap(arr, i, highPtr);
              highPtr--;
          }
      }   
  }
 private:
    static void swap(vector<int> &myVec, int a, int b){     //helper function to swap values in vector
        int temp = myVec[a];
        myVec[a] = myVec[b];
        myVec[b] = temp;
    }

};

int main(int argc, char *argv[]) {
  vector<int> arr = {1, 0, 2, 1, 0};
  DutchFlag::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;
//   cout << endl;
//   cout << endl;
//   cout << endl;
  arr = vector<int>{2, 2, 0, 1, 2, 0};
  DutchFlag::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
}
  cout << endl;
}