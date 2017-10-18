# rtt_soem
RTT SOEM EtherCAT components and drivers

## Why have I forked it?
This repository depends on the SOEM library which was previously hosted on berlios.de.
The website of berlios is down. In the mean time, the SOEM library source code has moved to [github](https://github.com/OpenEtherCATsociety/SOEM).

SOEM version 1.2.5 is needed for the original repository of orocos/rtt_soem which can be found on the website of [Open EtherCAT society](https://github.com/OpenEtherCATsociety). This is [the link to V 1.2.5](http://openethercatsociety.github.io/dl/rel/SOEM1.2.5.tar.bz2).

This repositry will link and test integration with the latest version of SOEM.

## How can you use it?
- In order for SOEM library to be used in a catkin workspace, CMakeLists file has to be modified, therefore you find a text file at the root of this repository which can be replace the CMakeLists file in `soem_core` directory.
- catkin packages require a package.xml file. That one is also found here under the name `necessary_package_xml.txt`
- copying these can also be done by running `run_me_first.sh`.