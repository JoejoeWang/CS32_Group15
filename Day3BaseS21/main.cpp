/* ZJW simple C++ code to write out a PPM file representing an ellipse(s) */

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "ppmR.h"
#include "color.h"
#include "ellipse.h"

using namespace std;


/*write out PPM data, using the defined implicit equation 
  interior points write a differnt color then exterior points */
void writeOut(ostream& out, ppmR& theWriter, vector<shared_ptr<ellipse> > IEs) {

	float res;
	color inC;
	color background(12, 34, 56);
	bool inTrue = false;

	//for every point in the 2D space
	for (int y=0; y < theWriter.height; y++) {
		for (int x =0; x < theWriter.width; x++) {

			inTrue = false;
			//iterate through all possible equations (note 'front' determined by order in vector)
			for (auto eq : IEs) {
				res = eq->eval(x, y);
				if (res < 0) {
					inC = eq->getInC();
					inTrue = true;
				}
			}
			if (inTrue) {			
				theWriter.writePixel(out, x, y, inC);
			}
			else
				theWriter.writePixel(out, x, y, background);
		}
		theWriter.writeNewLine(out);
	}
}


/*read command line arguments and write out new ascii file of given size */
int main(int argc, char *argv[]) {

	ofstream outFile;
	int sizeX, sizeY;

	// create all the equations for a simple asci face
	// note order in vector matters
	vector<shared_ptr<ellipse> > theEquations;
	theEquations.push_back(make_shared<ellipse>(116, 116, 80, 120, color(34, 98, 112)));
	theEquations.push_back(make_shared<ellipse>(52, 90, 20, 33,color(34, 198, 112)));
	theEquations.push_back(make_shared<ellipse>(168, 90, 20, 33,color(34, 198, 112)));
	theEquations.push_back(make_shared<ellipse>(116, 140, 50, 30,color(134, 98, 112)));


	if (argc < 4) {
		cerr << "Error format: a.out sizeX sizeY outfileName" << endl;
	} else {
		sizeX = stoi(argv[1]);
		sizeY = stoi(argv[2]);
		ppmR theWriter(sizeX, sizeY);
		outFile.open(argv[3]);
		if (outFile) {
			cout << "writing an image of size: " << sizeX << " " << sizeY << " to: " << argv[3] << endl;
			theWriter.writeHeader(outFile);
			writeOut(outFile, theWriter, theEquations);
		} else {
			cout << "Error cannot open outfile" << endl;
			exit(0);
		}
	}

}
