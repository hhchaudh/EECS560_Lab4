lab4: main.o ClosedHashTable.o OpenHashTable.o DoubleLinkedList.o Node.o
	g++ -std=c++11 -g -Wall main.o ClosedHashTable.o OpenHashTable.o DoubleLinkedList.o Node.o -o lab4

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

ClosedHashTable.o: ClosedHashTable.h ClosedHashTable.cpp
	g++ -std=c++11 -g -Wall -c ClosedHashTable.cpp

OpenHashTable.o: OpenHashTable.h OpenHashTable.cpp
	g++ -std=c++11 -g -Wall -c OpenHashTable.cpp

DoubleLinkedList.o: DoubleLinkedList.h DoubleLinkedList.cpp
	g++ -std=c++11 -g -Wall -c DoubleLinkedList.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp

clean:
	rm *.o lab4
	echo clean done
