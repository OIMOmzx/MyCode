case = 0
while 1:
    case += 1
    print('Case', case, ':')
    print('You should input three variables next, you height(m), weight(kg), and if you are a boy or a girl')
    height = float(input())
    weight = float(input())
    option = int(input())

    print('Because I cannot remember the standard, so I need you to input them. ', 'First in pust the lower limit, then the higher limit; First boys, then girls')
    boy_low_standard = float(input())
    boy_high_standard = float(input())

    girl_low_standard = float(input())
    girl_high_standard = float(input())

    bmi = weight / (height * height)
    if(option == 1):
        print('Boy: ')
        if(bmi < boy_low_standard):
            print('Too thin!')
        elif(bmi >= boy_low_standard and bmi <= boy_high_standard):
            print('Not too thin, or not too fat.')
        else:
            print('Too fat')
    if(option == 0):
        print('Girl: ')
        if(bmi < girl_low_standard):
            print('Too thin!')
        elif(bmi >= girl_low_standard and bmi <= girl_high_standard):
            print('Not too thin, or not too fat.')
        else:
            print('Too fat')