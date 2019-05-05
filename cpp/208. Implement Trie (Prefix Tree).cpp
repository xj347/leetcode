class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> children;
    TrieNode()
    {
        isWord = false;
        children = vector<TrieNode*>(26, NULL);
    }
    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
            delete children[i];
    }
};

class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); i++)
        {
            int pos = word[i] - 'a';
            if (cur->children[pos] == NULL)
                cur->children[pos] = new TrieNode();
            cur = cur->children[pos];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); i++)
        {
            int pos = word[i] - 'a';
            if (cur->children[pos] == NULL)
                return false;
            cur = cur->children[pos];
        }
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            int pos = prefix[i] - 'a';
            if (cur->children[pos] == NULL)
                return false;
            cur = cur->children[pos];
        }
        return true;
    }
};