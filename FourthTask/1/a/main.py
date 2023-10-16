import matplotlib.pyplot as plt

data_files = ['out0.txt', 'out1.txt', 'out2.txt']
y_values = [1, 2, 3]

for file, y in zip(data_files, y_values):
    x = []
    with open(file, 'r') as f:
        for line in f:
            x.append(int(line.strip()))

    plt.scatter(range(len(x)), [y] * len(x), label='y={}'.format(y), s=5)

plt.xlabel('Index')
plt.ylabel('Value of y')
plt.title('Graphs')
plt.legend()

plt.show()