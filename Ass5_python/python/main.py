from include import calculate

while True:
    print("Enter Query : ")
    query = input()
    
    res = calculate.Calculate(query)
    res.evaluate()
    print("for continue press 1\nfor exit press 0")
    response = int(input())
    if response == 1:
        continue
    elif response == 0:
        break