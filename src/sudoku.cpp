#include "sudoku.h"

sudoku::sudoku(){
	f9(i)f9(j)s[i][j]=0;
	init_sat();
}

bool sudoku::solve(){
	make_assumptions();
	if(sat.solve(&assumptions) == l_True){
		model_to_sudoku(sat.get_model());
		return true;
	}
	return false;
}

void sudoku::out(){
    f9(j){
        f9(i)cout<<(int)s[i][j]<<(i<8?" ":"");
        cout<<endl;
    }
}

void sudoku::init_from_istream(istream& is){
    char c;
    f9(j)f9(i){
        do is>>c;
        while(c<48 || c>57);
        s[i][j] = c-48;
    }
}

void sudoku::init_from_stdin(){
    init_from_istream(cin);
}

void sudoku::init_from_file(const string& file){
    ifstream ifs;
    ifs.open(file);
    init_from_istream(ifs);
    ifs.close();
}

void sudoku::init_sat(){
	sat.new_vars(729);
	vector<Lit> clause;
	
	//each cell contains at least 1 number
	f9(i)f9(j){
		f19(k)clause.push_back(Lit(to_v(i, j, k), false));
		sat.add_clause(clause);
		clause.clear();
	}

	//each cell contains no more than 1 number
	f9(i)f9(j)l(k,1,9)l(w,k+1,10){
		clause.push_back(Lit(to_v(i, j, k), true));
		clause.push_back(Lit(to_v(i, j, w), true));
		sat.add_clause(clause);
		clause.clear();
	}

	//each row contains every number
	f9(j)f19(k){
		f9(i)clause.push_back(Lit(to_v(i, j, k), false));
		sat.add_clause(clause);
		clause.clear();
	}

	//each column contains every number
	f9(i)f19(k){
		f9(j)clause.push_back(Lit(to_v(i, j, k), false));
		sat.add_clause(clause);
		clause.clear();
	}

	//each group contains every number
	fg(i,j)f19(k){
		fg(w,x)clause.push_back(Lit(to_v(i*3+w, j*3+x, k), false));
		sat.add_clause(clause);
		clause.clear();
	}
}

void sudoku::make_assumptions(){
	assumptions.clear();
	f9(i)f9(j)if(s[i][j])f19(k)assumptions.push_back(Lit(to_v(i,j,k), s[i][j]!=k));
}

void sudoku::model_to_sudoku(const vector<lbool>& model){
	f9(i)f9(j)f19(k)if(model[to_v(i, j, k)] == l_True){
		s[i][j] = k;
		break;
	}
}

ssint sudoku::to_v(const sint i, const sint j, const sint k){
	return i*81 + j*9 + k - 1;
}
