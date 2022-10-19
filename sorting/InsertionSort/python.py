import random

def sort(_arr):
    arr = [x for x in _arr]
    if len(arr) <= 1:
        return arr

    for i in range(1, len(arr)):
        sort_val = arr[i]
        
        while arr[i-1] > sort_val and i > 0:
            arr[i], arr[i-1] = arr[i-1], arr[i]
            i = i - 1

    return arr

def main():
    random.seed(0)

    arr = [random.randint(0, 10) for _ in range(20)]
    print("Initial arr:", arr)
    sorted_arr = sort(arr)
    print("Sorted arr:", sorted_arr)

if __name__ == "__main__":
    main()