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

#include <iostream>
#include <vector>

class HeapDown{
private:
  std::vector<int> heap;
  
  void heapheap(int index){
    while (index > 0){
      int parent = (index - 1) / 2;
      if (heap[index] > heap[index]){
        std::swap(heap[index], heap[parent]);
        index = parent;
      }
      else{
        break;
      }
    }
  }
public:
  void findMax(){
    std::cout << heap[0] << std::endl;
  }

  void insert(int val){
    heap.push_back(val);
    heapheap(heap.size() - 1);
  }

  void deleteMax(){
    heap[0] = heap.back();
    heap.pop_back();
    heapheap(size() - 1);
  }

  void display(){
    for (int data : heap){
      std::cout << data << " ";
    }
    std::cout << std::endl;
  }
};

int main(){
  HeapDown down;
  down.insert(65);
  down.insert(44);
  down.insert(54);
  down.insert(23);
  down.insert(43);
  down.insert(13);

  down.display();
  down.findMax();
  down.deleteMax();
  down.display();

  return 0;
}
    

