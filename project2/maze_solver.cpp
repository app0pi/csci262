/*
    CSCI 262 Data Structures, Fall 2018, Assignment 2 - mazes

    maze_solver.cpp

    Code for the maze_solver class.  This class will use stack-based depth
    first search or queue-based breadth first search to find a solution (if
    one exists) to a simple maze.

    C. Painter-Wakefield
*/

#include "maze_solver.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// TODO: read the complete assignment instructions before beginning.  Also look
// at maze_solver.h - you will need to modify it as well.  In this file you
// will need to complete several methods, and add any others as needed for your
// solution. 


/*
 _read_maze()

 Read in maze information (rows, columns, maze) from the provided input stream.
*/
void maze_solver::_read_maze(istream& in) {
    // TODO: write this method
    in >> _rows >> _columns;
    for(int i=0; i<_rows; i++) {
		string digit;
		in >> digit;
		_maze.push_back(digit);
	}
}


/*
 _write_maze()

 Output the (partially or totally solved) maze on the provided output stream.
*/
void maze_solver::_write_maze(ostream& out) {
    // TODO: write this method
    for(string line: _maze) {
    	cout << line << endl;
    }
}


/*
 _initialize()

 Find the start point.  Push or enqueue the start point.
*/
void maze_solver::_initialize() {
	// TODO: write this method
	int row, column;
	for(int i=0; i<_rows; i++) {
		for(int j=0; j<_columns; j++) {
			if(_maze.at(i).at(j)=='o') {
				row = i;
				column = j;
			}
		}
	}
    point start(row, column);
	_stack.push(start);
	_queue.push(start);
}


/*
 _step()

 Take *one* step towards solving the maze, setting _no_more_steps and
 _goal_reached as appropriate.  This implements the essential maze search
 algorithm; take the next location from your stack or queue, mark the
 location with '@', add all reachable next points to your stack or queue,
 etc.

 Notes:

 - Your initial point should have been pushed/enqueued in the _initialize()
   method.

 - Set the _no_more_steps variable to true when there are no more reachable
   points, or when the maze was successfully solved.

 - Set the _goal_reached variable to true if/when the maze was successfully
   solved.

 - You should write an '@' over every location you have previously visited,
   *except* for the start and goal positions - they should remain 'o' and '*',
   respectively.

 - Since the run() method will call _write_maze() in between calls to _step(),
   you probably want to try to make progress on each call to step.  On some
   mazes, depending on your approach, it may be possible to add the same
   point multiple times to your stack or queue - i.e., if a point is reachable
   from multiple other points.  When this happens, your code will work, but
   it may make very slow progress.  To fix the problem, simply run a loop to
   scavenge any already visited points from your stack or queue at the beginning
   or end of _step().

 - There are many approaches to dealing with invalid/unreachable points; you
   can choose to add them and then remove them next time you get into _step(),
   you can choose to not add them in the first place, etc.

 - It is strongly recommended that you make helper methods to avoid code
   duplication; e.g., a function to detect that a point is out of bounds is
   a real help on the mazes with no walls.  You can also think about pulling
   out methods that do the actual acting on stacks/queues - this will reduce
   code duplication, since everything is identical between the two except
   for whether you use your stack or queue.  E.g., you could have methods
   named "_push", "_pop", "_next" which use the appropriate data structure.

 - Make sure you follow the order given in the assignment instructions for
   adding points to your data structure - up, right, down, left - or your
   final maze solution won't match the expected solution.  Check against the
   sample solutions provided.
*/
void maze_solver::_step() {
	// TODO: write this method
	if(_use_stack) {
		if(_stack.empty() || _goal_reached) {
			_no_more_steps = true;
			return;
		}

		point current = _stack.top();

		if(_maze.at(current.get_row()).at(current.get_column())!='o' && _maze.at(current.get_row()).at(current.get_column())!='*') {
			_maze.at(current.get_row()).at(current.get_column()) = '@';
		}

		if(_maze.at(current.get_row()).at(current.get_column())=='*') {
			_goal_reached = true;
			_no_more_steps = true;
			return;
		}

		point up(current.get_row()-1,current.get_column());
		point right(current.get_row(),current.get_column()+1);
		point down(current.get_row()+1,current.get_column());
		point left(current.get_row(),current.get_column()-1);
		if(_within_boundary(up) && (_maze.at(up.get_row()).at(up.get_column())=='.' || _maze.at(up.get_row()).at(up.get_column())=='*')) {
			_stack.push(up);
			return;
		} else if(_within_boundary(right) && (_maze.at(right.get_row()).at(right.get_column())=='.' || _maze.at(right.get_row()).at(right.get_column())=='*')) {
			_stack.push(right);
			return;
		} else if(_within_boundary(down) && (_maze.at(down.get_row()).at(down.get_column())=='.' || _maze.at(down.get_row()).at(down.get_column())=='*')) {
			_stack.push(down);
			return;
		} else if(_within_boundary(left) && (_maze.at(left.get_row()).at(left.get_column())=='.' || _maze.at(left.get_row()).at(left.get_column())=='*')) {
			_stack.push(left);
			return;
		}
		_stack.pop();
		return;
	}
	else {

		if (_queue.empty() || _goal_reached) {
			_no_more_steps = true;
			return;
		}

		point current = _queue.front();

		if (_maze.at(current.get_row()).at(current.get_column()) != 'o' &&
			_maze.at(current.get_row()).at(current.get_column()) != '*') {
			_maze.at(current.get_row()).at(current.get_column()) = '@';
		}

		if (_maze.at(current.get_row()).at(current.get_column()) == '*') {
			_goal_reached = true;
			_no_more_steps = true;
			return;
		}

		point up(current.get_row() - 1, current.get_column());
		point right(current.get_row(), current.get_column() + 1);
		point down(current.get_row() + 1, current.get_column());
		point left(current.get_row(), current.get_column() - 1);
		if (_within_boundary(up) &&
			(_maze.at(up.get_row()).at(up.get_column()) == '.' || _maze.at(up.get_row()).at(up.get_column()) == '*')) {
			_queue.push(up);
			//return;
		} if (_within_boundary(right) && (_maze.at(right.get_row()).at(right.get_column()) == '.' ||
											   _maze.at(right.get_row()).at(right.get_column()) == '*')) {
			_queue.push(right);
			//return;
		} if (_within_boundary(down) && (_maze.at(down.get_row()).at(down.get_column()) == '.' ||
											  _maze.at(down.get_row()).at(down.get_column()) == '*')) {
			_queue.push(down);
			//return;
		} if (_within_boundary(left) && (_maze.at(left.get_row()).at(left.get_column()) == '.' ||
											  _maze.at(left.get_row()).at(left.get_column()) == '*')) {
			_queue.push(left);
			//return;
		}
		_queue.pop();

		return;
	}
}

bool maze_solver::_within_boundary(point p) {
	if(p.get_row()>=0 && p.get_row()<_rows && p.get_column()>=0 && p.get_column()<_columns)
		return true;
	return false;
}

/***************************************************************************
    You should not need to modify code below this point.  Touch at your own
    risk!
****************************************************************************/

/*
 maze_solver constructor

 You should not need to modify this.  It opens the maze file and passes
 the input stream to read_maze(), along with setting up some internal state
 (most importantly, the variable telling you whether to use a stack or
 a queue).
*/
maze_solver::maze_solver(string infile, bool use_stak, bool pause) {
	_use_stack = use_stak;
	_do_pause = pause;

	_no_more_steps = false;
	_goal_reached = false;

	// parse out maze name for later use in creating output file name
	int pos = infile.find(".");
	if (pos == string::npos) {
		_maze_name = infile;
	} else {
		_maze_name = infile.substr(0, pos);
	}

	// open input file and read in maze
	ifstream fin(infile);

	_read_maze(fin);

	fin.close();
}

/*
 run()

 Initializes the maze_solver, then runs a loop to keep moving forward towards
 a solution.

 While more steps are possible (while no_more_steps == false), run() calls
 step(), then calls() write_maze() on cout, then pause().  Once there are no
 more steps, it prints a success/failure message to the user (based on the
 goal_reached flag) and writes the final maze to a solution file.
*/

void maze_solver::run() {
    _initialize();

	cout << "Solving maze '" << _maze_name << "'." << endl;
	cout << "Initial maze: " << endl << endl;
	_write_maze(cout);
	cout << endl;
	_pause();

	// main loop
	while (!_no_more_steps) {
		_step();
		cout << endl;
		_write_maze(cout);
		cout << endl;
		_pause();
	}

	// final output to user
	cout << "Finished: ";
	if (_goal_reached) {
		cout << "goal reached!" << endl;
	} else {
		cout << "no solution possible!" << endl;
	}

	// save solution file
	string outfile;
	if (_use_stack) outfile = _maze_name + "-stack-solution.txt";
	else outfile = _maze_name + "-queue-solution.txt";
	
	ofstream fout(outfile);
	if (!fout) {
		cerr << "Could not open file \"" << outfile << "\" for writing." << endl;
		cerr << "Solution file could not be saved!" << endl;
	}
	else {
		_write_maze(fout);
		fout.close();
	}
}


/*
 pause()

 Pauses execution until user hits enter (unless do_pause == false).
*/
void maze_solver::_pause() {
	if (!_do_pause) return;
	string foo;
	cout << "Hit Enter to continue...";
	getline(cin, foo);
}

