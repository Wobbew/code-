def ft_count_harvest_recursive():
    i = range(int(input("Days until harvest:")))
    recursion(i, 0)
    print("Harvest time!")


def recursion(i, j):
    if j in i:
        print('day', j+1)
        recursion(i, j+1)
