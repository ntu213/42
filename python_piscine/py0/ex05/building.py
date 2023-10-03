
import sys as system


def main():
    """the main function"""

    argv = system.argv
    argc = len(argv)

    if (argc > 2):
        print("AssertionError: more than one argument is provided")
        return (1)
    if (argc == 1):
        s = str(input("What is the text to count?\n"))
    else:
        s = argv[1]

    upper = 0
    lower = 0
    ponc = 0
    space = 0
    digit = 0

    for i in range(len(s)):

        if (s[i].isupper()):
            upper += 1
        elif (s[i].islower()):
            lower += 1
        elif (s[i].isspace()):
            space += 1
        elif (s[i].isdigit()):
            digit += 1
        else:
            ponc += 1

    print("The text contains", upper+lower+space+digit+ponc, "characters:")
    print(upper, "upper letters")
    print(lower, "lower letters")
    print(ponc, "ponctuation marks")
    print(space, "spaces")
    print(digit, "digits")

    return (0)


if (__name__ == "__main__"):
    main()
