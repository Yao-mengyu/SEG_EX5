SUBDIR  =  ./UI
MAKE  =  make
subsystem:
	cd $(SUBDIR)  &&  $(MAKE)


clean:
	cd $(SUBDIR)  && make clean

run:
	./UI.out ./output/equal.csv .