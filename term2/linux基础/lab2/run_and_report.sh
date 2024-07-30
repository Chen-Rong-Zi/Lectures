#!/usr/bin/env bash

log_path="/var/tmp/log/task.log"
script="./task.sh"
log_dir_path="/var/tmp/log"

# check log dir
if [[ ! -d $log_dir_path ]];then
    mkdir -p $log_dir_path
fi

# empty the log
echo >| $log_path

# loop util find error
while true;do
    if ! $script &>> $log_path;then
        break
    fi
done

# analyze the log file
success_time=$(grep "Everything went according to plan" $log_path | wc -l)
fail_time=$(grep "The error was using a magic number" $log_path  | wc -l)

# report
echo success: "$success_time"  fail: "$fail_time"
echo total: $(( success_time + fail_time ))
