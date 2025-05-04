#include "bst.hpp"
#include <iostream>
#include <iomanip>
// #include <algorithm>

RiverNode::RiverNode(std::string& name, int length) {
    this-> name = name;
    this->length = length;
    left = nullptr;
    right = nullptr;
}

RiverNode::~RiverNode() {
    if (left != nullptr){
        delete left;
        left = nullptr;
    }
    if (right != nullptr){
        delete right;
        right = nullptr;
    }
}

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    if (root != nullptr) {
        delete root;
        root = nullptr;
    }
}

void BST::insert(std::string& name, int length) {
    insert(root, name, length);
}

bool BST::search(std::string& name, int length) {
    return search(root, name, length);
}
void BST::in_order_traversal() {
    in_order_traversal(root);
    std::cout << std::endl;
}

/*
void BST::pre_order_traversal() {
    pre_order_traversal(root);
    std::cout << std::endl;
}

void BST::post_order_traversal() {
    post_order_traversal(root);
    std::cout << std::endl;
}
*/

void BST::delete_node(int val) {
    root = delete_node(root, val);
}

int BST::calculate_depth() {
    return calculate_depth(root);
}

void BST::print_tree() {
    print_tree(root, 0);
}

void BST::insert(RiverNode*& node, std::string& name, int length) {
    if( node == nullptr){
     node = new RiverNode(name, length);
    } else if(length < node->length){
        insert(node->left, name, length);
    } else{
     insert(node->right, name, length);
    }
 }

bool BST::search(RiverNode* node, std::string& name, int length){
    if (node == nullptr){
        return false;
    } else if (node->name == name && node->length == length){
        return true;
    } else if(node->length > length){
        return search(node->left, name, length);
    } else{
        return search(node->right, name, length);
    }
}


void BST::in_order_traversal(RiverNode* node) {
    if(node == nullptr){
        return;
    } else {
        in_order_traversal(node->left);
        std::cout << node->name << " ";
        std::cout << node->length << " ";
        in_order_traversal(node->right);
    }
}

/*
void BST::pre_order_traversal(Node* node) {
    return;
}

void BST::post_order_traversal(Node* node) {
    return;
}
*/

RiverNode* BST::delete_node(RiverNode* node, int length) {
    return node;
}

RiverNode* BST::find_min(RiverNode* node) {
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}

int BST::calculate_depth(RiverNode* node) {
    return 0;
}

void BST::print_tree(RiverNode* node, int space) {
    if (node == nullptr) {
        return;
    }
    space -= 5;
    print_tree(node->right, space);
    std::cout << std::endl;
    std::cout << "This is the " << node->name << ", which is " << node->length << " miles from the Spokane River Lower Falls Dam.\n";
    std::cout << " /"<< std::setw(2)<< " " << "Right: " << (node->right ? node->right->name : "None") << " |" << std::endl;
    std::cout << "|" << std::setw(3) << node->length << " at " << std::setw(17) << node << " |" << std::endl;
    std::cout << " \\"<< std::setw(2)<< " " << "Left : " << (node->left ? node->left->name : "None") << " |" << std::endl;
    if (node->right == nullptr && node->left == nullptr) {
        std::cout << "\nThis is a leaf RiverNode in our tree.\n";
    } else {
        std::cout << "\nPress Enter to continue printed traversal...\n";
        std::cin.get();
    }
    
    print_tree(node->left, space);

}
