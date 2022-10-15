#include <iostream>
using namespace std;

int ternarySearch(int a[], int lowerBound, int upperBound, int searchVal){
	int oneThird = lowerBound+((upperBound-lowerBound)/3);
	int twoThirds = upperBound-((upperBound-lowerBound)/3);
	if (lowerBound>upperBound)
		return -1;
	else{
		if (a[oneThird] == searchVal)
			return oneThird;
		else if (a[twoThirds] == searchVal)
			return twoThirds;
		else if (a[oneThird]>searchVal)
			ternarySearch(a, lowerBound, oneThird-1, searchVal);
		else if ((a[oneThird]<searchVal) && (a[twoThirds]>searchVal))
			ternarySearch(a, oneThird+1, twoThirds-1, searchVal);
		else if (a[twoThirds]<searchVal)
			ternarySearch(a, twoThirds+1, upperBound, searchVal);
	}
}

int main(){
	int n = 10;
	int a[n] = {1,2,3,4,5,6,7,8,9,10};
	int result = ternarySearch(a, 0, n-1, 1);
	if (result != -1){
		cout << "Found at index: " << result << endl;
	}else{
		cout << "Not found." << endl;
	}
	return 0;
}