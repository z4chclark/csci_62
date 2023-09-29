COMP = g++
FLAGS =-Wall -g

output: social_network.o user.o network.o
	$(COMP) social_network.o user.o network.o -o output

user.o: user.cpp
	$(COMP) -c $< -o $@

network.o: network.cpp
	$(COMP) -c $< -o $@

social_network.o: social_network.cpp
	$(COMP) -c $< -o $@


clean:
	rm *.o