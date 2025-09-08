// Implement the Tries
#include <bits/stdc++.h>
using namespace std;

class TriesNode
{
public:
    char data;
    TriesNode *children[26];
    bool isTerminal;

    TriesNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

// Insertion in Tries
void insertion(TriesNode *root, string word)
{
    // Base Case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'A';

    TriesNode *child;
    // present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // not Present
        child = new TriesNode(ch);
        root->children[index] = child;
    }
    // Recursive Call
    insertion(child, word.substr(1));
}

// Search in Tries
bool search(TriesNode *root, string word)
{
    // Base Case
    if (word.length() == 0)
    {
        return root->isTerminal;
    }
    char ch = word[0];
    int index = ch - 'A';
    TriesNode *child;
    // present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }
    return search(child, word.substr(1));
};

int main()
{
    TriesNode *root = new TriesNode('\0');
    insertion(root, "ABCD");
    insertion(root, "ABCE");
    insertion(root, "XYZ");
    insertion(root, "XYA");
    insertion(root, "PQR");
    insertion(root, "PQS");
    insertion(root, "PQRS");

    cout << "Present or Not " << search(root, "ABCD") << endl;
    cout << "Present or Not " << search(root, "ABCE") << endl;
    cout << "Present or Not " << search(root, "XYB") << endl;
    return 0;
}