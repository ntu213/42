
import cv2 as cv


def ft_load(file: str) -> object:
    """Function of the subject"""

    try:
        obj: object = cv.imread(file)
        tup = (len(obj), len(obj[0]), len(obj[0][0]))
        print(f"The shape of the image is: {tup}")
    except Exception as e:
        print(f"AssertionError: {e}")
        return
    return (obj)


def main():
    """The main function"""

    print(ft_load("landscape.jpg"))
    print(ft_load("se.jpg"))
    return 0


if __name__ == "__main__":
    main()
