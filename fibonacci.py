from sys import setrecursionlimit

setrecursionlimit(2000)

# Inicialization
fibonacci_memoization = {0: 0, 1: 1}

def fib(n: int) -> int:
    # Reuse previous answers
    if n in fibonacci_memoization:
        return fibonacci_memoization[n]
    
    # Calculate new answers recursively
    result = fib(n - 1) + fib(n - 2)
    fibonacci_memoization[n] = result

    return result

def main():
    print("Fibonacci: ")
    while True:
        try:
            n = int(input("Entrada: "))
            if n < 0:
                raise(ValueError)

            print(f"fib({n}) = {fib(n)}")

        except ValueError:
            print("Entrada inválida! Insira um número inteiro não negativo." )
        except RecursionError:
            print("Limite de recursões atingido!")
            print("Tente valores menores antes ou ajuste o limite de recursão na linha 3.")

main()