'''input
4
5
45 42 46 48 47
3
7 7 8
8
12 156 157 158 159 160 161 162
4
8 7 10 6
'''
import sys
def main():
	T = int(input())
	while(T!=0):
		T = T - 1
		N = long(input())
		s = raw_input()
		list = []
		list = map(long, s.split())
		list.sort()
		if long(list[0]) + 1 != long(list[1]):
			print long(list[0])
		elif long(list[-1]) != long(list[-2]) + 1:
			print long(list[-1])
		else:
			for itr in range(N-1):
				if(long(list[itr]) == long(list[itr+1])):
					print long(list[itr])
 
 
if __name__ == '__main__':
	main() 