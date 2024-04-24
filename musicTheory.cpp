//
// musicTheory.cpp
// Created by Khoa Nguyen on 4/22/24.

#include "musicTheory.h"

musicTheory::musicTheory(){
	query();
	cout << "Thank you for using the Music Theory assistant by Khoa T. Nguyen." << endl;
}

vector<string> musicTheory::gen_maj_scale(string tonic){
	int index = find_note(tonic, notes);
	vector<string> maj_scale;
	int k = 0;
	while(index < notes.size() and maj_scale.size() < 7){
		maj_scale.push_back(notes[index]);
		index += maj_scale_form[k];
		index %= 12;
		k++;
	}
	return maj_scale;
}

vector<string> musicTheory::gen_maj_triad(string tonic) {
	int index = find_note(tonic, notes);
	vector<string> maj_chord;
	maj_chord.push_back(tonic);
	maj_chord.push_back(notes[(index+4)%12]);
	maj_chord.push_back(notes[(index+7)%12]);
	return maj_chord;
}

vector<string> musicTheory::gen_nat_min_scale(string tonic){
	int index = find_note(tonic, notes);
	vector<string> nat_min_scale;
	int k = 0;
	while(index < notes.size() and nat_min_scale.size() < 7){
		nat_min_scale.push_back(notes[index]);
		index += nat_min_scale_form[k];
		index %= 12;
		k++;
	}
	return nat_min_scale;
}

int musicTheory::find_note(string note, vector<string> scale) {
	for(int i = 0; i < scale.size(); i++){
		if(scale[i] == note) {
			return i;
		} 
	}
	return -1;
}

int musicTheory::interval_calc(string note_low, string note_high) {
	int ind_low_note = find_note(note_low, notes);
	int ind_high_note = find_note(note_high, notes);
	if(ind_high_note == -1 or ind_low_note == -1) {
		return -1000;
	}
	if (ind_high_note >= ind_low_note) {
		return ind_high_note - ind_low_note;
	} else {
		return 12 + ind_high_note - ind_low_note;
	}
}

void musicTheory::query() {
	string input;
	cout << "query? ";
	while(cin >> input) {
		if (input == "maj_scale") {
			cin >> input;
			vector<string> scale = gen_maj_scale(input);
			cout << "the notes in " << input << " major scale are: ";
			for (auto &x : scale) {
				cout << x << " ";
			}
			cout << endl;
		} else if (input == "nat_min_scale") {
			cin >> input;
			vector<string> scale = gen_nat_min_scale(input);
			cout << "the notes in " << input << " natural minor scale are: ";
			for (auto &x : scale) {
				cout << x << " ";
			}
			cout << endl;
		} else if (input == "interval") {
			string note1, note2;
			cin >> note1 >> note2;
			int interval = interval_calc(note1, note2);
			if(interval < 0) {
				cout << "one or both of the notes do not exist! Check your input. The program only supports sharps (#)" << endl;
			} else {
				cout << "the interval between " << note1 << " and " << note2 << " is " 
				<< interval << " semitone(s)" << endl;

			}
		} else if (input == "maj_triad") {
			cin >> input;
			vector<string> scale = gen_maj_triad(input);
			cout << "the notes in " << input << " major triad are: ";
			for (auto &x : scale) {
				cout << x << " ";
				cout << endl;
			}
		} else if (input == "deg") {
			string scale_name, tonic;
			int deg;
			cin >> scale_name >> deg >> tonic;
			if(scale_name == "maj") {
				vector<string> scale = (gen_maj_scale(tonic));
				cout << "the " << deg <<"th degree of the " << tonic << " major scale is " << scale[(deg-1)%7] << endl;
			} else if (scale_name == "nat_min") {
				vector<string> scale = (gen_nat_min_scale(tonic));
				cout << "the " << deg <<"th degree of the " << tonic 
				<< " natural minor scale is " << scale[(deg-1)%7] << endl;
			}
		} else if (input == "quit") {
			return;
		}
		cout << "query? ";
	}
}
