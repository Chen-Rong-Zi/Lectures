#!/usr/bin/env bash
# 请编写一段bash脚本，运行如下的脚本直到它出错，将它的标准输出和标准错误输出记录到文件，报告脚本在失败前共运行了多少次，并通过记录的文件验证脚本输出结果的正确性。

n=$(( RANDOM % 100 ))

if [[ n -eq 50 ]]; then
  echo "Something went wrong"
  >&2 echo "The error was using a magic number"
  exit 1
fi

echo "Everything went according to plan"
