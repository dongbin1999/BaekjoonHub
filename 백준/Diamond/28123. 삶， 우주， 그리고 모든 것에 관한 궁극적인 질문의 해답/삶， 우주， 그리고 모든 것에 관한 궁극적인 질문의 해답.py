import decimal

def main():
    decimal.getcontext().prec = 1000
    n, k, x = map(int, input().split())

    if n < 2:
        print(0)
        return

    log_value = decimal.Decimal("1.25").log10()
    add = 1
	
    if 8 <= x:
        n -= 1
        x = 4

    if x == 4:
        add += 1
        n -= 2
    
    if 1 <= x <= 3:
    	n -= 1

    print(int(n * log_value) + add)

if __name__ == "__main__":
    main()
