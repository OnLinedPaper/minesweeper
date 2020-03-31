minesweeper: minesweeper.cpp minesweeper.h land.h grid.h
	clang++ -Wall -g -o minesweeper minesweeper.cpp

clean:
	rm minesweeper
