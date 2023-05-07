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
matplotlib.rc('xtick', labelsize=fnt_sz3)
matplotlib.rc('ytick', labelsize=fnt_sz3)
x_lim=10**5
y_lim=2
# R=1000.0;
C=10.0**(-6);
fc=100.0;
R=1./(2*pi*fc*C);
Rf=10**4;
R1=100;
A=(1+Rf/R1);
system = A*control.tf([R*C,0.0], [R*C,1.])
print(system)
f = logspace(1, 5)
mag, phase, freq = control.bode(system,f,Hz=True,dB=True,deg=False)
ax1,ax2 = plt.gcf().axes     # get subplot axes
plt.sca(ax1)
plt.plot([fc,10**4],[20.0*np.log10(max(mag))-20.0*np.log10(np.sqrt(2)),20.0*np.log10(max(mag))-20.0*np.log10(np.sqrt(2))],'r--')
plt.plot([fc,fc],[20.0*np.log10(min(mag)),20.0*np.log10(max(mag))-20.0*np.log10(np.sqrt(2))],'r--')
# plt.title("Cutoff frequencies = {0:.3g,0:.3g}".format(fc1,fc2))
plt.tight_layout()
pp=PdfPages('high_pass_plot.pdf')
pp.savefig()
d = pp.infodict()
d['Title'] = 'High Pass Filter Frequency Response'
d['Author'] = 'Y. V. Karteek'
d['Subject'] = 'UES035'
d['Keywords'] = 'Active filter'
d['CreationDate'] = datetime.datetime.today()
d['ModDate'] = datetime.datetime.today()
pp.close()
plt.close()
