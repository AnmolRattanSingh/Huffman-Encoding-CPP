"""

"""

import sys
from subprocess import Popen, PIPE, STDOUT

def run(cmd):
    p = Popen(cmd, shell=True, stdout=PIPE, stderr=STDOUT)
    stdout = []
    this_stdout, _ = p.communicate()
    line = this_stdout.decode('utf-8')
    stdout.append(line)
    print(line) 
    return ''.join(stdout)

# def plot_times():


run('./build/src/huffman')
