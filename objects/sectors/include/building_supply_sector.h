#ifndef _BUILDING_SUPPLY_SECTOR_H_ 
#define _BUILDING_SUPPLY_SECTOR_H_ 
#if defined(_MSC_VER)
#pragma once
#endif

/*! 
* \file building_supply_sector.h
* \ingroup CIAM
* \brief The building supply sector
* \author Steve Smith
* \date $Date$
* \version $Revision$
*/

#include <xercesc/dom/DOMNode.hpp>
#include "sectors/include/supply_sector.h"

// Forward declarations
class GDP;
class MarketInfo;

/*! 
* \ingroup CIAM
* \brief A class which defines the building service supplysector.
*
*  This sector is identical in operation to the regular supply sector.
*
*  The only addition is that additional information is supplied about the sector 
*  characteristics through the marketInfo mechanism.
*
* \author Steve Smith
*/

class BuildingSupplySector: public SupplySector
{
public:
    BuildingSupplySector( const std::string regionName );
    virtual ~BuildingSupplySector();
	static const std::string& getXMLNameStatic();
    void initCalc( const int period, const MarketInfo* aRegionInfo );
protected:
 	virtual const std::string& getXMLName() const; 
    bool XMLDerivedClassParse( const std::string& nodeName, const xercesc::DOMNode* curr ); 
private:
	static const std::string XML_NAME; //!< node name for toXML methods
};

#endif // _BUILDING_SUPPLY_SECTOR_H_ 
