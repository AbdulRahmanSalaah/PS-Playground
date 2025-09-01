class TrieNode {
public:
    vector<TrieNode*> children;
    bool isword;
    TrieNode() {
        children = vector<TrieNode*>(26, nullptr);
        isword = false;
    }
};
class WordDictionary {

public:
    TrieNode* root;

    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->children[i] == NULL) {
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->isword = true;
    }

    bool search(string word) { return dfs(word, 0, root); }

private:
    bool dfs(string word, int i, TrieNode* root) {
        if (!root)
            return false;
        if (i == word.size())
            return root->isword;

        if (word[i] != '.') {
            int j = word[i] - 'a';
            return dfs(word, i + 1, root->children[j]);
        } else {
            for (auto child : root->children) {
                if (child && dfs(word, i + 1, child)) {
                    return true;
                }
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */