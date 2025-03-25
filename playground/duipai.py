import subprocess
import random
import time

# 用于生成测试数据的特定函数
def generate_test_case():
    # 这里定义一个生成数据的具体规则，根据需要调整
    return random.randint(1, 100000)

# 执行给定程序并获取输出
def run_program(exe_path, input_data):
    process = subprocess.Popen(exe_path, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate(input_data.encode())
    return stdout.decode().strip()

# 主对拍函数
def compare_results(exe1, exe2, num_tests=1000):
    for i in range(num_tests):
        # 生成测试数据
        test_case = generate_test_case()
        input_data = str(test_case)
        print (f"Running test case {i + 1} with input {input_data}...")

        # 获取两个程序的输出
        result1 = run_program(exe1, input_data)
        result2 = run_program(exe2, input_data)

        # 对比结果
        if result1 != result2:
            print(f"!!Test case {i + 1} failed with input {input_data}:")
            print(f"  Result from brute force: {result1}")
            print(f"  Result from optimized algorithm: {result2}")
        

if __name__ == "__main__":
    # 提供暴力算法和优化算法的exe路径
    brute_force_exe = "brute_force.exe"
    optimized_exe = "optimized.exe"
    
    compare_results(brute_force_exe, optimized_exe)
