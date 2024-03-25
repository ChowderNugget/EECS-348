#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// global variables
int array1[10][10];
int array2[10][10];
int a_size;

// functions
void readMatrices();
void printMatrices();
void addM();
void multiplyM();
void subM();
void updateM();
void maxM();
void transposeM();

int main() {

    readMatrices();
    printMatrices();
    addM();
    multiplyM();
    subM();
    updateM();
    maxM();
    transposeM();
    return 0;
}

void readMatrices() {

    ifstream myfile; myfile.open("matrix_input.txt");
    a_size = myfile.get() - '0';  // get size as character, subtract ASCII code of '0' (48) to save as integer 
    
    for (int i = 0; i < a_size; i++) {
        for (int j = 0; j < a_size; j++) {
            myfile >> array1[i][j];
        }
    }
    for (int i = 0; i < a_size; i++) {
        for (int j = 0; j < a_size; j++) {
            myfile >> array2[i][j];
        }
    }
}

void printMatrices() {
    
    cout << "\n\t" << "Matrix A:" << endl;
    for (int i = 0; i < a_size; i++) {
	for (int j = 0; j < a_size; j++) {
		cout << "\t" << array1[i][j];
	}
	cout << endl;
    }
    cout << "\n\t" << "Matrix B:" << endl;
    for (int i = 0; i < a_size; i++) {
	for (int j = 0; j < a_size; j++) {
	    cout << "\t" <<array2[i][j];
	}
    cout << endl;
    }
}

void addM() {
    cout << "\n\t" << "Matrix Sum (A + B):" << endl;
    int sum[a_size][a_size];
    for (int i = 0; i < a_size; i++) {
	for (int j = 0; j < a_size; j++) {
	    sum[i][j] = array1[i][j] + array2[i][j];
	    cout << "\t" << sum[i][j];
	}
    cout << endl;
    }
};

void multiplyM() {
    cout << "\n\t" << "Matrix Product (A * B):" << endl;
    int product[a_size][a_size] = {};
    for (int i = 0; i < a_size; i++) {
	for (int j = 0; j < a_size; j++) {
	    for (int k = 0; k < a_size; k++) {
		product[i][j] += array1[i][k] * array2[k][j];
	    }
	cout << "\t" << product[i][j];
	}
    cout << endl;
    }
};

void subM() {
    cout << "\n\t" << "Matrix Difference (A - B):" << endl;
    int difference[a_size][a_size] = {};
    for (int i = 0; i < a_size; i++) {
	for (int j = 0; j < a_size; j++) {
	    difference[i][j] = array1[i][j] - array2[i][j];
	    cout << "\t" << difference[i][j];
		}
		cout << endl;
	}
	cout << endl;
};

void updateM() {
    int row;
    int col;
    int value;
    cout << "\n\t" << "Enter Row to update:" << endl;
    cin >> row;
    cout << "\n\t" << "Enter Col to update:" << endl;
    cin >> col;
    cout << "\n\t" << "Enter new value:" << endl;
    cin >> value; 
    array1[row-1][col-1] = value;
    printMatrices();
}

void maxM() {
    cout << "\n\t" << "Max of Matrix A: ";	
    int max = array1[0][0];
    for (int i = 0; i < a_size; i++) {
        for (int j = 0; j < a_size; j++) {
	    if (array1[i][j] > max) {
	        max = array1[i][j];
	    }
	}
    }
    cout << max << endl;
}

void transposeM() {
    cout << "\n\t" << "Transpose of Matrix A:" << endl;
    int copy[a_size][a_size] = {0};
    for (int i = 0; i < a_size; i++) {
        for (int j = 0; j < a_size; j++) {
	    copy[i][j] = array1[j][i];
	}
    }
    for (int i = 0; i < a_size; i++) {
       for (int j = 0; j < a_size; j++) {
          cout << "\t" << copy[i][j];
       }
    cout << endl;
    }
    
}
