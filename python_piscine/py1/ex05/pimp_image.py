
import matplotlib.pyplot as plt
import cv2 as cv
from load_image import ft_load


def ft_invert(array):
	"""Inverts the colors of image"""
	copy = array.copy()
	copy[:, :, 0] = 255 - copy[:, :, 0]
	copy[:, :, 1] = 255 - copy[:, :, 1]
	copy[:, :, 2] = 255 - copy[:, :, 2]
	print(copy)
	return copy


def ft_red(array):
	"""Turns the image on red mode"""
	copy = array.copy()
	copy[:, :, 0] = 0
	copy[:, :, 1] = 0
	return copy


def ft_green(array):
	"""Turns the image on green mode"""
	copy = array.copy()
	copy[:, :, 0] = 0
	copy[:, :, 2] = 0
	return copy


def ft_blue(array):
	"""Turns the image on blue mode"""
	copy = array.copy()
	copy[:, :, 1] = 0
	copy[:, :, 2] = 0
	return copy


def ft_grey(array):
	"""Turns the image on B&W mode"""
	copy = array.copy()
	print(copy[:, :, 0] + copy[:, :, 1] + copy[:, :, 2])
	copy[:, :, 0] = (copy[:, :, 0] // 3) + (copy[:, :, 1] // 3) + (copy[:, :, 2] // 3)
	copy[:, :, 1] = copy[:, :, 0]
	copy[:, :, 2] = copy[:, :, 0]
	print(copy)
	return copy


array = ft_load("landscape.jpg")
plt.imshow(array[..., ::-1])
plt.show()
plt.imshow(ft_invert(array)[..., ::-1])
plt.show()
plt.imshow(ft_red(array)[..., ::-1])
plt.show()
plt.imshow(ft_green(array)[..., ::-1])
plt.show()
plt.imshow(ft_blue(array)[..., ::-1])
plt.show()
plt.imshow(ft_grey(array)[..., ::-1])
plt.show()
print(ft_invert.__doc__)
