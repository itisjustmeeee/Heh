// рабочая тетрадь 1, #4
/*#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class CircleTwoList {
private:
    Node* head;
public:
    CircleTwoList() : head(nullptr) {}

    void AddtoEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void AddtoKnot(int key, int val) {
        if (head == nullptr) return;
        Node* current = head;
        do {
            if (current->data == key) {
                Node* newNode = new Node(val);
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;

                if (current == head) {
                    head = newNode;
                }

                return;
            }
            current = current->next;
        } while (current != head);
    }

    void removeKnot(int start, int end) {
        if (head == nullptr) return;

        Node* current = head;
        Node* del = nullptr;
        do {
            if (current->data >= start && current->data <= end) {
                del = current;

                if (del == head) {
                    head = head->next;
                    if (head == del) {
                        head = nullptr;
                    }
                }
                del->prev->next = del->next;
                del->next->prev = del->prev;

                Node* nextNode = del->next;
                delete del;
                current = nextNode;
            }
            else {
                current = current->next;
            }
        } while (current != head);
    }

    int count_elem() {
        if (!head) {
            return 0;
        }
        int count = 0;
        Node* current = head;
        do {
            count++;
            current = current->next;
        } while (current != head);

        return count;
    }


    void printList() {
        if (head == nullptr) return;
        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << " the end of the list (in right way) " << std::endl;
    }

    void Printinorder() {
        if (head == nullptr) return;
        Node* tail = head->prev;
        do {
            std::cout << tail->data << " ";
            tail = tail->prev;
        } while (tail != head);
        std::cout << head->data << " ";
        std::cout << " the end of the list (in reverse way) " << std::endl;
    }

    ~CircleTwoList() {
        if (head == nullptr) return;

        Node* current = head;
        Node* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }
};

int main() {
    CircleTwoList list;
    list.AddtoEnd(100);
    list.AddtoEnd(20);
    list.AddtoEnd(50);
    list.AddtoEnd(70);
    list.AddtoEnd(13);
    list.AddtoEnd(138);
    list.printList();
    list.Printinorder();

    int key, val;
    std::cout << "enter key and new number ";
    std::cin >> key >> val;

    list.AddtoKnot(key, val);
    list.printList();

    int x, y;
    std::cout << "enter number to delete by two coordinates ";
    std::cin >> x >> y;

    list.removeKnot(x, y);
    list.printList();

    int counts = list.count_elem();
    std::cout << counts << std::endl;

    return 0;
}*/

// рабочая тетрадь 1, #5
/*#include <iostream>

struct Node {
    int data;
    Node *prev, *next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

int get_len(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

Node* add(Node* first_list, Node* second_list) {
    Node head(0);
    Node* current = &head;
    int carry = 0;

    while (first_list || second_list || carry) {
        int summ = 0;
        if (first_list) {
            summ += first_list->data;
            first_list = first_list->next;
        }
        if (second_list) {
            summ += second_list->data;
            second_list = second_list->next;
        }
        carry = summ / 10;
        current->next = new Node(summ % 10);
        current = current->next;
    }
    return head.next;
}

void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* first_list = new Node(3);
    first_list->next = new Node(4);
    first_list->next->next = new Node(7);
    first_list->next->next->next = new Node(8);

    Node* second_list = new Node(5);
    second_list->next = new Node(8);
    second_list->next->next = new Node(9);
    second_list->next->next->next = new Node(1);

    std::cout << "first list: ";
    printList(first_list);
    std::cout << "second list: ";
    printList(second_list);

    Node* result = add(first_list, second_list);
    std::cout << "summ: ";
    printList(result);

    return 0;
}*/

// рабочая тетрадь 2, #3
/*#include <iostream>
#include <algorithm>


struct Node {
    int key;        
    int height;
    Node* left;
    Node* right;

    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) {
        return node ? getHeight(node->right) - getHeight(node->left) : 0;
    }

    void updateHeight(Node* node) {
        if (node) {
            node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
        }
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node* balance(Node* node) {
        updateHeight(node);
        int balance = getBalance(node);

        if (balance < -1 && getBalance(node->left) <= 0) {
            return rotateRight(node);
        }
        if (balance < -1 && getBalance(node->left) > 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance > 1 && getBalance(node->right) >= 0) {
            return rotateLeft(node);
        }
        if (balance > 1 && getBalance(node->right) < 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* insert(Node* node, int key) {
        if (!node) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        }
        else if (key > node->key) {
            node->right = insert(node->right, key);
        }
        else {
            return node;
        }

        return balance(node);
    }

    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    Node* remove(Node* node, int key) {
        if (!node) {
            return nullptr;
        }

        if (key < node->key) {
            node->left = remove(node->left, key);
        }
        else if (key > node->key) {
            node->right = remove(node->right, key);
        }
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* minNode = findMin(node->right);
            node->key = minNode->key;
            node->right = remove(node->right, minNode->key);
        }

        return balance(node);
    }

    void printInOrder(Node* node) const {
        if (node) {
            printInOrder(node->left);
            std::cout << node->key << " ";
            printInOrder(node->right);
        }
    }

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    AVLTree() : root(nullptr) {}

    ~AVLTree() {
        clear(root);
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = remove(root, key);
    }

    void print() const {
        if (!root) {
            std::cout << "Tree is empty" << std::endl;
        }
        else {
            printInOrder(root);
            std::cout << std::endl;
        }
    }
};

int main() {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(33);
    tree.insert(48);
    tree.insert(50);
    tree.insert(70);

    std::cout << "Tree after insertion: ";
    tree.print();

    std::cout << "Removing 20" << std::endl;
    tree.remove(20);
    std::cout << "Tree after removing 20: ";
    tree.print();

    return 0;
}*/

// рабочая тетрадь 3, #3
/*#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

class MaxHeap {
private:
    std::vector<int> heap;

    int parent(int index) const { return (index - 1) / 2; }
    int leftChild(int index) const { return 2 * index + 1; }
    int rightChild(int index) const { return 2 * index + 2; }

    void siftUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            std::swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void siftDown(int index) {
        int maxIndex = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heap.size() && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }
        if (right < heap.size() && heap[right] > heap[maxIndex]) {
            maxIndex = right;
        }

        if (index != maxIndex) {
            std::swap(heap[index], heap[maxIndex]);
            siftDown(maxIndex);
        }
    }

    void heapify() {
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            siftDown(i);
        }
    }

public:
    MaxHeap() {}

    MaxHeap(const std::vector<int>& arr) : heap(arr) {
        heapify();
    }

    int getMax() const {
        if (heap.empty()) {
            throw std::runtime_error("Heap is empty");
        }
        return heap[0];
    }

    void removeMax() {
        if (heap.empty()) {
            throw std::runtime_error("Heap is empty");
        }
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            siftDown(0);
        }
    }

    void insert(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    void merge(const MaxHeap& other) {
        heap.insert(heap.end(), other.heap.begin(), other.heap.end());
        heapify();
    }

    bool isEmpty() const {
        return heap.empty();
    }

    size_t size() const {
        return heap.size();
    }

    void print() const {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {

    MaxHeap heap1;

    heap1.insert(10);
    heap1.insert(20);
    heap1.insert(5);
    heap1.insert(30);
    std::cout << "Heap1: ";
    heap1.print();
    std::cout << "Max: " << heap1.getMax() << std::endl;
    heap1.removeMax();
    std::cout << "After removeMax: ";
    heap1.print();


    std::vector<int> arr = { 4, 10, 3, 5, 1 };
    MaxHeap heap2(arr);
    std::cout << "Heap2: ";
    heap2.print();
    std::cout << "Max: " << heap2.getMax() << std::endl;

    MaxHeap heap3;
    heap3.insert(15);
    heap3.insert(25);
    std::cout << "Heap3 before merge: ";
    heap3.print();
    heap3.merge(heap2);
    std::cout << "Heap3 after merging with Heap2: ";
    heap3.print();
    std::cout << "Max after merge: " << heap3.getMax() << std::endl;

    return 0;
}*/

// рабочая тетрадь 4, #3
/*#include <iostream>
#include <vector>
#include <string>

std::string findWordWithMostPrefixes(const std::vector<std::string>& words) {
    if (words.empty()) {
        return "";
    }

    std::string result = words[0];
    int maxPrefixes = 0;

    for (size_t i = 0; i < words.size(); ++i) {
        int prefixCount = 0;
        const std::string& candidate = words[i];

        for (size_t j = 0; j < words.size(); ++j) {
            if (i == j) continue;
            const std::string& potentialPrefix = words[j];

            if (potentialPrefix.size() <= candidate.size() &&
                candidate.substr(0, potentialPrefix.size()) == potentialPrefix) {
                ++prefixCount;
            }
        }

        if (prefixCount > maxPrefixes) {
            maxPrefixes = prefixCount;
            result = candidate;
        }
    }

    return result;
}

int main() {
    std::vector<std::string> words;
    std::string word;

    std::cout << "Enter words (one per line, Ctrl+D or Ctrl+Z to finish):\n";
    while (std::cin >> word) {
        words.push_back(word);
    }

    std::string result = findWordWithMostPrefixes(words);

    std::cout << "Word with most prefixes: " << result << std::endl;

    return 0;
}*/
