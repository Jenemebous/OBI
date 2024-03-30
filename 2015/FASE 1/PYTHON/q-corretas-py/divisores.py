def count_divisors(N):
    divisors = 1
    p = 2  # Começa com o menor número primo
    
    while p * p <= N:
        exp = 0
        while N % p == 0:
            exp += 1
            N //= p
        divisors *= exp + 1
        p += 1 if p == 2 else 2  # Pula para o próximo número primo
        
    if N > 1:
        divisors *= 2  # Se sobrar um fator primo, multiplica por 2
        
    return divisors

def main():
    N = int(input().strip())
    result = count_divisors(N)
    print(result)

if __name__ == "__main__":
    main()
