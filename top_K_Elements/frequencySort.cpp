using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

class FrequencySort {
 public:
  struct valueCompare {
    bool operator()(const pair<char, int> &x, const pair<char, int> &y) {       //bool operator overload
    //takes in two pair objects, made of a char and int
      return y.second > x.second;           //returns true if the second item passed in is larger than the first.
    }
  };

 static string sortCharacterByFrequency(const string &str) {
    unordered_map<char,int> charFreqMap;
    string resultString = "";

    for(int i = 0; i < str.length(); i++){
        // cout << str[i] << endl;
        charFreqMap[str[i]]++;
        // cout << charFreqMap[i] << endl;
        // cout << "Letter: --" << str[i] << "-- has value in map: " << charFreqMap[str[i]] << endl;
    }

    priority_queue<pair<char,int>, vector<pair<char,int>>, valueCompare> maxHeap;

    for(auto entry:charFreqMap){
        maxHeap.push(entry);
    }

    while(!maxHeap.empty()){
        auto cur = maxHeap.top();
        maxHeap.pop();
        for(int i = 0; i < cur.second; i++){
            // cout << cur.first << endl;
            resultString += cur.first;
        }
    }

    return resultString;

  }
};

int main(int argc, char *argv[]) {
  string result = FrequencySort::sortCharacterByFrequency("Programming");
  cout << "Here is the given string after sorting characters by frequency: " << result 
       << endl;

  result = FrequencySort::sortCharacterByFrequency("abcbab");
  cout << "Here is the given string after sorting characters by frequency: " << result 
       << endl;
}
