from pylab import *
from scipy import signal
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
fc=1000.0;
R=1./(2*pi*fc*C);
Rf=10**4;
R1=100;
A=(1+Rf/R1);
system = signal.lti([A], [2*pi*R*C,1.])
f = logspace(1, 5)
# w = 2 * pi * f
freq, mag, phase = signal.bode(system,f)
# semilogx( f, mag);
fig, axs = plt.subplots(1,figsize=(16, 7), dpi=600, facecolor='w', edgecolor='k')
axs.semilogx(freq,mag,'-',label=r'Frequency response',linewidth=lw, color='b', marker='s', markersize=ms)
# axs.plot(f,(max(mag)-20.0*np.log10(np.sqrt(2.)))*np.ones(size(f)),'--',linewidth=lw, color='r')
freq1, mag1, phase1 = signal.bode(system,f[0])
freq2, mag2, phase2 = signal.bode(system,fc)
axs.plot([freq1,freq2],[mag2,mag2],'--',linewidth=lw, color='r')
axs.plot([freq2,freq2],[min(mag),mag2],'--',linewidth=lw, color='r')
# axs.plot(density25,flow26,':',label=r'State Dependent with boundary escape',linewidth=lw, color='r', marker='s', markersize=ms)
axs.legend(loc='upper right',ncol=5,fontsize=fnt_sz4)
axs.set_xlabel(r'$\omega$ (Hz)',fontsize=fnt_sz2)
axs.set_ylabel(r'Gain (dB)',fontsize=fnt_sz2)
axs.set_title('Low Pass Filter',fontsize=fnt_sz2)
# axs.set_xlim([0,x_lim])
# axs.set_ylim([0,y_lim])
axs.grid(True)
a1=np.arange(1,9,step=1);
axs.set_xticks(np.concatenate((a1*10,a1*10**2,a1*10**3,a1*10**4,[10**5])))
# axs.set_xticks(np.arange(0, x_lim, step=50))
# axs.set_yticks(np.arange(0, y_lim, step=2000))
#axs.set_title(r'\textbf{Fundamental Diagram.}',fontsize=fnt_sz2)
plt.tight_layout()
pp=PdfPages('low_pass_plot.pdf')
pp.savefig()
d = pp.infodict()
d['Title'] = 'Filter Design'
d['Author'] = 'Y. V. Karteek'
d['Subject'] = 'UES035'
d['Keywords'] = 'Active filter'
d['CreationDate'] = datetime.datetime.today()
d['ModDate'] = datetime.datetime.today()
pp.close()
plt.close()
