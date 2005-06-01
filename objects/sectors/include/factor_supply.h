#ifndef _FACTOR_SUPPLY_H_
#define _FACTOR_SUPPLY_H_
#if defined(_MSC_VER)
#pragma once
#endif

/*
	This software, which is provided in confidence, was prepared by employees
	of Pacific Northwest National Labratory operated by Battelle Memorial
	Institute. Battelle has certain unperfected rights in the software
	which should not be copied or otherwise disseminated outside your
	organization without the express written authorization from Battelle. All rights to
	the software are reserved by Battelle.  Battelle makes no warranty,
	express or implied, and assumes no liability or responsibility for the 
	use of this software.
*/

/*! 
* \file factor_supply.h
* \ingroup Objects
* \brief Factor Supply class header file.
* \author Pralit Patel
* \author Sonny Kim
* \date $Date$
* \version $Revision$
*/

#include <vector>
#include <string>
#include <xercesc/dom/DOMNode.hpp>
#include <memory>
#include "reporting/include/output_container.h"

class MoreSectorInfo;
class Tabs;

/*! 
* \ingroup Objects
* \brief CHANGE
* \details CHANGE
*
* \note CHANGE
* \author Pralit Patel, Sonny Kim
*/

class FactorSupply 
{
    friend class SGMGenTable;
public:
	FactorSupply();
    const std::string& getName() const;
	bool XMLParse( const xercesc::DOMNode* node );
	void toInputXML( std::ostream& out, Tabs* tabs ) const;
	void toDebugXML( const int period, std::ostream& out, Tabs* tabs ) const;

	static const std::string& getXMLNameStatic();
	void completeInit( const std::string& aRegionName );
    void initCalc( const std::string& aRegionName, const int period );

	double getSupply( const std::string& aRegionName, const int period ) const;
	void calcPricePaid( const std::string& aRegionName, const int period );
	void csvSGMOutputFile( std::ostream& aFile, const int period ) const;
	friend void OutputContainer::updateFactorSupply( const FactorSupply* factorSupply, 
        const int period );

	void updateOutputContainer( OutputContainer* outputContainer, const int period ) const;

protected:
    void setMarket( const std::string& aRegionName );
    const std::string& getXMLName() const;
    void setMarket();
	std::string name; //!< CHANGE
    std::string marketName; //!< regional market. this isn't read in right now.
    double mBasePrice; //!< Price in the base year. only applied to capital, should be in derived class.
    double mBaseSupply; //!< Supply in the base year, only applies to land and labor.
private:
	static const std::string XML_NAME; //!< node name for toXML methods
	std::auto_ptr<MoreSectorInfo> moreSectorInfo; //! Additional sector information needed below sector
};

#endif // _FACTOR_SUPPLY_H_

