"""
plot_timing.py

This script runs the Huffman encoding algorithm and plots the time it takes to encode different input sizes.
"""

import matplotlib.pyplot as plt
from subprocess import Popen, PIPE, STDOUT

def run(cmd):
    """
    Runs a command in the shell and returns the stdout as a list of strings.

    Args:
        cmd (str): The command to run in the shell.

    Returns:
        stdout (list): The stdout of the command as a list of strings.
    """
    p = Popen(cmd, shell=True, stdout=PIPE, stderr=STDOUT)
    stdout = []
    this_stdout, _ = p.communicate()
    line = this_stdout.decode('utf-8')
    stdout = line.split('\n')
    stdout = [line for line in stdout if line != '']
    return stdout

def plot_times(stdout):
    """
    Parses the stdout of the Huffman encoding algorithm and plots the time it takes to encode different input sizes.

    Args:
        stdout (list): The stdout of the command as a list of strings.
    """
    sizes = []
    times = []

    sizes = [int(line.split(",")[0]) for line in stdout]
    times = [float(line.split(",")[1]) for line in stdout]

    plt.plot(sizes, times)
    # reverse the x-axis
    plt.gca().invert_xaxis()
    plt.xlabel('Number of Unique Characters')
    plt.ylabel('Compressed Size/ Original Size')
    plt.title('Compression ratio vs. number of unique characters')
    plt.show()

stdout = run('./build/src/huffman')
plot_times(stdout)
