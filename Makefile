

all: main.cpp
	g++ -Werror -Wall main.cpp spck.cpp helpers.cpp -o main
	time ./main 

clean:
	rm main 