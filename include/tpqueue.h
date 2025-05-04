// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template <typename T>
class TPQueue {
 private:
  struct node {
  T data;
  node *next;
  };
  node *head;

 public:
  TPQueue() : head(nullptr) {}
  ~TPQueue() {
  while (head) {
      node *temp = head;
      head = head->next;
      delete temp;
    }
  }
  bool isEmpty() { return head == nullptr;
  }
  void push(const T &item) {
     if (isEmpty() || item.prior > head->data.prior) {
       node *temp = head;
       head = new node;
       head->data = item;
       head->next = temp;
       return;
     }
     node *temp = head;
     while (temp->next && temp->next->data.prior >= item.prior) {
       temp = temp->next;
     }
     node *next_node = temp->next;
     temp->next = new node;
     temp = temp->next;
     temp->data = item;
     temp->next = next_node;
  }
  T pop() {
   if (isEmpty()) throw std::string("Empty!");
     T item = head->data;
    node *temp = head;
     head = head->next;
    delete temp;
     return item;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
