CPP = g++
OFLAG = -o
CAIROMM = `pkg-config --cflags --libs cairomm-1.0`
.SUFFIXES: .o .cpp
.cpp.o:
	$(CPP) -c $< $(CAIROMM)
main: main.o math.o turtle.o 
	$(CPP) $(OFLAG)main main.o math.o turtle.o $(CAIROMM)
all: \
	main.o
	math.o
	turtle.o
	


#	$(CPP) main.cpp math.cpp turtle.cpp -o main `pkg-config --cflags --libs cairomm-1.0`
	
