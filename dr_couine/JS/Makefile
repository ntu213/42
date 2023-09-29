
all:
	@echo "There is nothing to compile in JavaScript, use \"node <file.js>\""
	@echo "Use \"make test\" to execute all tests"

test: clean
	@echo
	node Colleen.js > tmp
	diff Colleen.js tmp
	@echo
	node Grace.js
	diff Grace.js Grace_kid.js
	@echo
	node Sully.js
	diff Sully.js Sully_5.js
	-diff Sully_0.js Sully_5.js
	@echo

clean:
	@rm -f tmp
	@rm -f Grace_kid.js
	@rm -f Sully_*.js

fclean: clean
