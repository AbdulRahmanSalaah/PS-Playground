class Trie
{

private:
    struct Node
    {
        char c;
        bool isword;
        Node *children[26];

        Node(char c)
        {
            this->c = c;
            isword = false;
            memset(children, 0, sizeof(children));
        }
    };
    Node *root;

    Node *getNode(string word)
    {
        Node *cur = root;
        for (int i = 0; i < word.size(); i++)
        {
            int IndexOfChar = word[i] - 'a';

            if (cur->children[IndexOfChar] == NULL)
            {
                return NULL;
            }

            cur = cur->children[IndexOfChar];
        }
        return cur;
    }

public:
    Trie()
    {
        root = new Node(' ');
    }

    void insert(string word)
    {
        Node *cur = root;
        for (int i = 0; i < word.size(); i++)
        {
            int IndexOfChar = word[i] - 'a';
            if (cur->children[IndexOfChar] == NULL)
            {
                cur->children[IndexOfChar] = new Node(word[i]);
            }
            cur = cur->children[IndexOfChar];
        }
        cur->isword = true;
    }

    bool search(string word)
    {

        Node *node = getNode(word);
        return node != NULL && node->isword;
    }

    bool startsWith(string prefix)
    {
        Node *node = getNode(prefix);
        return node != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */