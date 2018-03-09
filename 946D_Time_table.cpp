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

	int n, m, k;
	cin >> n >> m >> k;

	int sum = 0;

	vector<int> dp(k+1,0);

	for(int i = 0 ; i < n ; i++){
		string cad; cin >> cad;
		
		vector<int> vec;
		for(int j = 0 ; j < m ; j++){
			if(cad[j] == '1')
				vec.push_back(j);
		}
		if(vec.empty()) continue;

		int tot = vec.back() - vec[0] + 1;


		vector<int> best(k+1,0);
		int len = vec.size(); 
		int win;
		
		for(int i = -1, c1 = 0 ; i < len-1 && c1 <= k ; i++, c1++){
			for(int j = len ,c2 = 0; j > i+1 && j > 0 && c1+c2 <= k ; j--, c2++){
				
				int c = c1 + c2, win;
				if(i == -1 && j == len) continue;

				else if(i == -1){
					win = tot - (vec[j-1] - vec[0] +1);
					best[c] = max(best[c], win);
				}

				else if(j == len){
					win =  tot - (vec[len-1] - vec[i+1] +1);
					best[c] = max(best[c], win);
				}

				else {
					win = tot - (vec[j-1] - vec[i+1] +1);
					best[c] = max(best[c], win);
				}
			}
		}


		for(int i = len ; i <= k ; i++ ) best[i] = tot;

		vector<int> new_dp(k+1,0);	

		for(int w = 1 ; w <= k; w++){
			for(int i = 0, j = w ; i <= w ; i++, j--){
				new_dp[w] = max(new_dp[w], dp[i]+best[j] );
			}
		}	

		dp = new_dp;
		sum += tot;
	}

	int may = 0;
	for(int i = 0 ; i <= k ; i++) may = max(may, dp[i]);

	cout << sum - may;	

return 0;   
}