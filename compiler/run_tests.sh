#!/bin/bash

# Uya语言测试运行脚本

UYAC="./uyac"
TEST_DIR="./tests"
OUTPUT_DIR="./test_outputs"

# 创建输出目录
mkdir -p "$OUTPUT_DIR"

echo "开始运行Uya语言测试..."

# 测试切片功能
echo "测试切片功能..."
if [ -f "$TEST_DIR/final_slice_test.uya" ]; then
    echo "  编译 final_slice_test.uya..."
    $UYAC "$TEST_DIR/final_slice_test.uya" "$OUTPUT_DIR/final_slice_test.c"
    if [ $? -eq 0 ]; then
        echo "  ✓ 切片功能测试通过"
    else
        echo "  ✗ 切片功能测试失败"
    fi
else
    echo "  文件 $TEST_DIR/final_slice_test.uya 不存在"
fi

# 测试基本功能
echo "测试基本功能..."
if [ -f "$TEST_DIR/simple_slice_test.uya" ]; then
    echo "  编译 simple_slice_test.uya..."
    $UYAC "$TEST_DIR/simple_slice_test.uya" "$OUTPUT_DIR/simple_slice_test.c"
    if [ $? -eq 0 ]; then
        echo "  ✓ 基本功能测试通过"
    else
        echo "  ✗ 基本功能测试失败"
    fi
else
    echo "  文件 $TEST_DIR/simple_slice_test.uya 不存在"
fi

# 测试综合功能
echo "测试综合功能..."
if [ -f "$TEST_DIR/slice_tests.uya" ]; then
    echo "  编译 slice_tests.uya..."
    $UYAC "$TEST_DIR/slice_tests.uya" "$OUTPUT_DIR/slice_tests.c"
    if [ $? -eq 0 ]; then
        echo "  ✓ 综合功能测试通过"
    else
        echo "  ✗ 综合功能测试失败"
    fi
else
    echo "  文件 $TEST_DIR/slice_tests.uya 不存在"
fi

# 测试Python风格切片
echo "测试Python风格切片..."
if [ -f "$TEST_DIR/test_python_slice.uya" ]; then
    echo "  编译 test_python_slice.uya..."
    $UYAC "$TEST_DIR/test_python_slice.uya" "$OUTPUT_DIR/test_python_slice.c"
    if [ $? -eq 0 ]; then
        echo "  ✓ Python风格切片测试通过"
    else
        echo "  ✗ Python风格切片测试失败"
    fi
else
    echo "  文件 $TEST_DIR/test_python_slice.uya 不存在"
fi

echo "测试完成！"
echo "输出文件保存在 $OUTPUT_DIR 目录中"