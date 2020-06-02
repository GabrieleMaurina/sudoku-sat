all: sudoku-sat demo

sudoku-sat: src/sudoku-sat.cpp src/sudoku.h src/sudoku.cpp src/utils.h
	g++ -l cryptominisat5 -o sudoku-sat src/sudoku-sat.cpp src/sudoku.cpp

demo: src/demo.cpp src/sudoku.h src/sudoku.cpp src/utils.h
	g++ -l cryptominisat5 -o demo src/demo.cpp src/sudoku.cpp

clean:
	rm -f sudoku-sat demo
