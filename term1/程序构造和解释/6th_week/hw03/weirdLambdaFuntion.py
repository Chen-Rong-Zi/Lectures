def Y(f):
    def A(x):
        return x(x)

    def B(x):
        def C(z):
            return x(x)(z)
        return f(C)

    return A(B)

#     return B(B)
#     return f(C)
#     return f(B(B))
#     return f(f(B(B)))
#     return f(f(f(B(B))))

# Y(f)(z) = f(C)(z) = f(B(B))(z)


