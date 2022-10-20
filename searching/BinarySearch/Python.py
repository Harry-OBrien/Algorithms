import random

def find_idx_of(arr, element):
    """
    finds the index of a given element
    @returns index if element exists, else None
    """
    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = left + (right - left)//2
        midpoint_val = arr[mid]
        if midpoint_val == element:
            return mid
        
        if element < midpoint_val:
            right = mid - 1
            continue

        left = mid + 1
        
    return None

def main():
    random.seed(0)

    arr = [-14]
    for _ in range(19):
        increment = random.randint(1, 10)
        arr.append(arr[-1] + increment)

    print("Array:", arr)        
                                    # expected output:
    print(find_idx_of(arr, arr[7]))      # 7
    print(find_idx_of(arr, arr[0]))      # 0
    print(find_idx_of(arr, arr[-1]))     # 19
    print(find_idx_of(arr, arr[12]))     # 12
    print(find_idx_of(arr, -20))         # -1

if __name__ == "__main__":
    main()