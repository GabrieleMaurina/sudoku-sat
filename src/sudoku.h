#include "utils.h"

struct sudoku{
	sint s[9][9];
	SATSolver sat;
	vector<Lit> assumptions;

	sudoku();

	inline sint* operator[](const sint i){
        return s[i];
    }

	bool solve();
	void out();

	void init_from_istream(istream& is);
	void init_from_stdin();
	void init_from_file(const string& file);

	void init_sat();
	void make_assumptions();
	void model_to_sudoku(const vector<lbool>& model);

	static ssint to_v(const sint i, const sint j, const sint k);
};
