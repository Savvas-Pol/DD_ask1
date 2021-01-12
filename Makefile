CC=gcc
CFLAGS=-Wall


askisi1: ch6_Simulation.o ch6_QArray.o TStoixeiouOuras.o tameio.o
	$(CC) $(CFLAGS) -o askisi1 ch6_Simulation.o ch6_QArray.o TStoixeiouOuras.o tameio.o

ch6_Simulation.o: ch6_Simulation.c
	$(CC) $(CFLAGS) -c ch6_Simulation.c

ch6_QArray.o: ch6_QArray.c
	$(CC) $(CFLAGS) -c ch6_QArray.c

TStoixeiouOuras.o: TStoixeiouOuras.c
	$(CC) $(CFLAGS) -c TStoixeiouOuras.c

tameio.o: tameio.c
	$(CC) $(CFLAGS) -c tameio.c


.PHONY: clean

clean:
	rm -f myprog myprog.o stack.o stacktype.o
