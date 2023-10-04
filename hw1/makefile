COMP = g++
FLAGS = -Wall -g


output: social_network.o network.o user.o
	$(COMP) -g social_network.o network.o user.o -o $@ $(FLAGS)

%.o: %.cpp
	$(COMP) -c $< -o $@ $(FLAGS)

clean:
	rm *.o output


run: output
	./output < input.txt
