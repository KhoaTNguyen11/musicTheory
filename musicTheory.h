//
// musicTheory.h
// Created by Khoa Nguyen on 4/22/24.

#ifndef _musicTheory_h_
#define _musicTheory_h_

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class musicTheory{
	
	public:
	
		musicTheory();
		
		vector<string> gen_maj_scale(string tonic);
		
		vector<string> gen_nat_min_scale(string tonic);
		
		int interval_calc(string note_low, string note_high);
		
		vector<string> gen_maj_triad(string tonic);

		vector<string> gen_min_triad(string tonic);
		
		
	private:
		vector<string> notes{"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#",
			"A", "A#", "B"}; 
	
		int maj_scale_form[7] = {2, 2, 1, 2, 2, 2, 1};
		
		int nat_min_scale_form[7] = {2, 1, 2, 2, 1, 2, 2};
		
		int find_note(string note, vector<string> scale);
		
		void query();
		
};

#endif