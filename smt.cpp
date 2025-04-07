#include <iostream>
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
}
