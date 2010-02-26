import sys
import os

sys.path.append("./pyprop")
import pyprop
pyprop.ProjectNamespace = globals()

from libpotential import *


def SetupConfig(**args):
	conf = pyprop.Load("config.ini")

	if "imtime" in args:
		if args["imtime"]:
			conf.SetValue("Propagation", "timestep", 1.0j * abs(conf.Propagation.timestep))
			conf.SetValue("Propagation", "renormalization", True)
		else:
			conf.SetValue("Propagation", "timestep", abs(conf.Propagation.timestep))
			conf.SetValue("Propagation", "renormalization", False)


	return conf


def GetGridPrefix(**args):
	conf = SetupConfig(**args)
	xmax = conf.Representation.rank0[1]
	count = conf.Representation.rank0[2]
	return "xmax%s_n%s" % (xmax, count)


def FindGroundstate(**args):
	args["imtime"] = True

	filename = "groundstate/groundstate_%s.h5" % GetGridPrefix(**args)
	dir = os.path.join(os.path.split(filename)[:-1])
	if not os.path.exists(dir) and pyprop.ProcId == 0:
		os.makedirs(dir)

def Benchmark():
	timer = pyprop.Timers()
	
	timer["Setup"].Start()
	conf = SetupConfig()
	prop = pyprop.Problem(conf)
	prop.SetupStep()
	timer["Setup"].Stop()

	timer["TimeStep"].Start()
	prop.AdvanceStep()
	timer["TimeStep"].Stop()

	timer["TimeStep2"].Start()
	prop.AdvanceStep()
	timer["TimeStep2"].Stop()

	print timer
	
def Propagate(**args):
	conf = SetupConfig(**args)
	prop = pyprop.Problem(conf)
	prop.SetupStep()
	for t in prop.Advance(10):
		E = prop.GetEnergy()
		print "t = %03f, E = %s" % (t, E)


