'''input
8
3 2 3 2 3 5 1 3
'''

'''
dp1[i] he do not play ith match
dp2[i] he plays only ith match, not i-1 th match
dp3[i] he plays ith as well as i-1 th match, not i-2 th
'''
def maxi(a,b,c):
	return (a if (a > c) else c ) if (a > b) else (b if b > c else c)   

def main():
	N = int(map(int, raw_input().split())[0])
	array = map(long, raw_input().split())
	dp1, dp2, dp3 = [], [], []
	for i in range(N):
		dp1.append(0)
		dp2.append(0)
		dp3.append(0)
	dp1[0] = 0
	dp2[0] = array[0]
	dp3[0] = array[0]
	i = 1
	while i <= N-1:
		dp1[i] = maxi(dp1[i-1], dp2[i-1], dp3[i-1])
		dp2[i] = array[i] + dp1[i-1]
		dp3[i] = array[i] + dp2[i-1]
		i = i + 1
	ans = 0	
	for x in range(N):
		ans = ans + array[x]
	ans = ans - maxi (dp1[N-1], dp2[N-1], dp3[N-1])
	print ans
	return 0

if __name__ == '__main__':
	main()