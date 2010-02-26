import sys

sys.path.append("./pyprop")
import pyprop
pyprop.ProjectNamespace = globals()

from libpotential import *


def SetupConfig(**args):
	conf = pyprop.Load("config.ini")
	return conf


def Propagate(**args):
	conf = SetupConfig(**args)
	prop = pyprop.Problem(conf)
	prop.SetupStep()
	for t in prop.Advance(10):
		E = prop.GetEnergy()
		print "t = %03f, E = %s" % (t, E)
