src = $(wildcard ./*.cpp)
obj = $(patsubst ./%.cpp,./%.o,$(src))
tar=main
$(tar):$(obj)
		g++ $(obj) -o $(tar)

%.o:%.c
		g++ -c $<

all:
		./UI/Makefile UI

clean:
		rm ./*.o main

run:
		./main input
