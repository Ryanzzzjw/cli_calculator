# Command Line Calculator

一个用于学习 C 语言的命令行计算器项目,使用claude辅助学习

## 项目简介

这是一个循序渐进的 C 语言学习项目，通过开发一个功能完整的命令行计算器，逐步掌握 C 语言的核心概念和编程技巧。

## 当前功能

- ✅ 基础加法运算
- ✅ 支持浮点数计算
- ✅ 格式化输出（保留两位小数）

## 学习进度

- ✅ **模块一**: 项目初始化
- ✅ **模块二**: 基础加法计算器
- ⏳ **模块三**: 完整四则运算
- ⏳ **模块四**: 操作菜单
- ⏳ **模块五**: 循环功能
- ⏳ 更多模块开发中...

详细学习进度请查看 [process.md](process.md)

## 编译和运行

### 使用 GCC 编译

```bash
gcc main.c -o calculator.exe
```

### 运行程序

```bash
./calculator.exe
```

或在 Windows 上：

```bash
calculator.exe
```

## 项目结构

```
cli_calculator/
├── main.c          # 主程序文件
├── process.md      # 学习进度记录
├── README.md       # 项目说明文档
└── CMakeLists.txt  # CMake 配置文件
```

## 技术栈

- C 语言
- GCC 编译器
- CMake (可选)

## 已掌握的知识点

### 模块一
- C 程序基本结构
- 标准输入输出库 (`#include <stdio.h>`)
- printf 函数
- 程序编译和执行

### 模块二
- double 数据类型
- scanf() 函数
- 格式说明符 (%lf)
- 算术运算
- 浮点数格式化输出 (%.2lf)


## 版本

v1.0 - 基础加法计算器
