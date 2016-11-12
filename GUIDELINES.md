Guidelines for the SigFig class

Style:

- limit lines to 80 characters
- use 1TBS
- constants should be named 'CONSTANT_NAME_HERE'
- variables should be named 'variableNameHere'
- private variables should be named 'variableNameHere_'
- classes should be named 'ClassNameHere'
- methods should be named 'methodNameHere'
- spaces before and after every operator
- random intances of 'ClassNameHere' should be called 'aClassNameHere'
	- if the class is an unhelpfully named C++ class, call it 'classNameHere'
		with less abbreviated words

Development Environment:

- make sure all code compiles and runs correctly in clang, complying with
	C++11 and using libstdc++.
	Example - Run this line of code to compile
		$ clang++ -std=c++11 -stdlib=libstdc++ <filename>.cpp