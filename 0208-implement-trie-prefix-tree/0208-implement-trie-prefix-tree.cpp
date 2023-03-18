class TrieNode
{
public:

    bool isEnd;
    TrieNode* children[26];
};

class Trie {

private:
    TrieNode* root;

public:
    Trie() {
        
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode* temp = root;
        for(int i = 0 ; i < word.size() ; i++)
        {
            if(temp->children[word[i] - 'a'] == NULL)
            {
                temp->children[word[i] - 'a'] = new TrieNode();
            }
            
            temp = temp->children[word[i] - 'a'];
        }
        
        temp->isEnd = true;
    }
    
    bool search(string word) {
        
        TrieNode* node = root;
        
        for(int i = 0 ; i < word.size() ; i++)
        {
            if(node->children[word[i] - 'a'] == NULL)
            {
                return false;
            }
            node = node->children[word[i] - 'a'];
        }
        
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* node = root;
        
        for(int i = 0 ; i < prefix.size() ; i++)
        {
            if(node->children[prefix[i] - 'a'] == NULL)
            {
                return false;
            }
            node = node->children[prefix[i] - 'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */