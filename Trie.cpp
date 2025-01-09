#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Trie {
private:
    map<char, Trie*> next = {};
    bool isWord = false;

public:
    Trie() {}

    void insert(string word) {
        Trie *node = this;
        for (char ch : word) {
            if (!node->next.count(ch)) {
                node->next[ch] = new Trie();
            }
            node = node->next[ch];
        }
        node->isWord = true;
    }

    bool search(string word) {
        Trie *node = this;
        for (char ch : word) {
            if (!node->next.count(ch)) {
                return false;
            }
            node = node->next[ch];
        }
        return node->isWord;
    }

    bool startsWith(string prefix) {
        Trie *node = this;
        for (char ch : prefix) {
            if (!node->next.count(ch)) {
                return false;
            }
            node = node->next[ch];
        }
        return true;
    }

    void collectWords(Trie* node, string prefix, vector<string>& result) {
        if (node->isWord) {
            result.push_back(prefix);
        }
        for (auto &[ch, child] : node->next) {
            collectWords(child, prefix + ch, result);
        }
    }

    vector<string> getWordsWithPrefix(string prefix) {
        Trie *node = this;
        for (char ch : prefix) {
            if (!node->next.count(ch)) {
                return {}; // No words with this prefix
            }
            node = node->next[ch];
        }
        vector<string> result;
        collectWords(node, prefix, result);
        return result;
    }
};

int main() {
    Trie trie;
    int choice;
    string input;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert a word\n";
        cout << "2. Search for a word\n";
        cout << "3. Check if prefix exists\n";
        cout << "4. Get words with a prefix\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter word to insert: ";
                cin >> input;
                trie.insert(input);
                cout << "Word inserted.\n";
                break;

            case 2:
                cout << "Enter word to search: ";
                cin >> input;
                if (trie.search(input)) {
                    cout << "Word found.\n";
                } else {
                    cout << "Word not found.\n";
                }
                break;

            case 3:
                cout << "Enter prefix to check: ";
                cin >> input;
                if (trie.startsWith(input)) {
                    cout << "Prefix exists.\n";
                } else {
                    cout << "Prefix does not exist.\n";
                }
                break;

            case 4:
                cout << "Enter prefix to get words: ";
                cin >> input;
                {
                    vector<string> words = trie.getWordsWithPrefix(input);
                    if (!words.empty()) {
                        cout << "Words with prefix '" << input << "': ";
                        for (const string &word : words) {
                            cout << word << " ";
                        }
                        cout << "\n";
                    } else {
                        cout << "No words found with the given prefix.\n";
                    }
                }
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
