#include <iostream>
using namespace std;

class TreeNode {
    private:
        struct Node {
            int value;
            int count; // Đếm số lần xuất hiện của giá trị
            Node* left;
            Node* right;

            Node(int value) : value(value), count(1), left(nullptr), right(nullptr) {}
        };

        Node* root;

        // Chèn vào cây nhị phân
        Node* insert(Node* node, int value) {
            if (!node) {
                return new Node(value);
            }
            if (value < node->value) {
                node->left = insert(node->left, value);
            } else if (value > node->value) {
                node->right = insert(node->right, value);
            } else {
                // Tăng bộ đếm nếu giá trị đã tồn tại
                node->count++;
            }
            return node;
        }

        // Xóa một phần tử ra khỏi cây nhị phân
        Node* erase(Node* node, int value) {
            if (!node) {
                return nullptr;
            }
            if (value < node->value) {
                node->left = erase(node->left, value);
            }
            else if (value > node->value) {
                node->right = erase(node->right, value);
            }
            else {
                if (node->count > 1) {
                    // Giảm bộ đếm nếu còn nhiều hơn một lần xuất hiện
                    node->count--;
                    return node;
                }
                // Xóa node nếu chỉ xuất hiện một lần
                if (!node->left) {
                    Node* rightNode = node->right;
                    delete node;
                    return rightNode;
                } else if (!node->right) {
                    Node* leftNode = node->left;
                    delete node;
                    return leftNode;
                } else {
                    Node* minNode = node->right;
                    while(minNode->left) {
                        minNode = minNode->left;
                    }
                    node->value = minNode->value;
                    node->count = minNode->count;
                    minNode->count = 1; // Đảm bảo minNode sẽ bị xóa
                    node->right = erase(node->right, minNode->value);
                }
            }
            return node;
        }

        void clear(Node* node) {
            if(node) {
                clear(node->left);
                clear(node->right);
                delete node;
            }
        }

        void preorder(Node* node) {
            if (!node) return;
            for (int i = 0; i < node->count; i++) {
                cout << node->value << " ";
            }
            preorder(node->left);
            preorder(node->right);
        }

        void inorder(Node* node) {
            if (!node) return;
            inorder(node->left);
            for (int i = 0; i < node->count; i++) {
                cout << node->value << " ";
            }
            inorder(node->right);
        }

        void postorder(Node* node) {
            if (!node) return;
            postorder(node->left);
            postorder(node->right);
            for (int i = 0; i < node->count; i++) {
                cout << node->value << " ";
            }
        }

    public:
        // Constructor
        TreeNode() : root(nullptr) {}

        // Deconstructor
        ~TreeNode() {
            clear(root);
        }

        void insert(int value) {
            root = insert(root, value);
        }

        void erase(int value) {
            root = erase(root, value);
        }

        void printPreOrder() {
            preorder(root);
            cout << endl;
        }

        void printInOrder() {
            inorder(root);
            cout << endl;
        }

        void printPostOrder() {
            postorder(root);
            cout << endl;
        }
};
