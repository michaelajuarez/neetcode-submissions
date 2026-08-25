class TrieNode {
    public:
    TrieNode* children[26];
    bool end;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        end = false;
    }
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (auto x : word) {
            int i = x - 'a';
            if (cur->children[i] == NULL) {
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (auto x : word) {
            int i = x - 'a';
            if (cur->children[i] == NULL) {
                return false;
            }
            cur = cur->children[i];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto x : prefix) {
            int i = x - 'a';
            if (cur->children[i] == NULL) {
                return false;
            }
            cur = cur->children[i];
        }
        return true;
    }
};
