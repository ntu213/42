

def ft_filter(ft, list):
    """returns all ft(list[i]) == True"""

    res = []

    for i in range(len(list)):
        if (ft(list[i])):
            res.append(list[i])

    return (res)
