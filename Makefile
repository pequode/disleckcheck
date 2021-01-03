

all: main.cpp
	g++ -Werror -Wall main.cpp spck.cpp helpers.cpp -o main
	time ./main 

tess: test.cpp numm.cpp
	g++ -Werror -Wall test.cpp   -o test
	time ./test 
link:linkedin.cpp
	g++ -Werror -Wall linkedin.cpp  -o linked
	time ./linked
clean:
	rm main 