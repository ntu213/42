
def NULL_not_found(obj):

	if (obj is None):
		print("Nothing:", obj, type(obj))
	elif (type(obj) == float):
		print("Cheese:", obj, type(obj))
	elif (type(obj) == int):
		print("Zero:", obj, type(obj))
	elif (type(obj) == str):
		print("Empty:", obj, type(obj))
	elif (type(obj) == bool):
		print("Fake:", obj, type(obj))
	else:
		print("Type not found")
	return (1)

Nothing = None
Garlic = float("NaN")
Zero = 0
Empty = str()
Fake = False

NULL_not_found(Nothing)
NULL_not_found(Garlic)
NULL_not_found(Zero)
NULL_not_found(Empty)
NULL_not_found(Fake)
print(NULL_not_found("Brian"))
