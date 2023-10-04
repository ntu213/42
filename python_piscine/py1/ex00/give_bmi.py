

def is_illegal(lst):
    """Check if lst contains an element that is not int or float"""

    if (isinstance(lst, list) != 1):
        return (1)

    for elem in lst:
        if (isinstance(elem, int) != 1 and isinstance(elem, float) != 1):
            return (1)

    return (0)


def give_bmi(height, weight):
    """Function of the subject"""

    res = []

    if (is_illegal(height) or is_illegal(weight)
       or len(height) != len(weight)):
        print("AssertionError: the arguments are bad")
        return (res)

    for i in range(len(height)):
        res.append(weight[i] / (height[i]**2))

    return (res)


def apply_limit(lst, limit):
    """Function of the subject"""

    res = []

    if (is_illegal(lst) or isinstance(limit, int) != 1):
        print("AssertionError: the arguments are bad")
        return (res)

    for i in range(len(lst)):
        if (lst[i] <= limit):
            res.append(True)
        else:
            res.append(False)

    return (res)
