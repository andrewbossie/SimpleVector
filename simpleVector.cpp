// Andrew Bossie
// simpleVector.cpp

#include <iostream>
#include <string>

using namespace std;

bool again = true;
int s;

template <class S>

class SimpleVector{

	 int size;
	 S *vectorArray;
	 
public:

	SimpleVector();						// default constructor
	SimpleVector(int s);					// 1 arg constructor
	~SimpleVector()	;					// deconstructor
	SimpleVector(const SimpleVector & );	// copy constructor

	int getSize(){						// accessor for size
		return size;
	}

	S getElement(int elem);		
	void setElement(int elem, S v);			// return element at i
	S &operator[] (const int &);		// overloaded op

};


template <class S>
SimpleVector<S>::SimpleVector(){		// no arg
	vectorArray = 0;
	vectorArray = new S [0];
	size = 0;
}

template <class S>
SimpleVector<S>::SimpleVector(int s){		// 1 arg

	size = s;
	vectorArray = new S [s];

}

template <class S>
SimpleVector<S>::~SimpleVector(){					// destructs array
	delete [] vectorArray;
}

template <class S>
SimpleVector<S>::SimpleVector(const SimpleVector & copy){		// copies data from one array to a new array, duplicates

	size = copy.size;
	vectorArray = new S [size];

	for (int count = 0; count < size; count++){
		*(vectorArray + count) = *(copy.vectorArray + count);
	}


}

template <class S>	
S &SimpleVector<S>::operator [](const int & elem){		// overloaded operator to return array element

		return vectorArray[elem];
}

template <class S>
S SimpleVector<S>::getElement(int elem){				// returns array setElement
	return vectorArray[elem];
}

template <class S>
void SimpleVector<S>::setElement(int elem, S v){		// sets element in array
	vectorArray[elem] = v;
}



int main(){

	char reply;						// variables
	int integer;
	string str;
	double db;
	int index;
	bool getAgain = true;
	char answer;
	char temp;

	while (again == true){

		SimpleVector <int> intArray(s);				// initialize new simple vector arrays from templates.
		SimpleVector <double> doubleArray(s);
		SimpleVector <string> stringArray(s);


		cout << "What data would you like to input?" << endl;
		cout << "Enter '1' for integer, '2' for double or '3' for string: ";
		cin >> reply;
		cout << endl;


		cout << "How many data inputs do you have? ";
		cin >> s;

			for (int i = 0; i <= s; i++){

				cout << "Please enter your data: " << endl;			// Everything was working fine, until segmentation fault 11 here...
																	// I cant figure out why. 
				if (reply == 1){									// This part only works sometimes. 
					cin >> integer;
					intArray.setElement(i, integer);
				}

				else if (reply == 2){
					cin >> db;
					doubleArray.setElement(i, db);
				}

				else {
					cin >> str;
					stringArray.setElement(i, str);
				}
			}

		while (getAgain == true){	

			cout << "What index would you like the data for? ";			// prompt for get array element
			cin >> index;
			cout << endl;

			if (reply == 1){
					cout << intArray.getElement(index) << endl;
				}

				else if (reply == 2){
					cout << doubleArray.getElement(index) << endl;
				}

				else {
					cout << stringArray.getElement(index) << endl;
				}

			cout << "Would you like data for another index? Y or N: ";
			cin >> answer;

			 if (answer == 'Y'){
			 	getAgain = true;
			 }

			 else {
			 	getAgain = false;
			 }

		}

		cout << "New copied integer array: " << endl;			// call to copy arrays
		SimpleVector <int> copyInt(intArray);
		for (int i = 0; i < s; i++){
			cout << copyInt.getElement(i);
		}

		cout << "New copied string array: " << endl;
		SimpleVector <double> copyDouble(doubleArray);
		for (int i = 0; i < s; i++){
			cout << copyDouble.getElement(i);
		}

		cout << "New copied string array: " << endl;		
		SimpleVector <string> copyString(stringArray);
		for (int i = 0; i < s; i++){
			cout << copyString.getElement(i);
		}


		cout << "Would you like to start over? Y or N? ";
		cin >> temp;

		if (temp == 'Y'){
			 	again = true;
			 }

			 else {
			 	again = false;
			 }

	}

	return 0;
}