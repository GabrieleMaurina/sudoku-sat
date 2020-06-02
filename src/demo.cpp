#include "utils.h"
#include "sudoku.h"

const sint b_n = 20;
const string boards[b_n] = {
	"examples/easy/easy1.txt",
	"examples/easy/easy2.txt",
	"examples/easy/easy3.txt",
	"examples/easy/easy4.txt",
	"examples/easy/easy5.txt",
	"examples/medium/medium1.txt",
	"examples/medium/medium2.txt",
	"examples/medium/medium3.txt",
	"examples/medium/medium4.txt",
	"examples/medium/medium5.txt",
	"examples/hard/hard1.txt",
	"examples/hard/hard2.txt",
	"examples/hard/hard3.txt",
	"examples/hard/hard4.txt",
	"examples/hard/hard5.txt",
	"examples/expert/expert1.txt",
	"examples/expert/expert2.txt",
	"examples/expert/expert3.txt",
	"examples/expert/expert4.txt",
	"examples/expert/expert5.txt"
};

void run();
bool solve(sudoku& s, sint i);

int main(int argc, char** argv){
	run();
	return 0;
}

void run(){
	cout<<"*** Sudoku-sat demo ***"<<endl<<"Attempting to solve "<<(int)b_n<<" boards."<<endl<<endl;
	sint solved = 0;
	sudoku s;
	f(i,b_n) solved += solve(s, i);
	cout<<"Solved "<<(int)solved<<'/'<<(int)b_n<<" sudoku boards."<<endl;
}

bool solve(sudoku& s, sint i){
	bool solved;
	s.init_from_file(boards[i]);
	cout<<boards[i]<<endl;
	s.out();
	solved = s.solve();
	if(solved){
		cout<<"Solved:"<<endl;
		s.out();
		cout<<endl;
	}
	else cout<<"Unable to solve it."<<endl<<endl;
	return solved;
}
