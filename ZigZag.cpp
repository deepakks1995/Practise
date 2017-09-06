#include <iostream>
#include <vector>
using namespace std;

class ZigZag
{
public:
	ZigZag();
	~ZigZag();
	int longestZigZag(vector <int> sequence);	
};

int ZigZag::longestZigZag(vector <int> sequence){
	int SIZE = sequence.size();
	int dp1[SIZE], dp2[SIZE];
	for (int i = 0; i < SIZE; ++i)
		dp1[i] = dp2[i] = 1 ;
	// dp1[i] is subsequence ending at i such that last element is greater than second last
	// dp2[i] is subsequence ending at i such that last element is smaller than second last
	// dp1[0] = 1
	// dp2[0] = 1
	// dp1[i] = min (dp1[i], dp2[j] + 1)
	// dp2[i] = min (dp2[i], dp1[j] + 1)
	for (int i = 1; i < SIZE; ++i){
		for(int j = 0; j < i; ++j) {
			if (sequence[j] < sequence[i])
				dp1[i] = max (dp1[i], dp2[j] + 1);
			if (sequence[j] > sequence[i])
				dp2[i] = max (dp2[i], dp1[j] + 1);
		}
	}
	int result = 0;
	for (int i = 0; i < SIZE; ++i){
		if (result < max (dp1[i], dp2[i]))
			result = max (dp1[i], dp2[i]);
	}
	return result;
}

int main(){
	
}