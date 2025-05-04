#ifndef BST_HPP
#define BST_HPP
#include <string>

class RiverNode {
public:
    std::string name;
    int length;
    RiverNode* left;
    RiverNode* right;
    RiverNode(std::string& name, int length);
    ~RiverNode();
};

class BST {
public:
    BST();
    ~BST();
    void insert(std::string&name, int length);
    bool search(std::string& name, int length);
    void in_order_traversal();
    void pre_order_traversal();
    void post_order_traversal();
    void delete_node(int val);
    int calculate_depth();
    void print_tree();
    RiverNode* get_root(){return root;};

private:
    RiverNode* root;
    void insert(RiverNode*& node, std::string& name, int length);
    bool search(RiverNode* node, std::string& name, int length);
    void in_order_traversal(RiverNode* node);
    void pre_order_traversal(RiverNode* node);
    void post_order_traversal(RiverNode* node);
    RiverNode* delete_node(RiverNode* node, int length);
    RiverNode* find_min(RiverNode* node);
    int calculate_depth(RiverNode* node);
    void print_tree(RiverNode* node, int space);
};

#endif
