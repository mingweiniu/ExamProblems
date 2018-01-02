
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


void factoring(int, vector<int>&, vector<int>&);

int main(){

	int x;
	int y;

	while(cin>>x >> y){
		if((x==0) && (y==0)) return 0;
		cout << x << '\t'<< y << '\n';
        vector<int> px;
        vector<int> kx;
		factoring(x, px, kx);	

        vector<int> py;
        vector<int> ky;
        factoring(y, py, ky);
	
		int x_min = *min_element(kx.begin(), kx.end());
		int y_min = *min_element(ky.begin(), ky.end());

		int p = min(x_min, y_min );

	}
	return 0;
}

void factoring(int n, vector<int>& p, vector<int>& k){
	for(int i=2; i< n; ++i){
		//cout << "for (i,n)" << i << '\t' << n << '\n';
		if( (n % i) == 0){
			n /= i;
			p.push_back(i);
			int r = 1;
			bool not_stop=true;
			while( not_stop ){
				//cout << "while (i, n, stop)" << i << '\t' <<  n << '\t' << not_stop << '\n';
				if( n < i) not_stop=false;
				if((n % i) == 0){
					++r;
					n /= i;
				}
				else{
					not_stop=false;
				}
			}
			k.push_back(r);
		}
	}
	//cout << "factor:\n";
	for(int i = 0; i < p.size(); ++i){
		//cout << '\t' << p[i] << '\t' << k[i] << '\n';
	}
}

