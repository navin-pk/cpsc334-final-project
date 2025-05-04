#include <iostream>
#include <sstream>
#include <cassert>
#include "bst.hpp"

using namespace std;

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

bool test_find_min(){
        return true;
}

int main(){
        cout << "Insert test: " << (test_insert() ? "Passed" : "Failed") << endl;
        cout << "Search test: " << (test_search() ? "Passed" : "Failed") << endl;
        cout << "In Order test: " << (test_in_order_traversal() ? "Passed" : "Failed") << endl;
        return 0;
}