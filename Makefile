CMD=g++
OBJS=IntegerListArray.o IntegerListVector.o IntegerListLinked.o IntegerListSorted.o ListExceptions.o

listTest: listTest.cpp IntegerListArray.h IntegerListVector.h IntegerListLinked.h \
	  IntegerListSorted.h List.h List.hxx Node.h $(OBJS)
	$(CMD) -o listTest listTest.cpp $(OBJS)

IntegerListArray.o: IntegerListArray.cpp IntegerListArray.h ListExceptions.h ListExceptions.cpp
	$(CMD) -c IntegerListArray.cpp

IntegerListVector.o: IntegerListVector.cpp IntegerListVector.h ListExceptions.h ListExceptions.cpp
	$(CMD) -c IntegerListVector.cpp

IntegerListLinked.o: IntegerListLinked.cpp IntegerListLinked.h Node.h ListExceptions.h ListExceptions.cpp
	$(CMD) -c IntegerListLinked.cpp

IntegerListSorted.o: IntegerListSorted.cpp IntegerListSorted.h Node.h ListExceptions.h ListExceptions.cpp
	$(CMD) -c IntegerListSorted.cpp

ListExceptions.o: ListExceptions.cpp ListExceptions.h
	$(CMD) -c ListExceptions.cpp

clean:
	rm -f listTest IntegerListArray.o IntegerListVector.o \
		IntegerListLinked.o List.o IntegerListSorted.o ListExceptions.o

run: listTest
	make
	./listTest
