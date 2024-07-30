""" Homework 6: OOP and Inheritance"""

#####################
# Required Problems #
#####################

class PrintModule:
    def pp(self):
        pretty_print(self)

class VendingMachine:
    """A vending machine that vends some product for some price.

    >>> v = VendingMachine('candy', 10)
    >>> v.vend()
    'Machine is out of stock.'
    >>> v.add_funds(15)
    'Machine is out of stock. Here is your $15.'
    >>> v.restock(2)
    'Current candy stock: 2'
    >>> v.vend()
    'You must add $10 more funds.'
    >>> v.add_funds(7)
    'Current balance: $7'
    >>> v.vend()
    'You must add $3 more funds.'
    >>> v.add_funds(5)
    'Current balance: $12'
    >>> v.vend()
    'Here is your candy and $2 change.'
    >>> v.add_funds(10)
    'Current balance: $10'
    >>> v.vend()
    'Here is your candy.'
    >>> v.add_funds(15)
    'Machine is out of stock. Here is your $15.'

    >>> w = VendingMachine('soda', 2)
    >>> w.restock(3)
    'Current soda stock: 3'
    >>> w.restock(3)
    'Current soda stock: 6'
    >>> w.add_funds(2)
    'Current balance: $2'
    >>> w.vend()
    'Here is your soda.'
    """
    "*** YOUR CODE HERE ***"
    def __init__(self, product, price):
        self.stock = 0
        self.balance = 0
        self.product = product
        self.price = price

    def add_funds(self, input):
        if self.stock == 0:
            return f'Machine is out of stock. Here is your ${input}.'
        self.balance += input
        return f'Current balance: ${self.balance}'

    def restock(self, amount):
        self.stock += amount
        return f'Current {self.product} stock: {self.stock}'

    def vend(self):
        if self.stock == 0 and self.balance > 0:
            temp = self.balance
            self.balance = 0
            return f'Machine is out of stock. Here is your ${temp}.'
        elif self.stock == 0 and self.balance == 0:
            return 'Machine is out of stock.'
        elif self.balance < self.price:
            return f'You must add ${self.price - self.balance} more funds.'
        elif self.balance > self.price:
            temp = self.balance
            self.balance = 0
            self.stock -= 1
            return f'Here is your {self.product} and ${temp-self.price} change.'
        elif self.balance == self.price:
            self.balance = 0
            self.stock -= 1
            return f'Here is your {self.product}.'

class Pet(PrintModule):
    """A pet.

    >>> kyubey = Pet('Kyubey', 'Incubator')
    >>> kyubey.talk()
    Kyubey
    >>> kyubey.eat('Grief Seed')
    Kyubey ate a Grief Seed!
    """
    def __init__(self, name, owner):
        self.is_alive = True    # It's alive!!!
        self.name = name
        self.owner = owner

    def eat(self, thing):
        print(self.name + " ate a " + str(thing) + "!")

    def talk(self):
        print(self.name)

    def to_str(self):
        "*** YOUR CODE HERE ***"
        return f'({self.name}, {self.onwer})'


class Cat(Pet, PrintModule):
    """A cat.

    >>> vanilla = Cat('Vanilla', 'Minazuki Kashou')
    >>> isinstance(vanilla, Pet) # check if vanilla is an instance of Pet.
    True
    >>> vanilla.talk()
    Vanilla says meow!
    >>> vanilla.eat('fish')
    Vanilla ate a fish!
    >>> vanilla.lose_life()
    >>> vanilla.lives
    8
    >>> vanilla.is_alive
    True
    >>> for i in range(8):
    ...     vanilla.lose_life()
    >>> vanilla.lives
    0
    >>> vanilla.is_alive
    False
    >>> vanilla.lose_life()
    Vanilla has no more lives to lose.
    """
    def __init__(self, name, owner, lives=9):
        self.lives = lives
        self.name = name
        self.owner = owner
        self.is_alive = True
        "*** YOUR CODE HERE ***"

    def talk(self):
        """ Print out a cat's greeting.
        """
        "*** YOUR CODE HERE ***"
        print(f'{self.name} says meow!')

    def lose_life(self):
        """Decrements a cat's life by 1. When lives reaches zero, 'is_alive'
        becomes False. If this is called after lives has reached zero, print out
        that the cat has no more lives to lose.
        """
        "*** YOUR CODE HERE ***"
        if self.lives == 0:
            print('Vanilla has no more lives to lose.')
            return
        self.lives -= 1
        self.is_alive = self.lives != 0

    def to_str(self):
        "*** YOUR CODE HERE ***"
        return f'({self.name}, {self.owner}, {self.lives})'


class NoisyCat(Cat, PrintModule): # Dose this line need to change?
    """A Cat that repeats things twice.

    >>> chocola = NoisyCat('Chocola', 'Minazuki Kashou')
    >>> isinstance(chocola, Cat) # check if chocola is an instance of Cat.
    True
    >>> chocola.talk()
    Chocola says meow!
    Chocola says meow!
    """
#  def __init__(self, name, owner, lives=9):
        # Is this method necessary? If not, feel free to remove it.

    def talk(self):
        "*** YOUR CODE HERE ***"
        super().talk(self)
        super().talk(self)

class Colors:
    HEADER     = '\033[95m'
    OKBLUE     = '\033[34m'
    OKCYAN     = '\033[35m'
    WARNING    = '\033[93m'
    FAIL       = '\033[91m'
    ENDC       = '\033[0m'
    BOLD       = '\033[1m'
    UNDERLINE  = '\033[4m'

def pretty_print(obj):
    """Pretty prints the object using the Colors class.
    >>> kyubey = Pet('Kyubey', 'Incubator')
    >>> pretty_print(kyubey)
    \033[34mPet\033[0m\033[35m(Kyubey, Incubator)\033[0m
    """
    "*** YOUR CODE HERE ***"
    if type(obj) == Pet:
        print(f'{Colors.OKBLUE}Pet{Colors.ENDC}{Colors.OKCYAN}({obj.name}, {obj.owner}){Colors.ENDC}')
    elif type(obj) == Cat:
        print(f'{Colors.OKBLUE}Cat{Colors.ENDC}{Colors.OKCYAN}({obj.name}, {obj.owner}, {obj.lives}){Colors.ENDC}')
    elif type(obj) == NoisyCat:
        print(f'{Colors.OKBLUE}NoisyCat{Colors.ENDC}{Colors.OKCYAN}({obj.name}, {obj.owner}, {obj.lives}){Colors.ENDC}')

##########################
# Just for fun Questions #
##########################

class Fib:
    """A Fibonacci number.

    >>> start = Fib()
    >>> start.value
    0
    >>> start.next().value
    1
    >>> start.next().next().value
    1
    >>> start.next().next().next().value
    2
    >>> start.next().next().next().next().value
    3
    >>> start.next().next().next().next().next().value
    5
    >>> start.next().next().next().next().next().next().value
    8
    >>> start.value # Ensure start isn't changed
    0
    """

    def __init__(self, value=0):
        self.value = value

    def next(self):
        "*** YOUR CODE HERE ***"
