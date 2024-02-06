#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    void inOrderHelper(Node* node) {
        if (node == nullptr) return;
        inOrderHelper(node->left);
        cout << node->data << " ";
        inOrderHelper(node->right);
    }

    void preOrderHelper(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }

    void postOrderHelper(Node* node) {
        if (node == nullptr) return;
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    ~BinaryTree() {
        destroyTree(root);
    }

    void insert(int value) {
        root = insertHelper(root, value);
    }

    Node* insertHelper(Node* node, int value) {
        if (node == nullptr) {
            node = new Node(value);
        } else {
            if (value <= node->data) {
                node->left = insertHelper(node->left, value);
            } else {
                node->right = insertHelper(node->right, value);
            }
        }
        return node;
    }

    void inOrderTraversal() {
        cout << "In-order traversal: ";
        inOrderHelper(root);
        cout << endl;
    }

    void preOrderTraversal() {
        cout << "Pre-order traversal: ";
        preOrderHelper(root);
        cout << endl;
    }

    void postOrderTraversal() {
        cout << "Post-order traversal: ";
        postOrderHelper(root);
        cout << endl;
    }

    void breadthFirstTraversal() {
        if (root == nullptr) return;

        cout << "Breadth-first traversal: ";
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            cout << current->data << " ";
            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
            q.pop();
        }
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.inOrderTraversal();
    tree.preOrderTraversal();
    tree.postOrderTraversal();
    tree.breadthFirstTraversal();

    return 0;
}
