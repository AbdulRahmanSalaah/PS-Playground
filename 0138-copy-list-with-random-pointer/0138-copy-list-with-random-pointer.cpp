/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      if (head == NULL) return NULL;

        unordered_map<Node*,Node*> mp;
        mp[NULL]=NULL;
        Node* cur = head;
        while(cur!=NULL)
        {
            Node* copy = new Node(cur->val);
            mp[cur]=copy;
            cur = cur->next;
        }

        cur = head;
        while(cur!=NULL)
        {
            Node* copy = mp[cur];
            copy->next =mp[cur->next];
            copy->random = mp[cur->random];
            cur= cur->next;

        }
        return mp[head];
        
    }
};