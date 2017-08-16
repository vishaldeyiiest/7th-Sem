def calc(A, n):
	pos = 0
	for i in range(n):
                if A[i] >= 0:
                        pos = i
                        break
	dp = [0]*(pos+1)

	B = A[pos:]
	C = A[:pos]
	sb = sum(B)
	l = len(B)
	dp = []
	dp.append(sb*l + sum(C))
	sc = sum(C)
	lc = len(C)
	#print sb, sc
	i = pos-1
	k = 1
	while i >= 0:
		sb = sb+C[i]
		sc = sc-C[i]
		dp.append(sb*(l+k) + sc)
		i -= 1
		k += 1
	#print dp
	return max(dp)

T = int(raw_input())
for t in range(T):
        n = int(raw_input())
        A = map(int, raw_input().split())
        A.sort()
 
        flag = all(i <= 0 for i in A)
        for i in range(n):
                if A[i] >= 0:
                        pos = i
                        break
        if flag == False:
                print calc(A, n)
        else:
                print sum(A)
