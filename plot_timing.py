"""

"""

import matplotlib.pyplot as plt
from subprocess import Popen, PIPE, STDOUT

def run(cmd):
    """
    """
    p = Popen(cmd, shell=True, stdout=PIPE, stderr=STDOUT)
    stdout = []
    this_stdout, _ = p.communicate()
    line = this_stdout.decode('utf-8')
    stdout = line.split('\n')
    return stdout

def plot_times(stdout):
    """
    """
    sizes = []
    times = []

    for line in stdout: 
        if 'size' in line:
            size = int(line[line.index(' '):line.index('t') - 1])
            sizes.append(size)
            time = float(line[line.index('m') + 4: line.index('µ')])
            times.append(time)

    plt.plot(sizes, times)
    plt.show()



stdout = run('./build/src/huffman')
# print(stdout)
plot_times(stdout)

