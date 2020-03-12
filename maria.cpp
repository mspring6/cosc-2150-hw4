#include <string.h>
#include <iostream>
#include <algorithm>
#include <io.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <queue>
#include <iomanip>
#include <memory>

using namespace std;

int main(int argc, char** argv) {

	int i;
	char *in, *out;
	
	in = NULL;
	out = NULL;

	for ( i = 1; i < argc; i++ ) {
		if ( strcmp ( argv[i], "--in" ) == 0 ) {
			if ( (i+1) < argc ) {
				in = argv[i+1];
                //cout << "The file name is: " << in << endl;
				i++;
			} else {
				cerr << "Error: --in missing file name\n" ;
				exit(1);
			}
		} else if ( strcmp ( argv[i], "--out" ) == 0 ) {
			if ( (i+1) < argc ) {
				out = argv[i+1];
				i++;
			} else {
				cerr << "Error: --out missing file name\n";
				exit(1);
			}
		} else {
			cerr << "Error: invalid parameter >" << argv[i] << "<\n";
			exit(1);
		}
	}

	if ( in == NULL ) {
		cerr << "Error: missing --in <fn> parameter\n" ;
		exit(1);
	}
	if ( out == NULL ) {
		cerr << "Error: missing --out <fn> parameter\n" ;
		exit(1);
	}

    // TODO: Add more code 

    // Read in Input file into `memory` 
	//char hex[30];
	//string line;
	long hexNum; 
	char sharp = '#';
	queue<int> hexValue;
	ifstream inFile;
	char *ptr;

	//open the file, read input 
	//push all inputs from file into a queue
	inFile.open(in);
	if (inFile.is_open()) {
		while (!inFile.eof()) {
			string line;
			getline(inFile, line);
			
			char hex[30];

			for (int i = 0; i < line.length; i++) {
				hex[i] = line[i];
			}

			//copy(line.begin(), line.end(), hex);

			if (sharp == hex[0]) {
				continue;
			}
			else {
				hexNum = strtol(hex, &ptr, 16);
				
				hexValue.push(hexNum);
			}
			/*for (int i = 0; i < hexValue.size(); i++) {
				cout << "hex Value: " << hexValue.front() << endl;
				hexValue.pop();
			}*/
		}
	}

	int pc = 0;
	int ir;
	int ac;
	int mar;
	int mdr;

	//fetch cycle
	for (int i = 0; i <= hexValue.size()+1; i++) {
		

		ir = hexValue.front();
		cout << "ir: " << ir << endl;
		pc++;
		int hand = 0;
		int op = 0;

		hand = ir & 0xFFF;
		op = (ir & 0xF000);
		op = op >> 12;
		
		cout << "op: " << op << endl;
		cout << "hand: " << hand << endl;

		switch(op) {
			case 0: mdr = pc;
					mar = hand;
					memory[hand] = mdr;
					ac = hand;
					ac = ac +1;
					pc = ac;
					break;

			case 1: mar = hand;
					mdr = memory[mar];
					ac = mdr;
					break;
			case 2: mar = hand;
					mdr = ac;
					memory[mar] = mdr;
					break;
			case 3: mar = hand;
					mdr = memory[mar];
					ac = ac - mdr;
					break;
			case 4: mar = hand;
					mdr = memory[mar];
					ac = ac - mdr;
					break;
			case 5: break;
			case 6: break;
			case 7: exit(1);
					break;
			case 8: break;
			case 9: pc = hand;
					break;
			case 10: ac = 0;
					break;
		}

		hexValue.pop();
	}

    // Loop until 'Halt' instruction 

        // Fetch 

        // Execute 

}