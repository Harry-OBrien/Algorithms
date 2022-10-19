import random

def sort(arr):
    sorted = False
    
    while not sorted:
        sorted = True
        for i, n in enumerate(arr[:-1]):
            if n > arr[i+1]:
                # swap
                temp = arr[i]
                arr[i] = arr[i+1]
                arr[i+1] = temp

                sorted = False

    return arr

def main():
    random.seed(0)

    arr = [random.randint(0, 10) for _ in range(20)]
    print("Initial arr:", arr)
    sorted_arr = sort(arr)
    print("Sorted arr:", sorted_arr)

if __name__ == "__main__":
    main()