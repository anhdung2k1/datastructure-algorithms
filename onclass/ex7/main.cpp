#include "TreeNode.cpp"
#include <vector>

int main() {
    TreeNode treeNode;
    vector<int> valList = {1, 4, 5, 1, 4, 7, 9, 123, 121,34, 923};
    for (int val : valList) {
        treeNode.insert(val);
    }

    cout << "===== Trước khi xóa giá trị =====" << endl;
    cout << "Print Binary Tree Pre Order" << endl;
    treeNode.printPreOrder();
    
    cout << "\nPrint Binary Tree In Order" << endl;
    treeNode.printInOrder();

    cout << "\nPrint Binary Tree Post Order" << endl;
    treeNode.printPostOrder();

    cout << "\n=====  Sau khi xóa giá trị  =====" << endl;

    vector<int> targetDelVal = {4, 7, 9, 121};
    for (int target : targetDelVal) {
        treeNode.erase(target);
    }

    cout << "Print Binary Tree Pre Order" << endl;
    treeNode.printPreOrder();
    
    cout << "\nPrint Binary Tree In Order" << endl;
    treeNode.printInOrder();

    cout << "\nPrint Binary Tree Post Order" << endl;
    treeNode.printPostOrder();

    return 0;
}