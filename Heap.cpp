#include <iostream>
#include <vector>
#include <algorithm>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

class Heap {
private:
    std::vector<int> heap;
    bool isMaxHeap;

public:
    Heap(bool maxHeap) : isMaxHeap(maxHeap) {}

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && ((isMaxHeap && heap[index] > heap[parent]) || (!isMaxHeap && heap[index] < heap[parent]))) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && ((isMaxHeap && heap[leftChild] > heap[largest]) || (!isMaxHeap && heap[leftChild] < heap[largest]))) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && ((isMaxHeap && heap[rightChild] > heap[largest]) || (!isMaxHeap && heap[rightChild] < heap[largest]))) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    void deleteRoot() {
        if (heap.empty()) {
            std::cout << "Heap is empty\n";
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display() {
        if (heap.empty()) {
            std::cout << "Heap is empty\n";
            return;
        }

        std::cout << "Heap: ";
        for (int i = 0; i < heap.size(); ++i) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int choice;
    bool isMaxHeap;

    std::cout << "Choose the type of heap: 1 for (M)ax Heap or 2 for (m)in Heap: ";
    std::cin >> choice;

    if (choice == 1 || choice == 2) {
        isMaxHeap = (choice == 1);
    } else {
        std::cout << "Invalid choice. Exiting program.\n";
        return 1;
    }

    Heap heap(isMaxHeap);

    while (true) {
        std::cout << "\nChoose operation:\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Delete Root\n";
        std::cout << "3. Display\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        int operation;
        std::cin >> operation;

        switch (operation) {
            case 1: {
                int key;
                std::cout << "Enter element to insert: ";
                std::cin >> key;
                heap.insert(key);
                break;
            }
            case 2: {
                heap.deleteRoot();
                break;
            }
            case 3: {
                heap.display();
                break;
            }
            case 4: {
                std::cout << "Exiting program.\n";
                return 0;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }

    return 0;
}
