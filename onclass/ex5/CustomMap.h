#include <iostream>

class CustomMap {
private:
    struct TreeNode {
        int key;
        int value;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int k, int v)
            : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    // Phương thức đệ quy để chèn vào cây nhị phân
    TreeNode* insert(TreeNode* node, int key, int value) {
        if (!node) {
            return new TreeNode(key, value);
        }
        if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        } else {
            // Khóa đã tồn tại, cập nhật giá trị
            node->value = value;
        }
        return node;
    }

    // Phương thức đệ quy để tìm kiếm trong cây nhị phân
    int find(TreeNode* node, int key) const {
        if (!node) {
            return -1; // Khóa không được tìm thấy
        }
        if (key < node->key) {
            return find(node->left, key);
        } else if (key > node->key) {
            return find(node->right, key);
        } else {
            return node->value; // Trả về giá trị nếu khóa được tìm thấy
        }
    }
    // Phương thức đệ quy để xóa một phần tử khỏi cây nhị phân
    TreeNode* erase(TreeNode* node, int key) {
        if (!node) {
            return nullptr;
        }
        if (key < node->key) {
            node->left = erase(node->left, key);
        } else if (key > node->key) {
            node->right = erase(node->right, key);
        } else {
            // Đã tìm thấy nút cần xóa
            if (!node->left) {
                TreeNode* rightNode = node->right;
                delete node;
                return rightNode;
            } else if (!node->right) {
                TreeNode* leftNode = node->left;
                delete node;
                return leftNode;
            } else {
                // Tìm nút nhỏ nhất bên phải để thay thế
                TreeNode* minNode = node->right;
                while (minNode->left) {
                    minNode = minNode->left;
                }
                // Chuyển giá trị của nút nhỏ nhất bên phải
                node->key = minNode->key;
                node->value = minNode->value;
                // Xóa nút nhỏ nhất bên phải
                node->right = erase(node->right, minNode->key);
            }
        }
        return node;
    }

    // Phương thức đệ quy để giải phóng bộ nhớ của cây nhị phân
    void clear(TreeNode* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    // Phương thức đệ quy để in các phần tử trong cây theo thứ tự
    void printInOrder(TreeNode* node) const {
        if (node) {
            printInOrder(node->left);
            std::cout << "Key: " << node->key << ", Value: " << node->value << std::endl;
            printInOrder(node->right);
        }
    }

public:
    // Constructor
    CustomMap() : root(nullptr) {}

    // Destructor
    ~CustomMap() {
        clear(root);
    }

    // Phương thức chèn một cặp khóa-giá trị
    void insert(int key, int value) {
        root = insert(root, key, value);
    }

    // Phương thức tìm kiếm giá trị với khóa
    int find(int key) const {
        return find(root, key);
    }

    // Phương thức xóa một phần tử với khóa
    void erase(int key) {
        root = erase(root, key);
    }

    // Phương thức in toàn bộ map theo thứ tự
    void printMap() const {
        printInOrder(root);
    }
};