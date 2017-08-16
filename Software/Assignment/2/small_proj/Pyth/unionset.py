 
T = int(raw_input())
for t in range(T):
	n, k = map(int, raw_input().split())
        bitmap = []
	cnt = []
	f = 0
        for i in range(n):
		temp = ['0']*k
                
                A = map(int, raw_input().split())
                l = A[0]
		if l == k:
			f += 1
                A = A[1:]
                for e in A:
			temp[e-1] = '1'
		#print temp,
                bitmap.append(int(''.join(temp), 2))
     		cnt.append(l)

        #print bitmap   
        co = 0
	num = int(''.join(['1']*k), 2)
	#print f	
	co += f*(f-1)/2 + f*(n-f)
        for i in range(n-1):
		if cnt[i] == k:
			continue
		for j in range(i+1, n):
			if cnt[i]+cnt[j] < k or cnt[j] == k:
				continue
			if bitmap[i]|bitmap[j] == num:
				co += 1
				
              
     	print co 
