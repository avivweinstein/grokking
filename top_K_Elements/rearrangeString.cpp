using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class RearrangeString {
 public:
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return y.second > x.second;
    }
  };

  static string rearrangeString(const string &str) {
    unordered_map<char, int> map;

    for(int i = 0; i < str.length(); i++){      //find frequencies of all characters in our string.
        map[str[i]]++;
    }

    //push all values to maxheap.
    priority_queue<pair<char,int>,vector<pair<char,int>>;





 
  }
};

int main(int argc, char *argv[]) {
  cout << "Rearranged string: " << RearrangeString::rearrangeString("aappp") << endl;
  cout << "Rearranged string: " << RearrangeString::rearrangeString("Programming") 
       << endl;
  cout << "Rearranged string: " << RearrangeString::rearrangeString("aapa") << endl;
}