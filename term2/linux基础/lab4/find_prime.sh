#!/bin/bash

verbose=$(echo $@ | >/dev/null grep -E -- '-\w*v' && echo true)

is_prime() {
    for i in $(seq 2 1 $(expr $1 - 1));do
        is_even=$(expr $1 % $i )
        if [[ $is_even == 0 ]];then
            return 1
        fi
    done
    return 0
}

for num in $(seq 2 1 $1);do
    if  is_prime $num ;then
        [[ $verbose == 'true' ]] && echo "$num is a prime"
        [[ -z $verbose ]] && echo $num
        continue
    fi

    [[ $verbose == 'true' ]] && echo "No!!! $num is not a prime"
done
