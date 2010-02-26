#include <core/wavefunction.h>
#include <core/potential/dynamicpotentialevaluator.h>

template<int Rank>
class SoftColoumbPotential : public PotentialBase<Rank>
{
public:
	//Required by DynamicPotentialEvaluator
	cplx TimeStep;
	double CurTime;

	//Potential parameters
	double nuclearSoft;
	double nuclearCharge;
	double electronSoft;
	double electronCharge;

	void ApplyConfigSection(const ConfigSection &config)
	{
		config.Get("nuclear_soft", nuclearSoft);
		config.Get("nuclear_charge", nuclearCharge);
		config.Get("electron_soft", electronSoft);
		config.Get("electron_charge", electronCharge);
	}

	inline double GetPotentialValue(const blitz::TinyVector<double, Rank> &pos)
	{
		double x1 = pos(0);
		double x2 = pos(1);

		double V1 = nuclearCharge / sqrt(x1*x1 + nuclearSoft);
		double V2 = nuclearCharge / sqrt(x2*x2 + nuclearSoft);

		double V12 = electronCharge / sqrt( (x1-x2)*(x1-x2) + electronSoft);		
		return V1 + V2 + V12;
	}
};


template<int Rank>
class LaserDipolePotential : public PotentialBase<Rank>
{
public:
	//Required by DynamicPotentialEvaluator
	cplx TimeStep;
	double CurTime;

	void ApplyConfigSection(const ConfigSection &config)
	{
	}

	inline double GetPotentialValue(const blitz::TinyVector<double, Rank> &pos)
	{
		double x1 = pos(0);
		double x2 = pos(1);
		return x1 + x2;
	}

};

