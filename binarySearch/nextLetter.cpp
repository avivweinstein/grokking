using namespace std;

#include <iostream>
#include <vector>

class NextLetter {
 public:
  static char searchNextLetter(const vector<char>& letters, char key) {
    int start = 0;
    int end = letters.size()-1;
    int vecSize = letters.size();      //I want to keep track of how large the array is

    while(start<=end){
        int mid = start + (end-start)/2;
        if(key < letters[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return letters[start%vecSize];

  }
};

int main(int argc, char* argv[]) {
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'f') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'b') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'm') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'h') << endl;
}