CC=g++


werhauz: warehouse.o structure.o hashtable.o bucketlist.o cdr.o
	$(CC) -o werhauz warehouse.o structure.o hashtable.o bucketlist.o cdr.o 


warehouse.o: warehouse.cpp
	$(CC) -c warehouse.cpp

structure.o: structure.cpp
	$(CC) -c structure.cpp

hashtable.o: hashtable.cpp
	$(CC) -c hashtable.cpp

bucketlist.o: bucketlist.cpp
	$(CC) -c bucketlist.cpp

cdr.o: cdr.cpp
	$(CC) -c cdr.cpp




clean:
	rm -f werhauz
	rm -f warehouse.o
	rm -f structure.o
	rm -f hashtable.o
	rm -f bucketlist.o
	rm -f cdr.o

.PHONY: all clean


