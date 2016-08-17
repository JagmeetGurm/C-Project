// EightPuzzle2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class puzzle{

private:


 int pos;
 vector <int>sequence;
	int depth;
	int val;
	int cost;
	int goalposition;



public:
	

	void Initial(vector<int> current_pos) {
		pos = arrayToNumber(current_pos);
		depth = 1;
	sequence.push_back(pos);
	}

	void Goalpos(vector<int> goal_pos) {
		goalposition = arrayToNumber( goal_pos);
		evaluate(goal_pos);
	}

	bool goal() {
		return (pos == goalposition);
	}

	vector<int> Moves() {
		vector<int>Moves;// = array();
		int i, j;
		vector<int>current_pos = numberToArray(pos);
		for (i = 0; i < 3; i++) {
			for ( j = 0; j < 3; j++) {
				if (current_pos[i][j] == 0) {
					break ;
				}
			}
		}

		checkMove(i, j, i - 1, j, current_pos, Moves);
		checkMove(i, j, i + 1, j, current_pos, Moves);
		checkMove(i, j, i, j - 1, current_pos, Moves);
		checkMove(i, j, i, j + 1, current_pos, Moves);

		return Moves;
	}

	vector<int> moveBlank(int srcRow, int srcCol, int destRow, int destCol, vector<int> newpos) {
		int tmp = newpos[destRow][destCol];
		newpos[destRow][destCol] = newpos[srcRow][srcCol];
		newpos[srcRow][srcCol] = tmp;
		return newpos;
	}

	bool InSequence(int pos) {
		foreach($this->sequence as $seqpos) {
			if ($seqpos == $pos) {
				return true;
			}
		}
		return false;
	}

	bool canMove(int srcRow, int srcCol, int destRow, int destCol) {
		if (srcRow < 0 || srcCol < 0 || destRow < 0 || destCol < 0) {
			return false;
		}
		if (srcRow > 2 || srcCol > 2 || destRow > 2 || destCol > 2) {
			return false;
		}
		return true;
	}

	function checkMove($srcRow, $srcCol, $destRow, $destCol, $current_pos, &$Moves) {
		if ($this->canMove($srcRow, $srcCol, $destRow, $destCol)) {
			$newpos = $this->moveBlank($srcRow, $srcCol, $destRow, $destCol, $current_pos);
			$posnum = $this->arrayToNumber($newpos);
			if ($this->InSequence($posnum) == FALSE) {
				//$newMove = new Puzzle();
				$newMove = clone $this;
				$newMove->pos = $posnum;
				//$newMove->sequence = array_merge($this->sequence);
				$newMove->sequence[] = $posnum;
				//$newMove->goalpos = $this->goalpos;
				$newMove->depth++;
				$newMove->evaluate($newpos);
				$Moves[] = $newMove;
			}
		}
	}

	function printSequence() {
		for ($i = 0; $i < count($this->sequence); $i++) {
			print("Step $i -------<br>   ");
			$pos = $this->numberToarray($this->sequence[$i]);
			$this->printPos($pos);
			print("<br>");
		}
	}

	function printPos($pos) {
		for ($i = 0; $i < 3; $i++) {
			for ($j = 0; $j < 3; $j++) {
				print(" ".$pos[$i][$j] . " ");
			}
			print("<br>");
		}
	}

	function printReverse() {
		for ($i = ($this->depth - 1); $i >= 0; $i--) {
			print("Step $i -------<br>   ");
			$pos = $this->numberToArray($this->sequence[$i]);
			$this->printPos($pos);
			print("<br>");
		}
	}

	function evaluate($pos) {
		//$pos = $this->numberToarray($this->pos);
		$this->heuristics($pos);
		$this->pathCost();
	}

	function heuristics($pos) {
		$goalpos = $this->numberToarray($this->goalpos);
		$this->val = 0;
		for ($i = 0; $i < 3; $i++) {
			for ($j = 0; $j < 3; $j++) {
				$blockrow = 0;
				$blockcol = 0;
				$this->findBlock($goalpos[$i][$j], $blockrow, $blockcol, $pos);
				$blockval = abs($blockrow - $i) + abs($blockcol - $j);
				$this->val = $this->val + $blockval;
			}
		}
	}

	function pathCost() {
		$this->path_cost = $this->depth;
	}

	function findBlock($val, &$i, &$j, $pos) {
		for ($i = 0; $i < 3; $i++) {
			for ($j = 0; $j < 3; $j++) {
				if ($pos[$i][$j] == $val) {
					break 2;
				}
			}
		}
	}

	function arrayToString($posarray) {
		$posstr = "";
		for ($i = 0; $i < 3; $i++) {
			$s = implode(",", $posarray[$i]);
			$posstr = $posstr . "|".$s;
		}
		return $posstr;
	}

	function stringToarray($posstr) {

		$posarray = array();
		$iterarray = explode("|", $posstr);
		for ($i = 1; $i < count($iterarray); $i++) {
			$posarray[] = explode(",", $iterarray[$i]);
		}
		return $posarray;
	}

	function arrayToNumber($posarray) {
		$posnum = 0;
		$multiplier = 100000000;
		for ($i = 0; $i < 3; $i++) {
			for ($j = 0; $j < 3; $j++) {
				//$pw = (2 - $j) + (2 - $i) * 3;
				$posnum = $posnum + $posarray[$i][$j] * $multiplier;  //pow(10, $pw);
				$multiplier = $multiplier / 10;
			}
		}
		return $posnum;
	}

	function numberToArray($posnum) {
		$posarray = array();
		$divider = 100000000;
		for ($i = 0; $i < 3; $i++) {
			for ($j = 0; $j < 3; $j++) {
				//$pw = (2 - $j) + (2 - $i) * 3;
				//$divider = pow(10, $pw);
				$posarray[$i][$j] = (int)($posnum / $divider);
				$posnum = $posnum % $divider;
				$divider = $divider / 10;
			}
		}
		return $posarray;
	}

};

int main(int argc, _TCHAR* argv[])
{

	return 0;
}

