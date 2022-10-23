// To build and run: `g++ cpp.cpp -std=c++14 -o minHeap && ./minHeap`

#include <iostream>
#include <stdexcept>
#include <vector>

template<typename T>
class MaxHeap {
    std::vector<T> heap;

    int parentIndex(int childIdx) { return (childIdx - 1) / 2; }
    size_t leftChildIdx(size_t parentIdx) { return parentIdx*2 + 1; }
    size_t rightChildIdx(size_t parentIdx) { return parentIdx*2 + 2; }

    bool hasParent(size_t childIdx) { return parentIndex(childIdx) >= 0; }
    bool hasLeftChild(size_t parentIdx) { return leftChildIdx(parentIdx) < heap.size(); }
    bool hasRightChild(size_t parentIdx) { return rightChildIdx(parentIdx) < heap.size(); }

    T parent(size_t childIdx) { return heap[parentIndex(childIdx)]; }
    T leftChild(size_t parentIdx) { return heap[leftChildIdx(parentIdx)]; }
    T rightChild(size_t parentIdx) { return heap[rightChildIdx(parentIdx)]; }

    void swap(size_t idx_0, size_t idx_1) {
        T temp = heap[idx_0];
        heap[idx_0] = heap[idx_1];
        heap[idx_1] = temp;
    }

    void heapifyUp() {
        size_t idx = heap.size() - 1;
        // TODO: Optimise (parent idx calculated 3 times here!)
        while (hasParent(idx) && parent(idx) < heap[idx]) {
            size_t idx_p = parentIndex(idx);
            swap(idx, idx_p);
            idx = idx_p;
        }
    }

    void heapifyDown(size_t idx = 0) {
        
        // TODO: Optimise (parent idx calculated quite a few times here!)
        while(hasLeftChild(idx)) {
            size_t largerChildIndex = leftChildIdx(idx);
            if (hasRightChild(idx) && rightChild(idx) > leftChild(idx))
                largerChildIndex = rightChildIdx(idx);

            if (heap[idx] > heap[largerChildIndex])
                return;

            swap(idx, largerChildIndex);
            idx = largerChildIndex;
        }
    }

public:
    T peak() {
        if (heap.size() == 0)
            throw std::out_of_range("No elements in heap");

        return heap[0];
    }

    T poll() {
        if (heap.size() == 0) 
            throw std::out_of_range("No elements in heap");

        // replace head with last item and shrink vec
        T item = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapifyDown();

        return item;
    }
    
    bool remove(T value) {
        for (size_t i = 0; i < heap.size(); i++) {
            if (value == heap[i]) {
                heap[i] = heap.back();
                heap.pop_back();
                
                heapifyDown(i);
                return true;
            }
        }
        
        return false;
    }

    void insert(T value) {
        // insert and bubble up
        heap.push_back(value);
        heapifyUp();
    }

    void print() {
        for (auto t: heap)
            std::cout << t << " ";

        std::cout << std::endl;
    }

    size_t size() {
        return heap.size();
    }
};


int main(int argc, char** argv) {
    MaxHeap<int> maxHeap;
    int testVals[10] = {9, 6, 4, 0, 5, 4, 9, 0, 1, -3};
    for (int i = 0; i < 10; i++) {
        maxHeap.insert(testVals[i]);
    }

    maxHeap.print();

    try {
        // Should output 9 9 6 5 4
        for (int i = 0; i < 5; i++)
            std::cout << maxHeap.poll() << " ";

        std::cout << std::endl;
    }
    catch(const std::out_of_range& e) {
        std::cout << "WARN: " << e.what() << std::endl;
    }
    
    
    return 0;
}