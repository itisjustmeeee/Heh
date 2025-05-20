//workbook 1, #4
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

//workbook 1, #5
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

//workbook 2, #3
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

//workbook 3, #3
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

//workbook 4, #3
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

//workbook 1, #7
/*#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

struct Contact {
    std::string name;
    std::vector<std::string> phones;

    Contact(const std::string& n = "", const std::string& phone = "") : name(n) {
        if (!phone.empty()) {
            phones.push_back(phone);
        }
    }
};

struct Node {
    Contact contact;
    Node* left;
    Node* right;

    Node(const std::string& name, const std::string& phone) : contact(name, phone), left(nullptr), right(nullptr) {}
};

class PhoneBook {
private:
    Node* root;

    Node* insert(Node* node, const std::string& name, const std::string& phone) {
        if (!node) {
            return new Node(name, phone);
        }
        if (name == node->contact.name) {
            if (std::find(node->contact.phones.begin(), node->contact.phones.end(), phone) == node->contact.phones.end()) {
                node->contact.phones.push_back(phone);
            }
            return node;
        }
        if (name < node->contact.name) {
            node->left = insert(node->left, name, phone);
        }
        else {
            node->right = insert(node->right, name, phone);
        }
        return node;
    }

    Node* search(Node* node, const std::string& name) const {
        if (!node || node->contact.name == name) {
            return node;
        }
        return (name < node->contact.name) ? search(node->left, name) : search(node->right, name);
    }

    Node* findMin(Node* node) const {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    Node* remove(Node* node, const std::string& name) {
        if (!node) return nullptr;
        if (name < node->contact.name) {
            node->left = remove(node->left, name);
        }
        else if (name > node->contact.name) {
            node->right = remove(node->right, name);
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
            node->contact = minNode->contact;
            node->right = remove(node->right, minNode->contact.name);
        }
        return node;
    }

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    void print(Node* node, int depth = 0) const {
        if (node) {
            print(node->right, depth + 1);
            for (int i = 0; i < depth; ++i) std::cout << "  ";
            std::cout << node->contact.name << ": ";
            for (const auto& phone : node->contact.phones) {
                std::cout << phone << " ";
            }
            std::cout << std::endl;
            print(node->left, depth + 1);
        }
    }

public:
    PhoneBook() : root(nullptr) {}

    ~PhoneBook() {
        clear(root);
    }

    void add(const std::string& name, const std::string& phone) {
        root = insert(root, name, phone);
    }

    void find(const std::string& name) const {
        Node* node = search(root, name);
        if (node) {
            std::cout << "Contact: " << node->contact.name << std::endl;
            std::cout << "Phones: ";
            for (const auto& phone : node->contact.phones) {
                std::cout << phone << " ";
            }
            std::cout << std::endl;
        }
        else {
            std::cout << "Contact not found" << std::endl;
        }
    }

    void removeContact(const std::string& name) {
        root = remove(root, name);
    }

    void printAll() const {
        if (!root) {
            std::cout << "Phone book is empty" << std::endl;
            return;
        }
        print(root);
    }
};

int main() {
    PhoneBook phoneBook;
    std::string command, name, phone;

    while (true) {
        std::cout << "\nCommands: add, find, remove, print, exit\n";
        std::cout << "Enter command: ";
        std::cin >> command;

        if (command == "exit") break;
        else if (command == "add") {
            std::cout << "Enter name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter phone: ";
            std::getline(std::cin, phone);
            phoneBook.add(name, phone);
            std::cout << "Contact added" << std::endl;
        }
        else if (command == "find") {
            std::cout << "Enter name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            phoneBook.find(name);
        }
        else if (command == "remove") {
            std::cout << "Enter name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            phoneBook.removeContact(name);
            std::cout << "Contact removed" << std::endl;
        }
        else if (command == "print") {
            phoneBook.printAll();
        }
        else {
            std::cout << "Unknown command" << std::endl;
        }
    }
    return 0;
}*/

//workbook 1, #9
/*#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

struct Node {
    long long sum;
    int min_val;
    int max_val;
    int even_count;
    int odd_count;

    Node() : sum(0), min_val(INT_MAX), max_val(INT_MIN), even_count(0), odd_count(0) {}
};

class SegmentTree {
private:
    std::vector<Node> tree;
    std::vector<int> arr;
    int n;

    // Построение дерева отрезков
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node].sum = arr[start];
            tree[node].min_val = arr[start];
            tree[node].max_val = arr[start];
            tree[node].even_count = (arr[start] % 2 == 0) ? 1 : 0;
            tree[node].odd_count = (arr[start] % 2 != 0) ? 1 : 0;
            return;
        }

        int mid = (start + end) / 2;
        int left = 2 * node + 1;
        int right = 2 * node + 2;

        build(left, start, mid);
        build(right, mid + 1, end);

        tree[node].sum = tree[left].sum + tree[right].sum;
        tree[node].min_val = std::min(tree[left].min_val, tree[right].min_val);
        tree[node].max_val = std::max(tree[left].max_val, tree[right].max_val);
        tree[node].even_count = tree[left].even_count + tree[right].even_count;
        tree[node].odd_count = tree[left].odd_count + tree[right].odd_count;
    }

    long long querySum(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return 0;
        if (start >= l && end <= r) return tree[node].sum;

        int mid = (start + end) / 2;
        int left = 2 * node + 1;
        int right = 2 * node + 2;

        return querySum(left, start, mid, l, r) + querySum(right, mid + 1, end, l, r);
    }

    int queryMin(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return INT_MAX;
        if (start >= l && end <= r) return tree[node].min_val;

        int mid = (start + end) / 2;
        int left = 2 * node + 1;
        int right = 2 * node + 2;

        return std::min(queryMin(left, start, mid, l, r), queryMin(right, mid + 1, end, l, r));
    }

    int queryMax(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return INT_MIN;
        if (start >= l && end <= r) return tree[node].max_val;

        int mid = (start + end) / 2;
        int left = 2 * node + 1;
        int right = 2 * node + 2;

        return std::max(queryMax(left, start, mid, l, r), queryMax(right, mid + 1, end, l, r));
    }

    std::pair<int, int> queryEvenOdd(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return { 0, 0 };
        if (start >= l && end <= r) return { tree[node].even_count, tree[node].odd_count };

        int mid = (start + end) / 2;
        int left = 2 * node + 1;
        int right = 2 * node + 2;

        auto leftResult = queryEvenOdd(left, start, mid, l, r);
        auto rightResult = queryEvenOdd(right, mid + 1, end, l, r);

        return { leftResult.first + rightResult.first, leftResult.second + rightResult.second };
    }

public:
    SegmentTree(const std::vector<int>& input) {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    long long getSum(int l, int r) {
        if (l < 0 || r >= n || l > r) {
            std::cout << "Invalid range!" << std::endl;
            return 0;
        }
        return querySum(0, 0, n - 1, l, r);
    }

    int getMin(int l, int r) {
        if (l < 0 || r >= n || l > r) {
            std::cout << "Invalid range!" << std::endl;
            return INT_MAX;
        }
        return queryMin(0, 0, n - 1, l, r);
    }

    int getMax(int l, int r) {
        if (l < 0 || r >= n || l > r) {
            std::cout << "Invalid range!" << std::endl;
            return INT_MIN;
        }
        return queryMax(0, 0, n - 1, l, r);
    }

    std::pair<int, int> getEvenOddCount(int l, int r) {
        if (l < 0 || r >= n || l > r) {
            std::cout << "Invalid range!" << std::endl;
            return { 0, 0 };
        }
        return queryEvenOdd(0, 0, n - 1, l, r);
    }
};

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    SegmentTree segTree(arr);

    while (true) {
        int l, r;
        std::cout << "\nEnter the range [l, r] (indices from 0 to " << (n - 1) << ", or enter -1 to exit): ";
        std::cin >> l;
        if (l == -1) break;
        std::cin >> r;

        if (l < 0 || r >= n || l > r) {
            std::cout << "Invalid range! Indices must be between 0 and " << (n - 1) << ", and l <= r.\n";
            continue;
        }

        long long sum = segTree.getSum(l, r);
        std::cout << "Sum on range [" << l << ", " << r << "]: " << sum << std::endl;

        int minVal = segTree.getMin(l, r);
        std::cout << "Minimum on range [" << l << ", " << r << "]: " << minVal << std::endl;

        int maxVal = segTree.getMax(l, r);
        std::cout << "Maximum on range [" << l << ", " << r << "]: " << maxVal << std::endl;

        auto evenOdd = segTree.getEvenOddCount(l, r);
        std::cout << "Even count on range [" << l << ", " << r << "]: " << evenOdd.first << std::endl;
        std::cout << "Odd count on range [" << l << ", " << r << "]: " << evenOdd.second << std::endl;
    }

    return 0;
}*/

//workbook 1, #10
/*#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>


struct Node {
    int x;
    std::set<int> ySet;
    Node* left, * right;
    Node(int val) : x(val), left(nullptr), right(nullptr) {}
};

class RangeTree {
private:
    Node* root;

    void insert(Node*& node, int x, int y) {
        if (!node) {
            node = new Node(x);
            node->ySet.insert(y);
            return;
        }
        if (x <= node->x) {
            insert(node->left, x, y);
        }
        else {
            insert(node->right, x, y);
        }
        node->ySet.insert(y);
    }

    int countInRange(Node* node, int xMin, int xMax, int yMin, int yMax) {
        if (!node) return 0;

        int count = 0;
        if (xMin <= node->x && node->x <= xMax) {
            auto it1 = node->ySet.lower_bound(yMin);
            auto it2 = node->ySet.upper_bound(yMax);
            count += distance(it1, it2);
        }

        if (xMin <= node->x) {
            count += countInRange(node->left, xMin, xMax, yMin, yMax);
        }
        if (xMax >= node->x) {
            count += countInRange(node->right, xMin, xMax, yMin, yMax);
        }

        return count;
    }

    void deleteTree(Node* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    RangeTree(std::vector<std::pair<int, int>>& points) : root(nullptr) {
        for (const auto& p : points) {
            insert(root, p.first, p.second);
        }
    }

    ~RangeTree() {
        deleteTree(root);
    }

    int query(int xMin, int xMax, int yMin, int yMax) {
        return countInRange(root, xMin, xMax, yMin, yMax);
    }
};

int main() {
    std::vector<std::pair<int, int>> points = { {1, 2}, {2, 3}, {3, 5}, {4, 8}, {7, 10}, {5, 1} };
    RangeTree tree(points);

    int xMin = 2, xMax = 4, yMin = 2, yMax = 4;
    int result = tree.query(xMin, xMax, yMin, yMax);
    std::cout << "Number of points in rectangle: " << result << std::endl;

    return 0;
}*/

//workbook 2, #5
/*#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left, * right, * parent;

    Node(int val) : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left) y->left->parent = x;
        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right) x->right->parent = y;
        x->parent = y->parent;
        if (!y->parent) root = x;
        else if (y == y->parent->right) y->parent->right = x;
        else y->parent->left = x;
        x->right = y;
        y->parent = x;
    }

    void fixInsert(Node* node) {
        while (node->parent && node->parent->color == RED) {
            if (node->parent == node->parent->parent->left) {
                Node* uncle = node->parent->parent->right;
                if (uncle && uncle->color == RED) {
                    node->parent->color = BLACK;
                    uncle->color = BLACK;
                    node->parent->parent->color = RED;
                    node = node->parent->parent;
                }
                else {
                    if (node == node->parent->right) {
                        node = node->parent;
                        leftRotate(node);
                    }
                    node->parent->color = BLACK;
                    node->parent->parent->color = RED;
                    rightRotate(node->parent->parent);
                }
            }
            else {
                Node* uncle = node->parent->parent->left;
                if (uncle && uncle->color == RED) {
                    node->parent->color = BLACK;
                    uncle->color = BLACK;
                    node->parent->parent->color = RED;
                    node = node->parent->parent;
                }
                else {
                    if (node == node->parent->left) {
                        node = node->parent;
                        rightRotate(node);
                    }
                    node->parent->color = BLACK;
                    node->parent->parent->color = RED;
                    leftRotate(node->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void transplant(Node* u, Node* v) {
        if (!u->parent) root = v;
        else if (u == u->parent->left) u->parent->left = v;
        else u->parent->right = v;
        if (v) v->parent = u->parent;
    }

    Node* minimum(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    void fixDelete(Node* x, Node* xParent) {
        while (x != root && (!x || x->color == BLACK)) {
            if (x == xParent->left) {
                Node* w = xParent->right;
                if (w->color == RED) {
                    w->color = BLACK;
                    xParent->color = RED;
                    leftRotate(xParent);
                    w = xParent->right;
                }
                if ((!w->left || w->left->color == BLACK) && (!w->right || w->right->color == BLACK)) {
                    w->color = RED;
                    x = xParent;
                    xParent = x->parent;
                }
                else {
                    if (!w->right || w->right->color == BLACK) {
                        if (w->left) w->left->color = BLACK;
                        w->color = RED;
                        rightRotate(w);
                        w = xParent->right;
                    }
                    w->color = xParent->color;
                    xParent->color = BLACK;
                    if (w->right) w->right->color = BLACK;
                    leftRotate(xParent);
                    x = root;
                    xParent = nullptr;
                }
            }
            else {
                Node* w = xParent->left;
                if (w->color == RED) {
                    w->color = BLACK;
                    xParent->color = RED;
                    rightRotate(xParent);
                    w = xParent->left;
                }
                if ((!w->right || w->right->color == BLACK) && (!w->left || w->left->color == BLACK)) {
                    w->color = RED;
                    x = xParent;
                    xParent = x->parent;
                }
                else {
                    if (!w->left || w->left->color == BLACK) {
                        if (w->right) w->right->color = BLACK;
                        w->color = RED;
                        leftRotate(w);
                        w = xParent->left;
                    }
                    w->color = xParent->color;
                    xParent->color = BLACK;
                    if (w->left) w->left->color = BLACK;
                    rightRotate(xParent);
                    x = root;
                    xParent = nullptr;
                }
            }
        }
        if (x) x->color = BLACK;
    }

    void deleteNode(Node* z) {
        Node* y = z;
        Node* x;
        Node* xParent;
        Color yOriginalColor = y->color;

        if (!z->left) {
            x = z->right;
            xParent = z->parent;
            transplant(z, z->right);
        }
        else if (!z->right) {
            x = z->left;
            xParent = z->parent;
            transplant(z, z->left);
        }
        else {
            y = minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;
            xParent = y;
            if (y->parent == z) {
                xParent = y;
            }
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        delete z;
        if (yOriginalColor == BLACK) {
            fixDelete(x, xParent);
        }
    }

    Node* search(int val) {
        Node* current = root;
        while (current && current->data != val) {
            if (val < current->data) current = current->left;
            else current = current->right;
        }
        return current;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        std::cout << node->data << "(" << (node->color == RED ? "R" : "B") << ") ";
        inorder(node->right);
    }

    void deleteTree(Node* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    RedBlackTree() : root(nullptr) {}

    ~RedBlackTree() {
        deleteTree(root);
    }

    void insert(int val) {
        Node* node = new Node(val);
        if (!root) {
            root = node;
            root->color = BLACK;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;
        while (current) {
            parent = current;
            if (node->data < current->data) current = current->left;
            else current = current->right;
        }

        node->parent = parent;
        if (node->data < parent->data) parent->left = node;
        else parent->right = node;

        fixInsert(node);
    }

    void remove(int val) {
        Node* node = search(val);
        if (!node) {
            std::cout << "Node with value " << val << " not found." << std::endl;
            return;
        }
        deleteNode(node);
    }

    void print() {
        inorder(root);
        std::cout << std::endl;
    }
};

int main() {
    RedBlackTree tree;
    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);
    tree.insert(2);
    tree.insert(6);

    std::cout << "Initial Red-Black Tree: ";
    tree.print();

    tree.remove(18);
    std::cout << "After deleting 18: ";
    tree.print();

    tree.remove(3);
    std::cout << "After deleting 3: ";
    tree.print();

    return 0;
}*/

//workbook 2, #6
/*#include <iostream>

struct Node {
    int data;
    Node* left, * right, * parent;

    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

class SplayTree {
private:
    Node* root;

    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right) y->right->parent = x;
        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;
        y->right = x;
        x->parent = y;
    }

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left) y->left->parent = x;
        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void splay(Node* node) {
        while (node->parent) {
            Node* parent = node->parent;
            Node* grandparent = parent->parent;

            if (!grandparent) {
                if (node == parent->left) rightRotate(parent);
                else leftRotate(parent);
            }
            else if (node == parent->left && parent == grandparent->left) {
                rightRotate(grandparent);
                rightRotate(parent);
            }
            else if (node == parent->right && parent == grandparent->right) {
                leftRotate(grandparent);
                leftRotate(parent);
            }
            else if (node == parent->right && parent == grandparent->left) {
                leftRotate(parent);
                rightRotate(grandparent);
            }
            else {
                rightRotate(parent);
                leftRotate(grandparent);
            }
        }
    }

    
    Node* search(int val) {
        Node* current = root;
        while (current && current->data != val) {
            if (val < current->data) current = current->left;
            else current = current->right;
        }
        if (current) splay(current);
        return current;
    }

    
    Node* minimum(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

    
    void deleteTree(Node* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    SplayTree() : root(nullptr) {}

    ~SplayTree() {
        deleteTree(root);
    }

    void insert(int val) {
        Node* node = new Node(val);
        if (!root) {
            root = node;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;
        while (current) {
            parent = current;
            if (val < current->data) current = current->left;
            else current = current->right;
        }

        node->parent = parent;
        if (val < parent->data) parent->left = node;
        else parent->right = node;

        splay(node);
    }

    void remove(int val) {
        Node* node = search(val);
        if (!node) {
            std::cout << "Node with value " << val << " not found." << std::endl;
            return;
        }

        
        Node* leftSubtree = root->left;
        Node* rightSubtree = root->right;

        
        if (leftSubtree) leftSubtree->parent = nullptr;
        if (rightSubtree) rightSubtree->parent = nullptr;

        delete root;

        if (!leftSubtree) {
            root = rightSubtree;
            return;
        }

        
        Node* maxNode = leftSubtree;
        while (maxNode->right) maxNode = maxNode->right;
        splay(maxNode);

        
        root = maxNode;
        root->right = rightSubtree;
        if (rightSubtree) rightSubtree->parent = root;
    }

    void print() {
        inorder(root);
        std::cout << std::endl;
    }
};

int main() {
    SplayTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);

    std::cout << "Initial Splay Tree (inorder): ";
    tree.print();

    tree.remove(20);
    std::cout << "After deleting 20 (inorder): ";
    tree.print();

    tree.insert(25);
    std::cout << "After inserting 25 (inorder): ";
    tree.print();

    return 0;
}*/

//workbook 3, #5
/*#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* left, * right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    int countNodes(Node* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    bool isComplete(Node* node, int index, int totalNodes) {
        if (!node) return true;

        if (index >= totalNodes) return false;

        return isComplete(node->left, 2 * index + 1, totalNodes) &&
            isComplete(node->right, 2 * index + 2, totalNodes);
    }

    bool isMaxHeap(Node* node) {
        if (!node) return true;

        if (node->left && node->data < node->left->data) return false;
        if (node->right && node->data < node->right->data) return false;

        return isMaxHeap(node->left) && isMaxHeap(node->right);
    }

    bool isMinHeap(Node* node) {
        if (!node) return true;

        if (node->left && node->data > node->left->data) return false;
        if (node->right && node->data > node->right->data) return false;

        return isMinHeap(node->left) && isMinHeap(node->right);
    }

    void deleteTree(Node* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        deleteTree(root);
    }

    bool isBinaryHeap() {
        if (!root) return true;

        int totalNodes = countNodes(root);
        if (!isComplete(root, 0, totalNodes)) return false;

        return isMaxHeap(root) || isMinHeap(root);
    }
};

int main() {
    BinaryTree tree1;
    tree1.root = new Node(10);
    tree1.root->left = new Node(5);
    tree1.root->right = new Node(8);
    tree1.root->left->left = new Node(2);
    tree1.root->left->right = new Node(4);

    std::cout << "Tree 1 is a binary heap: " << (tree1.isBinaryHeap() ? "true" : "false") << std::endl;

    BinaryTree tree2;
    tree2.root = new Node(3);
    tree2.root->left = new Node(5);
    tree2.root->right = new Node(2);

    std::cout << "Tree 2 is a binary heap: " << (tree2.isBinaryHeap() ? "true" : "false") << std::endl;

    BinaryTree tree3;
    tree3.root = new Node(10);
    tree3.root->right = new Node(5);

    std::cout << "Tree 3 is a binary heap: " << (tree3.isBinaryHeap() ? "true" : "false") << std::endl;

    return 0;
}*/

//workbook 3, #7
/*#include <iostream>
#include <string>
#include <vector>

struct Task {
    std::string name;
    int priority;
    bool done;
    
    Task(std::string n, int p) : name(n), priority(p), done(false) {}
};

class PriorityQueue {
private:
    std::vector<Task> heap;

    int parent(int index) { return (index - 1) / 2; }
    int left(int index) { return 2 * index + 1; }
    int right(int index) { return 2 * index + 2; }

    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)].priority < heap[index].priority) {
            std::swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int maxIndex = index;
        int l = left(index);
        int r = right(index);

        if (l < heap.size() && heap[l].priority > heap[maxIndex].priority) {
            maxIndex = l;
        }
        if (r < heap.size() && heap[r].priority > heap[maxIndex].priority) {
            maxIndex = r;
        }

        if (index != maxIndex) {
            std::swap(heap[index], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

    int findTask(const std::string& name) {
        for (int i = 0; i < heap.size(); ++i) {
            if (heap[i].name == name && !heap[i].done) {
                return i;
            }
        }
        return -1;
    }

public:
    void addTask(std::string name, int priority) {
        heap.emplace_back(name, priority);
        heapifyUp(heap.size() - 1);
    }

    Task getMaxTask() {
        if (heap.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        return heap[0];
    }

    void markDone() {
        if (heap.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        heap[0].done = true;
        std::swap(heap[0], heap.back());
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
    }

    void editTask(std::string name, int newPriority) {
        int index = findTask(name);
        if (index == -1) {
            throw std::runtime_error("Task not found or already done");
        }
        heap[index].priority = newPriority;
        heapifyUp(index);
        heapifyDown(index);
    }

    void print() {
        for (const auto& task : heap) {
            std::cout << "Task: " << task.name << ", Priority: " << task.priority
                << ", Done: " << (task.done ? "Yes" : "No") << std::endl;
        }
    }
};

int main() {
    PriorityQueue todo;
    int choice;
    std::string name;
    int priority;

    while (true) {
        std::cout << "\n1. Add Task\n2. Get and Mark Done\n3. Edit Task\n4. Print Todo List\n5. Exit\nChoice: ";
        std::cin >> choice;
        std::cin.ignore();

        try {
            switch (choice) {
            case 1:
                std::cout << "Enter task name: ";
                std::getline(std::cin, name);
                std::cout << "Enter priority: ";
                std::cin >> priority;
                todo.addTask(name, priority);
                break;
            case 2:
            {
                Task task = todo.getMaxTask();
                std::cout << "Doing task: " << task.name << " (Priority: " << task.priority << ")\n";
                todo.markDone();
            }
            break;
            case 3:
                std::cout << "Enter task name to edit: ";
                std::getline(std::cin, name);
                std::cout << "Enter new priority: ";
                std::cin >> priority;
                todo.editTask(name, priority);
                break;
            case 4:
                todo.print();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice\n";
            }
        }
        catch (const std::runtime_error& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}*/

//workbook 4, #5
/*#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <sstream>
#include <iomanip>

struct Node {
    char ch;
    int freq;
    Node* left, * right;
    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
    ~Node() { delete left; delete right; }
};

struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void generateCodes(Node* root, const std::string& str, std::unordered_map<char, std::string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[root->ch] = str.empty() ? "0" : str; // для случая одного символа
    }
    generateCodes(root->left, str + "0", codes);
    generateCodes(root->right, str + "1", codes);
}

// Сериализация дерева Хаффмана в битовый поток (префиксный обход)
// 0 - внутренний узел, 1 + 8 бит - лист с символом
void serializeTree(Node* root, std::vector<bool>& bits, std::vector<char>& leaves) {
    if (!root) return;
    if (!root->left && !root->right) {
        bits.push_back(1);
        leaves.push_back(root->ch);
        return;
    }
    bits.push_back(0);
    serializeTree(root->left, bits, leaves);
    serializeTree(root->right, bits, leaves);
}

// Кодирование строки
std::string huffmanEncode(const std::string& text, std::unordered_map<char, std::string>& codes, Node*& root) {
    std::unordered_map<char, int> frequency;
    for (char ch : text) frequency[ch]++;
    std::priority_queue<Node*, std::vector<Node*>, Compare> minHeap;
    for (auto& pair : frequency) minHeap.push(new Node(pair.first, pair.second));
    if (minHeap.size() == 1) minHeap.push(new Node('\0', 0)); // для одного символа
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();
        Node* top = new Node('\0', left->freq + right->freq);
        top->left = left; top->right = right;
        minHeap.push(top);
    }
    root = minHeap.top();
    generateCodes(root, "", codes);
    std::string encoded;
    for (char ch : text) encoded += codes[ch];
    return encoded;
}

// Подсчёт бит для битового хранения дерева
size_t getSerializedTreeBitSize(Node* root) {
    std::vector<bool> bits;
    std::vector<char> leaves;
    serializeTree(root, bits, leaves);
    // 1 бит на структуру + 8 бит на каждый лист (символ)
    return bits.size() + leaves.size() * 8;
}

// Подсчёт бит для хранения словаря в виде пар (символ, код)
size_t getDictionaryBitSize(const std::unordered_map<char, std::string>& codes) {
    size_t bits = 0;
    for (const auto& p : codes) {
        bits += 8; // символ
        bits += p.second.size(); // длина кода
    }
    return bits;
}

int main() {
    std::string text;
    std::cout << "enter the string for coding: ";
    std::getline(std::cin, text);

    std::unordered_map<char, std::string> codes;
    Node* root = nullptr;
    std::string encoded = huffmanEncode(text, codes, root);

    // Сериализация дерева
    std::vector<bool> treeBits;
    std::vector<char> leaves;
    serializeTree(root, treeBits, leaves);

    // Оценка размеров
    size_t encodedBits = encoded.size();
    size_t dictBits = getDictionaryBitSize(codes);
    size_t treeBitsSize = getSerializedTreeBitSize(root);

    std::cout << "\nHaffman's codes:\n";
    for (const auto& p : codes) {
        std::cout << "'" << (p.first == '\n' ? "\\n" : std::string(1, p.first)) << "': " << p.second << "\n";
    }
    std::cout << "\nEncoded string (bit length): " << encodedBits << "\n";
    std::cout << "Dictionary (symbol+code, bit): " << dictBits << "\n";
    std::cout << "Dictionary (bit tree serialization): " << treeBitsSize << "\n";
    std::cout << "Total (string+dictionary):\n";
    std::cout << "  - Symbol+code: " << (encodedBits + dictBits) << " bit\n";
    std::cout << "  - Bit tree: " << (encodedBits + treeBitsSize) << " bit\n";

    if ((encodedBits + treeBitsSize) < (encodedBits + dictBits))
        std::cout << "Savings are achieved by storing the Huffman tree in bits.\n";
    else
        std::cout << "Savings are not achieved by storing the dictionary as (symbol, code) pairs.\n";

    delete root;
    return 0;
}*/

//workbook 4, #7
/*#include <iostream>
#include <vector>
#include <algorithm>

struct Order {
    int distance;
};

struct Courier {
    int remainingCapacity;
    std::vector<int> assignedOrders;
};

int minCouriers(int n, int k, int t, std::vector<Order>& orders) {
    std::sort(orders.begin(), orders.end(), [](const Order& a, const Order& b) {
        return a.distance < b.distance;
        });

    std::vector<Courier> couriers(k, { t, {} });

    int courierIndex = 0;
    for (int i = 0; i < n; ++i) {
        bool assigned = false;
        for (int j = 0; j < k; ++j) {
            if (couriers[j].remainingCapacity >= orders[i].distance) {
                couriers[j].remainingCapacity -= orders[i].distance;
                couriers[j].assignedOrders.push_back(i);
                assigned = true;
                break;
            }
        }

        if (!assigned && courierIndex < k) {
            couriers[courierIndex].remainingCapacity -= orders[i].distance;
            couriers[courierIndex].assignedOrders.push_back(i);
            assigned = true;
            courierIndex++;
        }

        if (!assigned) {
            break;
        }
    }

    int usedCouriers = 0;
    for (const auto& courier : couriers) {
        if (!courier.assignedOrders.empty()) {
            usedCouriers++;
        }
    }

    return usedCouriers;
}

int main() {
    int n, k, t;
    std::cout << "Enter number of orders (N): ";
    std::cin >> n;
    std::cout << "Enter number of couriers (K): ";
    std::cin >> k;
    std::cout << "Enter maximum route length (T): ";
    std::cin >> t;

    std::vector<Order> orders(n);
    std::cout << "Enter distances for " << n << " orders:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> orders[i].distance;
    }

    int result = minCouriers(n, k, t, orders);
    std::cout << "Minimum number of couriers needed: " << result << std::endl;

    return 0;
}*/

//workbook 5, #5
/*#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <climits>

struct Edge {
    int to;
    int weight;
    bool used;
    Edge(int t, int w) : to(t), weight(w), used(false) {}
};

class ChinesePostman {
private:
    std::vector<std::vector<Edge>> adj;
    std::vector<std::string> vertexNames;
    std::unordered_map<std::string, int> vertexMap;
    int totalCost;

    void addEdge(int u, int v, int weight) {
        adj[u].push_back(Edge(v, weight));
        adj[v].push_back(Edge(u, weight));
    }

    std::vector<int> computeDegrees() {
        std::vector<int> degrees(adj.size(), 0);
        for (int u = 0; u < adj.size(); ++u) {
            degrees[u] = adj[u].size();
        }
        return degrees;
    }

    int shortestPath(int start, int end) {
        std::vector<int> dist(adj.size(), INT_MAX);
        std::vector<bool> visited(adj.size(), false);
        dist[start] = 0;

        for (int i = 0; i < adj.size(); ++i) {
            int u = -1;
            for (int j = 0; j < adj.size(); ++j) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }
            if (u == -1 || dist[u] == INT_MAX) break;
            visited[u] = true;
            for (const Edge& e : adj[u]) {
                if (!visited[e.to] && dist[u] + e.weight < dist[e.to]) {
                    dist[e.to] = dist[u] + e.weight;
                }
            }
        }
        return dist[end];
    }

    void augmentGraph() {
        std::vector<int> degrees = computeDegrees();
        std::vector<int> oddVertices;
        for (int i = 0; i < degrees.size(); ++i) {
            if (degrees[i] % 2 != 0) {
                oddVertices.push_back(i);
            }
        }

        while (!oddVertices.empty()) {
            int u = oddVertices.back();
            oddVertices.pop_back();
            int v = oddVertices.back();
            oddVertices.pop_back();
            int weight = shortestPath(u, v);
            totalCost += weight;
            adj[u].push_back(Edge(v, weight));
            adj[v].push_back(Edge(u, weight));
        }
    }

    std::vector<int> findEulerianCircuit(int start) {
        std::vector<int> circuit;
        std::stack<int> st;
        st.push(start);

        while (!st.empty()) {
            int u = st.top();
            bool hasUnused = false;

            for (Edge& e : adj[u]) {
                if (!e.used) {
                    e.used = true;
                    for (Edge& re : adj[e.to]) {
                        if (re.to == u && !re.used) {
                            re.used = true;
                            break;
                        }
                    }
                    st.push(e.to);
                    hasUnused = true;
                    break;
                }
            }

            if (!hasUnused) {
                circuit.push_back(u);
                st.pop();
            }
        }

        return circuit;
    }

public:
    ChinesePostman(const std::vector<std::string>& vertices, const std::vector<std::pair<std::pair<std::string, std::string>, int>>& edges) {
        vertexNames = vertices;
        adj.resize(vertices.size());
        for (int i = 0; i < vertices.size(); ++i) {
            vertexMap[vertices[i]] = i;
        }

        totalCost = 0;
        for (const auto& edge : edges) {
            std::string u = edge.first.first;
            std::string v = edge.first.second;
            int weight = edge.second;
            addEdge(vertexMap[u], vertexMap[v], weight);
            totalCost += weight;
        }

        augmentGraph();
    }

    void solve(int startVertex) {
        std::cout << "Solution to the Chinese Postman Problem:\n";
        std::vector<int> circuit = findEulerianCircuit(startVertex);
        for (int i = 0; i < circuit.size() - 1; ++i) {
            std::cout << vertexNames[circuit[i]] << " -> " << vertexNames[circuit[i + 1]] << std::endl;
        }
        std::cout << "\nTotal cost of the route: " << totalCost << std::endl;
    }
};

int main() {
    std::vector<std::string> vertices = { "A", "B", "C", "D" };
    std::vector<std::pair<std::pair<std::string, std::string>, int>> edges = {
        {{"A", "B"}, 4},
        {{"A", "C"}, 3},
        {{"B", "C"}, 2},
        {{"C", "D"}, 5}
    };

    ChinesePostman cp(vertices, edges);
    cp.solve(0);

    return 0;
}*/

//workbook 5, #6
/*#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

void floydWarshall(std::vector<std::vector<int>>& dist, int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
}

int tsp(std::vector<std::vector<int>>& dist, int n, std::vector<int>& tour) {
    std::vector<std::vector<int>> dp(1 << n, std::vector<int>(n, INT_MAX));
    std::vector<std::vector<int>> parent(1 << n, std::vector<int>(n, -1));

    dp[1][0] = 0;

    for (int s = 1; s < (1 << n); s++) {
        for (int v = 0; v < n; v++) {
            if (!(s & (1 << v))) continue;
            for (int u = 0; u < n; u++) {
                if (u == v || !(s & (1 << u)) || dist[u][v] == INT_MAX) continue;
                int newCost = dp[s ^ (1 << v)][u] + dist[u][v];
                if (newCost < dp[s][v]) {
                    dp[s][v] = newCost;
                    parent[s][v] = u;
                }
            }
        }
    }

    int finalMask = (1 << n) - 1;
    int minCost = INT_MAX;
    int lastVertex = -1;
    for (int v = 0; v < n; v++) {
        if (dp[finalMask][v] != INT_MAX && dp[finalMask][v] + dist[v][0] < minCost) {
            minCost = dp[finalMask][v] + dist[v][0];
            lastVertex = v;
        }
    }

    tour.clear();
    int curr = lastVertex;
    int mask = finalMask;
    while (curr != -1) {
        tour.push_back(curr);
        int prev = parent[mask][curr];
        mask ^= (1 << curr);
        curr = prev;
    }
    tour.push_back(0);
    reverse(tour.begin(), tour.end());

    return minCost;
}

int main() {
    int n;
    std::cout << "Enter the number of cities: ";
    std::cin >> n;

    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INT_MAX));
    std::cout << "Enter the distance matrix (0 if no direct path, use large number like 999 for no path):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> dist[i][j];
            if (i == j) dist[i][j] = 0;
        }
    }

    floydWarshall(dist, n);

    std::vector<int> tour;
    int minCost = tsp(dist, n, tour);

    if (minCost == INT_MAX) {
        std::cout << "No valid tour exists.\n";
    }
    else {
        std::cout << "\nOptimal tour (starting from city 0):\n";
        for (size_t i = 0; i < tour.size(); i++) {
            std::cout << "City " << tour[i];
            if (i < tour.size() - 1) std::cout << " -> ";
        }
        std::cout << "\nTotal cost of the route: " << minCost << std::endl;
    }

    return 0;
}*/
