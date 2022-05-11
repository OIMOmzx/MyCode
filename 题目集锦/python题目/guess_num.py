price = int(input())
num = int(input())
left = 1
right = int(input())
cnt = 0

while left < right:
    mid = (left + right) / 2
    mid = int(mid)
    cnt += 1
    if(cnt > num):
        print('no chance!')
        break
    if mid > price :
        print('you guess',mid ,',and it is bigger')
        right = mid
        right = int(right)
    elif mid < price:
        print('you guess',mid ,',and it is smaller')
        left = mid + 1
        left = int(left)
    else:
        print('Right!!! you guess for', num, 'times')
        break



