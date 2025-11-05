# # # 预计算斐波那契数列，dp[n]表示递归n次时的最小a+b
# # dp = [0] * 82
# # dp[0] = 1  # n=0时，a=1,b=0,a+b=1
# # if len(dp) > 1:
# #     dp[1] = 3  # n=1时，a=2,b=1,a+b=3
# # for i in range(2, 82):
# #     dp[i] = dp[i-1] + dp[i-2]

# # T = int(input())
# # for _ in range(T):
# #     n = int(input())
# #     print(dp[n])
# #有问题
# dp =[0]*82
# dp[0]=1
# dp[1] =3
# for i in range(2,82):
#     dp[i]=dp[i-1]+dp[i-2]
# T=int(input())
# for _ in range(T):
#     n=int(input())
#     print(dp[n])