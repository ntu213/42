
def all_thing_is_obj(obj):

	if (type(obj) == list):
		print("List :", type(obj))
	elif (type(obj) == tuple):
		print("Tuple :", type(obj))
	elif (type(obj) == set):
		print("Set :", type(obj))
	elif (type(obj) == dict):
		print("Dict :", type(obj))
	elif (type(obj) == str):
		print("Bryan is in the kitchen :", type(obj))
	else:
		print("Type not found")
	return (42)


# ft_list = ["Hello", "tata!"]
# ft_tuple = ("Hello", "toto!")
# ft_set = {"Hello", "tutu!"}
# ft_dict = {"Hello" : "titi!"}

# all_thing_is_obj(ft_list)
# all_thing_is_obj(ft_tuple)
# all_thing_is_obj(ft_set)
# all_thing_is_obj(ft_dict)
# all_thing_is_obj("Brian")
# print(all_thing_is_obj(10))
