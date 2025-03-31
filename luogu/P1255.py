n = int(input())
dp = [1, 2, 0]
for i in range(2, n, 1):
    dp[i % 3] = dp[(i - 1) % 3] + dp[(i - 2) % 3]
print(dp[(n - 1) % 3])