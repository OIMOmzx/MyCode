num = int(input())
l = 0
r = num * 10
while(l <= r):
    mid = (l + r) / 2
    mid = int(mid)
    if(mid == num): print(mid)
    if(mid > num): r = mid - 1
    else: l = mid + 1
    
