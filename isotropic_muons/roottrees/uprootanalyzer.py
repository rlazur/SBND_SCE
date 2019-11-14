#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Spyder Editor

Uproot script to analyze the output in the harddrive just to see if it makes sense.
"""
import uproot as ur
import numpy as np
import matplotlib.pyplot as plt
import pandas

file = ur.open("harddrive/n100_isotropic_muon_0-2.0GeV_sbnd_ana.root")
anatree = file["analysistree"]["anatree"]


#fig = plt.figure()
#ax = fig.add_subplot(111)