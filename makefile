## Program name: finalProject
## Author:       Rebekah Koon
## Date:         8/7/19
## Description:  Makefile for a game in which a thief attempts to
##               steal treasure from a castle. Collects items along
##               the way to help them in their quest.

finalProject: Space.o MainHall.o Kitchen.o Library.o Courtyard.o DiningRoom.o TrainingArea.o Tower.o Player.o Menu.o Game.o validInput.o main.o
	g++ -g Space.o MainHall.o Kitchen.o Library.o Courtyard.o DiningRoom.o TrainingArea.o Tower.o Player.o Menu.o Game.o validInput.o main.o -o finalProject

Space.o: Space.cpp Space.hpp
	g++ -c Space.cpp

MainHall.o: MainHall.cpp MainHall.hpp
	g++ -c MainHall.cpp

Kitchen.o: Kitchen.cpp Kitchen.hpp
	g++ -c Kitchen.cpp

Library.o: Library.cpp Library.hpp
	g++ -c Library.cpp

Courtyard.o: Courtyard.cpp Courtyard.hpp
	g++ -c Courtyard.cpp

DiningRoom.o: DiningRoom.cpp DiningRoom.hpp
	g++ -c DiningRoom.cpp

TrainingArea.o: TrainingArea.cpp TrainingArea.hpp
	g++ -c TrainingArea.cpp

Tower.o: Tower.cpp Tower.hpp
	g++ -c Tower.cpp

Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp

Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp

validInput.o: validInput.cpp validInput.hpp
	g++ -c validInput.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o finalProject