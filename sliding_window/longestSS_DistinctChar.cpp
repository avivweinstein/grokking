using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    int left = 0;
    int maxLength = 0;
    unordered_map<char, int> charIdxMap;

    for(int right = 0; right < str.length(); right++){
         char temp = str[right];

         if(charIdxMap.find(temp) == charIdxMap.end()){
            charIdxMap.insert(str[right]);
         }
         else{
            
         }


         
         
         
         
         
         
         maxLength = max(maxLength, right-left+1);
    }



   

    return maxLength;
  }
};

int main(int argc, char* argv[]) {
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("aabccbb")
       << endl;
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abbbb") 
       << endl;
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abccde") 
       << endl;
}