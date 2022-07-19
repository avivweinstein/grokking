using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

/*
1. Find midpoint of LL
2. Revere LL
3. Compare front half of LL to back half.
*/

// class PalindromicLinkedList {
 public:
  static bool isPalindrome(ListNode *head) {

    ListNode *headSecondHalf = findMid(head);

    while(head != nullptr && headSecondHalf != nullptr){
        if(head->value != headSecondHalf->value){
            return false;
        }
        head = head->next;
        headSecondHalf = headSecondHalf->next;
    }

    if (head == nullptr || headSecondHalf == nullptr) {  // if both halves match
      return true;
    }
  
    return false;
    }

private:
    static ListNode *findMid (ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
    }
        return slow;
    }
    static ListNode *reverseLL(ListNode *current){
        ListNode *prev = nullptr;

        while(current != nullptr){
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;

  head->next->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;
}