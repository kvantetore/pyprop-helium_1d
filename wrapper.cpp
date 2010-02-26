
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <potential.cpp>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(libpotential)
{
    class_< DynamicPotentialEvaluator<SoftColoumbPotential<2>,2>, boost::noncopyable >("SoftColoumbPotential_2", init<  >())
        .def("ApplyConfigSection", &DynamicPotentialEvaluator<SoftColoumbPotential<2>,2>::ApplyConfigSection)
        .def("ApplyPotential", &DynamicPotentialEvaluator<SoftColoumbPotential<2>,2>::ApplyPotential)
        .def("MultiplyPotential", &DynamicPotentialEvaluator<SoftColoumbPotential<2>,2>::MultiplyPotential)
        .def("UpdateStaticPotential", &DynamicPotentialEvaluator<SoftColoumbPotential<2>,2>::UpdateStaticPotential)
        .def("GetPotential", &DynamicPotentialEvaluator<SoftColoumbPotential<2>,2>::GetPotential)
        .def("UpdatePotentialData", &DynamicPotentialEvaluator<SoftColoumbPotential<2>,2>::UpdatePotentialData)
        .def("CalculateExpectationValue", &DynamicPotentialEvaluator<SoftColoumbPotential<2>,2>::CalculateExpectationValue)
    ;

    class_< DynamicPotentialEvaluator<LaserDipolePotential<2>,2>, boost::noncopyable >("LaserDipolePotential_2", init<  >())
        .def("ApplyConfigSection", &DynamicPotentialEvaluator<LaserDipolePotential<2>,2>::ApplyConfigSection)
        .def("ApplyPotential", &DynamicPotentialEvaluator<LaserDipolePotential<2>,2>::ApplyPotential)
        .def("MultiplyPotential", &DynamicPotentialEvaluator<LaserDipolePotential<2>,2>::MultiplyPotential)
        .def("UpdateStaticPotential", &DynamicPotentialEvaluator<LaserDipolePotential<2>,2>::UpdateStaticPotential)
        .def("GetPotential", &DynamicPotentialEvaluator<LaserDipolePotential<2>,2>::GetPotential)
        .def("UpdatePotentialData", &DynamicPotentialEvaluator<LaserDipolePotential<2>,2>::UpdatePotentialData)
        .def("CalculateExpectationValue", &DynamicPotentialEvaluator<LaserDipolePotential<2>,2>::CalculateExpectationValue)
    ;

}

