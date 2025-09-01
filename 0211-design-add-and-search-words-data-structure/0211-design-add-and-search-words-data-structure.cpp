class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isword;

        TrieNode() : isword(false) {
            memset(children, 0, sizeof(children)); 
        }
    };

    TrieNode* root;

public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isword = true;
    }

    bool search(const string& word) {
        return dfs(word, 0, root);
    }

private:
    bool dfs(const string& word, int index, TrieNode* node) {
        if (!node) return false;
        if (index == word.size()) return node->isword;

        if (word[index] != '.') {
            int j = word[index] - 'a';
            return dfs(word, index + 1, node->children[j]);
        } else {
            for (TrieNode* child : node->children) {
                if (child && dfs(word, index + 1, child)) {
                    return true;
                }
            }
            return false;
        }
    }
};
