import random

def sort(arr):
    if len(arr) <= 1:
        return arr

    # split array in half
    mid = len(arr)//2
    left = sort(arr[:mid])
    right = sort(arr[mid:])

    return merge(left, right)

def merge(arr_l, arr_r):
    arr_out = []
    # print(arr_l, arr_r)
    while len(arr_l) > 0:
        if len(arr_r) <= 0:
            arr_out += arr_l
            break

        if arr_l[0] < arr_r[0]:
            arr_out.append(arr_l.pop(0))
        else:
            arr_out.append(arr_r.pop(0))

    arr_out += arr_r

    # print(arr_out)
    return arr_out

def main():
    random.seed(0)

    arr = [random.randint(0, 10) for _ in range(20)]
    print("Initial arr:", arr)
    sorted_arr = sort(arr)
    print("Sorted arr:", sorted_arr)

if __name__ == "__main__":
    main()