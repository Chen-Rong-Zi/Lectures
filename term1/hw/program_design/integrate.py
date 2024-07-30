def integrate(exp, start, end, minimal):
    print(end - start)
    if end - start <= minimal:
        return exp(start) * (end - start)
    return integrate(exp, start, (start + end) / 2, minimal) + integrate(exp, (start + end) / 2, end, minimal)
