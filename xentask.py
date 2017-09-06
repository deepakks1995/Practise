
import sys

def main():
	T = int(input())
	while(T!=0):
		N = input()
		xenny = []
		s = raw_input()
		xenny = s.split()
		del s
		s = raw_input()
		yana = s.split()
		total1 = 0
		total2 = 0
		for itr in range(N):
			if(itr%2==0):
				total1 += int(xenny[itr])
				total2 += int(yana[itr])
			else:
				total1 += int(yana[itr])
				total2 += int(xenny[itr])
		print min(total2, total1)
		T = T-1

if __name__ == '__main__':
	main()