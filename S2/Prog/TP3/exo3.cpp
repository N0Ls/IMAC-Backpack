#include "lib/mainwindow.h"
#include "lib/tp3.h"
#include <QApplication>
#include <time.h>
#include <stack>
#include <queue>

MainWindow* w = nullptr;
using std::size_t;

struct BinarySearchTree : public BinaryTree
{
    BinarySearchTree(int value=0) : BinaryTree(value) {}
    virtual ~BinarySearchTree() {}

    void insertNumber(int value) {

        if(this->value < value){
            if(this->right == NULL){
                this->right = createNode(value);
            }else {
                this->right->insertNumber(value);
            }
        }
        else{
            if(this->left == NULL){
                this->left = createNode(value);
            }else {
                this->left->insertNumber(value);
            }
        }

        /*
         * check where the new value must be inserted;
         * if there is no child in this emplacement
         * create a new node here else ask the child
         * to insert the value
         */
    }

    uint height() const	{
        if(this->isLeaf()){
            return 1;
        }else if(this->right==NULL){
            return this->left->height()+1;
        }else if(this->left==NULL){
            return this->right->height()+1;
        }else{
            int hauteurR=this->right->height();
            int hauteurL=this->left->height();
            if (hauteurR>hauteurL){
                return hauteurR+1;
            }else{
                return hauteurL+1;
            }
            // should return the maximum height between left child and
            // right child +1 for itself. If there is no child, return
            // just 1
        }
        return 1;
    }

    uint nodesCount() const {
        if(this->isLeaf()){
            return 1;
        }
        else if(this->right==NULL){
            return this->left->nodesCount()+1;
        }
        else if(this->left==NULL){
            return this->right->nodesCount()+1;
        }
        else{
            int countR=this->right->nodesCount();
            int countL=this->left->nodesCount();
            return countL+countR+1;
        }


        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        return 1;
    }

    bool isLeaf() const {
        if(this->right==NULL && this->left==NULL){
            return true;
        }
        return false;
    }

    void allLeaves(Node* leaves[], uint& leavesCount) {
        if(this->isLeaf()){
            leaves[leavesCount]=this;
            leavesCount++;
        }
        else if(this->right==NULL){
            this->left->allLeaves(leaves,leavesCount);
        }
        else if(this->left==NULL){
            this->right->allLeaves(leaves,leavesCount);
        }
        else{
            this->left->allLeaves(leaves,leavesCount);
            this->right->allLeaves(leaves,leavesCount);
        }
    }

    void inorderTravel(Node* nodes[], uint& nodesCount) {
        if(this->left!=NULL){
            this->left->inorderTravel(nodes,nodesCount);
        }
        nodes[nodesCount]=this;
        nodesCount++;
        if(this->right!=NULL){
            this->right->inorderTravel(nodes,nodesCount);

        }
    }

    void preorderTravel(Node* nodes[], uint& nodesCount) {
        nodes[nodesCount]=this;
        nodesCount++;
        if(this->left!=NULL){
            this->left->preorderTravel(nodes,nodesCount);
        }

        if(this->right!=NULL){
            this->right->preorderTravel(nodes,nodesCount);

        }
    }

    void postorderTravel(Node* nodes[], uint& nodesCount) {

        if(this->left!=NULL){
            this->left->postorderTravel(nodes,nodesCount);
        }

        if(this->right!=NULL){
            this->right->postorderTravel(nodes,nodesCount);

        }
        nodes[nodesCount]=this;
        nodesCount++;
    }

    //todo
    Node* find(int value) {
        if(value==this->value){
            return this;
        }
        if(value > this->value){
            this->right = find(value);
        }
        if(value < this->value){
            this->left = find(value);
        }

        return nullptr;
    }
};

Node* createNode(int value) {
    return new BinarySearchTree(value);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow::instruction_duration = 200;
    BinarySearchTree bst;
    w = new BinarySearchTreeWindow(bst);
    w->show();

    return a.exec();
}
