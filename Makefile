#
all: create_folders
	g++ -Wall -fexceptions -O2 -std=c++11  -c "main.cpp" -o obj/main.o
	g++ -Wall -fexceptions -O2 -std=c++11  -c "Time.cpp" -o obj/Time.o
	g++ -Wall -fexceptions -O2 -std=c++11  -c "Edge.cpp" -o obj/Edge.o
	g++ -Wall -fexceptions -O2 -std=c++11  -c "Node.cpp" -o obj/Node.o
	g++ -Wall -fexceptions -O2 -std=c++11  -c "Dijkstra.cpp" -o obj/Dijkstra.o
	g++ -Wall -fexceptions -O2 -std=c++11  -c "Instance.cpp" -o obj/Instance.o

	g++  -o bin/Program obj/main.o obj/Time.o obj/Edge.o obj/Node.o obj/Instance.o obj/Dijkstra.o -s 
	
create_folders:
	mkdir obj
	mkdir bin

clean:
	rm -rf obj/
	rm -rf bin/

