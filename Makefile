binary/picture:
	arm-linux-gcc source/*.c -o binary/picture  -I ./header

clean:
	rm binary/picture