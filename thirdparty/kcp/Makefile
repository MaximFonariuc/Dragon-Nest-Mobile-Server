
BUILD = libkcp.a

${BUILD} : ikcp.o
	ar rc $(BUILD) ikcp.o
	ranlib $(BUILD)

ikcp.o : ikcp.c
	gcc -c -o ikcp.o ikcp.c

clean :
	rm -f ${BUILD}
	rm -f ikcp.o
	@echo "clean success..."
