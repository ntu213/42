
import sys as system


def ft_check(str):

    for i in range(len(str)):
        if (str[i].isalpha() != 1 and str[i] != ' '):
            return (0)
    return (1)


def main():
    """The main function"""

    morse_code = {
        "A": ".-",
        "B": "-...",
        "C": "-.-.",
        "D": "-..",
        "E": ".",
        "F": "..-.",
        "G": "--.",
        "H": "....",
        "I": "..",
        "J": ".---",
        "K": "-.-",
        "L": ".-..",
        "M": "--",
        "N": "-.",
        "O": "---",
        "P": ".--.",
        "Q": "--.-",
        "R": ".-.",
        "S": "...",
        "T": "-",
        "U": "..-",
        "V": "...-",
        "W": ".--",
        "X": "-..-",
        "Y": "-.--",
        "Z": "--..",
        " ": "/"
    }
    argv = system.argv
    argc = len(argv)

    if (argc != 2 or ft_check(argv[1]) != 1):
        print("AssertionError: the arguments are bad")
        return (1)
    for i in range(len(argv[1])):
        if (i):
            print(end=" ")
        print(morse_code[argv[1][i].upper()], end="")
    print()
    return (0)


if (__name__ == "__main__"):
    main()
