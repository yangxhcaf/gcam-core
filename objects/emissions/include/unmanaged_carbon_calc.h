#ifndef _UNMANAGED_CARBON_CALC_H_
#define _UNMANAGED_CARBON_CALC_H_
#if defined(_MSC_VER)
#pragma once
#endif

/*! 
 * \file unmanaged_carbon_calc.h
 * \ingroup Objects
 * \brief The UnmanagedCarbonCalc class header file.
 * \author James Blackwood
 */

#include <xercesc/dom/DOMNode.hpp>
#include "emissions/include/asimple_carbon_calc.h"

/*!
 * \brief A simple carbon content calculator used for unmanaged land leaves.
 * \details The unmanaged land carbon calculator reads-in value for above and
 *          below ground carbon for all years. These read-in values are then
 *          used to calculate the carbon value of the land and the net land use
 *          change emissions.
 */
class UnmanagedCarbonCalc : public ASimpleCarbonCalc {
public:
    UnmanagedCarbonCalc();
    virtual ~UnmanagedCarbonCalc();

    static const std::string& getXMLNameStatic();

	virtual bool XMLParse( const xercesc::DOMNode* aNode );
	virtual void toDebugXML( const int aPeriod, std::ostream& aOut, Tabs* aTabs ) const;
	virtual void toInputXML( std::ostream& aOut, Tabs* aTabs ) const;

	virtual void completeInit();

	virtual void setUnitAboveGroundCarbon( const double aAboveGroundCarbon,
                                           const int aPeriod );

	virtual void setUnitBelowGroundCarbon( const double aBelowGroundCarbon,
                                           const int aPeriod );
protected:
    //! Read in above ground carbon content by year.
    objects::YearVector<double> mAboveGroundCarbon;

    //! Read in below ground carbon content by year.
    objects::YearVector<double> mBelowGroundCarbon;

    virtual double getPotentialAboveGroundCarbonPerLandArea( const int aYear ) const;
    virtual double getPotentialBelowGroundCarbonPerLandArea( const int aYear ) const;
};

#endif // _UNMANAGED_CARBON_CALC_H_