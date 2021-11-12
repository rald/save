def fib(n):
  f=0
  s=1
  v=True
  while n:
    if v:
      v=False
    else:
      print(", ",end="")
    print(f,end="")
    t=f+s
    f=s
    s=t
    n-=1
  print()



fib(int(input("Enter number: ")))
