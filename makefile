Lab03: main.o MathTools.o Executive.o NegativeDiscriminant.o NoIntersection.o CannotDetermineRoomDimensions.o
	g++ -std=c++11 -g -Wall main.o MathTools.o Executive.o NegativeDiscriminant.o NoIntersection.o CannotDetermineRoomDimensions.o -o Lab03

main.o: Executive.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: MathTools.h Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

MathTools.o: MathToolsInterface.h MathTools.h MathTools.cpp
	g++ -std=c++11 -g -Wall -c MathTools.cpp

NegativeDiscriminant.o: NegativeDiscriminant.h NegativeDiscriminant.cpp
	g++ -std=c++11 -g -Wall -c NegativeDiscriminant.cpp

NoIntersection.o: NoIntersection.h NoIntersection.cpp
	g++ -std=c++11 -g -Wall -c NoIntersection.cpp

CannotDetermineRoomDimensions.o: CannotDetermineRoomDimensions.h CannotDetermineRoomDimensions.cpp
	g++ -std=c++11 -g -Wall -c CannotDetermineRoomDimensions.cpp

clean:
	rm Lab03 *.o
