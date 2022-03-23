second = input()
second = int(second)
print(int(second / 3600), ':', int(second / 60), ':', second - int(second / 3600) * 3600 - int(second / 60) * 60)