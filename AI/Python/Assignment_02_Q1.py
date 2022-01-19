value = []
def seriesSum(N,I,F):

    if (N==0):
        value.append( 0 )
        return 0
    elif (N>=1):
        value.append( F + (N-1) * I )
        return seriesSum(N-1,I,F) + F + (N-1) * I


t=int(input('\nHow many times = '))
for i in range(t):
    print('\n---Iteration : ',i+1,'---\n') 
    f=int(input('First element :'))
    d=int(input('Interval : '))
    n=int(input('n : '))
    print('\nSeries Sum:', seriesSum(n,d,f))
    print('Series elements : ',value)
    value.clear()