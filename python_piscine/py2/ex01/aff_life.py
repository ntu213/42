
from matplotlib import pyplot as plt
from load_csv import load
import cv2 as cv
import numpy as np


def ft_load(file: str) -> object:
    """Loads an image"""

    try:
        obj: object = cv.imread(file)
    except Exception as e:
        print(f"AssertionError: {e}")
        return
    return (obj)


def main():
    try:
        data = load("life_expectancy_years.csv")
        plt.plot(np.asarray(data[0][1:], float), np.asarray(data[59][1:], float))
        plt.show()
    except Exception as e:
        print(f"AssertionError: {e}")
        return
    return


if __name__ == "__main__":
    main()
