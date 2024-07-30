def helper( n,  m):
    result = 0
    if ( n == 1 or n == 0 ):
        return 1
    elif n < 0:
        return 0
    for i in range(1, m+1):
        result += helper(n-i, m)
    return result

def main():
    n = int(input())
    m = int(input())
    print(helper(n, m))
    return 0

main()
