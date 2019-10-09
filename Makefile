all: cpp
kotlin: in.txt out.txt k_out.jar
	timeout 0.5s bash -c 'java -jar k_out.jar < in.txt &> out.txt' || echo 'FAILED\nRuntime Error or Timeout' >> out.txt
k_out.jar: program.kt
	kotlinc program.kt -include-runtime -d k_out.jar
python: in.txt python.py
	timeout 5s bash -c '/home/st0rmbring3r/miniconda3/bin/python python.py < in.txt &> out.txt' || echo '\nFAILED' >> out.txt
cpp: in.txt out.txt a.out
	timeout 1s bash -c './a.out < in.txt &> out.txt' || echo 'FAILED\nRuntime Error or Timeout' >> out.txt
cpp-fast: in.txt out.txt
	g++ -DLOCAL -std=c++17 temp.cpp
	timeout 0.5s bash -c './a.out < in.txt &> out.txt' || echo 'FAILED\nRuntime Error or Timeout' >> out.txt
a.out: temp.cpp
	time g++ -DLOCAL -std=c++17 -g -Wall -Wextra -O2 -fsanitize=address,undefined temp.cpp
debug:
	g++ -DLOCAL -std=c++17 -g temp.cpp
brute:
	bash -c '/home/st0rmbring3r/miniconda3/bin/python checker.py &> out.txt'