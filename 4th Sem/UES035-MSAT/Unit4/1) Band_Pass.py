from pylab import *
import control
import matplotlib.pyplot as plt
from matplotlib import rc, rcParams
from mpl_toolkits.axes_grid1.inset_locator import zoomed_inset_axes
from matplotlib.ticker import MaxNLocator
from mpl_toolkits.axes_grid1.inset_locator import mark_inset
from matplotlib.backends.backend_pdf import PdfPages
import numpy as np
import scipy.interpolate as inter

rc('text', usetex=True)
rc('axes', linewidth=2)
#rc('font', weight='bold')
rc('text.latex', preamble=r'\usepackage{amsmath}')
rc('font',**{'family':'serif'})
fnt_sz1=40
fnt_sz2=30
fnt_sz3=20
fnt_sz4=15
lw=2.
ms=4
matplotlib.rc('xtick', labelsize=fnt_sz4)
matplotlib.rc('ytick', labelsize=fnt_sz4)
x_lim=10**5
y_lim=2
# R=1000.0;
C1=10.0**(-6);
fc1=5000.0;
R1=1./(2*pi*fc1*C1);
Rf1=10**4;
R11=100;
A1=(1+Rf1/R11);
# A1=1.
system1 = A1*control.tf([1], [R1*C1,1.])
C2=10.0**(-6);
fc2=100.0;
R2=1./(2*pi*fc2*C2);
Rf2=10**4;
R12=100;
A2=(1+Rf2/R12);
# A2=1.
system2 = A2*control.tf([R2*C2,0.0], [R2*C2,1.])
print(system1)
print(system2)
print(system1*system2)
f = logspace(2, 5)
# w = 2 * pi * f
G=control.series(system1,system2);
print(G)
mag, phase, freq = control.bode(G,f,Hz=True,dB=True,deg=False)
ax1,ax2 = plt.gcf().axes     # get subplot axes
plt.sca(ax1)                 # magnitude plot
plt.plot([fc1,fc2],[20.0*np.log10(max(mag))-20.0*np.log10(np.sqrt(2)),20.0*np.log10(max(mag))-20.0*np.log10(np.sqrt(2))],'r--')
plt.plot([fc1,fc1],[20.0*np.log10(min(mag)),20.0*np.log10(max(mag))-20.0*np.log10(np.sqrt(2))],'r--')
plt.plot([fc2,fc2],[20.0*np.log10(min(mag)),20.0*np.log10(max(mag))-20.0*np.log10(np.sqrt(2))],'r--')
# plt.title("Cutoff frequencies = {0:.3g,0:.3g}".format(fc1,fc2))
plt.tight_layout()
pp=PdfPages('band_pass_plot.pdf')
pp.savefig()
d = pp.infodict()
d['Title'] = 'Band Pass Filter  Frequency Response'
d['Author'] = 'Y. V. Karteek'
d['Subject'] = 'UES035'
d['Keywords'] = 'Active filter'
d['CreationDate'] = datetime.datetime.today()
d['ModDate'] = datetime.datetime.today()
pp.close()
plt.close()
