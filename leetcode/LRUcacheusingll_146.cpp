#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class node {
public:
    node* prev;
    int key, value;
    node* next;

    node(int k, int v) {
        key=k;
        value=v;
        prev=next=NULL;
    }
};


class LRUcache {
public:
    int cap;
    unordered_map<int, node*> mp;
    node* head;
    node* tail;

    LRUcache(int capacity) {
        cap=capacity;
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next=tail;
        tail->prev=head;
    }

    void addnode(node* newnode) {
        node* oldnext = head->next;
        newnode->next=tail;
        newnode->prev=head;

        head->next = newnode;
        oldnext->prev=newnode;

    }

    void deletenode(node* oldnode) {
        node* oldprev = oldnode->prev;
        node* oldnext = oldnode->next;
        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    void put(int key, int val) {
        if (mp.find(key) != mp.end()) {
            node* oldnode = mp[key];
            deletenode(oldnode);
            mp.erase(key);
        }

        if (mp.size() == cap) {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        node* newnode = new node(key, val);
        addnode(newnode);
        mp[key]=newnode;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        node* ansnode = mp[key];
        int ans = ansnode->value;

        mp.erase(key);
        deletenode(ansnode);

        addnode(ansnode);
        mp[key] = ansnode;

        return ans;
    }

};

int main() {
    LRUcache cache(2);  // capacity = 2

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;  // returns 1

    cache.put(3, 3);               // evicts key 2
    cout << cache.get(2) << endl;  // returns -1 (not found)

    cache.put(4, 4);               // evicts key 1
    cout << cache.get(1) << endl;  // returns -1 (not found)
    cout << cache.get(3) << endl;  // returns 3
    cout << cache.get(4) << endl;  // returns 4

    return 0;
}

