import sys
from decimal import Decimal, getcontext

def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    n = int(data[0])
    k = int(data[1])

    # Extra precision so rounding to 6 decimals is safe
    getcontext().prec = 80

    N = Decimal(n)
    K = Decimal(k)

    ans = K  # E[M] = k - sum_{i=0}^{k-1} (i/k)^n

    for i in range(k):
        if i == 0:
            continue  # (0/k)^n = 0
        x = Decimal(i) / K
        ans -= x ** n

    # Print with enough decimals; judge wants 6, we can output 9 safely.
    # Using quantize to avoid weird representation issues.
    out = ans.quantize(Decimal("0.000000"))  # exactly 6 decimals
    print(out)

if __name__ == "__main__":
    main()
