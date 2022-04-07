chinese = float(input())
math = float(input())
english = float(input())
average = (chinese + math + english) / 3

if(average > 80 and chinese > 70 and math > 70 and english > 70): print('Got the money!')
else: print('No!!!!')