#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <list>
#include <math.h>

using namespace std;

int main(){

	string cad;
	cin >> cad;	

	int n = cad.size();
	int cont = 0;
	for(int i = 0; i < n-2 ; i++){
		if(cad[i] != 'Q') continue;
		for(int j = i+1; j < n-1 ; j++){
			if(cad[j]!='A') continue;
			for(int k = j+1 ; k < n ; k++){
				if(cad[k] == 'Q') cont++;
			}
		}
	}
	cout << cont;

return 0;   
}