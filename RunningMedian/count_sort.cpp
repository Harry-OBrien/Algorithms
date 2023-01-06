#include <algorithm>
#include <iostream>
#include <vector>

int getMedian(int arr[], int index, int& prev) {
    for (int i = 0; i < 201; i++ ) {
        int j = arr[i];
        while(j)  {
            if (--index <= 0)
                return i;
            prev = i;
            j--;
        }
    }
    return -1;
}
int main(int argc, char** argv) {
    std::vector<int> expenditure = {12, 4, 5, 3, 0, 200, 7};
    int const d = 3;

    std::vector<int> freqWindow(201, 0);
    
    for(int i = 0; i < d; i++)
        freqWindow[expenditure[i]]++;
    
    int count{};
    double median;
    for(int i = d; i < expenditure.size(); i++) {
        int prev;
        int retVal = getMedian(freqWindow.data(), d / 2 + 1, prev );
        median = (d % 2) ? retVal : (retVal + prev) / 2.0; 
        std::cout << median << std::endl;
        double cost = (double)expenditure[i]; 
        if (cost >= (2 * median)) {
            count++;  
        } 
        freqWindow[expenditure[i - d]]--;
        freqWindow[expenditure[i]]++;
    }

    return 0;
}