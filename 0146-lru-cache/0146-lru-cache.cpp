#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};
class LRUCache
{
private:
    int capacity;
    unordered_map<int, Node *> cache;
    Node *dummyhead;
    Node *dummytail;
    void insertNode(Node *node)
    {
        Node *lastnode = dummytail->prev;
        lastnode->next = node;
        node->prev = lastnode;
        node->next = dummytail;
        dummytail->prev = node;
    }
    void deleteNode(Node *node)
    {
        Node *prevnode = node->prev;
        Node *nextnode = node->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }

public:
    LRUCache(int capacity)
    {

        this->capacity = capacity;
        dummyhead = new Node(0, 0);
        dummytail = new Node(0, 0);
        dummyhead->next = dummytail;
        dummytail->prev = dummyhead;
        cache.clear();
    }

    int get(int key)
    {

        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            deleteNode(node);
            insertNode(node); // delete the node and insert it at the end to mark it as recently used
            return node->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            deleteNode(cache[key]);
        }

        Node *newNode = new Node(key, value);
        cache[key] = newNode;
        insertNode(newNode); // insert the  node at the end to mark it as recently used
        if (cache.size() > capacity)
        {
            Node *lru = dummyhead->next; // the least recently used node is the one after dummyhead
            deleteNode(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */