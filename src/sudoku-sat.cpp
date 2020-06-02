#include "utils.h"
#include "sudoku.h"

void run();

int main(void){
	run();
	return 0;
}

void run(){
	sudoku s;
	s.init_from_stdin();
	if(s.solve())s.out();
	else cout<<"Unable to solve it."<<endl;
}
