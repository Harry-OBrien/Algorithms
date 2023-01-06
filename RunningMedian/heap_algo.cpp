
#include <iostream>
#include <stdexcept>
#include <vector>
#include <functional>
#include <cstdlib>

template<typename T>
class GenericHeap {
    std::vector<T> heap;
    std::function<bool (T, T)> compare;

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
        while (hasParent(idx) && compare(heap[idx], parent(idx))) {
            size_t idx_p = parentIndex(idx);
            swap(idx, idx_p);
            idx = idx_p;
        }
    }

    void heapifyDown(size_t idx = 0) {
        
        // TODO: Optimise (parent idx calculated quite a few times here!)
        while(hasLeftChild(idx)) {
            size_t largerChildIndex = leftChildIdx(idx);
            if (hasRightChild(idx) && compare(rightChild(idx), leftChild(idx)))
                largerChildIndex = rightChildIdx(idx);

            if (compare(heap[idx], heap[largerChildIndex]))
                return;

            swap(idx, largerChildIndex);
            idx = largerChildIndex;
        }
    }

public:
    GenericHeap(std::function<bool (T, T)> comparisonFn)
        : compare(comparisonFn) 
    {}

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


std::vector<double> runningMedian(std::vector<int> A) {
    GenericHeap<int> maxHeap = GenericHeap<int>([] (auto a, auto b) { return a > b; });
    GenericHeap<int> minHeap = GenericHeap<int>([] (auto a, auto b) { return a < b; });

    std::vector<double> medians;
    double currentMedian = 0;

    for (int a: A) {
        // insert new val into correct heap
        if (a <= currentMedian)
            maxHeap.insert(a);
        else
            minHeap.insert(a);

        // balance heaps
        if (std::abs(long(minHeap.size() - maxHeap.size())) > 1){
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.insert(minHeap.poll());
            }
            else {
                minHeap.insert(maxHeap.poll());
            }
        }

        if (maxHeap.size() == minHeap.size()) {
            currentMedian = (minHeap.peak() + maxHeap.peak());
            currentMedian = double(currentMedian) / 2.;
        } else if (maxHeap.size() > minHeap.size()) {
            currentMedian = maxHeap.peak();
        } else {
            currentMedian = minHeap.peak();
        }

        medians.push_back(currentMedian);
    }

    return medians;
}

int main(int argc, char** argv) {

    std::vector<int> input = {12, 4, 5, 3, 8, 7};

    /* should print 12.0
                    8.0
                    5.0
                    4.5
                    5.0
                    6.0
    */

    for (auto i: runningMedian(input))
        std::cout << i << std::endl;

    return 0;
}