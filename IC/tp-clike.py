def main():
    num_1, num_2 = input().split()
    arr = []
    num_1 = int(num_1)
    num_2 = int(num_2)

    for n in range(num_1, num_2 + 1):
        print(n, end="")
        arr.append(n)

    for item in reversed(arr):
        num_in_string = str(item)
        reverse = num_in_string[::-1]
        print(reverse, end="")


if __name__ == "__main__":
    main()
