libgl2d.a: gl2d.o
	ar rcs libgl2d.a gl2d.o

gl2d.o: gl2d.c gl2d.h
	gcc -c gl2d.c -o gl2d.o

.PHONY: clean install

clean:
	rm gl2d.o libgl2d.a

install: gl2d.h libgl2d.a
	cp gl2d.h /usr/local/include/GL
	cp libgl2d.a /usr/local/lib

