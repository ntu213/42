
import sys as system
from ft_filter import ft_filter


def main():
    """The main function"""

    argv = system.argv
    argc = len(argv)

    if (argc != 3):
        print("AssertionError: the arguments are bad")
        return (1)
    if (argv[2].lstrip("-+").isdigit() != 1):
        print("AssertionError: the arguments are bad")
        return (1)

    splitted = argv[1].split()

    useless = [x for x in argv]
    if (useless):
        pass

    print(ft_filter((lambda x: len(x) > int(argv[2])), splitted))
    return (0)


if (__name__ == "__main__"):
    main()
