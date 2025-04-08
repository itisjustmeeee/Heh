// #1
#include <iostream>
#include <algorithm>

struct Tree {
	int data;
	Tree* right;
	Tree* left;

	Tree(int val) : data(val), right(nullptr), left(nullptr) {}
};

class BinaryTree {
private:
	Tree* root;

	Tree* insert(Tree* node, int val) {
		if (!node) {
			return new Tree(val);
		}
		if (val < node->data) {
			node->left = insert(node->left, val);
		}
		if (val > node->data) {
			node->right = insert(node->right, val);
		}
		return node;
	}


	int Height(Tree* node) {
		if (!node) {
			return 0;
		}
		return 1 + std::max(Height(node->left), Height(node->right));
	}

	void Display(Tree* node) {
		if (node) {
			Display(node->left);
			int hightleft = Height(node->left);
			int hightright = Height(node->right);
			int balance = hightleft - hightright;
			std::cout << node->data << " balance factor " << balance << std::endl;

			Display(node->right);
		}
	}
public:
	BinaryTree() : root(nullptr) {}

	void insertroot(int val) {
		root = insert(root, val);
	}

	void displaybalance() {
		Display(root);
	}
};

int main() {
	BinaryTree tree;

	tree.insertroot(10);
	tree.insertroot(100);
	tree.insertroot(1);
	tree.insertroot(3);
	tree.insertroot(17);
	tree.insertroot(28);
	tree.insertroot(0);
	tree.insertroot(5);
	tree.insertroot(19);
	tree.insertroot(21);

	std::cout << " balance data: \n";
	tree.displaybalance();

	return 0;
}
/*
// #2
#include <iostream>


struct Tree {
    int data, height;
    Tree* left;
    Tree* right;

    Tree(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Tree* root;

    int Height(Tree* node) {
        return node ? node->height : 0;
    }

    // Получение показателя баланса узла
    int getBalance(Tree* node) {
        return node ? Height(node->left) - Height(node->right) : 0;
    }

    Tree* rightRotate(Tree* y) {
        Tree* x = y->left;
        Tree* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(Height(y->left), Height(y->right)) + 1;
        x->height = std::max(Height(x->left), Height(x->right)) + 1;

        return x;
    }

    Tree* leftRotate(Tree* x) {
        Tree* y = x->right;
        Tree* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(Height(x->left), Height(x->right)) + 1;
        y->height = std::max(Height(y->left), Height(y->right)) + 1;

        return y;
    }

    Tree* insert(Tree* node, int val) {
        if (!node) {
            return new Tree(val);
        }
        if (val < node->data) {
            node->left = insert(node->left, val);
        }
        else {
            node->right = insert(node->right, val);
        }

        node->height = 1 + std::max(Height(node->left), Height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && val < node->left->data) {
            return rightRotate(node);
        }

        if (balance < -1 && val > node->right->data) {
            return leftRotate(node);
        }

        if (balance > 1 && val > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && val < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void preOrder(Tree* node) {
        if (node) {
            std::cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    void preOrder() {
        preOrder(root);
    }
};

int main() {
    AVLTree avl;

    avl.insert(10);
    avl.insert(100);
    avl.insert(13);
    avl.insert(4);
    avl.insert(78);
    avl.insert(1);
    avl.insert(7);
    avl.insert(15);
    avl.insert(38);
    avl.insert(41);

    std::cout << "printed in order AVLTree: \n";
    avl.preOrder();

    return 0;
}
*/
/*
// #4
#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left, * right, * parent;

    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    void rotateLeft(Node*& pt) {
        Node* pt_y = pt->right;
        pt->right = pt_y->left;

        if (pt->right != nullptr) {
            pt->right->parent = pt;
        }

        pt_y->parent = pt->parent;

        if (pt->parent == nullptr) {
            root = pt_y;
        }
        else if (pt == pt->parent->left) {
            pt->parent->left = pt_y;
        }
        else {
            pt->parent->right = pt_y;
        }

        pt_y->left = pt;
        pt->parent = pt_y;
    }

    void rotateRight(Node*& pt) {
        Node* pt_y = pt->left;
        pt->left = pt_y->right;

        if (pt->left != nullptr) {
            pt->left->parent = pt;
        }

        pt_y->parent = pt->parent;

        if (pt->parent == nullptr) {
            root = pt_y;
        }
        else if (pt == pt->parent->left) {
            pt->parent->left = pt_y;
        }
        else {
            pt->parent->right = pt_y;
        }

        pt_y->right = pt;
        pt->parent = pt_y;
    }

    void fixViolation(Node*& pt) {
        Node* pt_parent = nullptr;
        Node* pt_grandparent = nullptr;

        while ((pt != root) && (pt->color == RED) && (pt->parent->color == RED)) {
            pt_parent = pt->parent;
            pt_grandparent = pt->parent->parent;

            // Case A: pt_parent is a left child
            if (pt_parent == pt_grandparent->left) {
                Node* pt_uncle = pt_grandparent->right;

                // Case 1: The uncle of pt is also red
                if (pt_uncle != nullptr && pt_uncle->color == RED) {
                    pt_grandparent->color = RED;
                    pt_parent->color = BLACK;
                    pt_uncle->color = BLACK;
                    pt = pt_grandparent;
                }
                else {
                    // Case 2: pt is the right child of its parent
                    if (pt == pt_parent->right) {
                        rotateLeft(pt_parent);
                        pt = pt_parent;
                        pt_parent = pt->parent;
                    }
                    // Case 3: pt is the left child of its parent
                    rotateRight(pt_grandparent);
                    std::swap(pt_parent->color, pt_grandparent->color);
                    pt = pt_parent;
                }
            }
            else { // Case B: pt_parent is a right child
                Node* pt_uncle = pt_grandparent->left;

                // Case 1: The uncle of pt is also red
                if ((pt_uncle != nullptr) && (pt_uncle->color == RED)) {
                    pt_grandparent->color = RED;
                    pt_parent->color = BLACK;
                    pt_uncle->color = BLACK;
                    pt = pt_grandparent;
                }
                else {
                    // Case 2: pt is the left child of its parent
                    if (pt == pt_parent->left) {
                        rotateRight(pt_parent);
                        pt = pt_parent;
                        pt_parent = pt->parent;
                    }
                    // Case 3: pt is the right child of its parent
                    rotateLeft(pt_grandparent);
                    std::swap(pt_parent->color, pt_grandparent->color);
                    pt = pt_parent;
                }
            }
        }
    }
};*/
