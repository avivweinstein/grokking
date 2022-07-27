 using namespace std;

#include <iostream>
#include <vector>

class FindDuplicate {
 public:
  static int findNumber(vector<int> &n) {
    int idx = 0;

    while(idx < n.size()){
        cout << "n[" << idx << "]: " << n[idx] << endl;
        cout << "idx + 1: " << idx+1 << endl;
        if(n[idx] != idx+1){
            cout << "n[n[" << idx << "]-1]: " << n[idx] << endl;
            if(n[idx] != n[n[idx]-1]){
                cout << "swapping" << endl;
                swap(n,idx,n[idx]-1);
            }
            else{
                cout << "solution found" << endl;
                return n[idx];
            }
        }
        else{
            cout << "index increment" << endl;
            idx++;
        }
        cout << "bottom of while loop" << endl;
    }
    return -1; 
  }

 private:
 static void swap(vector<int> &v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {1, 4, 4, 3, 2};
  cout << FindDuplicate::findNumber(v1) << endl;
  cout << endl;
  v1 = {2, 1, 3, 3, 5, 4};
  cout << FindDuplicate::findNumber(v1) << endl;
cout << endl;
  v1 = {2, 4, 1, 4, 4};
  cout << FindDuplicate::findNumber(v1) << endl;
cout << endl;
  v1 = {1,1,2,3,4};
  cout << FindDuplicate::findNumber(v1) << endl;
  cout << endl;
}