/* 
Yan Hong
yhong5@uci.edu

Question 2:
Implement insert and delete in a tri-nary tree. A tri-nary tree is much like a 
binary tree but with three child nodes for each parent instead of two -- with 
the left node being values less than the parent, the right node values greater 
than the parent, and the middle nodes values equal to the parent
*/

#include <iostream>
#include <cassert>

using namespace std;
ostream& out=std::cout;

#define _DEBUG

template <typename T>
class TrinaryTree{
private:
    struct TrinaryNode{
        T key;
        TrinaryNode *left;
        TrinaryNode *middle;
        TrinaryNode *right;
    };
    TrinaryNode *root;
    void insert(TrinaryNode * &root, T key);
    void preOrderTraversal(const TrinaryNode *root);
    void makeEmpty(TrinaryNode *root);
public:
    TrinaryTree(): root(NULL){};
    ~TrinaryTree(){
       makeEmpty(root);
    };
    void insert(T key); // insert type T value
    void print();       // print the tri-ary tree in pre-order traversal
};

template <typename T>
void TrinaryTree<T>::makeEmpty(TrinaryNode *root){
    if (root != NULL){
        makeEmpty(root->left);
        makeEmpty(root->middle);
        makeEmpty(root->right);
        #ifdef _DEBUG
        cout << "delete "<< root->key<<endl;
        #endif
        delete root;
    }
    root = NULL;
}

template <typename T>
void TrinaryTree<T>::insert(T key){
    insert(root, key);
}

template <typename T>
void TrinaryTree<T>::print(){
    preOrderTraversal(root);
    out<<endl;
}

template <typename T>
void TrinaryTree<T>::insert(TrinaryNode * &root, T key){
    if (root == NULL) {     // create root node
        root = new TrinaryNode();
        root->key = key;
        root->left = NULL; root->middle = NULL; root->right = NULL;
    } else if (key < root->key) {
        insert(root->left, key);
    } else if (key == root->key) {
        insert(root->middle, key);
    } else {
        insert(root->right, key);
    }
}

template <typename T>
void TrinaryTree<T>::preOrderTraversal(const TrinaryNode *root){
    if (root != NULL){
        out << "(" << root->key;
        preOrderTraversal(root->left);
        preOrderTraversal(root->middle);
        preOrderTraversal(root->right);
        out << ")";
    }
}

int test(){
    // functional testing
    int nodes[7] = {5, 4, 9, 5, 7, 2, 2};
    // test deconstructor
    {
    TrinaryTree<int> intTree;
    for (int i = 0; i < 7; i++)
        intTree.insert(nodes[i]);
    intTree.print();
    }   
    // edge cases
    TrinaryTree<int> emptyTree; // empty tree
    emptyTree.print();
    TrinaryTree<int> singleValueTree; // single value tree
    for (int i = 0; i < 10; i++)
        singleValueTree.insert(0);
    singleValueTree.print();
    return 0;
} 

int main(int argc, char const *argv[]){
    int rc = test();
    assert(rc == 0);
    cout << "pass tests" << endl;
    return 0;
}