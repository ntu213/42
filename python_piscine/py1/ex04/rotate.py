
import matplotlib.pyplot as plt
import cv2 as cv
from load_image import ft_load


def main():
    """The main function"""

    try:
        tmp = ft_load("animal.jpeg")
        tmp = tmp[100:500, 450:850, 0:1]
        tup = (len(tmp), len(tmp[0]), len(tmp[0][0]))
        print(f"The shape of image is: {tup}")
        print(tmp)
        tmp = cv.rotate(tmp, cv.ROTATE_90_COUNTERCLOCKWISE)
        print(f"New shape after Transpose: {tup}")
        print(tmp)
        plt.imshow(tmp, cmap='gray')
        plt.show()
    except Exception as e:
        print(f"AssertionError: {e}")
    return 0


if __name__ == "__main__":
    main()
