import random

def sort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
            
        if i != min_idx:
            arr[i], arr[min_idx] = arr[min_idx], arr[i]

    return arr

def main():
    random.seed(0)

    arr = [random.randint(0, 10) for _ in range(20)]
    print("Initial arr:", arr)
    sorted_arr = sort(arr)
    print("Sorted arr:", sorted_arr)

if __name__ == "__main__":
    main()