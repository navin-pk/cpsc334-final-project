#include <iostream>
#include <sstream>
#include <cassert>
#include "bst.hpp"

using namespace std;

bool test_insert();
bool test_search();
bool test_in_order_traversal();
bool test_insert_duplicate();
bool test_search_wrong_value();
bool test_traversal_empty();
bool test_structure_shape();
bool test_search_empty();
bool test_delete_nonexistent();
bool test_tree_depth(); 

bool test_insert(){
        // setup
        BST b;
        string a = "A", b1 = "B", c = "C", d = "D", e = "E";

        // execution
        b.insert(a, 10); // empty case
        b.insert(b1, 2); // non-empty case left
        b.insert(c, 12); // non-empty case right
        b.insert(d, 5); //right on left subbranch
        b.insert(e, 7); //right on right left subbranch

        //validation
        RiverNode* root = b.get_root();
        assert(root != nullptr);
        assert(root->length == 10);
        assert(root->right->length == 12);
        assert(root->left->length == 2);
        assert(root->left->right->length == 5);
        assert(root->left->left == nullptr);
        assert(root->right->right == nullptr);
        assert(root->left->right->left == nullptr);
        assert(root->left->right->right->length == 7);
        assert(root->left->right->right->right == nullptr);
        assert(root->left->right->right->left == nullptr);

        //cleanup
        return true;
}

bool test_search(){
        //set up
        BST b;
        string a = "A", b1 = "B", c = "C", d = "D", e = "E";

        b.insert(a, 10); // empty case
        b.insert(b1, 2); // non-empty case left
        b.insert(c, 12); // non-empty case right
        b.insert(d, 5); //right on left subbranch
        b.insert(e, 7); //right on right left subbranch

        //execution
        bool s1 = b.search(b1, 2); // search for value in tree
        bool s2 = b.search(e, 7); // search in end of tree
        bool s3 = b.search(a, 4); // does not exist
        bool s4 = b.search(a, 10);
        bool s5 = b.search(c, 12);
        bool s6 = b.search(d, 5);

        //validation
        assert(s1 == true);
        assert(s2 == true);
        assert(s3 == false);
        assert(s4 == true);
        assert(s5 == true);
        assert(s6 == true);

        return true;

        //cleanup
}

bool test_in_order_traversal(){
        // setup
        BST b;
        string a = "A", b1 = "B", c = "C", d = "D", e = "E", f = "F", g = "G";

        b.insert(d, 10);
        b.insert(b1, 5);
        b.insert(f, 15);
        b.insert(a, 2);
        b.insert(c, 7);
        b.insert(e, 12);
        b.insert(g, 17);

        ostringstream output;
        streambuf* original = cout.rdbuf();
        cout.rdbuf(output.rdbuf());

        // execution
        b.in_order_traversal();
        cout.rdbuf(original);

        // validation
        string result = output.str();
        string expected = "A 2 B 5 C 7 D 10 E 12 F 15 G 17 \n";
        assert(result == expected);
        return true;

        // clean up
}

bool test_insert_duplicate(){
    BST b;
    std::string x = "X";

    b.insert(x, 10);
    b.insert(x, 20);

    RiverNode* root = b.get_root();
    assert(root != nullptr);
    assert(root->name == "X");
    assert(root->length == 10); // assuming duplicates are ignored
    return true;
}

bool test_search_wrong_value(){
    BST b;
    std::string river = "River";

    b.insert(river, 15);
    assert(b.search(river, 10) == false);
    return true;
}

bool test_traversal_empty(){
    BST b;
    std::ostringstream output;
    std::streambuf* original = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    b.in_order_traversal();
    std::cout.rdbuf(original);

    std::string result = output.str();
    assert(result == "\n");
    return true;
}

bool test_structure_shape(){
    BST b;
    std::string m = "M", l = "L", n = "N";

    b.insert(m, 10);
    b.insert(l, 8);
    b.insert(n, 12);

    RiverNode* root = b.get_root();
    assert(root->name == "M");
    assert(root->left != nullptr && root->left->name == "L");
    assert(root->right != nullptr && root->right->name == "N");
    return true;
}

bool test_search_empty(){
    BST b;
    std::string x = "X";

    assert(b.search(x, 10) == false);
    return true;
}

bool test_delete_nonexistent(){
    BST b;
    std::string a = "A", b1 = "B";

    b.insert(a, 10);
    b.insert(b1, 5);

    b.delete_node(999); // delete value not in tree

    RiverNode* root = b.get_root();
    assert(root != nullptr);
    assert(root->length == 10);
    assert(root->left != nullptr && root->left->length == 5);
    assert(root->right == nullptr);
    return true;
}

bool test_tree_depth(){
    BST b;
    std::string a = "A", b1 = "B", c = "C";

    b.insert(b1, 10);
    b.insert(a, 5);
    b.insert(c, 15);

    int depth = b.calculate_depth();

    assert(depth >= 0);
    return true;
}

int main(){
    cout << "Insert test: " << (test_insert() ? "Passed" : "Failed") << endl;
    cout << "Search test: " << (test_search() ? "Passed" : "Failed") << endl;
    cout << "In Order test: " << (test_in_order_traversal() ? "Passed" : "Failed") << endl;
    cout << "Insert Duplicate: " << (test_insert_duplicate() ? "Passed" : "Failed") << endl;
    cout << "Search Wrong Value: " << (test_search_wrong_value() ? "Passed" : "Failed") << endl;
    cout << "Traversal Empty: " << (test_traversal_empty() ? "Passed" : "Failed") << endl;
    cout << "Structure Shape: " << (test_structure_shape() ? "Passed" : "Failed") << endl;
    cout << "Search Empty Tree: " << (test_search_empty() ? "Passed" : "Failed") << endl;
    cout << "Delete Nonexistent Node: " << (test_delete_nonexistent() ? "Passed" : "Failed") << endl;
    cout << "Tree Depth: " << (test_tree_depth() ? "Passed" : "Failed") << endl;
    return 0;
}

