//
// Created by Aaron Rahman on 3/31/24.
//
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <initializer_list>

using namespace std;

struct Node {
    Node *next;
    Node *prev;
    int val;
    int key;
};

class LRUCache {
public:
    LRUCache(int capacity) : size(capacity), listSize(0) {
        head = new Node{nullptr, nullptr, -1, -1};
        tail = new Node{nullptr, nullptr, -1, -1};
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node *curr = head;
        while (curr != nullptr) {
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
    }

    int get(int key) {
        if (map.find(key) != map.end()) {
            Node *node = map[key];
            on_used(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            map[key]->val = value;
            on_used(map[key]);
        } else {
            listSize++;
            Node* new_node = new Node{nullptr, nullptr, value, key};
            map[key] = new_node;
            move_to_end(new_node);
        }

        if (listSize > size) {
            Node *first = head->next;
            head->next = first->next;
            first->next->prev = head;
            map.erase(first->key);
            delete first;
            listSize--;
        }
    }

private:
    Node *head;
    Node *tail;
    unordered_map<int, Node *> map;
    int size;
    int listSize;

    void on_used(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        move_to_end(node);
    }

    void move_to_end(Node *node) {
        tail->prev->next = node;
        node->next = tail;
        node->prev = tail->prev;
        tail->prev = node;
    }
};

int main() {
    LRUCache lru_cache(2);
    vector<string> instructions = {"put", "put", "get", "put", "get", "put", "get", "get", "get"};
    vector<vector<int>> args = { {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4}};
    //["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
    //[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    for(int i = 0; i < instructions.size(); i++) {
        if(instructions[i] == "put") {
            lru_cache.put(args[i][0], args[i][1]);
        } else {
            lru_cache.get(args[i][0]);
        }
    }
}