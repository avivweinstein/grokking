using namespace std;

#include <iostream>
#include <math.h>

class CalculateComplement {
public:
  static int bitwiseComplement(int num) {
    int complement;

    int mask = 1;
    int numBits = (int)log2(num)+1;
    // cout << "numBits: " << numBits << endl;
    // cout << "initial mask: " << mask << endl;

    for(int i = 0; i < numBits; i++){
        mask = mask << 1;
        // cout << "mask: " << mask << endl;
    }
    mask = mask-1;
    // cout << "mask: " << mask << endl;
    complement = num ^ mask;
    return complement;
  }
};

int main(int argc, char *argv[]) {
//   cout << endl;
//   cout << endl;
  cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(8) << endl;
  cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(10) << endl;
//   cout << endl;
}