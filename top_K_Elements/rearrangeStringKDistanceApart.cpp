using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class RearrangeStringKDistanceApart {
 public:
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return y.second > x.second;
    }
  };

  static string reorganizeString(const string &str, int k) {
    if (k <= 1){
        return str;
    }

    string result;

    unordered_map<char,int> map;          
    
    for(int i = 0; i < str.length(); i++){      //add all of the chrs to a hashmap.
        map[str[i]]++;
    }

    // priority_queue<pair<char,int>> maxHeap;
    priority_queue<pair<char,int>, vector<pair<char,int>>, valueCompare> maxHeap;

    for(auto entry : map){          //add all the values of the hashmap into the priority queue
        maxHeap.push(entry);
    }

    queue<pair<char,int>> q; //this will keep track of the values we current have in our string.
    //when our queue gets to a certain size, we will readd the value at the front of the hqueue
    //to our max heap.

    while(!maxHeap.empty()){
        auto currentEntry = maxHeap.top();
        maxHeap.pop();
        result += currentEntry.first;

        currentEntry.second--;
        q.push(currentEntry);

        if(q.size() == k){
            auto entryToReAdd = q.front();
            q.pop();
            if(entryToReAdd.second > 0){
                maxHeap.push(entryToReAdd);
            }
        }
    }

    if(result.length() == str.length()){
        return result;
    }
    
    return "";
  }
};

int main(int argc, char *argv[]) {
  cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("Programming", 3) << endl;
  cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("mmpp", 2) << endl;
  cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("aab", 2) << endl;
  cout << "Reorganized string: " 
       << RearrangeStringKDistanceApart::reorganizeString("aappa", 3) << endl;
}