# rtt_soem
RTT SOEM EtherCAT components and drivers

## Why have I forked it?
This repository depends on the SOEM library which was previously hosted on berlios.de.
The website of berlios is down. In the mean time, the SOEM library source code has moved to [github](https://github.com/OpenEtherCATsociety/SOEM).

SOEM version 1.2.5 is needed for the original repository of orocos/rtt_soem which can be found on the website of [Open EtherCAT society](https://github.com/OpenEtherCATsociety). This is [the link to V 1.2.5](http://openethercatsociety.github.io/dl/rel/SOEM1.2.5.tar.bz2).

This repositry will link and test integration with the latest version of SOEM.

## How can you use it?
- In order for SOEM library to be used in a catkin workspace, `CMakeLists.txt` file has to be modified, therefore you find a text file at the root of this repository which can replace the CMakeLists file in `soem_core` directory.
- For the ones who like patch approach, there is also a patch file
- catkin packages also require a `package.xml` file which is found again at root under the name `package_xml_soem_core.txt`
- copying these can also be done by running `run_me_first.sh`.