// myCopier.cpp take 2 command line arguments
// Both arguments are text file
// First argument is a text file for reading
// Second argument is a text file for writing from the first argument file
// e.g ./myCopier input.txt output.txt

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define FILE_PATH "/home/debian/tranhw6"

int main(int argc, char* argv[]){
	if(argc!=3){
		cout << endl;
		cout << "Usage is ./myCopier and name of file: " << endl;
		cout << " e.g. ./myCopier input.txt output.txt " << endl;
		return 3;
	}
	string inputFileName(argv[1]);
	string outputFileName(argv[2]);
	cout << endl;
	cout << "Starting the reading-file program" << endl;
	cout << "The current FILE Path is: " << FILE_PATH << endl;
	cout << "File name passed is: " << inputFileName << endl;
	cout << endl;
	
	fstream fsInput;
	fstream fsOutput;
	string line;
	
	string filename = "/" + inputFileName;
	cout << "The string filename is: " << filename << endl;

	string pathName = FILE_PATH + filename;
	string path(FILE_PATH);
	cout << "The string pathName is: " << pathName << endl;
	cout << endl;

	// The c_str() method returns a C++ string as a C string.
	fsInput.open((pathName).c_str(), fstream::in);
	fsOutput.open((path+"/"+outputFileName).c_str(), std::fstream::out);

	while(getline(fsInput,line)) {
		fsOutput << line << endl;
	}

	fsInput.close();
	fsOutput.close();

	cout << "Finished copy " << inputFileName << " file to " << outputFileName << " file"  << endl;
	cout << endl;
	cout << endl;
	return 0;

}
