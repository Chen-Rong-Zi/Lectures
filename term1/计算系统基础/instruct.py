import sys
from isa import instruction

arg_lst = sys.argv[1].split(' ')
oper = arg_lst[2]
print(arg_lst[0], arg_lst[1], end=':\t')
print(instruction[oper], end='\t')
for r in arg_lst[3:]:
    print(f"R{int(('0b' + r), 2)}", end="\t")
print()
