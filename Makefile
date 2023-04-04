CXX = g++
OPTIONS = -Wall -std=c++11
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp Card.cpp Deck.cpp Hand.cpp
	$(CXX) $(OPTIONS) main.cpp Card.cpp Deck.cpp Hand.cpp -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM)

test: test.cpp Card.cpp Deck.cpp Hand.cpp
	g++ -Wall -std=c++11 test.cpp Card.cpp Deck.cpp Hand.cpp -o test

testRun: test
	./test