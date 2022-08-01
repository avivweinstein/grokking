using namespace std;

#include <iostream>
#include <string>

class BackspaceCompare {
 public:
  static bool compare(const string &str1, const string &str2) {
    string nStr1, nStr2;

    for(int i = 0; i < str1.length(); i++){
        if(str1[i] == '#'){             //if we get a backspace char
            if(!nStr1.empty()){            // and if the string is not empty
                nStr1.pop_back();           //remove a char
            }
            else{                           //otherwise, do nothing
                // cout << "empty nStr1" << endl;
            }
        }
        else{
            nStr1 += str1[i];
        }
    }
    // cout << "nStr1: " << nStr1 << endl;

        for(int i = 0; i < str2.length(); i++){
        if(str2[i] == '#'){             //if we get a backspace char
            if(!nStr2.empty()){            // and if the string is not empty
                nStr2.pop_back();           //remove a char
            }
            else{                           //otherwise, do nothing
                // cout << "empty nStr2" << endl;
            }
        }
        else{
            nStr2 += str2[i];
        }
    }
    // cout << "nStr2: " << nStr2 << endl;

    if(nStr1.compare(nStr2) == 0){
        // cout << "Returning True" << endl;
        return true;
    }

    // cout << "Returning False" << endl;
    return false;
  }
};

int main(int argc, char *argv[]) {
  cout << BackspaceCompare::compare("xy#z", "xzz#") << endl;
  cout << BackspaceCompare::compare("xy#z", "xyz#") << endl;
  cout << BackspaceCompare::compare("xp#", "xyz##") << endl;
  cout << BackspaceCompare::compare("xywrrmp", "xywrrmu#p") << endl;
}