tst:Demo.o CMap.o Node.o Edge.o
	g++ Demo.o CMap.o Node.o Edge.o  tst
Demo.o:Demo.cpp
	g++ Demo.cpp -o Demo.o
CMap.o:CMap.cpp
	g++ CMap.cpp -o CMap.o
Edge.o:Edge.cpp
	g++ Edge.cpp -o Edge.o
Node.o:Node.cpp
	g++ Node.cpp -o Node.o
clean:
	rm *.o tst
