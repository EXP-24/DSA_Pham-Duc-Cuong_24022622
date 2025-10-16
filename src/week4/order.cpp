#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* firstChild;
    Node* nextSibling;
};
Node* createNode(int data) {
        Node* p = new Node();
        p->data = data;
        p->firstChild = nullptr;
        p->nextSibling = nullptr;
        return p;
    }

void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    Node* child = root->firstChild;
    while (child != nullptr) {
        preOrder(child);
        child = child->nextSibling;
    }
}

void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    Node* child = root->firstChild;
    while (child != nullptr) {
        postOrder(child);
        child = child->nextSibling;
    }
    cout << root->data << " ";
}

void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    Node* child = root->firstChild;
    if (child != nullptr) {
        inOrder(child);
    }
    cout << root->data << " ";
    if (child != nullptr) {
        Node* sibling = child->nextSibling;
        while (sibling != nullptr) {
            postOrder(sibling);
            sibling = sibling->nextSibling;
        }
    }
}
int main() {
    Node* root = createNode(1);
    root->firstChild = createNode(2);
    root->firstChild->nextSibling = createNode(3);
    root->firstChild->nextSibling->nextSibling = createNode(4);

    root->firstChild->firstChild = createNode(5);
    root->firstChild->firstChild->nextSibling = createNode(6);

    root->firstChild->nextSibling->nextSibling->firstChild = createNode(7);

    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);

}
