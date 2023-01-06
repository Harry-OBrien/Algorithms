#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstdlib>
#include <vector>

template <typename T>
std::vector<size_t> sort_indexes(const std::vector<T> &v) {

  // initialize original index locations
  std::vector<size_t> idx(v.size());
  std::iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  // using std::stable_sort instead of std::sort
  // to avoid unnecessary index re-orderings
  // when v contains elements of equal values 
  std::stable_sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

  return idx;
}

int main(int argc, char** argv) {
    std::vector<int> randArr(20);
    
    // fill arr
    for(size_t i = 0; i < randArr.size(); i++){
        randArr[i] =  (std::rand() % 10);
    }

    // print
    for (int i: randArr)
        std::cout << i << " ";

    std::cout << std::endl;

    for (auto i: sort_indexes(randArr))
        std::cout << "Sorted idx: " << i << "\tVal: " << randArr[i] << std::endl;
    return 0;
}

/*
// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int recursiveCount(vector<vector<int>> adjList, size_t idx, bool* seen, size_t n) {
    // (*seen)[idx] = true;
    // int count = 0;
    // for (int i = 0; i < adjList[idx].size(); i++) {
    //     if 
    // }

    for (auto v: adjList) {
        for (int i: v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

int solution(vector<int> &A, vector<int> &B) {
    std::vector<int> AB = A;
    AB.insert(AB.end(), B.begin(), B.end());
    sort(AB.begin(), AB.end());

    auto last = std::unique(AB.begin(), AB.end());
    AB.erase(last, AB.end());

    // Adjacency list
    vector<vector<int>> adjList(AB.size());
    
    for (size_t i = 0; i < A.size(); i++) {
        addEdge(adjList, A[i], B[i]);
    }

    bool seen[adjList.size()];
    return recursiveCount(adjList, 0, seen, adjList.size());
}

*/