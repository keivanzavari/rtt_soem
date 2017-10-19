#!/bin/bash

cp -f necessary_package_xml.txt soem_core/package.xml


cp -f CMakeLists_for_soem_core.txt soem_core/CMakeLists.txt

# cd soem_core
# patch --quiet <../patch_for_cmake_soem_core.txt
# cd ..

