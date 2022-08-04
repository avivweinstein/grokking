using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class MedianOfAStream {
 public:
    priority_queue<int> maxHeap; //contains smaller half of numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;     //This is how you create a minheap in c++
    //The priority queue is by default, a max heap. In order to turn it into a min heap, you need the other two parameters.

    void insertNum(int num){
        if(maxHeap.empty() || maxHeap.top() >= num)   {
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian(){
        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top())/2.0;
        }
        else{
            return maxHeap.top();
        }
    }
};

int main(int argc, char *argv[]) {
  MedianOfAStream medianOfAStream;
  medianOfAStream.insertNum(3);
  medianOfAStream.insertNum(1);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(5);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(4);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
}