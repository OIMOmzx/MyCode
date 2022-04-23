year = int(input())
if(year % 400 == 0): print('loop year')
elif(year % 4 == 0 and year % 100 != 0): print('loop year')
else: print('normal year')