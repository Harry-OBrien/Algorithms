import random

def sort(arr):
    if len(arr) <= 1:
        return arr

    # TODO: Optimise pivot point
    pivot = arr[-1]

    larger = []
    smaller = []
    for n in arr[:-1]:
        if n < pivot:
            smaller.append(n)
        else:
            larger.append(n)
    
    return sort(smaller) + [pivot] + sort(larger)

def main():
    random.seed(0)

    arr = [random.randint(0, 10) for _ in range(20)]
    print("Initial arr:", arr)
    sorted_arr = sort(arr)
    print("Sorted arr:", sorted_arr)

if __name__ == "__main__":
    main()