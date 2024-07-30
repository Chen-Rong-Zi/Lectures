echo_boot_log() {
    journalctl | grep -Po 'Startup finished in ([0-9.]+)s \(kernel\) \+ ([0-9.]+)s \(userspace\) \= [0-9.]+s\.$' | sed -E 's/Startup finished in ([0-9.]+)s \(kernel\) \+ ([0-9.]+)s \(userspace\) \= ([0-9.]+)s\.$/\3/'
}

time_lst=$(echo_boot_log)
sum=$(echo $time_lst | tr ' ' '\n' | paste -sd+ | bc)
num=$(echo $time_lst | wc -w)
average_time=$(echo 'scale=3;' "$sum / $num" | bc -l)
slowest=$(echo $time_lst  | tr ' ' '\n'| sort -n | tail -n1)
fastest=$(echo $time_lst  | tr ' ' '\n'| sort -n | head -n1)

echo total "$num" boots, average: "$average_time"s, fastest: "$fastest"s, slowest: "$slowest"s
