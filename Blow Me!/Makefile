output: Blow\ Me\!.o Animation.o Background.o Bubble.o Entity.o Fan.o ScreenManager.o
	g++ Blow\ Me\!.o Animation.o Background.o Bubble.o Entity.o Fan.o ScreenManager.o -lm -Wall -Wextra -lraylib -lGL -lpthread -ldl -lrt -lX11 -o output
	mkdir build/
	mv *.o build/
	./output

Blow\ Me\!.o:  
	g++ -c Blow\ Me\!.cpp

Animation.o: Animation.cpp Animation.hpp
	g++ -c Animation.cpp

Background.o: Background.cpp Background.hpp
	g++ -c Background.cpp

Bubble.o: Bubble.cpp Bubble.hpp
	g++ -c Bubble.cpp

Entity.o: Entity.cpp Entity.hpp
	g++ -c Entity.cpp

Fan.o: Fan.cpp Fan.hpp
	g++ -c Fan.cpp

ScreenManager.o: ScreenManager.cpp ScreenManager.hpp
	g++ -c ScreenManager.cpp

clean:
	rm -r build
	rm output
