import math
import numpy as np
import scipy.stats as stats
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages


for n in [10, 15, 20, 25, 30, 100]:
    x = np.arange(0, n+1)
    cdf = stats.binom.cdf(x, n, .5)
    E = stats.binom.mean(n, .5)
    var = stats.binom.var(n, .5)

    # Sn is a linear transformation of Bin(n, .5)
    tr_x = 2 * x - n
    tr_cdf = cdf # cdf y stays the same
    tr_E = 2 * E - n
    tr_var = 4 * var

    # Approximating with normal distribution
    norm_x = np.linspace(-n, n, 1000)
    norm_cdf = stats.norm.cdf(norm_x, tr_E, math.sqrt(tr_var))

    with PdfPages(f"plots/exc2/n{n}.pdf") as pdf:
        plt.figure()
        plt.title('N = ' + str(n))
        plt.bar(tr_x[:-1], tr_cdf[:-1], width=np.diff(tr_x), align='edge', color='royalblue', label='Sn CDF')
        plt.plot(norm_x, norm_cdf, color='red', label='Normal distribution CDF')
        plt.ylim([0, 1])
        plt.xlabel('x')
        plt.ylabel('P(X <= x)')
        plt.legend()
        pdf.savefig()
        plt.close()
