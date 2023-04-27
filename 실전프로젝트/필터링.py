import sys
import re

tc = int(input())

for i in range(tc):
	n,m = map(int,sys.stdin.readline().split())
	bad = list(sys.stdin.readline().rstrip().split())
	words = list(sys.stdin.readline().rstrip().split())
	ret = ""
	for word in words:
		sre = word.replace('.','[a-z]{1,' + str(m) + '}')
		regex = re.compile(sre)
		mat = False
		for b in bad:
			if(regex.fullmatch(b)):
				mat = True
		if mat:
			for i in range(len(word)):
				ret+='#'
		else:
			ret += word
		ret += " "
	print(ret)
