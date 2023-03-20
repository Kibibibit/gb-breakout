CC	= ${GBDK}/bin/lcc -Wa-l -Wl-m -Wl-j

BINS	= breakout.gb

all:	$(BINS)

%.o:	%.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o:	%.s
	$(CC) $(CFLAGS) -c -o $@ $<

%.s:	%.c
	$(CC) $(CFLAGS) -S -o $@ $<

%.gc:	%.o
	$(CC) -o $@ $<

clean:
	rm -f *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm *.noi *.adb *.gbc

breakout.gb:	breakout.o load_data.o trig.o sprites.o ball.o paddle.o helpers.o
	$(CC) $(CFLAGS) -Wm-yC -o breakout.gb trig.o breakout.o load_data.o sprites.o ball.o paddle.o helpers.o 
