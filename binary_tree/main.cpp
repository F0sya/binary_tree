#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

static int counter = 0;

class Node {
public:
    string word;
    string translation;
    int count;
    Node* left;
    Node* right;

    Node(string word,string translation) {
        this->word = word;
        this->translation = translation;
        this->count = 0;
        this->counter = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class binary_tree {
public:
    Node* root;

    binary_tree() { root = nullptr; }

    void addNode(string word, string translation) {
        Node* newNode = new Node(word,translation);

        if (root == nullptr) {
            root = newNode;
        }
        else {
            Node* focusNode = root;
            Node* parent;

            while (true) {
                parent = focusNode;

                if (newNode->word < focusNode->word) {
                    focusNode = focusNode->left;
                    if (focusNode == nullptr) {
                        parent->left = newNode;
                        return;
                    }
                }
                else {
                    focusNode = focusNode->right;
                    if (focusNode == nullptr) {
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }
    string findTranslation(string word) {
        Node* focusNode = root;
        
        while (focusNode != nullptr) {
            if (word == focusNode->word) {
                focusNode->count++;
                return focusNode->translation;
            }
            else if (word < focusNode->word) {
                focusNode = focusNode->left;
            }
            else {
                focusNode = focusNode->right;
            }
        }
        return "No occurencies";
    }
    void replaceTranslation(string word, string newTranslation) {
        Node* focusNode = root;
        while (focusNode != nullptr) {
            if (word == focusNode->word) {
                focusNode->translation = newTranslation;
                return;
            }
            else if (word < focusNode->word) {
                focusNode = focusNode->left;
            }
            else {
                focusNode = focusNode->right;
            }
        }
        cout << "No occurencies" << endl;

    }

    void deleteTree(Node* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    ~binary_tree() {
        deleteTree(root);
    }
};

int main() {

    return 0;
}