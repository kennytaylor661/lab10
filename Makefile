all: lab10

lab10: lab10.cpp
	g++ lab10.cpp -Wall -olab10

clean:
	rm -f lab10

