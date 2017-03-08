converter:  main.o textToBin.o binToText.o
    gcc main. textToBin.o binToText.o binToStats.o -o converter
main.o: main.c
    gcc -c main.c
textToBin.o: textToBin.c
    gcc -c textToBin.c
binToText.o: binToText.c
    gcc -c binToText.c
binToStats.o:   bintToStats.c
    gcc -c binToStats.c
clean:
    rm *.o
