# include <iostream>

using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
      data = val;
      next = NULL;
    }
};

void insertAtTail (Node* &head, int val) {
  Node* n = new Node(val);

  if (head == NULL) {
    head = n;
  }

  Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = n;
}

void display(Node* head) {
  Node* temp = head;
  while (temp->next != NULL) {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << "NULL" << end;
}

int main() {

}