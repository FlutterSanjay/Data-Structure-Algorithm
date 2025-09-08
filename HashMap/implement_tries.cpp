// implementation of tries
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

// Insertion
void Insertion(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'A';

    TrieNode *child;

    // Present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // Not Present
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    Insertion(child, word.substr(1));
}

// Searching

bool Searching(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'A';
    TrieNode *child;
    // Present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // Not Present
        return false;
    }
    return Searching(child, word.substr(1));
}

bool deletion(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = false;
        return true;
    }

    char ch = word[0];
    int index = ch - 'A';
    TrieNode *child;
    // Present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // Not present
        return false;
    }
    return deletion(child, word.substr(1));
}
int main()
{
    TrieNode *root = new TrieNode('\0');
    Insertion(root, "ABCD");
    cout << Searching(root, "ABCD") << endl;
    cout << Searching(root, "ABCE") << endl;
    cout << "Deletion Sucess : " << deletion(root, "ABCD") << endl;
    cout << Searching(root, "ABCD") << endl;
    cout << Searching(root, "ABCE") << endl;

    return 0;
}