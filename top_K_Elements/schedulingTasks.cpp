using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TaskScheduler {
 public:
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return y.second > x.second;
    }
  };

  static int scheduleTasks(vector<char> &tasks, int k) {
    int result = 0;

    unordered_map<char,int> map;

    for(int i = 0; i < tasks.size(); i++){      //create a hash map of pairs of the chars in the array and how often they occur
        map[tasks[i]]++;
    }

    priority_queue<pair<char,int>, vector<pair<char,int>>, valueCompare> maxHeap;
    for(auto entry : map){                      //Create a max heap that stores all the pairs of chars and ints/their frequencies
        maxHeap.push(entry);
    }

    while(!maxHeap.empty()){                //keep going while we have values which are in our max heap. We keep adding values back to the max heap until we are done.
        queue<pair<char,int>> q;            //store the values we have already seen
        int n = k+1;                        //k+1, as we are 1-indexed.
        for(; n > 0 && !maxHeap.empty(); n--){      //we can see how far we get without needing an idle, by indexing down n.
        //keep going until n = 0 OR we have no more operations to perform. This means that we need idle operations
            auto current = maxHeap.top();       //get most frequenct element.
            maxHeap.pop();
            result++;                           //indicate that a cycle has passed
            if(current.second > 1){             //if there are still pages/operations of this type to perform, add it to te queue.
                current.second--;
                q.push(current);
            }
        }

        for(int i = 0; i < q.size(); i++){      //add everything in the queue back to the pq.
            maxHeap.push(q.front());
            q.pop();
        }

        if(!maxHeap.empty()){               //if the pq is NOT empty, meaning we needed some idel states, add that to our total cycle count.
            result += n;
        }
    }
    //we break out when out pq is totally empty and return our result;
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<char> tasks = {'a', 'a', 'a', 'b', 'c', 'c'};
  cout << "Minimum intervals needed to execute all tasks: "
       << TaskScheduler::scheduleTasks(tasks, 2) << endl;

  tasks = vector<char>{'a', 'b', 'a'};
  cout << "Minimum intervals needed to execute all tasks: "
       << TaskScheduler::scheduleTasks(tasks, 3) << endl;
}