all: cpp
python: in.txt testing.py
	timeout 0.5s bash -c 'python testing.py < in.txt &> out.txt' || echo '\nFAILED' >> out.txt
cpp: in.txt out.txt a.out
	timeout 0.5s bash -c './a.out < in.txt &> out.txt' || echo '\nFAILED' >> out.txt
a.out: temp.cpp
	g++ -g -Wall -O2 -fsanitize=address,undefined temp.cpp
debug:
	g++ -g temp.cpp
