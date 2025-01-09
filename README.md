# Trie

## Description
A **Trie** (pronounced "try"), also known as a prefix tree, is a specialized tree data structure that is primarily used to store strings. It organizes strings in a way that allows for efficient searching, insertion, and prefix matching operations. Each node in a Trie represents a single character, and the path from the root to a node represents a prefix of the stored strings. This makes Tries particularly useful for applications like autocomplete, spell checking, and dictionary lookups.

### Key Characteristics of Trie:
- **Efficient Prefix Matching**: Tries enable fast lookups for words sharing a common prefix.
- **Space Optimization**: Common prefixes are stored only once, which reduces redundant storage.
- **Alphabet-Based Nodes**: Each node has links corresponding to characters in the alphabet.
- **Dynamic Storage**: Tries can grow dynamically as new words are added.

---

## Features
The implemented Trie in this project provides the following functionalities:

1. **Insert Words**:
   - Add a word to the Trie.
   - Each character of the word is inserted level by level into the tree structure.
   - At the end of the word, a flag (`isWord`) is marked as `true` to indicate that the sequence of characters forms a complete word.

2. **Search for Words**:
   - Check if a specific word exists in the Trie.
   - The search traverses the Trie character by character. If the traversal reaches the end of the word and the `isWord` flag is `true`, the word is considered found.

3. **Check Prefix Existence**:
   - Determine whether any word in the Trie starts with a given prefix.
   - The traversal stops as soon as the prefix is either matched or determined to be missing.

4. **Retrieve Words by Prefix**:
   - Find and list all words in the Trie that share a common prefix.
   - The method traverses to the node corresponding to the prefix, then recursively collects all valid words from that point.

---

## How to Use
### Compilation and Execution
1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/shakuntala123/Trie.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Trie
   ```
3. Compile the program using g++:
   ```bash
   g++ -o Trie Trie.cpp
   ```
4. Run the program:
   ```bash
   ./Trie
   ```

---

## Program Menu
The program provides the following options:

1. **Insert a word**: Add a new word to the Trie.
2. **Search for a word**: Check if a specific word exists in the Trie.
3. **Check if prefix exists**: Verify whether a given prefix exists in the Trie.
4. **Get words with a prefix**: Retrieve all words in the Trie that start with a given prefix.
5. **Exit**: Terminate the program.

---

## Example Usage
Here is an example of how the program works:

### Input:
```
1. Insert a word
Enter word to insert: apple

2. Insert a word
Enter word to insert: app

3. Check if prefix exists
Enter prefix to check: app

4. Get words with a prefix
Enter prefix to get words: app

5. Search for a word
Enter word to search: apple
```

### Output:
```
Word inserted.
Word inserted.
Prefix exists.
Words with prefix 'app': app apple
Word found.
```

---

## Author
Shakuntala Kumari

