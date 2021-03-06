/***************************************************************************
 tag: Ruben Smits  Tue Nov 16 09:26:15 CET 2010  soem_driver_factory.cpp

 soem_driver_factory.cpp -  description
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

#include <soem_master/soem_driver_factory.h>

namespace soem_master
{
using namespace RTT;
bool SoemDriverFactory::registerDriver(std::string name,
        CreateDriverCallBack create_fn)
{
    Logger::In in("SoemDriverFactor");
    log(Info) << "Registering driver for " << name << endlog();

    // Assign values to the map
    // std::map<string, int>::value_type is std::pair<string const, int>
    // so no (important) difference between them
    return m_factory_map.insert(FactoryMap::value_type(name, create_fn)).second;

    // insert returns
    // a pair, with its member pair::first set to an iterator pointing to
    // either the newly inserted element or to the element with an equivalent
    // key in the map. The pair::second element in the pair is set to true if
    // a new element was inserted or false if an equivalent key already existed.
}

SoemDriver* SoemDriverFactory::createDriver(ec_slavet* mem_loc)
{
    // search for the name in the map,
    // map.find is logarithmic in size.
    FactoryMap::const_iterator it = m_factory_map.find(
        std::string(mem_loc->name) );

    // find returns an iterator to the element,
    // if an element with specified key is found, or map::end otherwise.
    if (it == m_factory_map.end())
    {
        return NULL;
    }
    return (it->second)(mem_loc);
}

void SoemDriverFactory::displayAvailableDrivers()
{
    Logger::In in("SoemDriverFactory");
    log(Info) << "Following SOEM drivers are registered: \n"<< endlog();
    for (FactoryMap::const_iterator it = m_factory_map.begin(); it
            != m_factory_map.end(); ++it)
    {
      log(Info) << "\t" << it->first << endlog();
    }
}
}
