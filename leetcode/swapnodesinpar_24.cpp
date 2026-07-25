// // BRUTE FORCE
// #include <iostream>
// using namespace std;

// class node {
// public:
//     int data;
//     node* next;

//     node(int val) {
//         data=val;
//         next=NULL;
//     } 
// };

// class list {
// public:
//     node* head;
//     node* tail;

//     list() {
//         head=tail=NULL;
//     }

//     void insert(int val) {
//         node* n=new node(val);
//         if (head==NULL) {
//             head=tail=n;
//         }
//         else {
//             tail->next=n;
//             tail=n;
//         }
//     }

//     void display(node* head) {
//         node* temp=head;
//         while (temp!=NULL) {
//             cout<<temp->data<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }

//     node* swappair(node* head) {
//         if (head==NULL || head->next==NULL) {
//             return head;
//         }
//         node* first = head;
//         node* sec = head->next;
//         node* prev = NULL;

//         while (first!=NULL && sec!=NULL) {
//             node* third = sec->next;

//             sec->next=first;
//             first->next=third;
//             if (prev!=NULL) {
//                 prev->next=sec;
//             }
//             else head=sec;
            
//             prev=first;
//             first=third;
//             if (third!=NULL) sec=third->next;
//             else sec=NULL;
//         }
//         return head;
//     }
// };

// int main() {
//     list l;

//     l.insert(1);
//     l.insert(2);
//     l.insert(3);
//     l.insert(4);
//     l.insert(5);
//     l.insert(6);

//     cout<<"Original List: ";
//     l.display(l.head);

    
//     l.head = l.swappair(l.head);

//     cout<<"After Swapping Pairs: ";
//     l.display(l.head);

//     return 0;
// }

