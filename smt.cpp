/*#include <iostream>
#include <vector>

std::vector<int> heap;

void heapDown(int index){
  while (index > 0){
    int parent = (index - 1) / 2;
    if (heap[index] > heap[parent]){
      std::swap(heap[index], heap[parent]);
      index = parent;
    }
    else{
      break;
    }
  }
}

void insert(int val){
  heap.push_back(val);
  heapDown(heap.size() - 1);
}

void disaplay(){
  for (int data : heap){
    std::cout << data << " ";
  }
  std::cout << std::endl;
}

int main(){
  insert(11);
  insert(8);
  insert(9);
  insert(17);
  insert(26);
  insert(13);
  insert(4);
  insert(23);
  insert(1);

  display();
  return 0;
}*/

/*#include <iostream>
#include <vector>

class HeapDown {
private:
    std::vector<int> heap;

    void Heapdown(int index) {
        while (index < heap.size()) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < heap.size() && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < heap.size() && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            }
            else {
                break;
            }
        }
    }

    void heapheap(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[index]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }
public:

    HeapDown() {}

    HeapDown(const std::vector<int>& arr) {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            Heapdown(i);
        }
    }

    void findMax() {
        std::cout << heap[0] << std::endl;
    }

    void deleteMax() {
        heap[0] = heap.back();
        heap.pop_back();
        Heapdown(0);
    }

    void insert(int val) {
        heap.push_back(val);
        heapheap(heap.size() - 1);
    }

    void display() {
        for (int data : heap) {
            std::cout << data << " ";
        }
        std::cout << std::endl;
    }
};

int main() {

    std::vector<int> arr = { 10, 20, 1000, 30, 27, 95, 49, 1, 3, 5 };
    HeapDown down(arr);

    down.display();
    down.findMax();
    down.deleteMax();
    down.display();
    down.insert(13);
    down.display();

    return 0;
}*/


/*#include <iostream>
#include <vector>

std::vector<int> heap;

void heapDown(int index) {
    while (index < heap.size()) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            index = smallest;
        }
        else {
            break;
        }
    }
}

void insert(int val) {
    heap.push_back(val);
    int index = heap.size() - 1;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            std::swap(heap[index], heap[parent]);
            index = parent;
        }
        else {
            break;
        }
    }
}

void display() {
    for (int data : heap) {
        std::cout << data << " ";
    }
    std::cout << std::endl;
}

void bindRopes(std::vector<int>& ropes) {
    for (int rope : ropes) {
        insert(rope);
    }

    int costropes = 0;
    std::vector<std::pair<int, int>> order;

    while (heap.size() > 1) {
        int first = heap.front();
        std::swap(heap.front(), heap.back());
        heap.pop_back();
        heapDown(0);

        int second = heap.front();
        std::swap(heap.front(), heap.back());
        heap.pop_back();
        heapDown(0);

        int cost = first + second;
        costropes += cost;

        insert(cost);

        order.push_back({ first, second });
    }

    std::cout << "Binding order (pairs of ropes):\n";
    for (const auto& pair : order) {
        std::cout << pair.first << " + " << pair.second << " -> ";
    }
    std::cout << "Total cost: " << costropes << std::endl;
}

int main() {
    std::vector<int> ropes = {3, 7, 8, 10, 29, 1000, 5};

    bindRopes(ropes);

    return 0;
}*/

/*#include <iostream>

struct Node {
    int data, priority;
    Node* next;

    Node(int priority, int val) : data(val), priority(priority), next(nullptr) {}
};

class Que {
private:
    Node* head;
public:
    Que() : head(nullptr) {}

    void insert(int priority, int val) {
        Node* newNode = new Node(priority, val);

        if (head == nullptr || head->priority < priority) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            if (current->next != nullptr && current->next->priority >= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

    }

    int elem() {
        Node* temp = head;
        head = head->next;
        int data = temp->data;
        delete temp;
        return data;
    }

    bool isempty() {
        return head == nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout <<"( " << current->data << " -> " << current->priority << " )";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~Que() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Que queue;

    queue.insert(1, 10);
    queue.insert(3, 5);
    queue.insert(4, 20);
    queue.insert(2, 20);

    queue.display();
    queue.elem();
    queue.display();

    return 0;
}*/

#include <iostream>
#include <vector>

void heapDown(std::vector<int>& heap, int n, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < n && heap[right] > heap[largest]) {
        largest = right;
    }
    if (largest != index) {
        std::swap(heap[index], heap[largest]);

        heapDown(heap, n, largest);
    }
}

void heapSort(std::vector<int>& heap) {
    int n = heap.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapDown(heap, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        std::swap(heap[0], heap[i]);

        heapDown(heap, i, 0);
    }
}

void display(const std::vector<int>& heap) {
    for (int i = 0; i < heap.size(); i++) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    std::vector<int> heap = { 8, 9, 13, 26, 7, 1, 0 };
    display(heap);

    heapSort(heap);

    display(heap);

    return 0;
}
