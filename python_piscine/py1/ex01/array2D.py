
def is_illegal(lst):
    """Check if lst contains an element that is not a list"""

    if (isinstance(lst, list) != 1):
        return (1)

    for elem in lst:
        if (isinstance(elem, list) != 1):
            return (1)

    return (0)


def slice_me(lst, start, end):
    """Function of the subject"""

    res = []

    if (is_illegal(lst)):
        print("AssertionError: the arguments are bad")
        return (res)

    print(f"My shape is: {len(lst), len(lst[0])}")
    res = lst[start:end]
    print(f"My new shape is: {len(res), len(res[0])}")
    return (res)


def main():
    """The main function"""

    family = [[1.80, 78.4],
              [2.15, 102.7],
              [2.10, 98.5],
              [1.88, 75.2]]
    print(slice_me(family, 0, 2))
    print()
    print(slice_me(family, 1, -2))
    return 0


if __name__ == "__main__":
    main()
