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


#include <iostream>
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
}
