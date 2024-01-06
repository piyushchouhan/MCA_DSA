import cmath

def recursive_fft(a):
    n = len(a)
    if n == 1:
        return a

    wn = cmath.exp(2j * cmath.pi / n)
    w = 1
    a0 = a[::2]
    a1 = a[1::2]

    y0 = recursive_fft(a0)
    y1 = recursive_fft(a1)

    y = [0] * n
    for k in range(n // 2):
        y[k] = y0[k] + w * y1[k]
        y[k + n // 2] = y0[k] - w * y1[k]
        w = w * wn

    return y

if __name__ == "__main__":
    a = [1, 2, 3, 4]
    y = recursive_fft(a)

    for i, yi in enumerate(y):
        print(f"y[{i}] = {yi:.2f}")
