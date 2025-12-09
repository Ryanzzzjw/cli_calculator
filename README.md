# Command Line Calculator

一个用于学习 C 语言的命令行计算器项目,使用claude辅助学习

## 项目简介

这是一个循序渐进的 C 语言学习项目，通过开发一个功能完整的命令行计算器，逐步掌握 C 语言的核心概念和编程技巧。

## 当前功能

- ✅ 基础四则运算（加、减、乘、除）
- ✅ 支持浮点数计算
- ✅ 格式化输出（保留两位小数）
- ✅ 除零错误处理
- ✅ 交互式操作菜单
- ✅ 循环计算功能
- ✅ 退出选项
- ✅ 安全输入验证（fgets + sscanf）
- ✅ 指针演示（swap函数）
- ✅ 科学计算功能（幂运算、平方根、取模）
- ✅ Math.h 库函数使用
- ✅ 计算历史记录（结构体数组）
- ✅ 查看历史记录
- ✅ 清除历史记录

## 学习进度

- ✅ **模块一**: 项目初始化
- ✅ **模块二**: 基础加法计算器
- ✅ **模块三**: 完整四则运算
- ✅ **模块四**: 操作菜单
- ✅ **模块五**: 循环功能
- ✅ **模块六**: 输入验证
- ✅ **模块七**: 指针基础
- ✅ **模块八**: 多文件编译
- ✅ **模块九**: 科学计算器
- ✅ **模块十**: 结构体与历史记录
- ✅ **模块十一**: 历史记录管理
- ⏳ 更多模块开发中...

详细学习进度请查看 [process.md](process.md)

## 编译和运行

### 方法1：使用 CMake（推荐）

```bash
# 配置项目
cmake -B build

# 编译项目
cmake --build build

# 运行程序
./build/cli_calculator.exe
```

### 方法2：使用 GCC 直接编译

**Windows (MinGW):**
```bash
gcc main.c calc.c -o calculator.exe
```

**Linux/macOS:**
```bash
gcc main.c calc.c -o calculator.exe -lm
```

注意：Linux/macOS 需要添加 `-lm` 参数来链接数学库。

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
├── calc.h          # 计算函数头文件
├── calc.c          # 计算函数实现文件
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

### 模块三
- 条件语句 (if-else)
- 错误处理基础
- 比较运算符

### 模块四
- switch-case 语句
- 菜单驱动程序设计

### 模块五
- while 循环
- break 和 continue 语句
- 程序流程控制

### 模块六
- 输入缓冲区管理
- scanf 陷阱与返回值检查
- fgets() + sscanf() 安全输入

### 模块七
- 指针概念与内存地址
- 取地址运算符 (&)
- 解引用运算符 (*)
- 传值调用 vs 传引用调用
- 指针参数的使用

### 模块八
- 头文件和源文件的分离
- 函数声明与定义
- 头文件保护 (#ifndef, #define, #endif)
- 多文件编译（GCC 和 CMake）
- 代码模块化组织

### 模块九
- Math.h 数学库的使用
- pow() 函数（幂运算）
- sqrt() 函数（平方根）
- fmod() 函数（浮点数取模）
- 库链接配置（-lm 参数）
- 条件输入处理（单参数函数）
- 科学运算错误处理

### 模块十
- 结构体定义与使用
- typedef 关键字
- 结构体数组
- strcpy() 字符串操作
- 成员访问运算符 (.)

### 模块十一
- 结构体数组遍历
- strcmp() 字符串比较
- 条件格式化输出
- 历史记录管理功能

## 版本

v11.0 - 历史记录管理版（History Management Edition）
