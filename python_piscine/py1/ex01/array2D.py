
def is_illegal(lst, s, e):

	if (isinstance(lst, list) != 1):
		return (1)

	for elem in lst:
		if (isinstance(elem, list) != 1):
			return (1)

	return (0)


def slice_me(lst, start, end):

	res = []

	if (is_illegal(lst, start, end)):
		print("AssertionError: the arguments are bad")
		return (res)

	res = lst[start:end]
	return (res)

family = [[1.80, 78.4],
[2.15, 102.7],
[2.10, 98.5],
[1.88, 75.2]]
print(slice_me(family, 0, 2))
print(slice_me(family, 1, -2))
