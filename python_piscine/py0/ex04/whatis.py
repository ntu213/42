
import sys as system

def ft():
	argv = system.argv
	argc = len(argv)

	if (argc < 2):
		return
	if (argc > 2):
		print("AssertionError: more than one argument is provided")
		return
	if (argv[1].lstrip("-+").isdigit() != 1):
		print("AssertionError: argument is not an integer")
		return
	if (int(argv[1]) % 2):
		print("I'm Odd.")
	else:
		print("I'm Even.")

ft()
