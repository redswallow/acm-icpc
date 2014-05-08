import time


def timer(func):
    ''' calculate the running time of a function '''
    def newFunc(*args, **kwargs):
        start = time.clock()
        back = func(*args, **kwargs)
        end = time.clock()
        print "%s: %fs" % (func.__name__, end - start)
        return back
    return newFunc
