""" Homework 5: Nonlocal and Generators"""

from ADT import tree, label, branches, is_leaf, print_tree

#####################
# Required Problems #
#####################

def make_withdraw(balance, password):
    """Return a password-protected withdraw function.

    >>> w = make_withdraw(100, 'hax0r')
    >>> w(25, 'hax0r')
    75
    >>> error = w(90, 'hax0r')
    >>> error
    'Insufficient funds'
    >>> error = w(25, 'hwat')
    >>> error
    'Incorrect password'
    >>> new_bal = w(25, 'hax0r')
    >>> new_bal
    50
    >>> w(75, 'a')
    'Incorrect password'
    >>> w(10, 'hax0r')
    40
    >>> w(20, 'n00b')
    'Incorrect password'
    >>> w(10, 'hax0r')
    "Your account is locked. Attempts: ['hwat', 'a', 'n00b']"
    >>> w(10, 'l33t')
    "Your account is locked. Attempts: ['hwat', 'a', 'n00b']"
    >>> type(w(10, 'l33t')) == str
    True
    """
    "*** YOUR CODE HERE ***"
    attempted_password = []
    def withdraw(amount, typed):
        nonlocal balance, attempted_password
        if len(attempted_password) >= 3:
            return f"Your account is locked. Attempts: {attempted_password}"

        if typed != password:
            attempted_password.append(typed)
            return 'Incorrect password'

        if amount > balance:
           return 'Insufficient funds'
        balance = balance - amount
        return balance
    return withdraw


def make_joint(withdraw, old_pass, new_pass):
    """Return a password-protected withdraw function that has joint access to
    the balance of withdraw.

    >>> w = make_withdraw(100, 'hax0r')
    >>> w(25, 'hax0r')
    75
    >>> make_joint(w, 'my', 'secret')
    'Incorrect password'
    >>> j = make_joint(w, 'hax0r', 'secret')
    >>> w(25, 'secret')
    'Incorrect password'
    >>> j(25, 'secret')
    50
    >>> j(25, 'hax0r')
    25
    >>> j(100, 'secret')
    'Insufficient funds'

    >>> j2 = make_joint(j, 'secret', 'code')
    >>> j2(5, 'code')
    20
    >>> j2(5, 'secret')
    15
    >>> j2(5, 'hax0r')
    10

    >>> j2(25, 'password')
    'Incorrect password'
    >>> j2(5, 'secret')
    "Your account is locked. Attempts: ['my', 'secret', 'password']"
    >>> j(5, 'secret')
    "Your account is locked. Attempts: ['my', 'secret', 'password']"
    >>> w(5, 'hax0r')
    "Your account is locked. Attempts: ['my', 'secret', 'password']"
    >>> make_joint(w, 'hax0r', 'hello')
    "Your account is locked. Attempts: ['my', 'secret', 'password']"
    """
    signal = withdraw(0, old_pass)
    if signal == 'Incorrect password' or 'locked' in str(signal):
        return signal

    def joint_withdraw(amount, typed):
        if typed == old_pass or typed == new_pass:
            return withdraw(amount, old_pass)
        else:
            return withdraw(amount, typed)
    return joint_withdraw


def remove(lst, n):
    new_list = []
    for index in range(len(lst)):
        if index == lst.index(n):
            continue
        new_list.append(lst[index])
    return new_list

def permutations(seq):
    """Generates all permutations of the given sequence. Each permutation is a
    list of all elements in seq. The permutations could be yielded in any order.

    >>> perms = permutations([100])
    >>> type(perms)
    <class 'generator'>
    >>> next(perms)
    [100]
    >>> try: #this piece of code prints "No more permutations!" if calling next would cause an error
    ...     next(perms)
    ... except StopIteration:
    ...     print('No more permutations!')
    No more permutations!
    >>> sorted(permutations([1, 2, 3])) # Returns a sorted list containing elements of the generator
    [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
    >>> sorted(permutations((10, 20, 30)))
    [[10, 20, 30], [10, 30, 20], [20, 10, 30], [20, 30, 10], [30, 10, 20], [30, 20, 10]]
    >>> sorted(permutations("ab"))
    [['a', 'b'], ['b', 'a']]
    """
    if len(seq) == 0:
        yield []
    for i in seq:
        for j in permutations(remove(seq, i)):
            yield [i] + j


def two_sum_pairs(target, pairs):
    """Return True if there is a pair in pairs that sum to target.
    """
    for (i, j) in pairs:
        if i + j == target:
            return True
    return False

def pairs(lst):
    """Yield the search space for two_sum_pairs. 

    >>> two_sum_pairs(1, pairs([1, 3, 3, 4, 4])) 
    False
    >>> two_sum_pairs(8, pairs([1, 3, 3, 4, 4])) 
    True
    >>> lst = [1, 3, 3, 4, 4]
    >>> plst = pairs(lst)
    >>> n, pn = len(lst), len(list(plst))
    >>> n * (n - 1) / 2 == pn
    True
    """
    for i in range(len(lst)):
        for j in range(i+1, len(lst)):
            yield lst[i], lst[j]

def two_sum_list(target, lst):
    """Return True if there are two different elements in lst that sum to target.

    >>> two_sum_list(1, [1, 3, 3, 4, 4])
    False
    >>> two_sum_list(8, [1, 3, 3, 4, 4])
    True
    """
    for index in range(len(lst)):
        "*** YOUR CODE HERE ***"
        if target-lst[index] in lst[index+1:]:
            return True
    return False

def lookups(k, key):
    """Yield one lookup function for each node of k that has the label key.
    >>> k = tree(5, [tree(7, [tree(2)]), tree(8, [tree(3), tree(4)]), tree(5, [tree(4), tree(2)])])
    >>> v = tree('Go', [tree('C', [tree('C')]), tree('A', [tree('S'), tree(6)]), tree('L', [tree(1), tree('A')])])
    >>> type(lookups(k, 4))
    <class 'generator'>
    >>> sorted([f(v) for f in lookups(k, 2)])
    ['A', 'C']
    >>> sorted([f(v) for f in lookups(k, 3)])
    ['S']
    >>> [f(v) for f in lookups(k, 6)]
    []
    """
    timer = 0
    def compound_tree(k, v):
        if is_leaf(k):
            return tree([label(k), label(v)])
        new_branches, branch_range = [], range(len(branches(k)))
        for t in branch_range:
            new_branches.append(compound_tree(branches(k)[t], branches(v)[t]))
        return tree([label(k), label(v)], new_branches)

    def amount_key(tree, key):
        if is_leaf(tree):
            return label(tree) == key
        addup = 0
        for i in branches(tree):
            addup += amount_key(i, key)
        return addup + (label(tree) == key)

    def helper(v):
        nonlocal timer
        def search(t):
            if label(t)[0] == key:
                yield label(t)[1]
            for i in branches(t):
                yield from search(i)
        ntree = compound_tree(k, v)
        answer = []
        timer += 1
        for ans in search(ntree):
            answer.append(ans)
        return answer[timer-1]

    for i in range(amount_key(k, key)):
        yield helper
    "*** YOUR CODE HERE ***"

k = tree(5, [tree(7, [tree(2)]), tree(8, [tree(3), tree(4)]), tree(5, [tree(4), tree(2)])])
v = tree('Go', [tree('C', [tree('C')]), tree('A', [tree('S'), tree(6)]), tree('L', [tree(1), tree('A')])])
##########################
# Just for fun Questions #
##########################

def remainders_generator(m):
    """
    Yields m generators. The ith yielded generator yields natural numbers whose
    remainder is i when divided by m.

    >>> import types
    >>> [isinstance(gen, types.GeneratorType) for gen in remainders_generator(5)]
    [True, True, True, True, True]
    >>> remainders_four = remainders_generator(4)
    >>> for i in range(4):
    ...     print("First 3 natural numbers with remainder {0} when divided by 4:".format(i))
    ...     gen = next(remainders_four)
    ...     for _ in range(3):
    ...         print(next(gen))
    First 3 natural numbers with remainder 0 when divided by 4:
    4
    8
    12
    First 3 natural numbers with remainder 1 when divided by 4:
    1
    5
    9
    First 3 natural numbers with remainder 2 when divided by 4:
    2
    6
    10
    First 3 natural numbers with remainder 3 when divided by 4:
    3
    7
    11
    """
    "*** YOUR CODE HERE ***"
