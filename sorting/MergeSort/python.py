import random

def sort(arr):
    pass

def main():
    random.seed(0)
    
    arr = [random.randint(0, 10) for _ in range(20)]
    sorted_arr = sort(arr.copy)
    print(sorted_arr)

if __name__ == "__main__":
    main()