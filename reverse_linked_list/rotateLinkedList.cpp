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

class RotateList {
 public:
  static ListNode *rotate(ListNode *head, int rotations) {
    if(head == nullptr){
        return head;
    }

    ListNode *lastNode = head;
    int listLength = 1;
    while(lastNode->next != nullptr){
        lastNode = lastNode->next;
        listLength++;
    }

    lastNode->next = head;

    rotations = rotations % listLength;
    // rotations %= listLength;

    int skipLength = listLength - rotations;

    ListNode* lastNodeOfRotated= head;

    for(int i = 0; i < skipLength-1; i++){
        lastNodeOfRotated = lastNodeOfRotated->next;
    }

    head = lastNodeOfRotated->next;
    lastNodeOfRotated->next = nullptr;


    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  ListNode *result = RotateList::rotate(head, 3);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}