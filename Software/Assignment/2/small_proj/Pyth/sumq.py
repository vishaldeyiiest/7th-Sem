mod = 1000000007
import bisect
 
T = int(raw_input())
for t in range(T):
        p, q, r = map(int, raw_input().split())
        A = map(int, raw_input().split())
        B = map(int, raw_input().split())
        C = map(int, raw_input().split())
        A.sort()
        B.sort()
        C.sort()
	a = bisect.bisect(A, B[-1])
	c = bisect.bisect(C, B[-1])
	A = A[:a]
	C = C[:c]
	#print a, c
 	sa = [0]*(a+1)
	sc = [0]*(c+1)
	for i in range(1, a+1):
		sa[i] = sa[i-1]+A[i-1]
	for i in range(1, c+1):
		sc[i] = sc[i-1] + C[i-1]
	print sa, sc
        s = 0
        for i in B:
                la = bisect.bisect(A, i)
		lc = bisect.bisect(C, i)
		#print la, lc
		s += ((sa[la] + la*i)%mod) * ((lc*i + sc[lc]) % mod)
		s = s%mod
 
        print s%mod
