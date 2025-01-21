import subprocess
import random

# 生成随机测试数据的函数
def generate_test_data():
    T = "1"
    n = random.randint(1, 100)
    return [T, n] + [random.randint(1, 100000) for _ in range(n)]

# 运行exe程序并获取输出的函数
def run_program(exe_path, input_data):
    process = subprocess.Popen(exe_path, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    stdout, stderr = process.communicate(input=input_data)
    if process.returncode != 0:
        raise Exception(f"Error running {exe_path}: {stderr}")
    return stdout.strip().split('\n')

# 对拍函数
def stress_test(program1_path, program2_path):
    for _ in range(1000):  # 运行1000次测试
        test_data = generate_test_data()
        input_data = '\n'.join(map(str, test_data)) + '\n'
        
        try:
            result1 = run_program(program1_path, input_data)
            result2 = run_program(program2_path, input_data)
        except Exception as e:
            print(e)
            return
        
        if result1 != result2:
            print(f"Discrepancy found!\nData: {test_data}\nProgram1: {result1}\nProgram2: {result2}")
            return
        #else:
            # print(f"Test passed! Data: {test_data}")
    print("All tests passed!")

if __name__ == "__main__":
    program1_path = "A.exe"
    program2_path = "A2.exe"
    stress_test(program1_path, program2_path)