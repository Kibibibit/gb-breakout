CC	= ${GBDK}/lcc -Wa-l -Wl-m -Wl-j

BINS	= breakout.gb

all:	$(BINS)

%.o:	%.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o:	%.s
	$(CC) $(CFLAGS) -c -o $@ $<

%.s:	%.c
	$(CC) $(CFLAGS) -S -o $@ $<

%.gb:	%.o
	$(CC) -o $@ $<

clean:
	rm -f *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm *.noi

breakout.gb:	breakout.o load_data.o sprites.o object.o
	$(CC) $(CFLAGS) -Wm-yC -o breakout.gb breakout.o load_data.o sprites.o object.o
