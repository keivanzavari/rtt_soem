/***************************************************************************
 tag: Ruben Smits  Tue Nov 16 09:26:15 CET 2010  soem_driver_factory.cpp

 soem_driver_factory.h -  description
 -------------------
 begin                : Tue November 16 2010
 copyright            : (C) 2010 Ruben Smits
 email                : first.last@mech.kuleuven.be

 ***************************************************************************
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2.1 of the License, or (at your option) any later version.    *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place,                                    *
 *   Suite 330, Boston, MA  02111-1307  USA                                *
 *                                                                         *
 ***************************************************************************/

#ifndef SOEM_DRIVER_FACTORY_H
#define SOEM_DRIVER_FACTORY_H

#include <map>
#include <string>
#include "soem_driver.h"

namespace soem_master
{

class SoemDriverFactory
{
public:
    //! gives you a static instance of the class
    /**
    *  @return a static reference to SoemDriverFactory class.
    * On the object you can call its createDriver method.
    */
    static SoemDriverFactory& Instance()
    {
        static SoemDriverFactory soem_driver_factory;
        return soem_driver_factory;
    }

    // typedef int (*PFI)(char *, char *);
    // creates PFI as a synonym for a pointer to a function of
    // two char * arguments that returns an int.
    /** Made for ease of use in SoemDriver::registerDriver
    *
    * creates CreateDriverCallBack as a synonym for a pointer to a function of
    * ec_slavet* argument that returs a SoemDriver*
    */
    typedef SoemDriver* (*CreateDriverCallBack)(ec_slavet*);

    /**
    * registers the driver, it is only used in a few places:
    * - soem_ebox/src/soem_ebox.cpp: registerDriver("E/BOX",...
    * - soem_beckhoff_drivers/src/soem_el3062.cpp: registerDriver("EL3062",...
    * why? not documented...
    *
    * it basically inserts the given parameters to the FactoryMap type
    * @param std::string name
    * @param CreateDriverCallBack type defined here
    *
    * @return
    * - true if a new element was inserted or
    * - false if an equivalent key already existed.
    */
    bool registerDriver(std::string name, CreateDriverCallBack createFn);

    /**
    * Creates the driver by looking up its name in the map
    * @return a pointer to SoemDriver class.
    * @param pointer of ec_slavet
    *
    * ec_slavet is a structure defined in ../../soem_core/ethercatmain
    */
    SoemDriver* createDriver(ec_slavet* mem_loc);
    void displayAvailableDrivers();

private:
    /** Made for ease of use
    * creates the map of names and CreateDriverCallBack which is descibed above
    */
    typedef std::map<std::string, CreateDriverCallBack> FactoryMap;

    /// std::map that contains the names and reference to the slaves
    FactoryMap m_factory_map;

    //! Empty constructor
    /**
    * - used in SoemDriverFactory::Instance method
    */
    SoemDriverFactory(){};

    /** Constructor
    * - with a constant reference to SoemDriverFactory objects
    * since we want to make a static object...
    */
    SoemDriverFactory(const SoemDriverFactory&);

    /** Destructor is empty
    */
    ~SoemDriverFactory(){};

    /// equal operator
    SoemDriverFactory& operator=(const SoemDriverFactory&);

};
}
#endif
