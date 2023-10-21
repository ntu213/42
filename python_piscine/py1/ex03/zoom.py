
import matplotlib.pyplot as plt
from load_image import ft_load


def main():
    """The main function"""

    try:
        tmp = ft_load("animal.jpeg")
        tup = (len(tmp), len(tmp[0]), len(tmp[0][0]))
        print(f"The shape of image is: {tup}")
        print(tmp)
        tmp = tmp[100:500, 450:850, 0:1]
        plt.imshow(tmp, cmap='gray')
        tup = (len(tmp), len(tmp[0]), len(tmp[0][0]))
        print(f"New shape after slicing: {tup}")
        print(tmp)
        plt.show()
    except Exception as e:
        print(f"AssertionError: {e}")
    return 0


if __name__ == "__main__":
    main()
