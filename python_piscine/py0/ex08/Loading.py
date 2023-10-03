
def ft_tqdm(tab):
    """Fait des trucs"""

    for i in range(len(tab) + 1):
        perc = int(i / len(tab) * 100)
        tmp = ""
        if (perc - 1 >= 0):
            tmp = ">"
        s = f"{format(str(perc), '3')}% [{('=' * (perc - 1))}{tmp}\
            {(' ' * (100 - (perc + 1)))}] {format(str(i), '3')}/{len(tab)}"
        print(s, end="\r")
        yield i
