#include <stdio.h>
// 定义一个数组的最大长度
#define MAX_LEN 100

// 定义一个函数，输入一个数组和它的长度，输出它的最大连续子数组的和
int max_subarray_sum(int arr[], int len) {
    // 初始化当前的子数组的和为0
    int curr_sum = 0;
    // 初始化最大的子数组的和为数组的第一个元素
    int max_sum = arr[0];
    // 从数组的第一个元素开始，遍历数组
    for (int i = 0; i < len; i++) {
        // 如果当前的子数组的和为正，就把当前元素加上
        if (curr_sum > 0) {
            curr_sum += arr[i];
        }
        else {
            // 否则，就从当前元素开始重新计算子数组的和
            curr_sum = arr[i];
        }
        // 如果当前的子数组的和大于最大的子数组的和，就更新最大的子数组的和
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
        }
    }
    // 返回最大的子数组的和
    return max_sum;
}

// 主函数，用于测试
int main() {

    // 定义一个数组
    int arr[MAX_LEN];
    // 定义一个变量，记录数组的实际长度
    int len = 0;
    // 提示用户输入数组的元素，以空格分隔
    printf("请输入数组的元素，以空格分隔，以字符结束：\\n");
    // 从标准输入读取数组的元素，直到遇到回车或者超过最大长度
    while (scanf_s("%d", &arr[len]) == 1 && len < MAX_LEN) {
        // 数组的长度加一
        len++;
    }
    // 调用函数，计算数组的最大连续子数组的和
    int result = max_subarray_sum(arr, len);
    // 输出结果
    printf("数组的最大连续子数组的和为：%d\\n", result);
    // 返回0，表示程序正常结束
    return 0;
}