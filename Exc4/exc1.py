import scipy.stats as stats
from reportlab.platypus import Table, SimpleDocTemplate
from reportlab.lib import colors

document = SimpleDocTemplate("plots/exc1.pdf")

data = [
    ['', 'n', 'P(X >= 6/5E(X))', 'P(|X - E(X)| >= 1/10E(X))']
]
for n in [100, 1000, 10000]:
    X = stats.binom(n, .5)
    E, var = X.mean(), X.var()
    data.append(['Markow',      n,  f"{E/(6/5*E):.4}",                 f"{2 * (E/(11/10*E)):.4}"])
    data.append(['Czebyszew',   n,  f"{1/2 * (var/(1/5*E)**2):.4}",    f"{var/(1/10*E)**2:.4}"])
    data.append(['Exact',       n,  f"{1 - X.cdf(6/5*E -1):.4}",       f"{2 * (1 - X.cdf(11/10*E -1)):.4}"])

table = Table(data)
table_style = [
    ('FONTNAME', (0, 0), (-1, -1), 'Times-Roman'),
    ('GRID', (0, 0), (-1, -1), 1, colors.black)
]
table.setStyle(table_style)

document.build([table])