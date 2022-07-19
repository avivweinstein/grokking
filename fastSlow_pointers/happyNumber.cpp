using namespace std;
#include <iostream>

class HappyNumber {
 public:
  static bool find(int num) {
    bool result = false;
    int slow = num;
    int fast = num;

    do{
        slow = findHappySquare(slow);
        fast = findHappySquare(findHappySquare(fast));
    } while(slow != fast);

    // if((slow == 1) && (fast == 1)){
    //     // cout << "num: " << num << endl;
    //     result = true;
    // }

    if(slow == 1){
        result = true;
    }

    return result;
  }

private:
    static int findHappySquare(int n){
        int result = 0;
        int digit = 0;

        while (n > 0){
            digit = n % 10;
            result += digit*digit;
            n = n/10;
        }
        return result;
    }

};

int main(int argc, char* argv[]) {
  cout << HappyNumber::find(23) << endl;
  cout << HappyNumber::find(12) << endl;
}