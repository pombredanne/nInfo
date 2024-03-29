#
# nInfo (build script)
# Copyright (C) 2012 Frank "SeySayux" Erens <seysayux@gmail.com>
#
# This software is provided 'as-is', without any express or implied
# warranty. In no event will the authors be held liable for any damages
# arising from the use of this software.
#
# Permission is granted to anyone to use this software for any purpose,
# including commercial applications, and to alter it and redistribute it
# freely, subject to the following restrictions:
#
#     1. The origin of this software must not be misrepresented; you must not
#     claim that you wrote the original software. If you use this software
#     in a product, an acknowledgment in the product documentation would be
#     appreciated but is not required.
#
#     2. Altered source versions must be plainly marked as such, and must not be
#     misrepresented as being the original software.
#
#     3. This notice may not be removed or altered from any source
#     distribution.
#

#########################################################################

cmake_minimum_required(VERSION 2.6)
project(NINFO)

if(CMAKE_COMPILER_IS_GNUCC)
    add_definitions(-ansi -pedantic -Wall -Werror)
endif(CMAKE_COMPILER_IS_GNUCC)

add_subdirectory(libccm)
add_subdirectory(osinfo)
add_subdirectory(fsinfo)

add_subdirectory(bin/osinfo)

install( DIRECTORY libccm DESTINATION include FILES_MATCHING 
        PATTERN "*.h" )
install( DIRECTORY osinfo DESTINATION include FILES_MATCHING 
        PATTERN "*.h" )
install( DIRECTORY ccinfo DESTINATION include FILES_MATCHING 
        PATTERN "*.h" )
install( DIRECTORY fsinfo DESTINATION include FILES_MATCHING 
        PATTERN "*.h" )
