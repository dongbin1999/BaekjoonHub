while True:
    n=int(input())
    if n==0:
        break
    elif n%42:
        print("TENTE NOVAMENTE")
    else:
        print("PREMIADO")