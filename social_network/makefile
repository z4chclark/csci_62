COMP = g++
FLAGS = -Wall -g


output: social_network.o network.o user.o post.o incoming_post.o
	$(COMP) -g social_network.o network.o user.o post.o incoming_post.o -o $@ $(FLAGS)

%.o: %.cpp
	$(COMP) -c $< -o $@ $(FLAGS)

clean:
	rm *.o output test

run: output
	./output < input.txt

test: test.o network.o user.o
	g++ -o test test.cpp network.cpp user.cpp
	./test
