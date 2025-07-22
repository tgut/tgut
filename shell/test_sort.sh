#!/bin/bash

# 定义设备资源数据（格式：设备名 CPU剩余 GPU剩余）
devices=(
    "设备1 45 24"
    "设备2 35 25"
    "设备3 30 30"  # 示例新增设备，假设总和与设备2相同
)

# 计算总和并排序
{
    for device in "${devices[@]}"; do
        # 拆分字段：名称、CPU、GPU
        name=$(cut -d' ' -f1 <<< "$device")
        cpu=$(cut -d' ' -f2 <<< "$device")
        gpu=$(cut -d' ' -f3 <<< "$device")
        total=$((cpu + gpu))
        echo "$total $cpu $gpu $name"  # 输出格式：总和 CPU GPU 名称
    done
} | sort -k1,1nr -k3,3nr -k2,2nr | {  # 排序逻辑：总和 → GPU → CPU
    count=1
    while read total cpu gpu name; do
        echo "$count. $name(累积和:$total;GPU剩余;$gpu,CPU剩余:$cpu)"
        ((count++))
    done
}