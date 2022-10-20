#include <iostream>
#include <stdexcept>

template<typename T>
class MinHeap {
    vector<T> heap;

    size_t parentIndex(size_t thisIndex) { return (thisIndex - 1) / 2; }
    size_t leftChildIdx(size_t thisIndex) { return index*2 + 1; }
    size_t rightChildIdx(size_t thisIndex) { return index*2 + 2; }

    bool hasParent(size_t idx) { return parentIndex(idx) >= 0; }
    bool hasLeftChild(size_t idx) { return leftChildIdx(idx) < heap.size(); }
    bool hasRightChild(size_t idx) { return rightChildIdx(idx) < heap.size(); }

    T parent(size_t idx) { return heap[parentIndex(idx)]; }
    T leftChild(size_t idx) { return heap[leftChildIdx(idx)]; }
    T rightChild(size_t idx) { return heap[rightChildIdx(idx)]; }

    void swap(size_t idx_0, size_t idx_1) {
        T temp = heap[idx_0];
        heap[idx_0] = heap[idx_1];
        heap[idx_1] = temp;
    }

    void heapifyUp() {
        size_t idx = heap.size() - 1;
        // TODO: Optimise (parent idx calculated 3 times here!)
        if(hasParent(idx) && parent(idx) > heap[idx]) {
            idx_p = parentIndex(idx);
            swap(idx, idx_p);
            idx = idx_p
        }
    }

    void heapifyDown() {
        size_t idx = 0;
        while(hasLeftChild(idx)) {
            size_t smallerChildIndex = leftChildIdx(idx);
            if (hasRightChild(idx) && rightChild(idx) < leftChild(idx)
                smallerChildIndex = rightChildIdx();

            if (heap[idx] < heap[smallerChildIndex])
                return;

            swap(idx, smallerChildIndex);
            idx = smallerChildIndex;
        }
    }

public:
    T peak() {
        if (heap.size() == 0)
            throw std::out_of_range();

        return heap[0];
    }

    T poll() {
        if (heap.size() == 0) 
            throw std::out_of_range();

        // replace head with last item and shrink vec
        T item = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapifyDown();

        return item;
    }

    void insert(T value) {
        // insert and bubble up
        heap.push_back(value);
        heapifyUp();
    }
};

int main(int argc, char** argv) {
    MinHeap<int> minHeap;
    return 0;
}