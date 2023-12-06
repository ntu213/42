
from load_csv import load
import cv2 as cv


def ft_load(file: str) -> object:
    """Loads an image"""

    try:
        obj: object = cv.imread(file)
    except Exception as e:
        print(f"AssertionError: {e}")
        return
    return (obj)
