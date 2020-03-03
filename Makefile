OBJS=llist.o main.o

llist: $(OBJS)
		g++ -g -o $@ $^

.cpp.o:
		g++ -I. -g -c -o $@ $<


clean:
		rm -f *.o llist
